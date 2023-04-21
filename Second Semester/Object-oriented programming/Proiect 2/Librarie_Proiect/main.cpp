#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <list>
using namespace std;


class IOinterface{
public:
    virtual istream& citire(istream&) = 0;
    virtual ostream& afisare(ostream&) const = 0;
};

class Carti:public IOinterface
{
protected:
    string titluCarte;
    string autorCarte;
    float pret;

public:

    //Constructori
    Carti();
    Carti(string titluCarte, string autorCarte, float pret); // Constructor parametrizat
    Carti(const Carti& );

    //Operator
    Carti& operator = (const Carti&);
    friend ostream& operator <<(ostream&, const Carti& );
    friend istream& operator >>(istream&, Carti& );



    //Get+Set
    string getTitluCarte() { return titluCarte; }
    void setTitluCarte(string titlu) { titluCarte = titlu; }

    string getAutorCarte() { return autorCarte; }
    void setAutorCarte(string autor) { autorCarte = autor; }

    double getPret() { return pret; }
    void setPret(double pret) { this->pret = pret; }
    bool operator==(const Carti&);
    ostream& afisare (ostream& out) const
    {
    out << "Titlu carte: " << this->titluCarte << endl;
    out << "Autor carte: " << this->autorCarte << endl;
    out << "Pretul cartii: " << this->pret << " lei"<<endl;
    return out;
    }

   istream& citire (istream& in)
    {
    cout << "Introduceti titlul cartii: " << endl;
    in >> titluCarte;
    cout << "Introduceti autorul cartii: " << endl;
    in >> autorCarte;
    cout << "Introduceti pretul cartii: " << endl;
    in >> this->pret;

    return in;
    }

   // string getTitluCarte() {return this->titluCarte;}
    //string getTAutorCarte() {return this->autorCarte;}

    virtual ~Carti() {}

};
bool Carti::operator==(const Carti& obj){
    return this->titluCarte == obj.titluCarte;
    return this->autorCarte == obj.autorCarte;
}

class CarteStraina: virtual public Carti{
protected:
    string limba;
public:
    CarteStraina();
    CarteStraina(string titluCarte, string autorCarte, float pret, string limba);
    CarteStraina(const CarteStraina&);

    CarteStraina& operator =(const CarteStraina&);

    istream& citire(istream& in){
        this->Carti::citire(in);
        cout << "Introduceti in ce limba este cartea\n";
        in >> this->limba;
        return in;
    }

    ostream& afisare(ostream& out) const {
        this->Carti::afisare(out);
        cout << "Limba cartii: " << this->limba <<endl;
        return out;
    }
    virtual ~CarteStraina() {}

};


class CarteRomana: virtual public Carti{
protected:
    bool bac;
public:
    CarteRomana();
    CarteRomana(string titluCarte, string autorCarte, float pret, bool bac);
    CarteRomana(const CarteRomana&);

    CarteRomana& operator =(const CarteRomana&);
    bool getBac() {return bac;}

    istream& citire(istream& in){
        this->Carti::citire(in);
        cout << "Introduceti daca cartea este in programa de bac\n";
        in >> this->bac;
        return in;
    }

    ostream& afisare(ostream& out) const {
        this->Carti::afisare(out);
        cout << "Exista cartea in programa de bac: " << this->bac << endl;
        return out;
    }
    virtual ~CarteRomana() {}

};

istream& operator >>(istream& in, Carti& obj){
    return obj.citire(in);
}

ostream& operator <<(ostream& out, const Carti& obj){
    return obj.afisare(out);
}

Carti::Carti()
{
    titluCarte= "Anonim";
    autorCarte = "Anonim";
    pret = 0;

}

Carti::Carti(string titluCarte,string autorCarte, float pret)
{
    this->titluCarte= titluCarte;
    this->autorCarte= autorCarte;
    this->pret = pret;
}

Carti::Carti(const Carti& obj)
{
    this->titluCarte= obj.titluCarte;
    this->autorCarte= obj.autorCarte;
    this->pret = obj.pret;
}

Carti& Carti::operator = (const Carti& obj)
{
    if(this != &obj)
    {
        this->titluCarte= obj.titluCarte;
        this->autorCarte= obj.autorCarte;
        this->pret = obj.pret;
    }
    return *this;
}


CarteStraina::CarteStraina(): Carti(){
    this->limba = "-";
}

