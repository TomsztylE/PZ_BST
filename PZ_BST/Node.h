/**
 * @file Node.h
 * @brief Definicja struktury węzła drzewa BST.
 */

#pragma once

 /**
  * @struct Node
  * @brief Struktura reprezentująca pojedynczy węzeł w drzewie poszukiwań binarnych (BST).
  */
struct Node {
    int data;       /**< Wartość przechowywana w węźle */
    Node* left;     /**< Wskaźnik na lewe poddrzewo */
    Node* right;    /**< Wskaźnik na prawe poddrzewo */

    /**
     * @brief Konstruktor inicjalizujący węzeł.
     * @param val Wartość całkowita przypisywana do węzła.
     */
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};