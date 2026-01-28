# System Zarządzania Biblioteką 

## Opis projektu
Aplikacja konsolowa napisana w języku C++, służąca do  zarządzania zbiorami bibliotecznymi. Program umożliwia obsługę różnych typów zasobów, takich jak książki, filmy oraz czasopisma, z wykorzystaniem dziedziczenia i polimorfizmu.

Aplikacja  zapewnia trwałość danych poprzez zapis do pliku tekstowego.

## Funkcjonalności
- Dodawanie, usuwanie oraz wyszukiwanie pozycji w bibliotece
- Obsługa wypożyczeń i zwrotów (zmiana statusu dostępności)
- Wyszukiwanie pozycji i wyświetlanie informacji o niej
- Zarządzanie różnymi typami zbiorów: książki, filmy, czasopisma
- Zapis całej bazy danych do pliku tekstowego
- Automatyczne wczytywanie danych przy starcie programu
- Interaktywne menu konsolowe
- Obsługa parametru "-help"

## Struktura projektu

### Klasa bazowa
**Item**
- Przechowuje wspólne dane: tytuł, rok wydania, unikalny numer ID, status wypożyczenia
- Zawiera metody wirtualne do wyświetlania informacji oraz zapisu danych do pliku

### Klasy pochodne
**Book**
- Dodatkowy atrybut: autor

**Movie**
- Dodatkowy atrybut: reżyser

**Magazine**
- Dodatkowy atrybut: numer wydania

Klasy pochodne nadpisują metody zapisu, aby uwzględnić swoje unikalne dane.

### Klasa zarządzająca
**Library**
- Przechowuje zbiory jako `std::vector<Item*>`
- Obsługuje operacje: `addItem`, `removeItem`, `loanItem`, `saveAll`
- Odpowiada za zapis i odczyt danych z pliku `library.txt`
- Zawiera destruktor zwalniający zaalokowaną pamięć

## Jak uruchomić
1. Skompiluj wszystkie pliki `.cpp`:
   make
   lub
   g++ main.cpp item.cpp book.cpp movie.cpp magazine.cpp library.cpp -o biblioteka_projekt
2. Aby uruchomic ./biblioteka_projekt -> potem wpisujemy cyfre aby wejsc w odpowiednia funkcję i aby korzystać z konfugiracji domyślnej
3. Aby uruchomic ./biblioteka_projekt -file -> działanie to samo co powyżej tylko pracujemy na danych z pliku -file a nie domyślnej konfiguracji
4. Aby otworzyc menu pomocy ./biblioteka_projekt -help
