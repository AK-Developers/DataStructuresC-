#include <iostream>
using namespace std;
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else {
        root->right = insert(root->right, value);
    }
    return root;
}

TreeNode* findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        std::cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;

    int choice, temp;
    do {
        cout << "\n1. Insert Node\n2. Delete Node\n3. Traverse Tree(In-Order)\nEnter Your Choice:";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the Value :";
            cin >> temp;
            root = insert(root, temp);
            break;
        case 2:
            cout << "Enter the Value to be deleted :";
            cin >> temp;
            root = deleteNode(root, temp);
            break;
        case 3:inOrderTraversal(root);
            break;
        default:cout << "Enter a Valid Choice";
            break;
        }
    } while (choice != -10);

    return 0;
}
