#include "../header.h"

long getMaximumCouponValue(const string& coupon, int k) {
    constexpr unsigned long kMod = 1000000007;

    unsigned long currentValue = 0;
    unsigned long maxValue = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < k; i++) {
        int position = coupon[i] - 'a' + 1;
        count[position] += 1;
    }
    for (const auto& pair : count) {
        currentValue += pow(pair.first, pair.second);
    }
    for (int i = 1; i <= coupon.size() - k; i++) {
        int prevPosition = coupon[i - 1] - 'a' + 1;
        currentValue -= pow(prevPosition, count[prevPosition]);
        count[prevPosition]--;
        int nextPosition = coupon[i + k - 1];
        currentValue += pow(nextPosition, count[nextPosition]);
        maxValue = max(maxValue, currentValue);
    }
    return maxValue;
}

int main() {
    long result = getMaximumCouponValue("bcaa", 2);
    cout << "expected = 6, actual = " << result << "\n";
    return 0;
}
