#include "headers.h"

template<typename type>
struct Node {
    Node() = default; //Конструктор без параметров

    Node(type value); //Конструктор с параметрами

    bool isNull(); //Пусты ли указатели узла

    bool isRightNull(); //Пуст ли правый указатель

    bool isLeftNull(); //Пуст ли левый указатель

    ~Node() = default; //Деструктор

    type value = NULL; //Значение
    Node<type> *left = nullptr; //Указатель на левый узел
    Node<type> *right = nullptr; //Указатель на правый узел
};

template<typename type>
class BinaryTree {
public:
    BinaryTree(); //Конструктор без параметров

    BinaryTree(type value); //Конструктор с параметрами

    ~BinaryTree(); //Деструктор

    bool add(type value); //Добавление элемента

    bool remove(type value); //Удаление элемента

    bool find(type value); //Поиск элемента в бинарном дереве поиска

    void traversingNRL(); //Обход КПЛ

    void traversingLNR(); //Обход ЛКП

    int64_t getSize() const; //Возваращает текущее кол-во объектов

private:
    Node<type> *root = nullptr;
    Node<type> *ptr = nullptr;
    int64_t size = NULL;
};

template<typename type>
Node<type>::Node(type value) : value(value) {}

template<typename type>
bool Node<type>::isNull() {
    if ((right == nullptr) && (left == nullptr)) {
        return true;
    }
    else {
        return false;
    }
}

