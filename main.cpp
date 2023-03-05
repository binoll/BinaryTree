#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(7);

    tree.add(21);

    tree.add(4);

    tree.add(9);

    tree.add(2);

    tree.add(15);

    tree.add(12);

    tree.add(17);

    tree.add(14);

    if (tree.remove(10)) {
        std::cout << "LOX";
    }

    std::cout << tree.getSize();
    std::cout << '\n' << tree.find(50) << '\n' << tree.find(40) << '\n' << tree.find(15);



    return 0;
}
