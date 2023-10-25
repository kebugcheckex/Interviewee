# Social Media Suggestions

Implement a prototype of a friend recommendation system for a social media application.

There are `n` users indexed from 1 to `n`, and `m` friends represented as a 2D array, `friendships`, where the `i-th` friendship is a connection between users `friendship[ij[0]` and `friendship[i][1]`.

User `x` is suggested as a friend to user `y` if `x` and `y` are not friends and have the maximum number of common friends, i.e. a friend of both `x` and `y`. If there are multiple possible such users `x`, the one with the minimum index is
suggested.

Given `n` and `friendships`, for each of the `n` users, find the index of the friend that should be recommended to them. If there is no recommendation available, report -1.

## Example

Suppose `n = 5`, `m = 5`, and `connections = [[0, 1], [0, 2], [1, 3], [2, 3], [3, 4]]`

User | Max Common Friends With | Recommendation
---|---|---
0 | 3 (1, 2) | 3
1 | 2 (0, 3) | 2
2 | 1 (0, 3) | 1
3 | 0 (1, 2) | 0
4 | 2 (3), 1 (3) | 1 (minumum index)

Hence the answer returned is `[3, 2, 1, 0, 1]`.

## Function Description

Complete the function `getRecommendedFriends` in the editor below.

`getRecommendedFriends` has the following parameters:
- `int n`: the number of users
- `int friendships[m][2]`: the friendships between the users

## Constraints
- `1 <= n <= 10^5`
- `0 <= m <= 2.5e5`
- `0 < friendships[i][0], friendships[i][1] < n`
- There are no self-loops or multiple edges.
- Each user has a maximum of 15 friends.
- The network of friends _might be_ disconnected.

## Sample Case

### Sample Input For Custom Testing

```
STDIN    FUNCTION
-----    --------
3     ->  n = 3
3     ->  m = 3
2
0 1   -> friendships = [[0, 1],[1, 2],[2, 0]]
1 2
2 0
```

### Sample Output

```
-1
-1
-1
```

### Explanation