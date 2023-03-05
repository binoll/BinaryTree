#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(30);

    tree.add(35);

    tree.add(34);

    tree.add(40);

    if (tree.remove(40)) {
        std::cout << "LOX";
    }

    std::cout << tree.getSize();
    std::cout << '\n' << tree.find(50) << '\n' << tree.find(40) << '\n' << tree.find(15);



    return 0;
}
