#ifndef _MOVIE_H_ 
#define _MOVIE_H_ 

#include <iostream>
#include <string>
#include <fstream>
#include "item.h"

class Movie : public Item {
    std::string director; 

public:
    Movie(std::string t="", int yr=0, bool i_l=false, std::string dir="");
    std::string GetType() const override; 
    void display_info() override;
    std::string GetDirector();
    void SetDirector(std::string newDirector);
    void save_to_txt(std::ofstream& file) override;
    void load_from_txt(std::ifstream& file) override;
};
#endif