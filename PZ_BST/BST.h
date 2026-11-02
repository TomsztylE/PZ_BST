/**
 * @file BST.h
 * @brief Interfejs klasy reprezentującej drzewo poszukiwań binarnych (BST).
 */

#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <vector>

/**
 * @class BST
 * @brief Strukrura danych Binary Search Tree (BST) z zestawem podstawowych operacji.
 *
 * Umożliwia wstawianie, usuwanie i wyszukiwanie elementów, wyznaczanie ścieżki
 * oraz przechodzenie przez drzewo (porządki preorder, inorder, postorder).
 */
class BST {
private:
    Node* root; /**< Wskaźnik na korzeń (węzeł główny). */

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego umieszczania klucza w drzewie.
     * @param node Aktualnie rozpatrywany węzeł.
     * @param data Wartość wstawiana.
     * @return Zaktualizowany wskaźnik na poddrzewo.
     */
    Node* insert(Node* node, int data);

    /**
     * @brief Pomocnicza funkcja do rekurencyjnego usuwania klucza.
     * @param node Aktualny korzeń poddrzewa.
     * @param data Wartość przeznaczona do skasowania.
     * @return Wskaźnik na modyfikowane poddrzewo.
     */
    Node* remove(Node* node, int data);

    /**
     * @brief Wyszukuje węzeł o minimalnym kluczu w danym poddrzewie.
     * @param node Korzeń poddrzewa do przeszukania.
     * @return Wskaźnik na węzeł z najmniejszą wartością.
     */
    Node* findMin(Node* node);

    /**
     * @brief Rekurencyjnie destruuje węzły i czyści pamięć poddrzewa.
     * @param node Węzeł startowy czyszczenia.
     */
    void clear(Node* node);

    /**
     * @brief Rekurencyjne budowanie ścieżki do poszukiwanej wartości.
     * @param node Aktualny węzeł.
     * @param data Szukany klucz.
     * @param path Wektor, do którego dopisywane są kolejne węzły na ścieżce.
     * @return true jeśli element został odnaleziony, false w przeciwnym razie.
     */
    bool findPath(Node* node, int data, std::vector<int>& path);

    void printPreorder(Node* node);  /**< Przechodzenie w porządku preorder (NLR). */
    void printInorder(Node* node);   /**< Przechodzenie w porządku inorder (LNR). */
    void printPostorder(Node* node); /**< Przechodzenie w porządku postorder (LRN). */
    void saveToText(Node* node, std::ofstream& file); /**< Zapis struktur poddrzewa do strumienia plikowego. */

public:
    /**
     * @brief Tworzy puste drzewo BST (root = nullptr).
     */
    BST();

    /**
     * @brief Destruktor. Zwalnia dynamicznie alokowaną pamięć wszystkich węzłów.
     */
    ~BST();

    /**
     * @brief Wstawia nowy element do struktury drzewa.
     * @param data Wartość do dodania.
     */
    void insert(int data);

    /**
     * @brief Usuwa element o podanym kluczu z drzewa.
     */
    void remove(int data);

    /**
     * @brief Czyszczenie całego drzewa i zwalnianie pamięci.
     */
    void clear();

    /**
     * @brief Wyznacza ścieżkę od korzenia do zadanej wartości i drukuje ją na wyjściu.
     * @param data Poszukiwana wartość.
     */
    void findPath(int data);

    /**
     * @brief Wypisuje zawartość drzewa określonym trybem przejścia.
     * @param method Kod metody: 1 (Preorder), 2 (Inorder), 3 (Postorder).
     */
    void display(int method);

    /**
     * @brief Eksportuje strukturę drzewa do pliku tekstowego.
     * @param filename Ścieżka/nazwa pliku docelowego.
     */
    void saveToText(const std::string& filename);

    /** @brief Pobiera wskaźnik na korzeń drzewa (np. dla modułów FileManager). */
    Node* getRoot() const { return root; }

    /** @brief Podmienia wskaźnik korzenia (przydatne przy odczycie z pliku). */
    void setRoot(Node* newRoot) { root = newRoot; }
};