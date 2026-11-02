/**
 * @file BST.h
 * @brief Deklaracja klasy BST reprezentującej drzewo poszukiwań binarnych.
 */

#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <vector>

 /**
  * @class BST
  * @brief Klasa implementująca drzewo BST z podstawowymi operacjami.
  *
  * Zapewnia metody do dodawania, usuwania, wyszukiwania drogi oraz
  * wyświetlania drzewa w różnych porządkach.
  */
class BST {
private:
    Node* root; /**< Wskaźnik na korzeń drzewa */

    /**
     * @brief Rekurencyjne dodawanie elementu do drzewa.
     * @param node Aktualny węzeł.
     * @param data Wartość do dodania.
     * @return Zmodyfikowany węzeł (poddrzewo).
     */
    Node* insert(Node* node, int data);

    /**
     * @brief Rekurencyjne usuwanie elementu z drzewa.
     * @param node Aktualny węzeł.
     * @param data Wartość do usunięcia.
     * @return Zmodyfikowany węzeł (poddrzewo).
     */
    Node* remove(Node* node, int data);

    /**
     * @brief Znajduje węzeł z najmniejszą wartością w poddrzewie.
     * @param node Węzeł początkowy.
     * @return Wskaźnik na węzeł z najmniejszą wartością.
     */
    Node* findMin(Node* node);

    /**
     * @brief Rekurencyjne usuwanie wszystkich węzłów (zwalnianie pamięci).
     * @param node Węzeł początkowy do usunięcia.
     */
    void clear(Node* node);

    /**
     * @brief Rekurencyjne szukanie drogi do podanego elementu.
     * @param node Aktualny węzeł.
     * @param data Szukana wartość.
     * @param path Wektor przechowujący odwiedzone węzły (kontener STL).
     * @return True jeśli element znaleziono, False w przeciwnym razie.
     */
    bool findPath(Node* node, int data, std::vector<int>& path);

    void printPreorder(Node* node);  /**< Pomocnicza metoda wypisywania preorder */
    void printInorder(Node* node);   /**< Pomocnicza metoda wypisywania inorder */
    void printPostorder(Node* node); /**< Pomocnicza metoda wypisywania postorder */
    void saveToText(Node* node, std::ofstream& file); /**< Pomocniczy zapis węzłów */

public:
    /**
     * @brief Konstruktor domyślny. Inicjalizuje puste drzewo.
     */
    BST();

    /**
     * @brief Destruktor. Zwalnia całą pamięć zaalokowaną na drzewo.
     */
    ~BST();

    /**
     * @brief Dodaje nowy element do drzewa.
     * @param data Wartość do dodania.
     */
    void insert(int data);

    /**
     * @brief Usuwa wskazany element z drzewa.
     * @param data Wartość do usunięcia.
     */
    void remove(int data);

    /**
     * @brief Usuwa całe drzewo i zwalnia pamięć.
     */
    void clear();

    /**
     * @brief Szuka drogi do elementu i wypisuje ją na ekran.
     * @param data Szukana wartość.
     */
    void findPath(int data);

    /**
     * @brief Wyświetla drzewo graficznie/tekstowo wybraną metodą.
     * @param method 1 - Preorder, 2 - Inorder, 3 - Postorder.
     */
    void display(int method);

    /**
     * @brief Zapisuje aktualne drzewo do pliku tekstowego.
     * @param filename Nazwa pliku wyjściowego.
     */
    void saveToText(const std::string& filename);

    /** @brief Zwraca korzeń drzewa (używane przez FileManager). */
    Node* getRoot() const { return root; }

    /** @brief Ustawia nowy korzeń drzewa (używane przy wczytywaniu). */
    void setRoot(Node* newRoot) { root = newRoot; }
};