from collections import deque, defaultdict


def minKnightMoves(x: int, y: int) -> int:
    # 8 directions
    directions = {
        (-1, -2),
        (-1, 2),
        (-2, -1),
        (-2, 1),
        (1, -2),
        (1, 2),
        (2, -1),
        (2, 1),
        #     (2, 1),
        #     (2, -1),
        #     (-2, 1),
        #     (-2, -1),
        #     (1, 2),
        #     (1, -2),
        #     (-1, 2),
        #     (-1, -2),
    }
    queue = deque()
    visited = set()
    x, y = abs(x), abs(y)
    if x == 1 and y == 1:
        return 2
    # (x,y,steps)
    queue = deque([(0, 0, 0)])
    counter = defaultdict(int)
    while queue:
        cur_x, cur_y, steps = queue.popleft()
        print(f"Visiting ({cur_x}, {cur_y}) move = {steps}")
        if [cur_x, cur_y] == [x, y]:
            print(counter)
            return steps
        counter[steps] += 1
        for dx, dy in directions:
            if (
                0 <= cur_x + dx <= 300
                and 0 <= cur_y + dy <= 300
                and (cur_x + dx, cur_y + dy) not in visited
            ):
                visited.add((cur_x + dx, cur_y + dy))
                queue.append((cur_x + dx, cur_y + dy, steps + 1))


if __name__ == "__main__":
    print(minKnightMoves(60, 30))