CarteStraina::CarteStraina(string titluCarte, string autorCarte, float pret, string limba):
    Carti(titluCarte, autorCarte, pret){
    this->limba = limba;
}

CarteStraina::CarteStraina(const CarteStraina& obj): Carti(obj){
    this->limba = obj.limba;
}

CarteStraina& CarteStraina::operator =(const CarteStraina& obj){
    if(this != &obj){
        Carti::operator=(obj);
        this->limba = obj.limba;
    }
    return *this;
}

CarteRomana::CarteRomana(): Carti(){
    this->bac = 0;
}

CarteRomana::CarteRomana(string titluCarte, string autorCarte, float pret, bool bac):
    Carti(titluCarte, autorCarte, pret){
    this->bac = bac;
}

CarteRomana::CarteRomana(const CarteRomana& obj): Carti(obj){
    this->bac = obj.bac;
}

CarteRomana& CarteRomana::operator =(const CarteRomana& obj){
    if(this != &obj){
        Carti::operator=(obj);
        this->bac = obj.bac;
    }
    return *this;
}

class Audiobook: public CarteStraina, public CarteRomana {
    int nrDiscuri;
public:

    int getnrDiscuri() {return nrDiscuri;}
    Audiobook(){
        this->nrDiscuri = 0;
    }

    Audiobook(string titluCarte,string autorCarte, float pret, int nrDiscuri):
        Carti(titluCarte, autorCarte, pret), CarteStraina(titluCarte, autorCarte, pret, limba),
        CarteRomana(titluCarte, autorCarte, pret, bac){
        this->nrDiscuri = nrDiscuri;
    }

    Audiobook(const Audiobook& obj): Carti(obj), CarteStraina(obj), CarteRomana(obj){
        this->nrDiscuri = obj.nrDiscuri;
    }

    Audiobook& operator =(const Audiobook& obj){
        if(this != &obj){
            CarteStraina::operator=(obj);
            CarteRomana::operator=(obj);
            this->nrDiscuri = obj.nrDiscuri;
        }
        return *this;
    }

    istream& citire(istream& in) {
        this->Carti::citire(in);
        cout << "Introduceti in ce limba este cartea\n";
        in >> this->limba;
        cout << "Introduceti daca cartea este in programa de bac\n";
        in >> this->bac;
        cout << "Introduceti numarul de discuri\n";
        in >> this->nrDiscuri;
        return in;
    }
    ostream& afisare(ostream& out) const {
        Carti::afisare(out);
        cout << "Limba cartii: " << this->limba <<endl;
        cout << "Exista cartea in programa de bac: " << this->bac << endl;
        cout << "Numar de discuri: " << this->nrDiscuri << endl;
        return out;
    }


    void fAudiobook() {}

    virtual ~Audiobook() {}
};


class ItemInventar{
    Carti* carte;
    bool stoc;
public:
    Carti* getCarte() const { return carte; }
    void setCarte(Carti* carte) { this->carte = carte; }
    bool getStoc() const { return stoc; }
    void setStoc(bool stoc) { this->stoc = stoc; }
    friend istream& operator >>(istream& in, ItemInventar& obj){
        cout << "1. Carte Straina\n";
        cout << "2. Carte Romana\n";
        cout << "3. Audiobook\n";
        int k;
        cin >> k;
        if(k == 1){
            obj.carte = new CarteStraina();
        }
        if(k == 2){
            obj.carte = new CarteRomana();
        }
        if(k == 3)
            obj.carte = new Audiobook();
        in >> *obj.carte;
        cout << "Introduceti daca este in stoc\n";
        in >> obj.stoc;
        return in;
    }

    friend ostream& operator<<(ostream& os, const ItemInventar& obj){
        os << "\nCarte:\n " << *obj.carte ;
        os << "Stoc: " << obj.stoc << endl;
        return os;
    }
    ItemInventar() : carte(nullptr), stoc(false) {}
    ItemInventar(const Carti* _carte) : carte(const_cast<Carti*>(_carte)), stoc(false) {}


};

class Librarie{
    list<ItemInventar> inventar;
public:
    void addInventar();
    void addInventar1(const vector<CarteStraina>& listaCartiStraine);
    void addInventar2(const vector<CarteRomana>& listaCartiRomane);
    void addInventar3(const vector<Carti>& listaAudiobooks);
    void showInventar();
    void showInventar1(const vector<CarteStraina>& listaCartiStraine);
    void showInventar2(const vector<CarteRomana>& listaCartiRomane);
    void showInventar3(const vector<Carti>& listaAudiobooks);
    void addCartiStraine(vector<CarteStraina>& listaCartiStraine);
    void addCartiRomane( vector<CarteRomana>& listaCartiRomane);
    void addAudiobooks(vector<Carti>& listaAudiobooks);
};

