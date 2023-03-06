#include "binary_tree.h"

int main() {
    BinaryTree<int> tree(10);

    tree.add(4);
    tree.add(1);
    tree.add(9);
    tree.add(21);
    tree.add(25);
    tree.add(15);
    tree.add(12);
    tree.add(17);
    tree.add(16);
    tree.add(18);
    tree.add(20);

    tree.traversingLNR();
    std::cout << '\n';
    tree.traversingNRL();
    std::cout << '\n';

    int rd1 = 20, rd2 = 50, rd3 = 800, rd4 = 20, rd5 = 100;
    int ru1 = 2, ru2 = 50, ru3 = 80, ru4 = 2, ru5 = 10;
    int h1 = 5, h2 = 11, h3 = 10, h4 = 5, h5 = 40;
    Cone cone1(rd1, ru1, h1);
    Cone cone2(rd2, ru2, h2);
    Cone cone3(rd3, ru3, h3);
    Cone cone4(rd4, ru4, h4);
    Cone cone5(rd5, ru5, h5);

    BinaryTree<Cone> tree_cone(cone1);

    tree_cone.add(cone2);

    tree_cone.add(cone3);

    tree_cone.add(cone4);

    tree_cone.add(cone5);

    std::cout << tree_cone.find(cone1) << '\n';

    std::cout << tree_cone;

    return 0;
}
