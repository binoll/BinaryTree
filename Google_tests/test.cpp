#include "lib/googletest/include/gtest/gtest.h"
#include "../headers.h"
#include "../binary_tree.h"

int rd1 = 20, rd3 = 800, rd4 = 20, rd5 = 100;
int ru1 = 2, ru3 = 80, ru4 = 5, ru5 = 10;
int h1 = 5, h3 = 10, h4 = 5, h5 = 40;
Cone cone1(rd1, ru1, h1);
Cone cone3(rd3, ru3, h3);
Cone cone4(rd4, ru4, h4);
Cone cone5(rd5, ru5, h5);
BinaryTree<Cone> tree_cone(cone1);
BinaryTree<int> tree(10);


TEST(TestBinaryTree, TestAdd) {
    ASSERT_TRUE(tree.add(7));
    ASSERT_TRUE(tree.add(21));
    ASSERT_TRUE(tree.add(4));
    ASSERT_TRUE(tree.add(9));
    ASSERT_TRUE(tree.add(15));
    ASSERT_TRUE(tree.add(12));
    ASSERT_TRUE(tree.add(17));
    ASSERT_TRUE(tree.add(11));
    ASSERT_FALSE(tree.add(12));
};

TEST(TestBinaryTree, TestRemove) {
    ASSERT_TRUE(tree.remove(12));
    ASSERT_FALSE(tree.remove(12));
    ASSERT_TRUE(tree.remove(17));
};

TEST(TestBinaryTree, TestFind) {
    ASSERT_TRUE(tree.find(15));
};

TEST(TestBinaryTree, TestClear) {
    tree.clear();
    ASSERT_EQ(1, tree.getSize());
};

TEST(TestCone, TestAdd) {
    ASSERT_TRUE(tree_cone.add(cone3));
    ASSERT_TRUE(tree_cone.add(cone4));
    ASSERT_TRUE(tree_cone.add(cone5));
};

TEST(TestCone, TestRemove) {
    ASSERT_TRUE(tree_cone.remove(cone3));
};

TEST(TestCone, TestFind) {
    ASSERT_TRUE(tree_cone.find(cone4));
};