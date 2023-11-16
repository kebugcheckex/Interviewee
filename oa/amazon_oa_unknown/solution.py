from typing import List


def search(a: List[int], b: List[int], remaining: int, tabs: int) -> int:
    print(f"{tabs}Remaining = {remaining}")
    if remaining <= 0:
        return 0

    min_value = 99999999999
    for i in range(len(a)):
        for num_items in range(1, remaining + 1):
            per_item_cost = a[i] + (num_items - 1) * b[i]
            result = per_item_cost * num_items + search(
                a, b, remaining - num_items, tabs + "  "
            )
            print(
                f"{tabs}Buy {num_items} pieces of {i}-th item, per item cost = {per_item_cost}, recursion result = {result}"
            )
            min_value = min(min_value, result)
    print(f"{tabs}When {remaining} quota remains, the min cost is {min_value}")
    return min_value


def compute(a: List[int], b: List[int], m: int) -> int:
    if len(a) != len(b):
        raise Exception("len(a) != len(b)")
    k = len(a)
    items_count = [0] * k
    total_cost = []
    for i in range(k):
        total_cost.append([0] * (m + 1))
        for j in range(m + 1):
            items_count[i] = j
            if j == 0:
                continue
            if sum(items_count) > m:
                continue
            unit_cost = a[i] + (j - 1) * b[i]
            total_cost[i][j] = unit_cost * j
    sum_cost = [sum(row) for row in total_cost]
    for i in range(k):
        for c in total_cost[i]:
            print(f"{c},", end=" ")
        print(sum_cost[i])
    return min(sum_cost)


if __name__ == "__main__":
    a = [1, 2, 3]
    b = [3, 2, 1]
    m = 2
    compute(a, b, m)
