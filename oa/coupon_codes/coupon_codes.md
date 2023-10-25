# Coupon Codes

Several e-commerce websites provide discount coupons as scratch cards to faciliate business.

For a coupon code that consisits of lowercase English characters, the value of the coupon is calculated as follows:
1. Each lowercase character is mapped to a positive integer, i.e. its corresponding position in the alphabet. So 'a' is mapped to 1, 'b' to 2, ... and 'z' to 26.
2. The contribution of a character is calculated as (mapped value of the character)^(frequency of that character in coupon) modulo (10^9+7). For example, the contribution of character 'z' in coupon "ddzdzz" is 26^3 modulo (10^9 + 7)
3. The value of the coupon is the sum of the contributions of each character in the coupon. For example, the value of the coupon "ddzdd" is 4^3+26^3 modulo (10^9+7).

Given an initial coupon string _coupon_, and an integer _k_, coupon codes are created by taking all substrings of length _k_ in _coupon_. Find the maximum possible coupon value amongst all coupon code generated.

Note that the maximum value can be more than 10^9+7.

## Example

Consider `coupon = "abcc"` and `k = 2`.

All coupon codes are of length 2, and their coupon values are:
1. "ab": value = 1^1+2^1 = 3
2. "bc": value = 2^1+3^1 = 5
3. "cc": value = 3^2 = 9

The maximum coupon value amongst all coupon is 9.

## Function Description

Complete the function `getMaximumCouponValue` in the editor below.

`getMaximumCouponValue` has the following parameters:
- `string coupon`: the coupon
- `int k`: the substring length for the coupon codes

## _Returns_
- `long_int`: the maximum coupon value amongst all coupons generated

## Constraints
- 1 <= |coupon| <= 10^5
- 1 <= k <= |coupon|