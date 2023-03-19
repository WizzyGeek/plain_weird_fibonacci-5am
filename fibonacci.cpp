#include<cstddef>
#include<cstdlib>
#include<vector>
#include<stack>
#include<iostream>

// Cursed Code with lots of copies, more copies than python
// Some bugs come up when u try to be smart
class fib_node {
    public:
        std::vector<fib_node> children;

        fib_node() {
            children = std::vector<fib_node>();
        }

        fib_node(std::vector<fib_node> c) {
            children = c;
        }

        fib_node(const fib_node &other) {
            children = std::vector<fib_node>(other.children);
        }

        fib_node operator+= (fib_node &other) {
            // std::cout << "aa " << other.children.size() << " " << children.size() << '\n';
            // std::cout << "conds " << other.children.size() << " " << std::max<unsigned long>(0, children.size() - 1) << '\n';
            if ((other.children.size() == std::max<unsigned long>(0, children.size() - 1)) && (children.size() > other.children.size())) {
                children.push_back(other);
            }
            return *this;
        }
};

fib_node ZERO = fib_node();
fib_node ONE = fib_node();

fib_node make_tree(int rank) {
    int i = 0;
    fib_node t1 = fib_node();
    fib_node t2 = t1;
    t2.children.push_back(t1);
    fib_node tmp;
    while (i < rank) {
        tmp = t2;
        t2 += t1;
        t1 = tmp;
        // std::cout << "The ret tree degree is " << t2.children.size() << "\n";
        i++;
    }
    return t1;
}

int walk_tree(fib_node node) {
    int visited = 1;
    std::vector<fib_node> visiting(node.children);
    while (visiting.size() != 0) {
        auto n = visiting[visiting.size() - 1].children;
        visiting.pop_back();
        for (auto &elem : n) {
            visiting.push_back(elem);
        }
        visited++;
    }
    return visited;
}

int main() {
    ONE.children.push_back(ZERO);
    std::cout << "0 0\n1 1\n";
    for (int i = 2; i < 30; i++) {
        std::cout << i << " " << walk_tree(make_tree(i - 2)) << '\n';
    }
    return 0;
}