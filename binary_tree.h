#include "headers.h"
#include "Cone.h"

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

    bool traversingNRL(); //Обход КПЛ

    bool traversingLNR(); //Обход ЛКП

    bool isClear(); //Проверка пустоты

    bool clear(); //Очищение дерева

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
    if (root != nullptr) {
        clear();
    }
}

template<typename type>
bool BinaryTree<type>::add(type value) {
    try {
        if (!find(value)) {
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
            }
        }
        else {
            return false;
        }
    } catch (...) {
        ptr = root;
        std::cout << "\nMethod 'add' threw except\n";
        return false;
    }
}

template<typename type>
bool BinaryTree<type>::remove(type value) {
    try {
        while (true) {
            if (ptr->value == value) {
                if (ptr->isNull()) {
                    delete ptr;
                    ptr = nullptr;
                    root = nullptr;
                    --size;
                    return true;
                }
                if (!ptr->isLeftNull() && !ptr->isRightNull()) {
                    type new_value;

                    if (!ptr->left->isNull()) {
                        auto *new_ptr = ptr->left->right;
                        auto *old_ptr = ptr->left;

                        while (true) {
                            if (new_ptr == nullptr) {
                                new_value = old_ptr->value;
                                remove(new_value);
                                ptr->value = new_value;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->right;
                                old_ptr = old_ptr->right;
                            }
                        }
                    }
                    else if (ptr->left->isNull()) {
                        new_value = ptr->left->value;
                        remove(new_value);
                        ptr->value = new_value;
                    }
                    else if (!ptr->right->isNull()) {
                        auto *new_ptr = ptr->right->left;
                        auto *old_ptr = ptr->right;

                        while (true) {
                            if (new_ptr == nullptr) {
                                new_value = old_ptr->value;
                                remove(new_value);
                                ptr->value = new_value;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->left;
                                old_ptr = old_ptr->left;
                            }
                        }
                    }
                    else if (ptr->right->isNull()) {
                        new_value = ptr->right->value;
                        remove(new_value);
                        ptr->value = new_value;
                    }
                }
                else if (ptr->isLeftNull() || ptr->isRightNull()) {
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
                    else if (!ptr->left->isLeftNull() && !ptr->left->isRightNull()) {
                        type new_value;
                        auto this_ptr = ptr->left;
                        auto new_ptr = ptr->left->left->right;
                        auto old_ptr = ptr->left->left;

                        while (true) {
                            if (new_ptr == nullptr) {
                                new_value = old_ptr->value;
                                remove(new_value);
                                this_ptr->value = new_value;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->right;
                                old_ptr = old_ptr->right;
                            }
                        }
                    }
                    else if ((ptr->left->isLeftNull()) || (ptr->left->isRightNull())) {
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
                    else if (!ptr->right->isLeftNull() && !ptr->right->isRightNull()) {
                        type new_value;
                        auto this_ptr = ptr->right;
                        auto new_ptr = ptr->right->right->left;
                        auto old_ptr = ptr->right->right;

                        while (true) {
                            if (new_ptr == nullptr) {
                                new_value = old_ptr->value;
                                remove(new_value);
                                this_ptr->value = new_value;
                                ptr = root;
                                return true;
                            }
                            else {
                                new_ptr = new_ptr->left;
                                old_ptr = old_ptr->left;
                            }
                        }
                    }
                    else if ((ptr->right->isRightNull()) || (ptr->right->isLeftNull())) {
                        auto *new_ptr = ptr->right;

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
        ptr = root;
        std::cout << "\nMethod 'find' threw except\n";
        return false;
    }
}

template<typename type>
bool BinaryTree<type>::traversingNRL() {
    if (ptr == root) {
        std::cout << ptr->value << ' ';

        do {
            if ((!ptr->isRightNull()) && (ptr != nullptr)) {
                ptr = ptr->right;
                std::cout << ptr->value << ' ';
                if (traversingNRL()) {
                    ptr = root;
                }
            }
            else {
                ptr = root;
            }
        } while (ptr != root);
        do {
            if ((!ptr->isLeftNull()) && (ptr != nullptr)) {
                ptr = ptr->left;
                std::cout << ptr->value << ' ';
                if (traversingNRL()) {
                    ptr = root;
                }
            }
            else {
                ptr = root;
            }
        } while (ptr != root);
    }
    else {
        if (!ptr->isRightNull() && !ptr->isLeftNull()) {
            auto ptr_right = ptr->right;
            auto ptr_left = ptr->left;

            ptr = ptr_right;
            std::cout << ptr->value << ' ';
            traversingNRL();
            ptr = ptr_left;
            std::cout << ptr->value << ' ';
            traversingNRL();
        }
        else if (!ptr->isRightNull()) {
            auto ptr_right = ptr->right;

            ptr = ptr_right;
            std::cout << ptr->value << ' ';
            traversingNRL();
            return true;
        }
        else if (!ptr->isLeftNull()) {
            auto ptr_left = ptr->left;

            ptr = ptr_left;
            std::cout << ptr->value << ' ';
            traversingNRL();
            return true;
        }
        else if (ptr->isNull()) {
            return false;
        }
    }
}

template<typename type>
bool BinaryTree<type>::traversingLNR() {
    if (ptr == root) {
        do {
            if ((!ptr->isLeftNull()) && (ptr != nullptr)) {
                ptr = ptr->left;
                if (traversingLNR()) {
                    ptr = root;
                    std::cout << ptr->value << ' ';
                }
                else {
                    ptr = root;
                }
            }
        } while (ptr != root);

        do {
            if ((!ptr->isRightNull()) && (ptr != nullptr)) {
                ptr = ptr->right;
                if (traversingLNR()) {
                    ptr = root;
                }
                else {
                    ptr = root;
                }
            }
        } while (ptr != root);
    }
    else {
        if (ptr == nullptr) {
            return false;
        }
        if (!ptr->isRightNull() && !ptr->isLeftNull()) {
            auto new_ptr = ptr;

            ptr = new_ptr->left;
            traversingLNR();
            ptr = new_ptr->right;
            std::cout << new_ptr->value << ' ';
            traversingLNR();
        }
        else if (!ptr->isLeftNull() && ptr->isRightNull()) {
            auto new_ptr = ptr;
            auto ptr_left = ptr->left;

            ptr = ptr_left;
            traversingLNR();
            std::cout << new_ptr->value << ' ';
            return true;
        }
        else if (!ptr->isRightNull() && ptr->isLeftNull()) {
            auto ptr_right = ptr->right;

            std::cout << ptr->value << ' ';
            ptr = ptr_right;
            traversingLNR();
            return true;
        }
        else if (ptr->isNull()) {
            std::cout << ptr->value << ' ';
            return true;
        }
    }
}

template<typename type>
bool BinaryTree<type>::isClear() {
    if (root == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

template<typename type>
bool BinaryTree<type>::clear() {
    if (root != nullptr) {
        do {
            remove(root->value);
        } while (root != nullptr);
    }
    else {
        return false;
    }
}

template<typename type>
int64_t BinaryTree<type>::getSize() const {
    return size;
}

template<typename type>
std::ostream& operator<<(std::ostream& stream, BinaryTree<type> &tree) {
    tree.traversingNRL();
    return stream;
}