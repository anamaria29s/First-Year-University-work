class Node:
    def __init__(self, value):
        self.value = value
        self.child = None
        self.next_sibling = None
        self.rank = 0


class PairingHeap:
    def __init__(self):
        self.root = None
    def insert(self, value):
        new_node = Node(value)
        self.root = self._merge(self.root, new_node)

    def merge(self, other_heap):
        self.root = self._merge(self.root, other_heap.root)

    def find_max(self):
        if self.root is None:
            return None
        max_node = self.root
        curr_node = max_node.next_sibling
        while curr_node is not None:
            if curr_node.value > max_node.value:
                max_node = curr_node
            curr_node = curr_node.next_sibling
        return max_node.value

    def delete_max(self):
        if self.root is None:
            return None
        max_value = self.root.value
        if self.root.child is None:
            self.root = None
        else:
            new_root = self._combine_pairs(self.root.child)
            self.root = new_root
        return max_value

    def _merge(self, node1, node2):
        if node1 is None:
            return node2
        if node2 is None:
            return node1
        if node1.value > node2.value:
            node2.next_sibling = node1.child
            node1.child = node2
            return node1
        else:
            node1.next_sibling = node2.child
            node2.child = node1
            return node2

    def _combine_pairs(self, first_node):
        if first_node is None or first_node.next_sibling is None:
            return first_node
        else:
            a = first_node
            b = first_node.next_sibling
            c = b.next_sibling
            a.next_sibling = None
            b.next_sibling = None
            c = self._combine_pairs(c)
            return self._merge(self._merge(a, b), c)

heap = {}
with open("mergeheap.in", "r") as f:
    n, q = map(int, f.readline().split())
    for i in range(q):
        line = f.readline().split()
        if line[0] == "1":
            if line[1] not in heap:
                heap[line[1]] = PairingHeap()
            heap[line[1]].insert(int(line[2]))
        elif line[0] == "2":
            with open("mergeheap.out", "a") as g:
                g.write(str(heap[line[1]].find_max()) + '\n')
                heap[line[1]].delete_max()
        elif line[0] == "3":
            if line[1] not in heap:
                heap[line[1]] = PairingHeap()
            heap[line[1]].merge(heap[line[2]])
