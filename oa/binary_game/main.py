def goodBinaryStrings(
    minLength: int, maxLength: int, oneGroup: int, zeroGroup: int
) -> int:
    kMod = 1000000007
    dp = [0] * (maxLength + 1)
    dp[0] = 1

    for i in range(maxLength + 1):
        if dp[i] > 0:
            appendZeros = i + zeroGroup
            if appendZeros <= maxLength:
                dp[appendZeros] += dp[i]
                dp[appendZeros] %= kMod
            appendOnes = i + oneGroup
            if appendOnes <= maxLength:
                dp[appendOnes] += dp[i]
                dp[appendOnes] %= kMod

    return sum(dp[minLength:]) % kMod


if __name__ == "__main__":
    print(goodBinaryStrings(2, 4, 2, 2))
