#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include "item.h"
using namespace std;

Item::Item(string t, int yr, bool i_l)
{
    title = t;    
    year = yr;   
    id = 0;       
    is_loaned = i_l;  
}

void Item::display_info()  {
    cout<< "--- INFORMACJE O POZYCJI ---"<<endl;
    cout<< "ID: " << id <<endl;
    cout<< "Tytuł: " << title <<endl;
    cout<< "Rok Wydania: " << year <<endl;
    if (is_loaned == true){
        cout<<"Status: WYPOŻYCZONE"<<endl;
    }else {
        cout<<"Status: NIEWYPOŻYCZONY"<<endl;
    } 
}

string Item::GetType() const{
    return "ITEM: ";
}

int Item::GetId(){
    return id;
}
string Item::GetTitle(){
    return title;
}

int Item::GetYear(){
    return year;
}

bool Item::GetIs_loaned(){
    return is_loaned;
}
void Item::SetTitle(string newTitle){
    title = newTitle; 
}

void Item::SetId(int newId){ 
    id = newId;
}
void Item::SetYear(int newYear){
    year = newYear;
}
void Item::SetIs_loaned(bool newIs_loaned){
    is_loaned = newIs_loaned; //true wypozyczona
}
void Item::save_to_txt(ofstream& file){
    file<<title<<endl;
    file<<year<<endl;
    file<<id<<endl;
    file<<is_loaned<<endl;
}
//zaladuj dane 
void Item::load_from_txt(ifstream& file) {
    getline(file, title);
    file>>year>>id>>is_loaned;
    file.ignore(); //pomija enter
}

Item::~Item(){}





