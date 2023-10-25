import random
import networkx as nx
import matplotlib.pyplot as plt
from typing import List, Tuple

random.seed(114514)

def generate_random_graph(n: int) -> List[Tuple[int, int]]:
    """
    n: number of nodes
    Returns a list of edges
    """
    G = nx.Graph()
    for i in range(n):
        G.add_node(i)
    
    for i in range(n):
        for j in range(i + 1, n):
            if random.random() < 0.3:
                print(f"edges {i} - {j}")
                G.add_edge(i, j)
    
    nx.draw_networkx(G, nx.spring_layout(G))
    plt.show()
    return G.edges

if __name__ == "__main__":
    edges = generate_random_graph(8)
    print(f"Edges, {edges}")
