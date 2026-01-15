#ifndef _ITEM_H_ 
#define _ITEM_H_ 

#include <iostream>
#include <string>
#include <fstream>

class Item{
    protected:
    std::string title; 
    int year;
    int id; 
    bool is_loaned;
    
    public:
    Item(std::string t="", int yr=0, bool i_l=false); 
    virtual std::string GetType() const;
    int GetId();
    std::string GetTitle();
    int GetYear();  
    bool GetIs_loaned();
    void SetTitle(std::string newTitle);
    void SetId(int newId);
    void SetYear(int newYear);
    void SetIs_loaned(bool newIs_loaned);
    virtual void display_info();
    virtual void save_to_txt(std::ofstream& file);  
    virtual void load_from_txt(std::ifstream& file);  
    virtual ~Item();    
     
};

#endif


