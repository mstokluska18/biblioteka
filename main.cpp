#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "item.h"
#include "book.h"
#include "magazine.h"
#include "movie.h"
#include "library.h"

using namespace std;

void showHelp() {
    cout << "--- POMOC PROGRAMU BIBLIOTEKA ---" << endl;
    cout << "Uruchom program bez argumentow, aby wejsc do menu." << endl;
    cout << "Opcje w menu:" << endl;
    cout << "1 - Dodaj pozycję" << endl;
    cout << "2 - Wyświetl wszystkie pozycje" << endl;
    cout << "3 - Wypożycz / zwróć pozycję" << endl;
    cout << "4 - Usuń pozycję" << endl;
    cout << "5 - Zapisz do pliku" << endl;
    cout << "6 - Wyszukaj pozycję" << endl;
    cout << "7 - Wyjście z programu" << endl;
}

int main(int argc, char* argv[]) {
    //konsola -help
    if (argc > 1 && string(argv[1]) == "-help") {
        showHelp();
        return 0;
    }

    int choice;
    Library library;

    //gotowe obiekty do testowania
    library.addItem(new Book("Hobbit", 1937, false, "Tolkien"));
    library.addItem(new Book("Harry Potter", 1997, false, "J.K. Rowling"));
    library.addItem(new Movie("Matrix", 1999, false, "Wachowski"));
    library.addItem(new Magazine("National Geographic", 2023, false, 5));

    while (true) {
        cout << "\n=== SYSTEM BIBLIOTEKI ===\n";
        cout << "1. Dodaj pozycję\n";
        cout << "2. Wyświetl wszystkie pozycje\n";
        cout << "3. Wypożycz / zwróć pozycję\n";
        cout << "4. Usuń pozycję\n";
        cout << "5. Zapisz do pliku\n";
        cout << "6. Wyszukaj pozycję\n";
        cout << "7. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> choice;

        switch (choice) {
            case 1: { //Dodaj pozycję
                int typeChoice;
                cout << "Wybierz typ: 1-Książka, 2-Film, 3-Czasopismo: ";
                cin >> typeChoice;
                cin.ignore();

                string title;
                int year;
                bool loaned = false;

                cout << "Tytuł: ";
                getline(cin, title);
                cout << "Rok wydania: ";
                cin >> year;
                cin.ignore();

                if (typeChoice == 1) { // Book
                    string author;
                    cout << "Autor: ";
                    getline(cin, author);
                    library.addItem(new Book(title, year, loaned, author));
                }
                else if (typeChoice == 2) { // Movie
                    string director;
                    cout << "Reżyser: ";
                    getline(cin, director);
                    library.addItem(new Movie(title, year, loaned, director));
                }
                else if (typeChoice == 3) { // Magazine
                    int numer;
                    cout << "Numer wydania: ";
                    cin >>numer;
                    cin.ignore();
                    library.addItem(new Magazine(title, year, loaned, numer));
                }
                else {
                    cout << "Nieprawidłowy typ!" << endl;
                }
                break;
            }
            case 2: // Wyświetlanie wszystkich pozycji
                library.displayAll();
                break;
            case 3: { // Wypożycz / zwróć
                int id;
                cout << "Podaj ID pozycji: ";
                cin >> id;
                library.loanItem(id);
                break;
            }
            case 4: { // Usuwanie
                int id;
                cout << "Podaj ID pozycji do usunięcia: ";
                cin >> id;
                library.removeItem(id);
                break;
            }
            case 5: {// Zapis do pliku
                library.saveAll("library.txt");
                break;
            }
            case 6: {// Wyszukaj pozycję
                string szukany_title;
                cout << "Podaj tytuł szukanej pozycji: ";
                cin >> szukany_title;
                library.findItemTitle(szukany_title);
            }
            case 7: {// Wyjście
                return 0;
            }
            default:
                cout << "Nieprawidłowy wybór. Spróbuj ponownie." << endl;
        }
    }
}
