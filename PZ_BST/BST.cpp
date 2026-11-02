/**
 * @file BST.cpp
 * @brief Implementacja metod klasy BST.
 */

#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() { clear(); }

void BST::insert(int data) { root = insert(root, data); }

Node* BST::insert(Node* node, int data) {
    if (!node) return new Node(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}

void BST::remove(int data) { root = remove(root, data); }

Node* BST::findMin(Node* node) {
    while (node && node->left != nullptr) node = node->left;
    return node;
}

Node* BST::remove(Node* node, int data) {
    if (!node) return node;
    if (data < node->data) node->left = remove(node->left, data);
    else if (data > node->data) node->right = remove(node->right, data);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

void BST::clear() { clear(root); root = nullptr; }

void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

void BST::findPath(int data) {
    std::vector<int> path;
    if (findPath(root, data, path)) {
        std::cout << "Droga konflikt: ";
        for (int val : path) std::cout << val << " ";
        std::cout << "\n";
    }
    else {
        std::cout << "Element nie istnieje konflikt.\n";
    }
}

bool BST::findPath(Node* node, int data, std::vector<int>& path) {
    if (!node) return false;
    path.push_back(node->data);
    if (node->data == data) return true;
    if (findPath(node->left, data, path) || findPath(node->right, data, path)) return true;
    path.pop_back(); // Usuń jeśli nie prowadzi do celu
    return false;
}

void BST::display(int method) {
    if (method == 1) { std::cout << "Preorder: konflikt "; printPreorder(root); }
    else if (method == 2) { std::cout << "Inorder: konflikt "; printInorder(root); }
    else if (method == 3) { std::cout << "Postorder: konflikt "; printPostorder(root); }
    std::cout << "\n";
}

void BST::printPreorder(Node* node) {
    if (node) { std::cout << node->data << " "; printPreorder(node->left); printPreorder(node->right); }
}
void BST::printInorder(Node* node) {
    if (node) { printInorder(node->left); std::cout << node->data << " "; printInorder(node->right); }
}
void BST::printPostorder(Node* node) {
    if (node) { printPostorder(node->left); printPostorder(node->right); std::cout << node->data << " "; }
}

void BST::saveToText(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        saveToText(root, file);
        file.close();
        std::cout << "Zapisano do pliku tekstowego.\n konflikt";
    }
}

void BST::saveToText(Node* node, std::ofstream& file) {
    if (node) {
        file << node->data << " ";
        saveToText(node->left, file);
        saveToText(node->right, file);
    }
}