#include <iostream>
#include <string>
#include <fstream>
#include "item.h"
#include "book.h"
using namespace std;

Book::Book(string t, int yr, bool i_l, string a) : Item(t,yr,i_l),author(a){}

void Book::display_info(){
    Item::display_info();
    cout << "Typ: Książka"<< "\nAutor: " << author <<endl;
}
string Book::GetType() const{
    return "BOOK";
}

string Book::GetAuthor(){
    return author;
}
void Book::SetAuthor(string newAuthor){
    author = newAuthor;
}
void Book::save_to_txt(ofstream& file){ 
    file << GetType() << endl;
    Item::save_to_txt(file);
    file<<author<<endl;
}
void Book::load_from_txt(ifstream& file) {
    Item::load_from_txt(file);
    getline(file, author);
}

