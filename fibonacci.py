class FibonacciNode:
    __Slots__ = ("_children",)
    def __init__(self, *children) -> None:
        self._children = tuple(children)

    def __add__(self, o):
        if len(o._children) == max(0, len(self._children) - 1) and len(self._children) > len(o._children):
            return FibonacciNode(*self._children, o)

ZERO = FibonacciNode()
ONE = FibonacciNode(ZERO)

def make_tree(rank):
    i = 0
    t1 = ZERO
    t2 = ONE
    tmp = None
    while i < rank:
        tmp = t2
        t2 = t2 + t1
        t1 = tmp
        i+=1
    return t1

def walk_tree(node):
    visited = 1 # root node
    visiting = list(node._children)
    while visiting:
        n = visiting.pop()
        visited += 1
        visiting.extend(n._children)
    return visited

def fibonacci_0indexed(n):
    if n == 0 or n == 1:
        return n
    return walk_tree(make_tree(n - 2))

for i in range(100):
    print(i, fibonacci_0indexed(i))
