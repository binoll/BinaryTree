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
                    ++size;
                    ptr = const_cast<Node<type> *>(root);
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
    while (true) {
        if (ptr->value > value) {
            try {
                if (ptr->left == nullptr) {
                    ptr = const_cast<Node<type> *>(root);
                    return false;
                }
                else if (ptr->left->value == value) {
                    if ((ptr->left->left == nullptr) && (ptr->left->right == nullptr)) {
                        delete ptr->left;
                        ptr->left = nullptr;
                        --size;
                        return true;
                    }
                    else if ((ptr->left->left == nullptr) || (ptr->left->right == nullptr)) {
                        Node<type> *new_ptr = ptr->left;

                        if (ptr->left->left != nullptr) {
                            ptr->left = ptr->left->left;
                            delete new_ptr;
                            --size;
                            return true;
                        }
                        else if (ptr->left->right != nullptr) {
                            ptr->left = ptr->left->right;
                            delete new_ptr;
                            --size;
                            return true;
                        }
                    }
                    else if ((ptr->left->left != nullptr) && (ptr->left->right != nullptr)) {
                        type new_value = NULL;
                        Node<type> *new_ptr = ptr->left;

                        while (true) {
                            if (new_ptr->right->right == nullptr) {
                                new_value = new_ptr->right->value;
                                delete new_ptr->right;
                                ptr->left->right = nullptr;
                                ptr->left->value = new_value;
                                --size;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->right;
                            }
                        }
                    }
                }
                else {
                    ptr = ptr->left;
                }
            } catch (...) {
                std::cout << "\nMethod 'remove' threw except\n";
                return false;
            }
        }
        else {
            try {
                if (ptr->right == nullptr) {
                    ptr = const_cast<Node<type> *>(root);
                    return false;
                }
                else if (ptr->value == value) {
                    type new_value = NULL;
                    Node<type> *new_ptr = ptr->right;

                    while (true) {
                        if (new_ptr->left->left == nullptr) {
                            new_value = new_ptr->left->value;
                            delete new_ptr->left;
                            new_ptr->left = nullptr;
                            ptr->value = new_value;
                            --size;
                            return true;
                        }
                        else {
                            new_ptr = new_ptr->left;
                        }
                    }
                }
                else if (ptr->right->value == value) {
                    if ((ptr->right->left == nullptr) && (ptr->right->right == nullptr)) {
                        delete ptr->right;
                        ptr->right = nullptr;
                        --size;
                        return true;
                    }
                    else if ((ptr->right->left == nullptr) || (ptr->right->right == nullptr)) {
                        Node<type> *new_ptr = ptr->right;

                        if (ptr->right->left != nullptr) {
                            ptr->right = ptr->right->left;
                            delete new_ptr;
                            --size;
                            return true;
                        }
                        else if (ptr->right->right != nullptr) {
                            ptr->right = ptr->right->right;
                            delete new_ptr;
                            --size;
                            return true;
                        }
                    }
                    else if ((ptr->right->left != nullptr) && (ptr->right->right != nullptr)) {
                        type new_value = NULL;
                        Node<type> *new_ptr = ptr->right;

                        while (true) {
                            if (new_ptr->left->left == nullptr) {
                                new_value = new_ptr->left->value;
                                delete new_ptr->left;
                                ptr->right->left = nullptr;
                                ptr->right->value = new_value;
                                --size;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->left;
                            }
                        }
                    }
                }
                else {
                    ptr = ptr->right;
                }
            } catch (...) {
                std::cout << "\nMethod 'remove' threw except\n";
                return false;
            }
        }
    }
}

template<typename type>
bool BinaryTree<type>::find(type value) {
    Node<type> *new_ptr = ptr;

    while (true) {
        if (new_ptr->value < value) {
            if (new_ptr->value == value) {
                return true;
            }
            else if (new_ptr->right == nullptr) {
                return false;
            }
            else if (new_ptr->value != value) {
                new_ptr = new_ptr->right;
            }
        }
        else {
            if (new_ptr->value == value) {
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