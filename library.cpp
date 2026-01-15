#include <iostream>
#include "library.h"
#include "item.h"
using namespace std;


Library::Library(){
    id_counter=0;
}

void Library::addItem(Item* i){
    if (i == nullptr){
        cout<<"Nie mozna dodac pustej pozycji."<<endl;
        return;
    }
    i->SetId(id_counter); 
    id_counter++;  
    items.push_back(i);
    cout<<"Dodano nowa pozycje: "<<i->GetTitle()<<" ID: "<<i->GetId()<<endl;
}
Item* Library::findItem(int id){
    for (size_t i=0; i<items.size(); i++){
        if (items[i]->GetId() == id){
            return items[i];
        }
    }
    return nullptr;
}
Item* Library::findItemTitle(string szukany_title){
    for (size_t i=0; i<items.size(); i++){
        if (items[i]->GetTitle() == szukany_title){
            items[i]->display_info();
            return nullptr;}
    }
    cout<<"Nie ma pozycji o takim tytule."<<endl;
    return nullptr;
}

void Library::loanItem(int id){ //sluzy do zwracania lub wypozyczania
    Item* item = findItem(id);
    if (item == nullptr){
    cout<<"Nie znaleziono pozycji o ID: "<<id<<endl;
    }
    if(item->GetIs_loaned() == false){ //jest niewypozyczona czyli mozna wypozyczyc 
        item->SetIs_loaned(true);
        cout<<"Pozycja "<<item->GetTitle()<<" zostala WYPOZYCZONA"<<endl;
    }else{
        item->SetIs_loaned(false); //bo zwracamy
        cout<<"Pozycja "<<item->GetTitle()<<" zostala ZWROCONA"<<endl;
    }
}

void Library::removeItem(int id){
    for (size_t i = 0; i < items.size();i++){ 
        if (items[i]->GetId() == id){
            delete items[i]; //usuwanie wskaznika
            items.erase(items.begin()+i); //usuwanie elementu wektora o indeksie i
            cout << "Pozycja ID "<<id<<" zostala usunieta z biblioteki."<<endl;
            return;
        }
    }
    cout<<"Nie znaleziono pozycji o ID "<<id<<" -> NIE MOZNA USUNAC"<<endl;
}
void Library::saveAll(const std::string& filename){
    ofstream file(filename); 
    if (!file.is_open()) {
        cout << "Blad otwarcia pliku!" << endl;
        return;
    }
    for (size_t i = 0; i < items.size(); i++) {
        items[i]->save_to_txt(file);
    }
    file.close(); 
    cout << "Zapisano dane do pliku: " << filename << endl;
}

void Library::loadAll(const string& filename){
    ifstream file(filename); //strumien wejscia z plikiem filename
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }
    for (size_t i = 0; i < items.size(); i++){
        delete items[i];
    }
    items.clear();

    string type; //"BOOK"/"MOVIE"/"MAGAZINE"

    //ZACZYNAMY CZYTAC JENDA LINIE I ZAPISUJEMY DO TYPE (jesli nie mozna to znaczy ze
    //koniec pliku i wychodzimy z petli)
    while (getline(file, type)) {
        Item* item = nullptr; //na razie pusty obiekt-zaraz uzupelnimy ale trzeba zdefiniowac
        if (type == "BOOK")
            item = new Book();
        else if (type == "MOVIE")
            item = new Movie();
        else if (type == "MAGAZINE")
            item = new Magazine();
        if (item){
            item->load_from_txt(file);
            items.push_back(item);//dodaje do danych library
        }
    }
    file.close();
    cout << "Wczytano dane z pliku: " << filename << endl;
}

void Library::displayAll(){
    if (items.empty()){
        cout << "Biblioteka jest pusta."<<endl;;
        return;
    }
    for (size_t i = 0; i < items.size(); i++){
        items[i]->display_info();
        cout << "-----------------"<<endl;
    }
}

Library::~Library() {
    for (size_t i = 0; i < items.size(); i++) {
        delete items[i];
    }
}





