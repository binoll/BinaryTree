#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.remove(10);

    std::cout << tree.getSize();
    std::cout << '\n' << tree.find(50) << '\n' << tree.find(40) << '\n' << tree.find(35);

    tree.traversingNRL();

    return 0;
}
