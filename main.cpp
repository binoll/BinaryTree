#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(30);

    tree.add(5);

    tree.add(20);

    tree.add(40);


    std::cout << tree.getSize();

    return 0;
}