void Librarie::showInventar() {
     for (auto it = inventar.begin(); it != inventar.end(); it++)
        cout << "\nItemInventar\n" << "Carte:\n " << *(it->getCarte()) << "Stoc: " << it->getStoc() << endl;
}

void Librarie::showInventar1(const vector<CarteStraina>& listaCartiStraine) {
    for (const auto& carte : listaCartiStraine)
        cout << carte << endl;
}

void Librarie::showInventar2(const vector<CarteRomana>& listaCartiRomane) {
    for (const auto& carte : listaCartiRomane)
        cout << carte << endl;
}

void Librarie::showInventar3(const vector<Carti>& listaAudiobooks) {
    for (const auto& carte : listaAudiobooks)
        cout << carte << endl;
}

void Librarie::addInventar(){
    ItemInventar i;
    cin >> i;
    inventar.push_back(i);
}

void Librarie::addInventar1(const vector<CarteStraina>& listaCartiStraine) {
     for (const auto& carte : listaCartiStraine) {
        bool existaInventar = false;
        for (const auto& item : inventar) {
            if (item.getCarte() == &carte) { // Verifica daca carte exista deja in inventar
                existaInventar = true;
                break;
            }
        }
        if (!existaInventar) { // Daca carte nu exista in inventar, o adauga
            ItemInventar item(&carte);
            item.setStoc(true);
            inventar.push_back(item);
        }
    }
}


void Librarie::addInventar2(const vector<CarteRomana>& listaCartiRomane) {
    for (const auto& carte : listaCartiRomane) {
        bool existaInventar = false;
        for (const auto& item : inventar) {
            if (item.getCarte() == &carte) { // Verifica daca carte exista deja in inventar
                existaInventar = true;
                break;
            }
        }
        if (!existaInventar) { // Daca carte nu exista in inventar, o adauga
            ItemInventar item(&carte);
            item.setStoc(true);
            inventar.push_back(item);
        }
    }
}

void Librarie::addInventar3(const vector<Carti>& listaAudiobooks) {
    for (const auto& carte : listaAudiobooks) {
        bool existaInventar = false;
        for (const auto& item : inventar) {
            if (item.getCarte() == &carte) { // Verifica daca carte exista deja in inventar
                existaInventar = true;
                break;
            }
        }
        if (!existaInventar) { // Daca carte nu exista in inventar, o adauga
            ItemInventar item(&carte);
            item.setStoc(true);
            inventar.push_back(item);
        }
    }
}
void Librarie::addCartiStraine(vector<CarteStraina>& listaCartiStraine){
    CarteStraina i;
    cin>>i;
    listaCartiStraine.push_back(i);

}

void Librarie::addCartiRomane(vector<CarteRomana>& listaCartiRomane){
    CarteRomana i;
    cin>>i;
    listaCartiRomane.push_back(i);
}

void Librarie::addAudiobooks(vector<Carti>& listaAudiobooks){
    Audiobook i;
    cin>>i;
    listaAudiobooks.push_back(i);
}

vector<CarteStraina> citesteCartiStraine(string numeFisier) {
    vector<CarteStraina> listaCartiStraine;
    list<ItemInventar> inventar;
    int nr;
    ifstream f("CartiStraine.in");

    if (f.is_open()) {
        string titlu, autor, limba;
        float pret;
        f>>nr;
        f.ignore();
        for(int i=0;i<nr;i++)
        {
            getline(f, titlu);
            getline(f, autor);
            getline(f, limba);
            f >> pret;
            f.ignore();
            //Carti carte(titlu, autor, pret);
            //listaCartiStraine.push_back(carte);
            CarteStraina* carte = new CarteStraina(titlu, autor, pret, limba);
            listaCartiStraine.push_back(*carte);
        }
        f.close();
    } else {
        cout << "Eroare la deschiderea fisierului!" << endl;
    }

    return listaCartiStraine;
}
vector<CarteRomana> citesteCartiRomane(string numeFisier) {
    vector<CarteRomana> listaCartiRomane;
    list<ItemInventar> inventar;
    int nr;
    ifstream f("CartiRomane.in");

    if (f.is_open()) {
        string titlu, autor;
        float pret;bool bac;
        f>>nr;
        f.ignore();
        for(int i=0;i<nr;i++)
        {
            getline(f, titlu);
            getline(f, autor);
            f >> pret;
            f.ignore();
            f >> bac;
            f.ignore();
            CarteRomana* carte = new CarteRomana(titlu, autor, pret, bac);
            listaCartiRomane.push_back(*carte);
        }
        f.close();
    } else {
        cout << "Eroare la deschiderea fisierului!" << endl;
    }

    return listaCartiRomane;
}

