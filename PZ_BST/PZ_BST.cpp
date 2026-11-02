/**
 * @file main.cpp
 * @brief Punkt wejścia programu.
 * @details Zawiera menu użytkownika pozwalające na testowanie funkcjonalności drzewa BST i menedżera plików.
 */

#include <iostream>
#include "BST.h"
#include "FileManager.h"

 /**
  * @brief Funkcja główna programu.
  * @return Wartość 0 w przypadku poprawnego zakończenia.
  */
int main() {
    BST tree;
    FileManager fm;
    int choice, val, method;
    std::string filename;

    while (true) {
        std::cout << "\n=== MENU DRZEWA BST ===\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj drogi do podanego elementu\n";
        std::cout << "5. Wyswietl drzewo graficznie na ekranie\n";
        std::cout << "6. Zapis do pliku tekstowego wygenerowanego drzewa\n";
        std::cout << "7. Zapis binarny (BTS)\n";
        std::cout << "8. Odczyt z pliku binarnego\n";
        std::cout << "9. Wczytaj liczby z pliku tekstowego do drzewa\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
        case 1: std::cout << "Podaj liczbe: "; std::cin >> val; tree.insert(val); break;
        case 2: std::cout << "Podaj liczbe do usuniecia: "; std::cin >> val; tree.remove(val); break;
        case 3: tree.clear(); std::cout << "Drzewo usuniete.\n"; break;
        case 4: std::cout << "Czego szukasz: "; std::cin >> val; tree.findPath(val); break;
        case 5:
            std::cout << "Wybierz metode: 1(Preorder), 2(Inorder), 3(Postorder): ";
            std::cin >> method;
            tree.display(method);
            break;
        case 6: std::cout << "Nazwa pliku txt: "; std::cin >> filename; tree.saveToText(filename); break;
        case 7: std::cout << "Nazwa pliku bin: "; std::cin >> filename; fm.saveBinary(tree, filename); break;
        case 8: std::cout << "Nazwa pliku bin: "; std::cin >> filename; fm.loadBinary(tree, filename); break;
        case 9: std::cout << "Nazwa pliku txt: "; std::cin >> filename; fm.loadFromText(tree, filename); break;
        case 0: return 0; // Poprawne zamknięcie programu zgodnie z wymaganiami
        default: std::cout << "Niepoprawna opcja.\n";
        }
    }
}