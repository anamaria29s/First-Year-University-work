#include <iostream>
#include <cstring>
#include <string.h>
#include <list>
#include <map>
#include <vector>
#include <set>

using namespace std;

class Aroma{
    string numeAroma;
    float pret;

public:
    Aroma (string,float); //constructor fara parametri
    Aroma (const Aroma&); //Copy constructor

    Aroma& operator= (const Aroma&); //operator egal
    friend istream& operator>> (istream&, Aroma&); //supraincarcare >>
    friend ostream& operator<< (ostream&, const Aroma&); //supraincarcare <<

    float getPret() const {return this->pret;}


};

Aroma::Aroma(string numeAroma = "-", float pret = 0)
{
    this->numeAroma = numeAroma;
    this->pret = pret;
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
    string numeAlergeni;

public:
    Alergeni (string); //constructor fara parametri
    Alergeni (const Alergeni&); //Copy constructor

    Alergeni& operator= (const Alergeni&); //operator egal
    friend istream& operator>> (istream&, Alergeni&); //supraincarcare >>
    friend ostream& operator<< (ostream&, const Alergeni&); //supraincarcare <<



};

Alergeni::Alergeni(string numeAlergeni = "-")
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

class IOinterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};


class Gelato: public IOinterface{
protected:
    string nume;
    vector<Aroma> listaArome;
    string gust;

public:
    Gelato();
    Gelato(string nume, vector<Aroma> listaArome, string gust);
    Gelato (const Gelato&);

    Gelato& operator= (const Gelato&);
    istream& citire(istream& in);
    ostream& afisare(ostream& os) const;
    friend istream& operator>>(istream& in, Gelato& c);
    friend ostream& operator<<(ostream& os, const Gelato& c);

    string getnume() {return this-> nume;}
    string getgust() {return this-> gust;}


     virtual ~Gelato() {}
};



istream& Gelato::citire(istream& in)
{
    cout << "Introduceti numele\n";
        in >> this->nume;
        if(!this->listaArome.empty()){
                this->listaArome.clear();
        }
        cout << "1. Add aroma\n";
        cout << "2. Inceteaza sa adaugi\n";
        int k;

        while(cin >> k && k != 2){
            this->listaArome.push_back(*(new Aroma()));
            in >> this->listaArome.back();
            cout << "1. Add aroma\n";
            cout << "2. Inceteaza sa adaugi\n";
        }

        cout << "Introduceti gustul\n";
        in >> this->gust;
        return in;
}

istream& operator>>(istream& in, Gelato& g)
{
    return g.citire(in);
}

ostream& Gelato::afisare(ostream& os) const
{
    os << "Nume: " << this->nume << endl;
        os << "Lista de arome: \n";
        for(int i = 0; i < this->listaArome.size(); i++)
            os << this->listaArome[i] << endl;
        os << "Gust: " << this->gust << endl;
        return os;
}

ostream& operator<<(ostream& out,const Gelato& g)
{
    return g.afisare(out);
}

Gelato::Gelato()
{
    nume = "-";
    listaArome = {};
    gust = "-";
}

Gelato::Gelato(string nume, vector<Aroma> listaArome, string gust)
{
    this->nume = nume;
    this-> listaArome = listaArome;
    this->gust = gust;
}

Gelato::Gelato(const Gelato& obj)
{
    this->nume = obj.nume;
    this-> listaArome = obj.listaArome;
    this->gust = obj.gust;
}

Gelato& Gelato::operator = (const Gelato& obj)
{
    if(this!=&obj)
    {
        this->nume = obj.nume;
        this-> listaArome = obj.listaArome;
        this->gust = obj.gust;
    }
    return *this;
}




class InghetataAmbalata: virtual public Gelato{
protected:
    string dataexp;
public:
    InghetataAmbalata();
    InghetataAmbalata(string nume, vector<Aroma> listaArome, string gust, string dataexp);
    InghetataAmbalata (const InghetataAmbalata&);

    InghetataAmbalata& operator= (const InghetataAmbalata&);
    istream& citire (istream& in);
    friend istream& operator>>(istream& in, InghetataAmbalata& g);
    friend ostream& operator<<(ostream& os, const InghetataAmbalata& g);
    ostream& afisare (ostream& os) const;

    string getdataexp() {return dataexp;}


    virtual ~InghetataAmbalata() {}
};

istream& InghetataAmbalata::citire (istream& in){
   Gelato::citire(in);
   // this->Gelato::citire(in);
    cout << "Introduceti data expirarii\n";
    in >> this->dataexp;
    return in;
}

istream& operator>>(istream& in, InghetataAmbalata& g){
    return g.citire(in);
}