vector<Carti> citesteAudiobooks(string numeFisier) {
    vector<Carti> listaAudiobooks;
    //vector<Audiobook> listaAudiobooks;
    int nr;
    ifstream f("Audiobooks.in");

    if (f.is_open()) {
        string titlu, autor;
        float pret;//bool cadou;int nrDiscuri;
        f>>nr;
        f.ignore();
        for(int i=0;i<nr;i++)
        {
            getline(f, titlu);
            getline(f, autor);
            f >> pret;
            f.ignore();
            Carti carte(titlu, autor, pret);
            listaAudiobooks.push_back(carte);
            //Audiobook* carte = new Audiobook(titlu, autor, pret, cadou, nrDiscuri);
            //listaAudiobooks.push_back(*carte);
        }
        f.close();
    } else {
        cout << "Eroare la deschiderea fisierului!" << endl;
    }

    return listaAudiobooks;
}
//////////////////////////////////////////////
int main()
{
    Librarie b;

    Carti* p = new Audiobook();
    dynamic_cast<Audiobook*>(p)->fAudiobook();

    vector<CarteStraina> listaCartiStraine = citesteCartiStraine("CartiStraine.in");
    vector<CarteRomana> listaCartiRomane = citesteCartiRomane("CartiRomane.in");
    vector<Carti> listaAudiobooks = citesteAudiobooks("Audiobooks.in");
    b.addInventar1(listaCartiStraine);
    b.addInventar2(listaCartiRomane);
    b.addInventar3(listaAudiobooks);

    int choice;
    cout<<endl<<endl<<endl<<endl;
    do
    {
        cout << "**************************************************************************************************" << endl;
        cout << "**************************************************************************************************" << endl;
        cout << "                            Bine ati venit la libraria noastra!                                   " << endl;
        cout << "**************************************************************************************************" << endl;
        cout << "**************************************************************************************************" << endl;
        cout << "                                                                                                  " << endl;
        cout << "1. Sunt un angajat" << endl;
        cout << "2. Sunt un client" << endl;
        cout << "3. Parasiti libraria noastra" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            do
            {
                    cout << "                                                            " << endl;
                    cout << "1. Inventarul pentru Carti Straine" << endl;
                    cout << "2. Inventarul pentru Carti Romane" << endl;
                    cout << "3. Inventarul pentru Audiobooks" << endl;
                    cout << "4. Inventarul total" << endl;
                    cout << "5. Parasiti inventarul" << endl;
                    cout << endl << "Enter your choice: ";
                    cin >> choice;
                    cout << endl;
                switch(choice)
                {
                case 1:
                {
                    do{
                    cout << "1. Add inventar\n";
                    cout << "2. Show inventar\n";
                    cout << "3. Stop\n";
                    cin >> choice;
                    cout<<endl;
                    switch(choice)
                    {

                    case 1:
                        {
                            b.addCartiStraine(listaCartiStraine);
                            break;
                        }
                    case 2:
                        {
                            b.showInventar1(listaCartiStraine);
                            break;
                        }
                    case 3:
                        {
                            break;
                        }
                    }

                    }while(choice!=3);
                    break;
                }

                case 2:
                {
                    do{
                    cout << "1. Add inventar\n";
                    cout << "2. Show inventar\n";
                    cout << "3. Stop\n";
                    cin >> choice;
                    cout<<endl;
                    switch(choice)
                    {

                    case 1:
                        {
                           b.addCartiRomane(listaCartiRomane);
                            break;
                        }
                    case 2:
                        {
                            b.showInventar2(listaCartiRomane);
                            break;
                        }
                    case 3:
                        {
                            break;
                        }
                    }

                    }while(choice!=3);
                    break;
                }
                case 3:
                {
                    do{
                    cout << "1. Add inventar\n";
                    cout << "2. Show inventar\n";
                    cout << "3. Stop\n";
                    cin >> choice;
                    cout<<endl;
                    switch(choice)
                    {
                        b.addInventar3(listaAudiobooks);
                    case 1:
                        {
                            b.addAudiobooks(listaAudiobooks);
                            break;
                        }
                    case 2:
                        {
                            b.showInventar3(listaAudiobooks);
                            break;
                        }
                    case 3:
                        {
                            break;
                        }
                    }

                    }while(choice!=3);
                    break;
                }
                    case 4:
                        {
                            b.addInventar1(listaCartiStraine);
                            b.addInventar2(listaCartiRomane);
                            b.addInventar3(listaAudiobooks);
                            b.showInventar();
                            break;
                        }
                    case 5:
                        {
                            break;
                        }
                }
            }while(choice!=5);
            break;
        }

        case 2:
        {
            do{
            cout << "                                                            " << endl;
            cout << "               Ce doriti sa cumparati?                      " << endl;
            cout << "                                                            " << endl;
            cout << "1. Carte Straina" << endl;
            cout << "2. Carte Romana" << endl;
            cout << "3. Audiobook" << endl;
            cout << "4. Nu doresc sa cumpar nimic" << endl;
            cout << endl << "Enter your choice: ";
            cin >> choice;
            cout << endl;

            switch(choice)
            {
            case 1:
            {
                cout << "                       Avem urmatoarele carti de autori straini pe stoc:                  "<<endl<<endl;
                //vector<CarteStraina> listaCartiStraine = citesteCartiStraine("CartiStraine.in");
                for (int i = 0; i < listaCartiStraine.size(); i++)
                {
                    CarteStraina carte = listaCartiStraine[i];
                    cout << "                     "<<i+1<<".  "<< carte.getTitluCarte() << " scrisa de " << carte.getAutorCarte() << " la pretul de " << carte.getPret() <<" lei"<<endl<< endl;

                }

                break;
            }
            case 2:
            {
                cout << "                       Avem urmatoarele carti de autori romani pe stoc:                  "<<endl<<endl;
                //vector<CarteRomana> listaCartiRomane = citesteCartiRomane("CartiRomane.in");
                for (int i = 0; i < listaCartiRomane.size(); i++)
                {
                    CarteRomana carte = listaCartiRomane[i];
                    if(carte.getBac() == true)
                        cout << "                     "<<i+1<<".  "<< carte.getTitluCarte() << " scrisa de " << carte.getAutorCarte() << " la pretul de " << carte.getPret() <<" lei (de bac)"<< endl<<endl;
                    else
                        cout << "                     "<<i+1<<".  "<< carte.getTitluCarte() << " scrisa de " << carte.getAutorCarte() << " la pretul de " << carte.getPret() <<" lei "<< endl<<endl;

                }
                cout<<endl<<endl;
                cout<< "**************************** Pentru cartile din programa de bac, avem o reducere de 20% cu ocazia Pastelui!  **************" << endl<<endl;
                cout<< "                       Doriti sa vedeti pretul redus pentru cartile respective?        " << endl<<endl<<endl;
                cin>>choice;
                float pretnou;
                if(choice==1)
                    for (int i = 0; i < listaCartiRomane.size(); i++)
                {
                    CarteRomana carte = listaCartiRomane[i];
                                if(carte.getBac() == true)
                                {
                                    pretnou=0.8*carte.getPret();
                                    cout << "                     "<< carte.getTitluCarte() << " scrisa de " << carte.getAutorCarte() << " la pretul de " << pretnou <<" lei"<< endl<<endl;
                                }

                }
                break;
            }
            case 3:
            {
                cout << "                       Avem urmatoarele carti in format audiobook:                  "<<endl<<endl;
                //vector<Carti> listaAudiobooks = citesteAudiobooks("Audiobooks.in");
                for (int i = 0; i < listaAudiobooks.size(); i++)
                {
                    Carti carte = listaAudiobooks[i];
                    cout << "                     "<<i+1<<".  "<< carte.getTitluCarte() << " scrisa de " << carte.getAutorCarte() << " la pretul de " << carte.getPret() <<" lei "<< endl<<endl;

                }

                break;
            }
            case 4:
            {
                cout<<"La revedere! Ne bucuram ca ne-ati vizitat!"<<endl;
                break;
            }
            }
        }while (choice!=4);
        break;
        }
        case 3:
        {
            cout<<"La revedere! Ne bucuram ca ne-ati vizitat!"<<endl;
            break;
        }
        }
    }
    while (choice!=3);

    return 0;
}
