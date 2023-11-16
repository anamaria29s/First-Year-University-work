#include <iostream>
#include <cstring>
#include <string.h>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <utility>

using namespace std;

template <typename A, typename P>
class Aroma{
    A numeAroma;
    P pret;

public:
    Aroma (A numeAroma = "" ,P pret = 0);
    Aroma (const Aroma&); //Copy constructor

    Aroma& operator= (const Aroma&); //operator egal
    friend istream& operator>> (istream&, Aroma&); //supraincarcare >>
    friend ostream& operator<< (ostream&, const Aroma&); //supraincarcare <<

    P getPret() const {return this->pret;}
    A getnumeAroma() const {return this->numeAroma;}

};

template <typename A, typename P>
Aroma<A,P>::Aroma(A numeAroma, P pret)
{
    this->numeAroma = numeAroma;
    this->pret = pret;
}

template <typename A, typename P>
Aroma<A,P>::Aroma(const Aroma& obj)
{
    this-> numeAroma = obj.numeAroma;
    this-> pret = obj.pret;
}

template <typename A, typename P>
Aroma<A,P>& Aroma<A,P>::operator= (const Aroma& obj)
{
    if(this != &obj)
    {
        this-> numeAroma = obj.numeAroma;
        this-> pret = obj.pret;
    }
    return *this;
}


istream& operator >>(istream& in, Aroma<string,float>& obj){
    cout << "Introduceti numele aromei\n";
    in >> obj.numeAroma;
    cout << "Introduceti pretul\n";
    in >> obj.pret;
    return in;
}

ostream& operator <<(ostream& os, const Aroma<string,float>& obj){
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
    virtual istream& citire(istream&) = 0; //functie virtuala pura
    virtual ostream& afisare(ostream&) const = 0; //fct virtuala pura & metoda constanta
};

class Gelato: public IOinterface{
protected:
    string nume;
    vector<Aroma<string,float>> listaArome;
    string gust;

public:
    Gelato();
    Gelato(string nume, vector<Aroma<string,float>> listaArome, string gust);
    Gelato (const Gelato&);

    Gelato& operator= (const Gelato&);
    istream& citire(istream& in);
    ostream& afisare(ostream& os) const;
    friend istream& operator>>(istream& in, Gelato& c);
    friend ostream& operator<<(ostream& os, const Gelato& c);

    string getnume() {return this-> nume;}
    string getgust() {return this-> gust;}

    template <typename T>
    float total(const T& obj)const;

    void afiseazaTotal() const;

     virtual ~Gelato() {}
};

template <typename T>
float Gelato::total(const T& obj) const
{
    int pret2=0;
    for(int i =0; i<obj.listaArome.size(); i++)
    {
        pret2+=obj.listaArome[i].getPret();
    }
    return pret2;
}

void Gelato::afiseazaTotal() const
{
    float totalpret = total(*this);
    cout << "Total: " << totalpret << endl;
}

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
            this->listaArome.push_back(*(new Aroma<string,float>()));
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
        afiseazaTotal();
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

Gelato::Gelato(string nume, vector<Aroma<string,float>> listaArome, string gust)
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
    InghetataAmbalata(string nume, vector<Aroma<string,float>> listaArome, string gust, string dataexp);
    InghetataAmbalata (const InghetataAmbalata&);

    InghetataAmbalata& operator= (const InghetataAmbalata&);
    istream& citire (istream& in);
    friend istream& operator>>(istream& in, InghetataAmbalata& g);
    friend ostream& operator<<(ostream& os, const InghetataAmbalata& g);
    ostream& afisare (ostream& os) const;

    string getdataexp() {return dataexp;}
    float pret() const {
    float pret = 0;
    for(int i = 0; i < this->listaArome.size(); i++)
        pret += this->listaArome[i].getPret();
    return pret;}

    virtual ~InghetataAmbalata() {}
};

istream& InghetataAmbalata::citire (istream& in){
   Gelato::citire(in);
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

InghetataAmbalata::InghetataAmbalata(string nume, vector<Aroma<string,float>> listaArome, string gust, string dataexp):
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
    InghetataFresh(string nume, vector<Aroma<string,float>> listaArome, string gust, list<Alergeni> listaAlergeni);
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

InghetataFresh::InghetataFresh(string nume, vector<Aroma<string,float>> listaArome, string gust, list<Alergeni> listaAlergeni): Gelato(nume, listaArome,gust)
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

    Cornet(string nume, vector<Aroma<string,float>> listaArome, string gust,list<Alergeni> listaAlergeni, string tipCornet):
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
        this->InghetataFresh::citire(in);
        cout << "Introduceti tipul de cornet(simplu, alune, ciocolata)\n";
        in >> this->tipCornet;
        return in;
    }
    ostream& afisare(ostream& os) const {
        InghetataFresh:afisare(os);
        cout << "Cornet: " << this->tipCornet <<endl;
        return os;
    }

    float pret() const {
    float pret = 0;
    for(int i = 0; i < this->listaArome.size(); i++)
        pret += this->listaArome[i].getPret();
    return pret;}

    template<typename ExceptionType>
    string detalii();

};

