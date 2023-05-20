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

Aroma& Aroma::operator= (const Aroma& obj)
{
    if(this != &obj)
    {
        this-> numeAroma = obj.numeAroma;
        this-> pret = obj.pret;
    }
    return *this;
}

istream& operator >>(istream& in, Aroma& obj){
    cout << "Introduceti numele aromei\n";
    in >> obj.numeAroma;
    cout << "Introduceti pretul\n";
    in >> obj.pret;
    return in;
}

ostream& operator <<(ostream& os, const Aroma& obj){
    os << "Nume Aroma: " << obj.numeAroma << endl;
    os << "Pret: " << obj.pret << endl;
    return os;
}

class Alergeni{
protected:
    string numeAlergeni;

public:
    Alergeni (); //constructor fara parametri
    Alergeni (string numeAlergeni); //constructor parametrizat
    Alergeni (const Alergeni&); //Copy constructor

    Alergeni& operator= (const Alergeni&); //operator egal
    friend istream& operator>> (istream&, Alergeni&); //supraincarcare >>
    friend ostream& operator<< (ostream&, Alergeni&); //supraincarcare <<


    ~Alergeni();
};

Alergeni::Alergeni()
{
    numeAlergeni = "-";
}

Alergeni::Alergeni(string numeAlergeni)
{
    this-> numeAlergeni = numeAlergeni;
}

Alergeni::Alergeni(const Alergeni& obj)
{
    this-> numeAlergeni = obj.numeAlergeni;
}

Alergeni& Alergeni::operator= (const Alergeni& obj)
{
    if(this != &obj)
    {
        this-> numeAlergeni = obj.numeAlergeni;
    }
    return *this;
}

istream& operator >>(istream& in, Alergeni& obj){
    cout << "Introduceti numele alergenului\n";
    in >> obj.numeAlergeni;
    return in;
}

ostream& operator <<(ostream& os, const Alergeni& obj){
    os << "Nume alergen: " << obj.numeAlergeni << endl;
    return os;
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

    string getnume() {return this-> nume;}
    string getgust() {return this-> gust;}

    ~Gelato();
};

class InghetataAmbalata: virtual public Gelato{
protected:
    string dataexp;
public:
    InghetataAmbalata();
    InghetataAmbalata(string nume, vector<Aroma> listaArome, string gust, string dataexp);
    InghetataAmbalata (const InghetataAmbalata&);

    InghetataAmbalata& operator= (const InghetataAmbalata&);
    friend istream& operator>> (istream&, InghetataAmbalata&);
    friend ostream& operator<< (ostream&, InghetataAmbalata&);
};

class InghetataFresh: virtual public Gelato{
protected:
    list<Alergeni> listaAlergeni;
public:
    InghetataFresh();
    InghetataFresh(string nume, vector<Aroma> listaArome, string gust, list<Alergeni> listaAlergeni);
    InghetataFresh (const InghetataFresh&);

    InghetataFresh& operator= (const InghetataFresh&);
    friend istream& operator>> (istream&, InghetataFresh&);
    friend ostream& operator<< (ostream&, InghetataFresh&);
};

class Cornet:virtual public InghetataFresh{
protected:
    map<string,int> tipCornet;
public:
    Cornet();
    Cornet(string nume, vector<Aroma> listaArome, string gust, list<Alergeni> listaAlergeni, map<string,int> tipCornet);
    Cornet (const Cornet&);

    Cornet& operator= (const Cornet&);
    friend istream& operator>> (istream&, Cornet&);
    friend ostream& operator<< (ostream&, Cornet&);
};

class Pahar:virtual public InghetataFresh{
protected:
    bool lingurita;
public:
    Pahar();
    Pahar(string nume, vector<Aroma> listaArome, string gust, list<Alergeni> listaAlergeni, lingurita);
    Pahar (const Pahar&);

    Pahar& operator= (const Pahar&);
    friend istream& operator>> (istream&, Pahar&);
    friend ostream& operator<< (ostream&, Pahar&);
};
int main()
{
    return 0;
}
