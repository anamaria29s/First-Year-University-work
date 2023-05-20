#include <iostream>
#include <cstring>
#include <string.h>
#include <list>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Aroma{
protected:
    string numeAroma;
    float pret;
    
public:
    Aroma (); //constructor fara parametri
    Aroma (string numeAroma, float pret); //constructor parametrizat
    Aroma (const Aroma&); //Copy constructor
    
    Aroma& operator= (const Aroma&); //operator egal
    friend istream& operator>> (istream&, Aroma&); //supraincarcare >>
    friend ostream& operator<< (ostream&, Aroma&); //supraincarcare <<
    
    float getPret() const {return this->pret;}
    
    ~Aroma();
};

Aroma::Aroma()
{
    numeAroma = "-";
    pret=0;
}

Aroma::Aroma(string numeAroma, float pret)
{
    this-> numeAroma = numeAroma;
    this-> pret = pret;
} 

Aroma::Aroma(const Aroma& obj)
{
    this-> numeAroma = obj.numeAroma;
    this-> pret = obj.pret;
}

class Gelato{
protected:
    string nume;
    vector<Aroma> listaArome;
    string gust;
    
public:
    Gelato();
    Gelato(string nume, vector<Aroma> listaArome, string gust);
    Gelato (const Gelato&);
    
    Gelato& operator= (const Gelato&);
    friend istream& operator>> (istream&, Gelato&); 
    friend ostream& operator<< (ostream&, Gelato&);
    
    string getnume() {return this->nume;}
    
};
