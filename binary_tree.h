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
    Node<type> const *root = nullptr;
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
        ptr = const_cast<Node<type> *>(root);
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
    do {
        if (value < ptr->value) {
            try {
                if ((ptr->left == nullptr)) {
                    ptr->left = new Node<type>(value);
                    ptr = const_cast<Node<type> *>(root);
                    ++size;
                }
                else {
                    ptr = ptr->left;
                }
            } catch (...) {
                std::cout << "\nMethod 'add' threw except\n";
                return false;
            }
        }
        else if (value >= ptr->value) {
            try {
                if (ptr->right == nullptr) {
                    ptr->right = new Node<type>(value);
                    ptr = const_cast<Node<type> *>(root);
                    ++size;
                }
                else {
                    ptr = ptr->right;
                }
            } catch (...) {
                std::cout << "\nMethod 'add' threw except\n";
                return false;
            }
        }
    } while (ptr != root);

    return true;
}

template<typename type>
bool BinaryTree<type>::remove(type value) {
    if (ptr->value > value) {
        try {
            if (ptr->isLeftNull()) {
                if (ptr->value == value) {
                    if (ptr == root) {
                        ptr->value = NULL;
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
            if ((ptr->left->value == value) || (ptr->value == value)) {
                if (ptr->left->isNull()) {
                    delete ptr->left;
                    ptr->left = nullptr;
                    --size;
                    return true;
                }
                else if (ptr->left->isLeftNull() || ptr->left->isRightNull()) {
                    if (!ptr->left->isLeftNull()) {
                        auto new_ptr = ptr->left;
                        ptr->left = ptr->left->left;
                        delete new_ptr;
                        --size;
                        return true;
                    }
                    else if (!ptr->right->isRightNull()) {
                        auto new_ptr = ptr->right;
                        ptr->right = ptr->right->right;
                        delete new_ptr;
                        --size;
                        return true;
                    }
                }
                else if (!ptr->left->isNull()) {
                    type new_value = NULL;
                    auto old_ptr = ptr->left;
                    auto new_ptr = ptr->left->right;
                    ptr = ptr->left;

                    while (true) {
                        if (new_ptr->isRightNull()) {
                            new_value = new_ptr->value;
                            delete new_ptr;
                            ptr->right = nullptr;
                            old_ptr->value = new_value;
                            --size;
                            ptr = const_cast<Node<type> *>(root);
                            return true;
                        }
                        else {
                            ptr = ptr->right;
                            new_ptr = new_ptr->right;
                        }
                    }
                }
            }
            else if (ptr->left->value != value) {
                ptr = ptr->left;
                remove(value);
            }
        } catch (...) {
            std::cout << "\nMethod 'remove' threw except\n";
            return false;
        }
    }
    else {
        try {
            if (ptr->value == value) {
                if (ptr->isNull()) {
                    if (ptr == root) {
                        ptr->value = NULL;
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else if (ptr->isLeftNull() || ptr->isRightNull()) {
                    if (!ptr->isLeftNull()) {
                        ptr->value = ptr->left->value;
                        delete ptr->left;
                        ptr->left = nullptr;
                        --size;
                        return true;
                    }
                    else if (!ptr->isRightNull()) {
                        ptr->value = ptr->right->value;
                        delete ptr->right;
                        ptr->right = nullptr;
                        --size;
                        return true;
                    }
                }
                else if (!ptr->isNull()) {
                    ptr = ptr->right;
                    remove(value);
                }
            }
            else if (ptr->right->value == value) {
                if (ptr->right->isNull()) {
                    delete ptr->right;
                    ptr->right = nullptr;
                    --size;
                    return true;
                }
                else if (ptr->right->isLeftNull() || ptr->right->isRightNull()) {
                    if (!ptr->left->isLeftNull()) {
                        auto new_ptr = ptr->left;
                        ptr->left = ptr->left->left;
                        delete new_ptr;
                        --size;
                        return true;
                    }
                    else if (!ptr->right->isRightNull()) {
                        auto new_ptr = ptr->right;
                        ptr->right = ptr->right->right;
                        delete new_ptr;
                        --size;
                        return true;
                    }
                }
                else if (!ptr->right->isNull()) {
                    type new_value = NULL;
                    auto old_ptr = ptr->right;
                    auto new_ptr = ptr->right->left;
                    ptr = ptr->right;

                    while (true) {
                        if (new_ptr == nullptr) {
                            new_value = new_ptr->value;
                            delete new_ptr;
                            ptr->left = nullptr;
                            old_ptr->value = new_value;
                            --size;
                            ptr = const_cast<Node<type> *>(root);
                            return true;
                        }
                        else {
                            ptr = ptr->left;
                            new_ptr = new_ptr->left;
                        }
                    }
                }
            }
            else if (ptr->right->value != value) {
                ptr = ptr->right;
                remove(value);
            }
        } catch (...) {
            std::cout << "\nMethod 'remove' threw except\n";
            return false;
        }
    }
}


template<typename type>
bool BinaryTree<type>::find(type value) {
    Node<type> *new_ptr = ptr;

    while (true) {
        if (new_ptr->value < value) {
            if (new_ptr->right == nullptr) {
                return false;
            }
            else if (new_ptr->value != value) {
                new_ptr = new_ptr->right;
            }
        }
        else {
            if (new_ptr->value == value) {
                ptr = new_ptr;
                return true;
            }
            else if (new_ptr->left == nullptr) {
                return false;
            }
            else if (new_ptr->value != value) {
                new_ptr = new_ptr->left;
            }
        }
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