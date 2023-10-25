#include "../header.h"

constexpr unsigned long kMod = 1000000007;

int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
    // dp[i] means number of good binary strings with length i
    vector<unsigned long> dp(maxLength + 1);
    dp[0] = 1;
    for (int i = 0; i < maxLength + 1; i++) {
        if (dp[i] > 0) {
            int appendZeros = i + zeroGroup;
            if (appendZeros <= maxLength) {
                dp[appendZeros] += dp[i];
                dp[appendZeros] %= kMod;
            }
            int appendOnes = i + oneGroup;
            if (appendOnes <= maxLength) {
                dp[appendOnes] += dp[i];
                dp[appendOnes] %= kMod;
            }
        }
    }
    return reduce(dp.begin() + minLength, dp.end()) % kMod;
}

int main() {
    int result = goodBinaryStrings(7304, 8195, 88, 58);
    cout << "result = " << result << "\n";
    return 0;
}