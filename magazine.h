#ifndef _MAGAZINE_H_ 
#define _MAGAZINE_H_ 

#include <iostream>
#include <string>
#include <fstream>
#include "item.h"

class Magazine : public Item{
    int numer;

    public:
    Magazine(std::string t="", int yr=0, bool i_l=false, int nr=0);
    std::string GetType() const override; 
    void display_info() override;
    int GetNumer();
    void SetNumer(int newNumer);
    void save_to_txt(std::ofstream& file) override;
    void load_from_txt(std::ifstream& file) override;
};


#endif