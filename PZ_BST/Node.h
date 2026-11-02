/**
 * @file Node.h
 * @brief Deklaracja struktury opisującej pojedynczy element (węzeł) drzewa BST.
 */

#pragma once

/**
 * @struct Node
 * @brief Reprezentacja pojedynczego węzła w strukturze drzewa binarnego.
 *
 * Przechowuje właściwą wartość klucza oraz wskaźniki na potomków (lewe i prawe poddrzewo).
 */
struct Node {
    int data;    /**< Klucz / wartość przechowywana w węźle. */
    Node* left;  /**< Wskaźnik na lewego potomka (elementy mniejsze). */
    Node* right; /**< Wskaźnik na prawego potomka (elementy większe). */

    /**
     * @brief Tworzy nowy węzeł o zadanej wartości.
     * @param val Wartość całkowita, która ma zostać zapisana w węźle.
     *
     * Inicjalizuje wskaźniki potomków wartością nullptr.
     */
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};