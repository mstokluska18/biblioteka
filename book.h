#ifndef _BOOK_H_ 
#define _BOOK_H_

#include <iostream>
#include <string>
#include <fstream>
#include "item.h"

class Book: public Item{
    std::string author; 
    
    public:
    Book(std::string t="", int yr=0, bool i_l=false, std::string a="");
    void display_info();
    std::string GetType() const override; 
    std::string GetAuthor();
    void SetAuthor(std::string newAuthor);
    void save_to_txt(std::ofstream& file) override;
    void load_from_txt(std::ifstream& file) override;

};
#endif