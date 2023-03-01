#include "headers.h"

template<typename type>
struct Node {
    Node() = default; //Конструктор без параметров

    Node(type value); //Конструктор с параметрами

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

    int64_t getSize() const; //Возваращает текущее кол-во объектов

private:
    Node<type> const *root = nullptr;
    Node<type> *ptr = nullptr;
    int64_t size = NULL;
};

template<typename type>
Node<type>::Node(type value) : value(value) {}

template<typename type>
BinaryTree<type>::BinaryTree() {
    try {
        *root = new Node<type>();
        ptr = root;
    } catch (...) {
        std::cout << "\nConstruct BinaryTree threw except\n";
    }
};

template<typename type>
BinaryTree<type>::BinaryTree(type value) {
    try {
        this->root = new Node<type>(value);
        ptr = const_cast<Node<type>*>(root);
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
                    ptr = const_cast<Node<type>*>(root);
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
                    ptr = const_cast<Node<type>*>(root);
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
    do {
        if (value < ptr->value) {
            try {
                if ((ptr->left == nullptr)) {
                    return false;
                }
                else if (value == ptr->value) {
                    delete ptr;
                    ptr = root;
                    --size;
                }
                else {
                    ptr = ptr->left;
                }
            } catch (...) {
                std::cout << "\nMethod 'remove' threw except\n";
                return false;
            }
        }
        else if (value >= ptr->value) {
            try {
                if ((ptr->left == nullptr)) {
                    return false;
                }
                else if (value == ptr->value) {
                    delete ptr;
                    ptr = root;
                    --size;
                }
                else {
                    ptr = ptr->right;
                }
            } catch (...) {
                std::cout << "\nMethod 'remove' threw except\n";
                return false;
            }
        }
    } while (ptr != root);

    return true;
}

template<typename type>
int64_t BinaryTree<type>::getSize() const {
    return size;
}