ostream& InghetataAmbalata::afisare(ostream& os) const{
   Gelato::afisare(os);
   cout << "Data de expirare: " << this->dataexp <<endl;
        return os;
}

ostream& operator<<(ostream& os, const InghetataAmbalata& g){
   return g.afisare(os);
}

InghetataAmbalata::InghetataAmbalata(): Gelato()
{
    this->dataexp = "-";
}

InghetataAmbalata::InghetataAmbalata(string nume, vector<Aroma> listaArome, string gust, string dataexp):
    Gelato(nume, listaArome,gust)
{
    this->dataexp = dataexp;
}

InghetataAmbalata::InghetataAmbalata(const InghetataAmbalata& obj): Gelato(obj)
{
   this->dataexp = obj.dataexp;
}

InghetataAmbalata& InghetataAmbalata::operator= (const InghetataAmbalata& obj)
{
    if(this!=&obj)
    {
        Gelato::operator=(obj);
        this->dataexp=obj.dataexp;
    }

    return *this;
}

class InghetataFresh: virtual public Gelato{
protected:
    list<Alergeni> listaAlergeni;
public:
    InghetataFresh();
    InghetataFresh(string nume, vector<Aroma> listaArome, string gust, list<Alergeni> listaAlergeni);
    InghetataFresh (const InghetataFresh&);

    InghetataFresh& operator= (const InghetataFresh&);
    istream& citire (istream& in);
    friend istream& operator>>(istream& in, InghetataFresh& g);
    friend ostream& operator<<(ostream& os, const InghetataFresh& g);
    ostream& afisare (ostream& os) const;



    virtual ~InghetataFresh() {}
};

istream& InghetataFresh::citire (istream& in){
   Gelato::citire(in);
   if(!this->listaAlergeni.empty()){
                this->listaAlergeni.clear();
        }
        cout << "1. Add alergen\n";
        cout << "2. Inceteaza sa adaugi\n";
        int k;

        while(cin >> k && k != 2){
            this->listaAlergeni.push_back(*(new Alergeni()));
            in >> this->listaAlergeni.back();
            cout << "1. Add alergen\n";
            cout << "2. Inceteaza sa adaugi\n";
        }

        return in;
}

istream& operator>>(istream& in, InghetataFresh& g){
    return g.citire(in);
}

ostream& InghetataFresh::afisare(ostream& os) const{
   Gelato::afisare(os);
    os << "Lista de alergeni: \n";
        list <Alergeni>::iterator it;
        for (auto it=listaAlergeni.begin(); it!=listaAlergeni.end(); it++)
        {
            os<<*it<<endl;
        }
        return os;
}

ostream& operator<<(ostream& os, const InghetataFresh& g){
   return g.afisare(os);
}

InghetataFresh::InghetataFresh(): Gelato()
{
    listaAlergeni = {};
}

InghetataFresh::InghetataFresh(string nume, vector<Aroma> listaArome, string gust, list<Alergeni> listaAlergeni): Gelato(nume, listaArome,gust)
{
    this->listaAlergeni = listaAlergeni;
}

InghetataFresh::InghetataFresh(const InghetataFresh& obj): Gelato(obj)
{
    this->listaAlergeni = obj.listaAlergeni;
}

InghetataFresh& InghetataFresh::operator= (const InghetataFresh& obj)
{
    if(this!=&obj)
    {
        Gelato::operator=(obj);
        this-> listaAlergeni=obj.listaAlergeni;
    }

    return *this;
}


class Cornet:virtual public InghetataFresh{
protected:
    string tipCornet;
public:

    string getTipCornet() {return this->tipCornet;}
    Cornet(){
        this->tipCornet = "-";
    }

    Cornet(string nume, vector<Aroma> listaArome, string gust,list<Alergeni> listaAlergeni, string tipCornet):
        Gelato(nume, listaArome, gust), InghetataFresh(nume, listaArome, gust, listaAlergeni){
        this->tipCornet = tipCornet;
    }

    Cornet(const Cornet& obj): Gelato(obj), InghetataFresh(obj){
        this->tipCornet = obj.tipCornet;
    }

    Cornet& operator =(const Cornet& obj){
        if(this != &obj){
            InghetataFresh::operator=(obj);
            this->tipCornet = obj.tipCornet;
        }
        return *this;
    }
    istream& citire(istream& in) {
        this->Gelato::citire(in);
        cout << "Introduceti tipul de cornet\n";
        in >> this->tipCornet;
        return in;
    }
    ostream& afisare(ostream& os) const {
        Gelato::afisare(os);
        cout << "Cornet: " << this->tipCornet <<endl;
        return os;
    }

};

class Pahar:virtual public InghetataFresh{
protected:
    bool lingurita;
public:
    int getLingurita() {return lingurita;}

    Pahar(){
        this->lingurita = 0;
    }