template<typename type>
bool Node<type>::isLeftNull() {
    if (left == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename type>
bool Node<type>::isRightNull() {
    if (right == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename type>
BinaryTree<type>::BinaryTree() {
    try {
        *root = new Node<type>();
        ptr = root;
    } catch (...) {
        std::cout << "\nConstruct BinaryTree threw except\n";
    }
}

template<typename type>
BinaryTree<type>::BinaryTree(type value) {
    try {
        this->root = new Node<type>(value);
        ptr = root;
        ++size;
    } catch (...) {
        std::cout << "\nConstruct BinaryTree threw except\n";
    }
}

template<typename type>
BinaryTree<type>::~BinaryTree() {

}

template<typename type>
bool BinaryTree<type>::add(type value) {
    try {
        while (true) {
            if (ptr->value > value) {
                if ((ptr->left == nullptr)) {
                    ptr->left = new Node<type>(value);
                    ptr = root;
                    ++size;
                    return true;
                }
                else {
                    ptr = ptr->left;
                }
            }
            else if (ptr->value < value) {
                if (ptr->right == nullptr) {
                    ptr->right = new Node<type>(value);
                    ptr = root;
                    ++size;
                    return true;
                }
                else {
                    ptr = ptr->right;
                }
            }
            else if (ptr->value == value) {
                return false;
            }
        }
    } catch (...) {
        ptr = const_cast<Node<type>*>(root);
        std::cout << "\nMethod 'add' threw except\n";
        return false;
    }
}

template<typename type>
bool BinaryTree<type>::remove(type value) {
    try {
        while (true) {
            if (ptr->value == value) {
                if ((ptr == root) && (ptr->isNull())) {
                    ptr->value = NULL;
                }
                else if ((ptr->isLeftNull()) || (ptr->isLeftNull())) {
                    auto new_ptr = ptr;

                    if (!ptr->isLeftNull()) {
                        root = ptr->left;
                        delete new_ptr;
                        --size;
                        ptr = root;
                        return true;
                    }
                    else if (!ptr->isRightNull()) {
                        root = ptr->right;
                        delete new_ptr;
                        --size;
                        ptr = root;
                        return true;
                    }
                }
                else if (!ptr->isLeftNull() && !ptr->isRightNull()) {
                    if (!ptr->right->isLeftNull()) {
                        type new_value = NULL;
                        auto *new_ptr = ptr->right->left;
                        auto *old_ptr = ptr->right;

                        while (true) {
                            if (new_ptr != nullptr) {
                                new_value = new_ptr->value;
                                delete old_ptr->left;
                                old_ptr->left = nullptr;
                                ptr->right->value = new_value;
                                --size;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->left;
                                old_ptr = old_ptr->left;
                            }
                        }
                    }
                    else if (!ptr->left->isRightNull()) {
                        type new_value = NULL;
                        auto *new_ptr = ptr->left->right;
                        auto *old_ptr = ptr->left;

                        while (true) {
                            if (new_ptr != nullptr) {
                                new_value = new_ptr->value;
                                delete old_ptr->left;
                                old_ptr->left = nullptr;
                                ptr->left->value = new_value;
                                --size;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->right;
                                old_ptr = old_ptr->right;
                            }
                        }
                    }
                }
            }
            else if (ptr->value > value) {
                if (ptr->left == nullptr) {
                    ptr = root;
                    return false;
                }
                else if (ptr->left->value == value) {
                    if (ptr->left->isNull()) {
                        delete ptr->left;
                        ptr->left = nullptr;
                        --size;
                        ptr = root;
                        return true;
                    }
                    else if ((ptr->left->isLeftNull()) || (ptr->left->isLeftNull())) {
                        auto *new_ptr = ptr->left;

                        if (!ptr->left->isLeftNull()) {
                            ptr->left = ptr->left->left;
                            delete new_ptr;
                            --size;
                            ptr = root;
                            return true;
                        }
                        else if (!ptr->left->isRightNull()) {
                            ptr->left = ptr->left->right;
                            delete new_ptr;
                            --size;
                            ptr = root;
                            return true;
                        }
                    }
                    else if (!ptr->left->isLeftNull() && !ptr->left->isRightNull()) {
                        type new_value = NULL;
                        auto *new_ptr = ptr->left->right->right;
                        auto *old_ptr = ptr->left->right;

                        while (true) {
                            if (new_ptr == nullptr) {
                                new_value = old_ptr->value;
                                delete old_ptr;
                                old_ptr = nullptr;
                                ptr->left->value = new_value;
                                --size;
                                ptr = root;
                                return true;
                            }
                            else if (new_ptr->isRightNull()) {
                                new_value = old_ptr->value;
                                delete old_ptr->right;
                                old_ptr->right = nullptr;
                                ptr->left->value = new_value;
                                --size;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->right;
                                old_ptr = old_ptr->right;
                            }
                        }
                    }
                }
                else {
                    ptr = ptr->left;
                }
            }
            else if (ptr->value < value) {
                if (ptr->right == nullptr) {
                    ptr = root;
                    return false;
                }
                else if (ptr->right->value == value) {
                    if (ptr->right->isNull()) {
                        delete ptr->right;
                        ptr->right = nullptr;
                        --size;
                        ptr = root;
                        return true;
                    }
                    else if ((ptr->right->isLeftNull()) || (ptr->right->isLeftNull())) {
                        auto *new_ptr = ptr->left;

                        if (!ptr->right->isRightNull()) {
                            ptr->right = ptr->right->right;
                            delete new_ptr;
                            --size;
                            ptr = root;
                            return true;
                        }
                        else if (!ptr->right->isLeftNull()) {
                            ptr->right = ptr->right->left;
                            delete new_ptr;
                            --size;
                            ptr = root;
                            return true;
                        }
                    }
                    else if (!ptr->right->isLeftNull() && !ptr->right->isRightNull()) {
                        type new_value = NULL;
                        auto *new_ptr = ptr->right->right->left;
                        auto *old_ptr = ptr->right->right;

                        while (true) {
                            if (new_ptr == nullptr) {
                                new_value = old_ptr->value;
                                delete old_ptr;
                                ptr->right->right = nullptr;
                                ptr->right->value = new_value;
                                --size;
                                ptr = root;
                                return true;
                            }
                            else if (new_ptr->isLeftNull()) {
                                new_value = new_ptr->value;
                                delete new_ptr->left;
                                old_ptr->left = nullptr;
                                ptr->right->value = new_value;
                                --size;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->left;
                                old_ptr = old_ptr->left;
                            }
                        }
                    }
                }
                else {
                    ptr = ptr->right;
                }
            }
        }
    } catch (...) {
        ptr = root;
        std::cout << "\nMethod 'remove' threw except\n";
        return false;
    }
}

template<typename type>
bool BinaryTree<type>::find(type value) {
    try {
        while (true) {
            if (ptr->value > value) {
                if (ptr->left == nullptr) {
                    ptr = root;
                    return false;
                }
                else if (ptr->value != value) {
                    ptr = ptr->left;
                }
            }
            else {
                if (ptr->value == value) {
                    ptr = root;
                    return true;
                }
                if (ptr->right == nullptr) {
                    ptr = root;
                    return false;
                }
                else if (ptr->value != value) {
                    ptr = ptr->right;
                }
            }
        }
    } catch (...) {
        ptr = const_cast<Node<type>*>(root);
        std::cout << "\nMethod 'find' threw except\n";
        return false;
    }
}

template<typename type>
void BinaryTree<type>::traversingNRL() {
    Node<type> *ptr_node = const_cast<Node<type>*>(root);

    while (true) {
        if (ptr_node->right != nullptr) {
            ptr_node = ptr_node->right;
            if (ptr_node->left != nullptr) {
                ptr_node = ptr_node->left;
            }
        }
        else if (ptr_node->left != nullptr) {
            if (ptr_node->right != nullptr) {
                ptr_node = ptr_node->right;
                if (ptr_node->left != nullptr) {
                    ptr_node = ptr_node->left;
                }
            }
        }
        if ((ptr_node->right != nullptr) && (ptr_node->left != nullptr)) {

        }
    }
}

template<typename type>
void BinaryTree<type>::traversingLNR() {

}

template<typename type>
int64_t BinaryTree<type>::getSize() const {
    return size;
}