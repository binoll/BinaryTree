#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(10);

    tree.add(15);

    tree.add(20);

    tree.add(10);

    if (tree.remove(10)) {
        std::cout << "LOX";
    }

    if (tree.remove(15)) {
        std::cout << "LOX";
    }

    std::cout << tree.getSize();
    std::cout << '\n' << tree.find(50) << '\n' << tree.find(40) << '\n' << tree.find(15);



    return 0;
}