    Pahar(string nume, vector<Aroma> listaArome, string gust, list<Alergeni> listaAlergeni, bool lingurita):
        Gelato(nume, listaArome, gust), InghetataFresh(nume, listaArome, gust, listaAlergeni){
        this->lingurita = lingurita;
    }

    Pahar(const Pahar& obj): Gelato(obj), InghetataFresh(obj){
        this->lingurita = obj.lingurita;
    }

    Pahar& operator =(const Pahar& obj){
        if(this != &obj){
            InghetataFresh::operator=(obj);
            this->lingurita = obj.lingurita;
        }
        return *this;
    }
    istream& citire(istream& in) {
        this->Gelato::citire(in);
        cout << "Introduceti daca doriti lingurita\n";
        in >> this->lingurita;
        return in;
    }
    ostream& afisare(ostream& os) const {
        Gelato::afisare(os);
        cout << "Lingurita: " << this->lingurita <<endl;
        return os;
    }
};

class Gelaterie:public IOinterface
{
private:
    int nrGelato;
    int rating;
    set<pair<int,string>> listaRatingGelato;
public:
    Gelaterie();
    Gelaterie(int nrGelato, int rating, set<pair<int,string>> listaRatingGe);
    Gelaterie(const Gelaterie& obj);
    Gelaterie& operator=(const Gelaterie& obj);

    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    friend istream& operator>>(istream& in, Gelaterie& g);
    friend ostream& operator<<(ostream& out, const Gelaterie& g);

    ~Gelaterie();
};

Gelaterie:: Gelaterie()
{
    this->nrGelato = 0;
    this->rating = 0;
    this->listaRatingGelato = {};
}

Gelaterie:: Gelaterie(int nrGelato, int rating, set<pair<int,string>> listaRatingGelato)
{
    this->nrGelato = nrGelato;
    this->rating = rating;
    this->listaRatingGelato = listaRatingGelato;
}

Gelaterie:: Gelaterie(const Gelaterie& obj)
{
    this->nrGelato = obj.nrGelato;
    this->rating = obj.rating;
    this->listaRatingGelato = obj.listaRatingGelato;
}

Gelaterie& Gelaterie::operator= ( const Gelaterie& obj)
{
    if(this != &obj)
    {
        this->nrGelato = obj.nrGelato;
        if (this->listaRatingGelato.empty() == 0)
            this->listaRatingGelato.clear();
            this->rating=obj.rating;
        this->listaRatingGelato=obj.listaRatingGelato;
    }
    return *this;
}
istream& Gelaterie::citire(istream& in)
{
    if (this->listaRatingGelato.empty()==0)
        this->listaRatingGelato.clear();
    int p=1;
    while (p!=0)
    {
        string nr;
        cout<<"Introduceti numarul de inghetate gelato al Gelateriei."<<endl;
        in>>nr;
        try{
            if(stoi(nr)){
                  p=0;
                  this->nrGelato=stoi(nr);

            }
            else throw(nr);
        }catch(...){
            cout<<"Nu ati dat o valoare buna. Incercati din nou."<<endl;

        }
    }

    for( int i=0; i< this->nrGelato; i++)
    {
        Gelato g;
        cout<<"Introduceti o inghetata gelato."<<endl;
        cin>>g;
        int p=1;
        while(p!=0)
        {
            cout<<"Dati un rating pentru inghetata. "<<endl;
            string h;
            in>>h;
            try{
                if (stoi(h))
                {
                    p=0;
                    this->rating=stoi(h);
                }
                else throw(h);

            }catch(...){
                cout<<"Nu ati dat o valoare buna."<<endl;

            }
        }
        this->listaRatingGelato.insert(make_pair(rating,g.getnume()));
    }

    return in;
}

istream& operator>>(istream& in, Gelaterie& g)
{
    return g.citire(in);
}

ostream& Gelaterie::afisare(ostream& os) const
{
    if (this->listaRatingGelato.empty()==0)
    {
        os<<"Avem "<<this->nrGelato<<" inghetate disponibile in Gelaterie."<<endl;
        os<<"------------Rating si nume----------- "<<endl;
        for(auto it=this->listaRatingGelato.begin();it!=this->listaRatingGelato.end();it++)
        {
            os<<"Rating : "<<(*it).first<<";"<<" Nume : "<<(*it).second<<endl;
            os<<endl;
        }
    }
    else
    {
        os<<"Nu avem nicio inghetata"<<endl;
    }

    return os;
}

ostream& operator<<(ostream& os,const Gelaterie& g)
{
    return g.afisare(os);
}

Gelaterie::~Gelaterie()
{
     if (this->listaRatingGelato.empty()==0)
        this->listaRatingGelato.clear();
}

int main()
{
    return 0;
}
