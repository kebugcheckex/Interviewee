import networkx as nx
import matplotlib.pyplot as plt
import random
import json
from typing import List, Tuple


def visualize_tree(parents: List[int], values: List[int], image_file_name: str):
    print("parents = ", parents)
    print("values = ", values)
    labels = {i: f"{i}: {values[i]}" for i in range(len(values))}
    G = nx.Graph()
    G.add_nodes_from([n for n in range(len(parents))])
    G.add_edges_from([(i, parents[i]) for i in range(1, len(parents))])
    pos = nx.spring_layout(G)
    nx.draw_networkx(
        G, pos, node_size=1200, node_color="#00ccff", width=2.0, with_labels=False
    )
    nx.draw_networkx_labels(G, pos, labels=labels)
    plt.show()


def generate_tree(
    number_of_nodes: int, data_range: (int, int)
) -> (List[int], List[int]):
    values = [
        random.randint(data_range[0], data_range[1]) for n in range(number_of_nodes)
    ]
    parents = [-1] * number_of_nodes
    for i in range(1, number_of_nodes):
        parent = random.randint(0, i - 1)
        parents[i] = parent

    return (values, parents)


def main():
    number_of_nodes_list = [1, 2, 3, 6, 10, 100]
    data_ranges = [(-10, 10), (-10, 10), (-10, 10), (-20, 20), (-20, 20), (-1000, 1000)]
    with open("test_cases.json", "w") as test_case_file:
        test_cases = []
        for i in range(len(number_of_nodes_list)):
            values, parents = generate_tree(number_of_nodes_list[i], data_ranges[i])
            image_file_name = "{0:2}.png".format(i)
            visualize_tree(parents, values, image_file_name)
            test_case = {
                "values": values,
                "parents": parents,
                "result": 0,
                "graph": image_file_name,
            }
            test_cases.append(test_case)
        json.dump(test_cases, test_case_file)


def draw_test_cases():
    with open("test_cases.json") as f:
        test_cases = json.load(f)
        for test_case in test_cases:
            visualize_tree(test_case["parents"], test_case["values"], None)


if __name__ == "__main__":
    draw_test_cases()
