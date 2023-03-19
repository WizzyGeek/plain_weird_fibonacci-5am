class FibNode {
    constructor(children) {
        this.children = children;
    }

    add(other) {
        if ((other.children.length == Math.max(0, this.children.length - 1)) && (this.children.length > other.children.length)) {
            let tmp = this.children.slice();
            tmp.push(other);
            return new FibNode(tmp);
        }
        return null;
    }
}

const ZERO = new FibNode([]);
const ONE = new FibNode([ZERO]);

function makeTree(rank) {
    let i = 0;
    let t1 = ZERO;
    let t2 = ONE;
    let tmp;
    while (i < rank) {
        tmp = t2;
        t2 = t2.add(t1);
        t1 = tmp;
        i++;
    }
    return t1;
}

function walkTree(node) {
    let visited = 1;
    let visiting = node.children.slice();
    while (visiting.length > 0) {
        let n = visiting.pop();
        visited++;
        visiting.push(...n.children);
    }
    return visited;
}

function fib(n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return walkTree(makeTree(n - 2));
}

for (let i = 0; i < 40; i++) {
    console.log(i, fib(i));
}