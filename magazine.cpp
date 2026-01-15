#include <iostream>
#include <fstream>
#include <string>
#include "item.h"
#include "magazine.h"

using namespace std;


Magazine::Magazine(string t, int yr, bool i_l, int nr) : Item(t, yr, i_l),numer(nr){}

void Magazine::display_info(){
    Item::display_info(); 
    cout << "Typ: Czasopismo: "<< "Numer wydania: " << numer << "\n";
}
string Magazine::GetType() const{
    return "MAGAZINE";
}
int Magazine::GetNumer(){
    return numer;
}
void Magazine::SetNumer(int newNumer){
    numer = newNumer;
}
void Magazine::save_to_txt(ofstream& file){
    file << GetType() << endl;
    Item::save_to_txt(file);
    file<<numer<<endl;
}
void Magazine::load_from_txt(ifstream& file) {
    Item::load_from_txt(file);
    file>>numer;
    file.ignore();
}
