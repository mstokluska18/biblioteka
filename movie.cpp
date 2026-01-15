#include <iostream>
#include <string>
#include <fstream>
#include "item.h"
#include "movie.h"
using namespace std;

Movie::Movie(string t, int yr, bool i_l, string dir) : Item(t,yr,i_l),director(dir){}

void Movie::display_info() {
    Item::display_info(); 
    cout << "Typ: Film"<< "\nReżyser: " << director << "\n";
}
string Movie::GetType() const{
    return "MOVIE";
}
string Movie::GetDirector(){
    return director;
}
void Movie::SetDirector(string newDirector){
    director = newDirector;
}
void Movie::save_to_txt(ofstream& file){ 
    file << GetType() << endl;
    Item::save_to_txt(file);
    file<<director<<endl;
}
void Movie::load_from_txt(ifstream& file) {
    Item::load_from_txt(file);
    getline(file, director);
}
