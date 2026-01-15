#ifndef _LIBRARY_H_ 
#define _LIBRARY_H_ 
#include <iostream>
#include <vector> 
#include <fstream>
#include "item.h" 
#include "book.h"
#include "magazine.h"
#include "movie.h"


class Library {
private:
    std::vector<Item*> items; //tablica wskaznikow Item nazywam elemnety jej items czyli to wskazniki
    int id_counter = 0; //numeracja kolejnosc pozycji automatyczna
    public:
    Library();
    ~Library(); 
    void addItem(Item* i);
    Item* findItem(int id);
    Item* findItemTitle(std::string szukany_title);
    void loanItem(int id);
    void removeItem(int id);
    void saveAll(const std::string& filename = "library.txt");
    void loadAll(const std::string& filename = "library.txt");
    void displayAll();
};

#endif