template<typename ExceptionType>
string Cornet::detalii()
{
    try
    {
        if (this->tipCornet == "alune")
        {
            cout << endl << "Atentie! Neindicat pentru persoanele alergice la alune." << endl;
        }
        else if (this->tipCornet != "simplu" && this->tipCornet != "ciocolata" )
            throw std::invalid_argument("Ai introdus un tip invalid de cornet.");
    }
    catch (const std::exception& e)
    {
         cout << endl << "A aparut o exceptie: " << e.what() << endl;
    }
    return this->tipCornet;
}

class Pahar:virtual public InghetataFresh{
protected:
    bool lingurita;
public:
    int getLingurita() {return lingurita;}

    Pahar(){
        this->lingurita = 0;
    }

    Pahar(string nume, vector<Aroma<string,float>> listaArome, string gust, list<Alergeni> listaAlergeni, bool lingurita):
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
        this->InghetataFresh::citire(in);
        cout << "Introduceti daca doriti lingurita\n";
        in >> this->lingurita;
        return in;
    }
    ostream& afisare(ostream& os) const {
        InghetataFresh::afisare(os);
        cout << "Lingurita: " << this->lingurita <<endl;
        return os;
    }
    float pret() const {
    float pret = 0;
    for(int i = 0; i < this->listaArome.size(); i++)
        pret += this->listaArome[i].getPret();
    return pret;}
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
    bool operator>(const Gelaterie& g);
    istream& citire(istream& in);
    ostream& afisare(ostream& out) const;
    friend istream& operator>>(istream& in, Gelaterie& g);
    friend ostream& operator<<(ostream& out, const Gelaterie& g);



    pair<string, int> ratingMax() const;

    int getRating() {return this->rating;}

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

bool Gelaterie::operator>(const Gelaterie& g)
{
    if (this->rating>g.rating)
    {
        cout<<"Primul rating este mai mare"<<endl;
        return true;
    }
    return false;
}


pair<string, int> Gelaterie::ratingMax() const
{
     if (listaRatingGelato.empty()) {
        throw runtime_error("Lista de gelato este goală.");
    }

    if (listaRatingGelato.size() == 1) {
        const pair<int, string>& gelatoUnic = *listaRatingGelato.begin();
        return make_pair(gelatoUnic.second, gelatoUnic.first);
    }

    const pair<int, string>* maxRatingPair = nullptr;
    int maxRating = 0;

    for (const auto& gelatoPair : listaRatingGelato) {
        if (gelatoPair.first > maxRating) {
            maxRating = gelatoPair.first;
            maxRatingPair = &gelatoPair;
        }
    }

    if (maxRatingPair == nullptr) {
        throw runtime_error("Nu s-a găsit un rating maxim în lista de gelato.");
    }

    return make_pair(maxRatingPair->second, maxRatingPair->first);
}

