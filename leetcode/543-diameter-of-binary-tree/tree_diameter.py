import json

max_length = 0


def tree_diameter(edges):
    """
    :type edges: List[List[int]]
    :rtype: int
    """
    global max_length
    if len(edges) == 0:
        return 0
    max_length = 0
    graph = {}
    in_degrees = {}
    for edge in edges:
        from_ = edge[0]
        to_ = edge[1]
        if from_ not in graph:
            graph[from_] = []
        if to_ not in graph:
            graph[to_] = []
        graph[from_].append(to_)
        if from_ not in in_degrees:
            in_degrees[from_] = 0
        if to_ not in in_degrees:
            in_degrees[to_] = 0
        in_degrees[to_] += 1

    root = None
    for node, in_degree in in_degrees.items():
        if in_degree == 0:
            root = node
            break
    traverse(graph, root)
    return max_length


def traverse(graph, node):
    global max_length
    if len(graph[node]) == 0:
        return 0  # leaf node
    lengths = [traverse(graph, child) for child in graph[node]]
    sorted(lengths)
    current_max_length = lengths[0] + 1
    if len(lengths) >= 2:
        current_max_length += lengths[1]
    max_length = max(max_length, current_max_length)
    return lengths[0] + 1


def main():
    with open("test_cases.json") as test_cases_file:
        test_cases = json.load(test_cases_file)
        for test_case in test_cases:
            result = tree_diameter(test_case["edges"])
            expected = test_case["result"]
            print(f"result = {result}, expected = {expected}")


if __name__ == "__main__":
    main()
