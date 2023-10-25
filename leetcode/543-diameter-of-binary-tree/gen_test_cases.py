import networkx as nx
import matplotlib.pyplot as plt
import random
import json
from typing import List, Tuple


def visualize_tree(parents: List[int], image_file_name: str):
    print("parents = ", parents)
    G = nx.Graph()
    G.add_nodes_from([n for n in range(len(parents))])
    G.add_edges_from([(i, parents[i]) for i in range(1, len(parents))])
    pos = nx.spring_layout(G)
    nx.draw_networkx(G, pos, node_size=1200, node_color="#00ccff", width=2.0)
    plt.show()


def generate_tree(
    number_of_nodes: int,
) -> (List[int], List[Tuple[int, int]]):
    parents = [-1] * number_of_nodes
    for i in range(1, number_of_nodes):
        parent = random.randint(0, i - 1)
        parents[i] = parent
    edges = []
    for index in range(number_of_nodes):
        if parents[index] == -1:
            continue
        edges.append((parents[index], index))
    return parents, edges


def main():
    random.seed(114514)
    number_of_nodes_list = [1, 2, 3, 6, 10, 100]
    with open("test_cases.json", "w") as test_case_file:
        test_cases = []
        for i in range(len(number_of_nodes_list)):
            parents, edges = generate_tree(number_of_nodes_list[i])
            image_file_name = "{0:2}.png".format(i)
            visualize_tree(parents, image_file_name)
            test_case = {
                "parents": parents,
                "edges": edges,
                "result": 0,
                "graph": image_file_name,
            }
            test_cases.append(test_case)
        json.dump(test_cases, test_case_file, indent=2)


def draw_test_cases():
    with open("test_cases.json") as f:
        test_cases = json.load(f)
        for test_case in test_cases:
            visualize_tree(test_case["parents"], test_case["values"], None)


if __name__ == "__main__":
    main()
