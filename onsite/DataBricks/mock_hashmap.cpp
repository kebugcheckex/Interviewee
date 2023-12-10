#include <chrono>
#include <deque>
#include <iostream>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

constexpr int kSecondsIn1Minute = 60;

template <class ValueType>
class MockHashMap {
 public:
  MockHashMap(int loadMeasureMinutes = 5)
      : loadMeasureInterval_(loadMeasureMinutes * kSecondsIn1Minute),
        getCounter_(std::vector<int>(loadMeasureMinutes * kSecondsIn1Minute)),
        putCounter_(std::vector<int>(loadMeasureMinutes * kSecondsIn1Minute)) {}

  ValueType& get(const std::string& key) const {
    int timestamp = std::chrono::system_clock::now().time_since_epoch();
    int cursor = timestamp % loadMeasureInterval_;
    int rangeToInvalidate =
        (timestamp - lastGetTimestamp_) % loadMeasureInterval_;
    for (int i = getCounterCursor_; i < getCounterCursor_ + rangeToInvalidate;
         i++) {
      getCounter_[i % loadMeasureInterval_] = 0;
    }
    getCounter_[timestamp % loadMeasureInterval_] += 1;
    lastGetTimestamp_ = timestamp;
    getCounterCursor_ =
        (getCounterCursor_ + rangeToInvalidate) % loadMeasureInterval_;
    return data_.at(key);
  }

  void put(const std::string& key, const ValueType& value) {
    data_[key] = value;
    int timestamp = std::chrono::system_clock::now().time_since_epoch();
    int cursor = timestamp % loadMeasureInterval_;
    int rangeToInvalidate =
        (timestamp - lastGetTimestamp_) % loadMeasureInterval_;
    for (int i = putCounterCursor_; i < putCounterCursor_ + rangeToInvalidate;
         i++) {
      putCounter_[i % loadMeasureInterval_] = 0;
    }
    putCounterCursor_ =
        (putCounterCursor_ + rangeToInvalidate) % loadMeasureInterval_;
    putCounter_[timestamp % loadMeasureInterval_] += 1;
    lastPutTimeStamp_ = timestamp;
  }

  double measure_put_load() {
    int timestamp = std::chrono::system_clock::now().time_since_epoch();
    if (timestamp - lastGetTimestamp_ >= loadMeasureInterval_) {
      return 0.0;
    }
    double sum = 0.0;
    for (int i = timestamp % loadMeasureInterval_; i <= getCounterCursor_;
         i++) {
      sum += getCounter_[i];
    }
    return sum / loadMeasureInterval_;
  }

  double measure_get_load() {}

 private:
  std::unordered_map<std::string, ValueType> data_;
  int loadMeasureInterval_;
  std::vector<int> getCounter_, putCounter_;
  int getCounterCursor_, putCounterCursor_;
  int lastGetTimestamp_, lastPutTimeStamp_;
};

class TimeSeries {
 public:
  // Constructor initializes the circular buffer with a given capacity
  TimeSeries(size_t capacity) : capacity_(capacity) {}

  // Update the value and remove old values
  void updateValue(double value) {
    auto currentTime = std::chrono::steady_clock::now();
    values_.emplace_back(currentTime, value);

    // Remove values older than 1 minute
    while (!values_.empty() &&
           (currentTime - values_.front().first) > std::chrono::minutes(1)) {
      values_.pop_front();
    }
  }

  // Query the sum of values in the past minute
  double querySum() const {
    double sum = 0.0;
    auto currentTime = std::chrono::steady_clock::now();

    // Calculate the sum of values within the past minute
    for (const auto& entry : values_) {
      if ((currentTime - entry.first) <= std::chrono::minutes(1)) {
        sum += entry.second;
      } else {
        // Values are in chronological order, so we can break early
        break;
      }
    }

    return sum;
  }

 private:
  // Pair of timestamp and value
  using Entry = std::pair<std::chrono::steady_clock::time_point, double>;

  // Circular buffer to store timestamped values
  std::deque<Entry> values_;

  // Capacity of the circular buffer
  size_t capacity_;
};

int main() {}