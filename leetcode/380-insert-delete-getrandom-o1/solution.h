#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
   public:
    RandomizedSet() {}

    bool insert(int val) {
        if (data_.contains(val)) {
            return false;
        }
        values_.push_back(val);
        data_.insert({val, values_.size() - 1});
        return true;
    }

    bool remove(int val) {
        if (!data_.contains(val)) {
            return false;
        }
        int index = data_.at(val);
        data_.erase(val);
        if (!data_.empty()) {
            int lastValue = values_[values_.size() - 1];
            values_[index] = lastValue;
            data_[lastValue] = index;
        }
        values_.pop_back();
        return true;
    }

    int getRandom() {
        uniform_int_distribution<> dist(0, values_.size() - 1);
        return values_[dist(generator_)];
    }

   private:
    vector<int> values_;
    unordered_map<int, int> data_;
    mt19937 generator_;
};

void insert(RandomizedSet& set, int value) {
    bool res = set.insert(value);
    printf("Insert %d => %s\n", value, res ? "true" : "false");
}

void remove(RandomizedSet& set, int value) {
    bool res = set.remove(value);
    printf("Remove %d => %s\n", value, res ? "true" : "false");
}

void getRandom(RandomizedSet& set) { printf("GetRandom: %d\n", set.getRandom()); }

int main() {
    RandomizedSet rs;
    fstream if0("380_test_case0.txt");
    fstream if1("380_test_case1.txt");
    string buffer, op;
    while (getline(if0, op)) {
        auto& res = getline(if0, op);
        if (!res) {
            break;
        }
        getline(if1, buffer);
        int data = stoi(buffer);
        if (op == "insert") {
            insert(rs, data);
        } else if (op == "remove") {
            remove(rs, data);
        } else if (op == "getRandom") {
            getRandom(rs);
        } else {
            printf("Fuck\n");
        }
    }
    return 0;
}
