/**
 * @file FileManager.cpp
 * @brief Implementacja metod klasy FileManager.
 */

#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::serialize(Node* node, std::ofstream& out) {
    if (!node) {
        int marker = -999999;
        out.write(reinterpret_cast<char*>(&marker), sizeof(marker));
        return;
    }
    out.write(reinterpret_cast<char*>(&node->data), sizeof(node->data));
    serialize(node->left, out);
    serialize(node->right, out);
}

void FileManager::saveBinary(BST& tree, const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    if (out.is_open()) {
        serialize(tree.getRoot(), out);
        out.close();
        std::cout << "Zapisano binarnie.\n";
    }
}

void FileManager::deserialize(BST& tree, std::ifstream& in) {
    int val;
    if (in.read(reinterpret_cast<char*>(&val), sizeof(val))) {
        if (val == -999999) return;
        tree.insert(val);
        deserialize(tree, in);
        deserialize(tree, in);
    }
}

void FileManager::loadBinary(BST& tree, const std::string& filename) {
    tree.clear(); // Czyści aktualne drzewo przed wczytaniem binarnego
    std::ifstream in(filename, std::ios::binary);
    if (in.is_open()) {
        deserialize(tree, in);
        in.close();
        std::cout << "Wczytano z pliku binarnego.\n";
    }
}

void FileManager::loadFromText(BST& tree, const std::string& filename) {
    std::ifstream in(filename);
    int val;
    if (in.is_open()) {
        while (in >> val) {
            tree.insert(val);
        }
        in.close();
        std::cout << "Wczytano liczby z pliku tekstowego.\n";
    }
    else {
        std::cout << "Blad otwarcia pliku tekstowego.\n";
    }
}