The straightforward intuition is to try all possible locations to insert the different operators. For a number with `n` digits, there are `n-1` potential locations to insert operators, each location has four possibilities: `+`, `-`, `*` and no operators. In total there are `4^(n-1)` choices to try. Note that we don't have to insert an operator in-between every two digits. This is not immediately clear from the problem description.

It is not difficult to observe that the brutal-force algorithm involves a lot of redundant calculations. For example, when we try to put an operator at the `i`-th location, we can reuse the value from the existing expression up to this point without calculating it from the beginning, thus leads us to a backtracking approach.

The backtracking algorithm on the high level recursively try to choose one of the four possibilities mentioned above at each location and check if the eventual expression evaluates to the target.

The actual implemenation requires handling a few special cases.

- **Leading zeros**: The problem description states that the solutions should not contain any leading zeros. However, a single zero is allowed. For example, `1*0+2` is a valid solution. To take care of leading zeros, we check the current number we are constructing and see if it has two or more consecutive zeros from the beginning. In this case we can just return from the recursion function as any subsequent combiantions will be invalid.
- **Operator precedences**: Multiplications have higher precedence than additions and subtractions. If we decide to insert `*` after the current number, we need to undo the previous update to the value. For example, `1+2*3`. At the moment we want to insert `*` between 2 and 3, the existing expression `1+2` evaluates to `3`. Blindly multiplying this value with 3 will result in incorrect values. Therefore, we need to subtract the previous number 2 from the current value and instead adding the result of `2*3` to the value before 2, which is 1. Similar operations can be done to `+` and `-`.

## Language-specific Optimizations

### C++

To reduce the number of parameters in the recursion function, we can store the two input `string num` and `int target` into class member variables. Same for the solutions vector.
