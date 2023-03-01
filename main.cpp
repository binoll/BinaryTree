#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(30);

    tree.add(5);

    tree.add(7);

    tree.add(3);

    tree.add(20);

    tree.add(40);

    tree.add(1);

    tree.add(4);

    tree.remove(5);

    tree.add(35);

    tree.add(50);

    tree.remove(40);

    std::cout << tree.getSize();

    return 0;
}
