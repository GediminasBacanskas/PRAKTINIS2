#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Aikstele{
    string marke;
    int metai;
    double litrazas;
    int lokacija;
};
//------------------------------------FUNKCIJOS------------------------------------
void Pildymas (int dydis, int automobilis, Aikstele & vieta, bool Tikrinimas,vector<Aikstele> & aikstele );
void Isvedimas (vector<Aikstele> aikstele);
void PagalMarke(vector<Aikstele> & aikstele, string & marke,int & k);
void PagalMetus(vector<Aikstele> & aikstele, int & m);
void PagalLitraza(vector<Aikstele> & aikstele,double & l);
void RusiavimasPagalSkaiciu (vector<Aikstele> & aikstele);
void RusiavimasPagalAbecele (vector<Aikstele> & aikstele);
//---------------------------------------------------------------------------------
int main() {
    cout << " Uzpildykite aikstele " << endl;
    int dydis = 20;
    int automobilis;
       bool Tikrinimas = true;
    int uzimta = 0;
    Aikstele vieta;
    vector<Aikstele> aikstele;
    Pildymas (dydis,automobilis,vieta,Tikrinimas,aikstele);
    Isvedimas (aikstele);
    int stop = 1;
    while (stop != 0) {

        cout << "-------------MENIU------------------------" << endl;
        cout << "1. Paieska pagal marke" << endl;
        cout << "2. Paieska pagal metus" << endl;
        cout << "3. Paieska pagal litraza" << endl;
        cout << "0. Uzbaigti." << endl;
        cout << "-------------------------------------" << endl;
        cout << "Pasirinkite opcija: ";
        cin >> stop;
        cout << "-------------------------------------" << endl;

    switch (stop) {
        case 0: {
            break;
        }
        case 1: {
            string marke;
            int k = 0;
            cout << " Iveskite marke mazosiomis raidemis" << endl;
            cin >> marke;
            PagalMarke(aikstele, marke,k);
            break;
        }
        case 2: {
            int m;
            cout << "Iveskite automobilio metus" << endl;
            cin >> m;
            PagalMetus(aikstele,m);
            break;
        }
        case 3: {
            double l;
            cout << "Iveskite automobilio litraza (pvz 1.1) " << endl;
            cin >> l;
            PagalLitraza(aikstele,l);
        }
     }
    }
    cout << "Rusiavimas pagal metus didejimo tvarka: " << endl;
    RusiavimasPagalSkaiciu (aikstele);
    Isvedimas (aikstele);
    cout << " Rusiavimas pagal markes pavadinima, abeceles tvarka: " << endl;
    RusiavimasPagalAbecele (aikstele);
    Isvedimas (aikstele);
    return 0;
}
void Pildymas (int dydis, int  automobilis, Aikstele & vieta, bool Tikrinimas, vector<Aikstele> & aikstele){
    cout << " Iveskite kiek stoves automobiliu aiksteleje " << endl;
    cin >> automobilis;
    if(automobilis <= 0 ) { cout << " Nera automobiliu, kuriuos butu galima pastatyti i aikstele " << endl;}
    else {
    for (int i = 0; i < dydis; ++i) {
        if (automobilis > 0) {
            cout << " Aiksteles vieta: " << i << ". Ar norite ja uzpildyti?(0 - Ne, 1- Taip)" << endl;
            cin >> Tikrinimas;
            if (Tikrinimas) {
                cout << "Iveskite automobilio marke: " << endl;
                cin >> vieta.marke;                                     // objektas
                cout << "Iveskite automobilio metus" << endl;
                cin >> vieta.metai;
                cout << " Iveskite litraza " << endl;
                cin >> vieta.litrazas;
                vieta.lokacija = i;
                aikstele.push_back(vieta);                          // dejimas i sarasa
                automobilis--;
            }
        }
        }
    }
}
void Isvedimas (vector<Aikstele> aikstele){
    for (int i = 0; i < aikstele.size(); ++i) {
            cout << "Aiksteles numeris - " << aikstele[i].lokacija << " ";
            cout << "Automobilio marke -  " << aikstele[i].marke;
            cout << " metai - " << aikstele[i].metai;
            cout << " litrazas - " << aikstele[i].litrazas << endl;
    }
}
void PagalMarke(vector<Aikstele> & aikstele, string & marke, int & k){
    for (int i = 0; i < aikstele.size(); ++i) {
        if(aikstele[i].marke == marke){
            cout << "Aiksteles numeris - " << aikstele[i].lokacija << " ";
            cout << "Automobilio marke -  " << aikstele[i].marke;
            cout << " metai - " << aikstele[i].metai;
            cout << " litrazas - " << aikstele[i].litrazas << endl;
            k++;
        }
    }
}
void PagalMetus(vector<Aikstele> & aikstele, int & m){
    for (int i = 0; i < aikstele.size(); ++i) {
        if(aikstele[i].metai == m){
            cout << "Aiksteles numeris - " << aikstele[i].lokacija << " ";
            cout << "Automobilio marke -  " << aikstele[i].marke;
            cout << " metai - " << aikstele[i].metai;
            cout << " litrazas - " << aikstele[i].litrazas << endl;
        }
    }
}
void PagalLitraza(vector<Aikstele> & aikstele,double & l){
    for (int i = 0; i < aikstele.size(); ++i) {
        if(aikstele[i].litrazas == l){
            cout << "Aiksteles numeris - " << aikstele[i].lokacija << " ";
            cout << "Automobilio marke -  " << aikstele[i].marke;
            cout << " metai - " << aikstele[i].metai;
            cout << " litrazas - " << aikstele[i].litrazas << endl;
        }
    }
}
void RusiavimasPagalSkaiciu (vector<Aikstele> & aikstele){
    for (int i = 0; i < aikstele.size(); ++i) {
        for (int j = 0; j < aikstele.size() - 1; ++j) {
            if(aikstele[i].metai < aikstele[j].metai){
                swap(aikstele[i],aikstele[j]);
            }
        }
    }
}
void RusiavimasPagalAbecele (vector<Aikstele> & aikstele){
    for (int i = 0; i < aikstele.size(); ++i) {
        for (int j = 0; j < aikstele.size() - 1; ++j) {
            if(aikstele[i].marke < aikstele[j].marke){
                swap(aikstele[i],aikstele[j]);
            }
        }
    }
}