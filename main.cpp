#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(30);

    tree.remove();

    std::cout << tree.getSize();

    return 0;
}
