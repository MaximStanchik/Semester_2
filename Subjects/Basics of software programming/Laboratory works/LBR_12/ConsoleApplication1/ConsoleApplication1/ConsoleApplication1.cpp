#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int key;
    string data;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int key, string data);
    TreeNode* search(int key);
    void inorderTraversal();
    void mixedTraversal();
    void descendingTraversal();
    int countBranchesAtLevel(int level);
    void printBranchesAtLevel(int level);
    bool isBalanced();

private:
    void insert(TreeNode*& node, int key, string data);
    void destroy(TreeNode*& node);
    TreeNode* search(TreeNode* node, int key);
    void inorderTraversal(TreeNode* node);
    void mixedTraversal(TreeNode* node);
    void descendingTraversal(TreeNode* node);
    int countBranchesAtLevel(TreeNode* node, int level);
    void printBranchesAtLevel(TreeNode* node, int level, int& count);
    int getHeight(TreeNode* node);
    bool isBalanced(TreeNode* node);
    TreeNode* root;
};

void BinaryTree::mixedTraversal() {
    mixedTraversal(root);
}

void BinaryTree::mixedTraversal(TreeNode* node) {
    if (node != nullptr) {
        cout << "Ключ: " << node->key << ", Строка: " << node->data << endl;
        mixedTraversal(node->right);
        mixedTraversal(node->left);
    }
}

void BinaryTree::descendingTraversal() {
    descendingTraversal(root);
}

void BinaryTree::descendingTraversal(TreeNode* node) {
    if (node != nullptr) {
        descendingTraversal(node->right);
        cout << "Ключ: " << node->key << ", Строка: " << node->data << endl;
        descendingTraversal(node->left);
    }
}

bool BinaryTree::isBalanced() {
    return isBalanced(root);
}

bool BinaryTree::isBalanced(TreeNode* node) {
    if (node == nullptr) {
        return true;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right)) {
        return true;
    }

    return false;
}

int BinaryTree::getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return max(leftHeight, rightHeight) + 1;
}


BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    destroy(root);
}

void BinaryTree::destroy(TreeNode*& node) {
    if (node != nullptr) {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = nullptr;
    }
}

void BinaryTree::insert(int key, string data) {
    insert(root, key, data);
}

void BinaryTree::insert(TreeNode*& node, int key, string data) {
    if (node == nullptr) {
        node = new TreeNode{ key, data, nullptr, nullptr };
    }
    else if (key < node->key) {
        insert(node->left, key, data);
    }
    else if (key > node->key) {
        insert(node->right, key, data);
    }
    else {
        node->data = data;
    }
}

TreeNode* BinaryTree::search(int key) {
    return search(root, key);
}

TreeNode* BinaryTree::search(TreeNode* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    else if (key < node->key) {
        return search(node->left, key);
    }
    else {
        return search(node->right, key);
    }
}

void BinaryTree::inorderTraversal() {
    inorderTraversal(root);
}

void BinaryTree::inorderTraversal(TreeNode* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        cout << "Ключ: " << node->key << ", Строка: " << node->data << endl;
        inorderTraversal(node->right);
    }
}

int BinaryTree::countBranchesAtLevel(int level) {
    return countBranchesAtLevel(root, level);
}

int BinaryTree::countBranchesAtLevel(TreeNode* node, int level) {
    if (node == nullptr) {
        return 0;
    }
    else if (level == 1) {
        return (node->left != nullptr) + (node->right != nullptr);
    }
    else {
        return countBranchesAtLevel(node->left, level - 1) + countBranchesAtLevel(node->right, level - 1);
    }
}

void BinaryTree::printBranchesAtLevel(int level) {
    setlocale(LC_ALL, "Russian");
    int count = 0;
    printBranchesAtLevel(root, level, count);
    cout << "Количество веток на уровне " << level << ": " << count << endl;
}

void BinaryTree::printBranchesAtLevel(TreeNode* node, int level, int& count) {
    setlocale(LC_ALL, "Russian");
    if (node == nullptr) {
        return;
    }
    else if (level == 1) {
        if (node->left != nullptr) {
            cout << "Левый дочерний: Ключ: " << node->left->key << ", Строка: " << node->left->data << endl;
            count++;
        }
        if (node->right != nullptr) {
            cout << "Правый дрчерний: Ключ: " << node->right->key << ", Строка: " << node->right->data << endl;
            count++;
        }
    }
    else {
        printBranchesAtLevel(node->left, level - 1, count);
        printBranchesAtLevel(node->right, level - 1, count);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree tree;
    int choice;
    int key;
    int level;
    do {
        cout << "Выберите вариант:" << endl;
        cout << "1. Добавить" << endl;
        cout << "2. Поиск" << endl;
        cout << "3. Вывести в обратном порядке" << endl;
        cout << "4. Посчитать количество веток" << endl;
        cout << "5. Вывести количество веток" << endl;
        cout << "6. Смешанный обход" << endl;
        cout << "7. Нисходящий обход" << endl;
        cout << "8. Проверить сбалансированность" << endl;
        cout << "9. Выход" << endl;

        cin >> choice;

        switch (choice) {
        case 1: {
            int key;
            string data;
            cout << "Введите ключ: ";
            cin >> key;
            cout << "Введите значение: ";
            cin >> data;
            tree.insert(key, data);
            break;
        }
        case 2: {
            cout << "Введите ключ для поиска: ";
            cin >> key;
            if (TreeNode* result = tree.search(key)) {
                cout << "Ключ: " << result->key << ", Значение: " << result->data << endl;
            }
            else {
                cout << "Ключ не найден." << endl;
            }
            break;
        }
        case 3: {
            tree.inorderTraversal();
            break;
        }
        case 4: {
            int level;
            cout << "Введите уровень на котором нужно посчитать количество веток: ";
            cin >> level;
            cout << "lКоличество веток на уровне " << level << ": " << tree.countBranchesAtLevel(level) << endl;
            break;
        }
        case 5: {
            cout << "Введите уровень, с которого нужно вывеси ветки : ";
            cin >> level;
            tree.printBranchesAtLevel(level);
            break;
        }
        case 6: {
            cout << "Смешанный обход:" << endl;
            tree.mixedTraversal();
            break;
        }
        case 7: {
            cout << "Нисходящий обход:" << endl;
            tree.descendingTraversal();
            break;
        }
        case 8: {
            if (tree.isBalanced()) {
                cout << "Дерево сбалансировано." << endl;
            }
            else {
                cout << "Дерево не сбалансировано." << endl;
            }
            break;
        }
        case 9: {
            cout << "До связи" << endl;
            break;}
        default:
            cout << "Неправильно, попробуй ещё раз" << endl;
            break;
        }
    } while (choice != 9);

    return 0;
}