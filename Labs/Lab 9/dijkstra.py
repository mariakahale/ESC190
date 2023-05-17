import numpy as np




class Node:
    def __init__(self, value):
        self.value = value #value of node
        self.connections = [] #list of connections of type Con
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set([start])
    current = start
    while current != end:
        
        cur_dist = np.inf
        cur_v = None
        for node in visited:
            for con in node.connections:
                if con.node in visited:
                    continue
                if cur_dist > node.distance_from_start + con.weight:
                    cur_dist = node.distance_from_start + con.weight
                    cur_v = con.node
    
        current = cur_v
        current.distance_from_start = cur_dist
        visited.add(current)
    return current.distance_from_start
                                                
if __name__ == "__main__":
    #initialize the nodes
    NodeA = Node("A")
    NodeB = Node("B")
    NodeC = Node("C")
    NodeD = Node("D")
    NodeE = Node("E")

    #initialize connections
    NodeA.connections = [Con(NodeB, 8), Con(NodeC, 2)]
    NodeB.connections = [Con(NodeA,8), Con(NodeD,9),Con(NodeE,4)]
    NodeC.connections = [Con(NodeA,2), Con(NodeD,5)]
    NodeD.connections = [Con(NodeB,9), Con(NodeC,5),Con(NodeE,5)]
    NodeE.connections = [Con(NodeB,4), Con(NodeD,5)]

    print(dijkstra(NodeA,NodeE))




















    