istream& Gelaterie::citire(istream& in)
{
    if (this->listaRatingGelato.empty()==0)
        this->listaRatingGelato.clear();
    int p=1;
    while (p!=0)
    {
        string nr;
        cout<<"Introduceti numarul de inghetate pentru care doriti sa lasati un rating."<<endl;
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
            int r;
            in >> r;
            try{
                if (r>=1 and r<=10)
                {
                    p=0;
                    this->rating=r;
                }
                else throw(r);

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

class MeniuInteractiv{
private:
    static MeniuInteractiv* ob;
    int c;

    MeniuInteractiv()
    {
        c=0;
    }
public:
    static MeniuInteractiv* getInstance()
    {
       if (!ob)
           ob = new MeniuInteractiv;
       return ob;
    }



    void meniu()
    {
        vector <Gelato*> listaGelato;
        map <int, Gelaterie> listaRating;
        int i=1;
        int k=1;
        while(k!=0)
        {
            cout << "**************************************************************************************************" << endl;
            cout << "**************************************************************************************************" << endl;
            cout << "                            Bine ati venit la Gelateria noastra!                                   " << endl;
            cout << "**************************************************************************************************" << endl;
            cout << "**************************************************************************************************" << endl;
            cout << "                                                                                                  " << endl;
            cout << "1. Adaugati in inventar" << endl;
            cout << "2. Vizualizarea produselor" << endl;
            cout << "3. Stergeti produsele" << endl;
            cout << "4. Lasati un rating pentru o inghetata" << endl;
            cout << "5. Aflati lista de inghetate cu rating-urile lor" << endl;
            cout << "6. Aflati inghetata cu rating maxim" << endl;
            cout << "7. Parasiti gelateria noastra" << endl;
            int x = 1;
            int optiune;
            cout << endl << "Enter your choice: ";
            while (x != 0)
            {
                int choice;
                cin >> choice;
                try
                {
                    if (choice == 1)
                    {
                        optiune = 1;
                        x = 0;
                    }
                    else if (choice == 2)
                    {
                        optiune = 2;
                        x = 0;
                    }
                    else if (choice == 3)
                    {
                        optiune = 3;
                        x = 0;
                    }
                    else if (choice == 4)
                    {
                        optiune = 4;
                        x = 0;
                    }
                    else if (choice == 5)
                    {
                        optiune = 5;
                        x = 0;
                    }
                    else if (choice == 6)
                    {
                        optiune = 6;
                        x = 0;
                    }
                    else if (choice == 7)
                    {
                        optiune = 7;
                        x = 0;
                    }
                    else
                        throw (choice);
                }
                catch (int y)
                {
                    cout << "Nu ati introdus o valoare buna." << endl;
                }

            }
            switch (optiune)
            {
            case 1:
            {
                int l = 1;
                while (l != 0)
                {
                    cout << "                                                            " << endl;
                    cout << "               Ce doriti sa adaugati in inventar?                      " << endl;
                    cout << "                                                            " << endl;
                    cout << "1. Inghetata Ambalata" << endl;
                    cout << "2. Inghetata Fresh la cornet" << endl;
                    cout << "3. Inghetata Fresh la pahar" << endl;
                    cout << "4. Nu doresc sa adaug nimic" << endl;
                    int x = 1;
                    int optiune2;
                    while (x != 0)
                    {
                        int choice;
                        cin >> choice;
                        try
                        {
                            if (choice == 1)
                            {
                                optiune2 = 1;
                                x = 0;
                            }
                            else if (choice == 2)
                            {
                                optiune2 = 2;
                                x = 0;
                            }
                            else if (choice == 3)
                            {
                                optiune2 = 3;
                                x = 0;
                            }
                            else if (choice == 4)
                            {
                                optiune2 = 4;
                                x = 0;
                            }
                            else
                                throw (choice);
                        }
                        catch (int y)
                        {
                            cout << "Nu ati introdus o valoare buna." << endl;
                        }
                    }
                    switch (optiune2)
                    {
                    case 1:
                    {
                        InghetataAmbalata i;
                        cin >> i;
                        listaGelato.push_back(new Gelato(i));
                        break;
                    }
                    case 2:
                    {
                        Cornet i;
                        cin >> i;
                        listaGelato.push_back(new Gelato(i));

                        // Downcasting
                        Cornet* cornetPtr = dynamic_cast<Cornet*>(&i);
                        if (cornetPtr != nullptr)
                            {
                                // Downcasting successful
                                cornetPtr->detalii<std::string>();
                            }
                        break;
                    }
                    case 3:
                    {
                        Pahar i;
                        cin >> i;
                        listaGelato.push_back(new Gelato(i));
                        break;
                    }
                    case 4:
                    {
                        l = 0;
                        break;
                    }
                    }
                }
                break;

            }
            case 2:
                {
                    for (int i=0; i<listaGelato.size();i++)
                            {
                                cout<<*listaGelato[i]<<endl;
                            }
                            break;
                }
            case 3:
                {
                    while (!listaGelato.empty())
                                listaGelato.pop_back();
                            break;
                }
            case 4:
                {
                     Gelaterie g;
                     cin >> g;
                     listaRating.insert(pair<int,Gelaterie> (i++,g));


                     break;
                }
            case 5:
                {
                    map<int,Gelaterie>::iterator it;
                    for(it=listaRating.begin(); it!=listaRating.end(); it++)
                    {
                        cout<<it->second<<endl;
                    }
                    break;
                }
            case 6:
                {
                    Gelaterie g;
                    try
                    {
                        pair<string, int> maxRating;
                        bool isFirstRating = true;

                        for (const auto& entry : listaRating)
                        {
                            const Gelaterie& g = entry.second;

                            pair<string, int> rating = g.ratingMax();

                            if (isFirstRating || rating.second > maxRating.second)
                            {
                                maxRating = rating;
                                isFirstRating = false;
                            }
                        }

                        if (isFirstRating)
                        {
                            throw runtime_error("Nu există nicio inghetată în lista de rating.");
                        }

                        cout << "Inghetata cu rating-ul maxim este: " << endl;
                        cout << "Nume: " << maxRating.first << endl;
                        cout << "Rating: " << maxRating.second << endl;
                    }
                    catch (const runtime_error& error)
                    {
                        cout << "Eroare: " << error.what() << endl;
                    }
                    break;
                }
            case 7:
                {
                    k = 0;
                    break;
                }
            }
        }
    }
};

MeniuInteractiv* MeniuInteractiv::ob = 0;
int main()
{
    MeniuInteractiv* meniu;
    if(meniu == NULL)
        throw runtime_error("Eroare");
    meniu = meniu->getInstance();
    meniu->meniu();
    return 0;
}
