/**
 * @file FileManager.h
 * @brief Deklaracja klasy obsługującej operacje plikowe (odczyt/zapis).
 */

#pragma once
#include "BST.h"
#include <string>

 /**
  * @class FileManager
  * @brief Klasa narzędziowa do zapisu i odczytu drzewa BST.
  *
  * Implementuje zapis/odczyt binarny oraz wczytywanie drzewa
  * z pliku tekstowego zawierającego liczby oddzielone spacjami.
  */
class FileManager {
private:
    /**
     * @brief Serializuje węzeł do pliku binarnego.
     * @details Używa specjalnej wartości -999999 jako znacznika pustego węzła (nullptr).
     * @param node Aktualny węzeł.
     * @param out Strumień pliku binarnego wyjściowego.
     */
    void serialize(Node* node, std::ofstream& out);

    /**
     * @brief Deserializuje węzeł z pliku binarnego do obiektu drzewa.
     * @param tree Referencja do drzewa docelowego.
     * @param in Strumień pliku binarnego wejściowego.
     */
    void deserialize(BST& tree, std::ifstream& in);

public:
    /**
     * @brief Zapisuje całe drzewo do pliku binarnego.
     * @param tree Drzewo do zapisania.
     * @param filename Nazwa pliku wyjściowego.
     */
    void saveBinary(BST& tree, const std::string& filename);

    /**
     * @brief Wczytuje drzewo z pliku binarnego. Zastępuje obecne drzewo.
     * @param tree Drzewo docelowe.
     * @param filename Nazwa pliku wejściowego.
     */
    void loadBinary(BST& tree, const std::string& filename);

    /**
     * @brief Wczytuje liczby z pliku tekstowego do drzewa (pustego lub istniejącego).
     * @param tree Drzewo docelowe.
     * @param filename Nazwa pliku tekstowego.
     */
    void loadFromText(BST& tree, const std::string& filename);
};