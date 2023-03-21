#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
/////////////////////////////////////////////////////
class Clienti
{
private:
    static int contorIdClient;
    const int idClient;
    float buget;
    int nrVouchere;
    float* voucher;
    string preferinta;

public:
    //Constructori
    Clienti();  // Constructor fara parametrii
    Clienti(float buget,int nrVouchere, float* voucher, string preferinta); // Constructor parametrizat
    Clienti(const Clienti& obj);   // Copy constructor

    //Operator
    Clienti& operator = (const Clienti&);
    friend ostream& operator <<(ostream& out, const Clienti& obj);
    friend istream& operator >>(istream& in, Clienti& obj);
    Clienti& operator++();
    Clienti operator++(int);
    Clienti operator+(const Clienti& obj);
    Clienti operator+(int);
    friend Clienti operator+(int, Clienti obj);
    bool operator==(const Clienti&);
    float operator[](int);
    operator int();
    operator int() const {return this->nrVouchere;}

    //Get+Set
    static int getcontorIdClient(){return Clienti::contorIdClient;}
    const int getidClient(){return Clienti::idClient;}
    float getbuget(){return buget;}
    int getnrVouchere(){return nrVouchere;}
    string getpreferinta(){return preferinta;}
    const float* getvoucher() const {return this->voucher;}

    //Destructor
    ~Clienti();

};
int Clienti::contorIdClient = 100;

Clienti::Clienti():idClient(contorIdClient++)
{
    buget=0;
    voucher=NULL;
    nrVouchere=0;
    preferinta="Anonim";  // Initializam variabila
}
Clienti::Clienti(float buget,int nrVouchere,float* voucher, string preferinta):idClient(contorIdClient++)
{
    this->buget=buget;
    this->voucher=new float[nrVouchere];
    this->nrVouchere=nrVouchere;
    for (int i = 0; i < nrVouchere; i++) {
        this->voucher[i] = voucher[i];
    }
    this->preferinta=preferinta;
}
Clienti::Clienti(const Clienti& obj): idClient(contorIdClient++)
{
    this->buget=obj.buget;
    this->voucher=obj.voucher;
    this->nrVouchere=obj.nrVouchere;
    for (int i = 0; i < nrVouchere; i++) {
        this->voucher[i] = obj.voucher[i];
    }
    this->preferinta=obj.preferinta;
}
Clienti& Clienti::operator=(const Clienti& obj)
{
    if(this!=&obj)
    {
        if(this->voucher!=NULL)
        {
            delete[] this->voucher;
            this->voucher=NULL;
        }

        this->buget=obj.buget;
        this->voucher=new float[obj.nrVouchere];
        this->preferinta=obj.preferinta;
    }
    return *this;
}
Clienti& Clienti::operator++(){
    this->nrVouchere++;
    return *this;
}

Clienti Clienti::operator++(int){
    Clienti aux(*this);
    ++*this;
    return aux;
}

Clienti Clienti::operator+(const Clienti& obj){
    Clienti aux(*this);
    aux.preferinta += obj.preferinta;
    aux.nrVouchere += obj.nrVouchere;
    return aux;
}

Clienti Clienti::operator+(int x){
    Clienti aux(*this);
    aux.nrVouchere += x;
    return aux;
}

Clienti operator+(int x, Clienti obj){
    return obj+x;
}

bool Clienti::operator==(const Clienti& obj){
    return this->preferinta == obj.preferinta;
}

float Clienti::operator[](int i){
    if(this->voucher == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > this->nrVouchere){
        throw runtime_error("Index invalid");
    }
    else
        return this->voucher[i];
}

Clienti::operator int(){
    return this->nrVouchere;
}
ostream& operator <<(ostream& out,const Clienti& obj)
{
    out<<"ID Client: "<<obj.idClient<<endl;
    out<<"Buget Client: "<<obj.buget<<" lei"<<endl;
    out<<"Numar de vouchere: "<<obj.nrVouchere<<endl;
    out<<"Voucherele: ";
    for(int i = 0; i < obj.nrVouchere; i++)
        out << obj.voucher[i] << " ";
    out << endl;
    //out<<"Preferinta categorie: "<<obj.preferinta<<endl;
    return out;
}
istream& operator >>(istream& in, Clienti& obj)
{
    cout<<"Introduceti bugetul clientului: ";
    in>>obj.buget;
    cout<<"lei"<<endl;

    cout<<"Introduceti numarul de vouchere ale clientului: "<<endl;
    in>>obj.nrVouchere;

    cout<<"Introduceti voucherele clientului: "<<endl;
    if(obj.voucher != NULL)
    {
        delete[] obj.voucher;
        obj.voucher = NULL;
    }
    obj.voucher = new float[obj.nrVouchere];
    for(int i=0;i<obj.nrVouchere;i++)
        in>>obj.voucher[i];

   // cout<<"Introduceti preferinta clientului: "<<endl;
    //in>>obj.preferinta;

    return in;
}

Clienti::~Clienti()
{
    if(this->voucher != NULL)
    {
        delete[] this->voucher;
        this->voucher = NULL;
    }
}


////////////////////////////////////////////////



class Carti
{
private:
    static int contorIdCarte;
    const int idCarte;
    char* titluCarte;
    char* autorCarte;
    char categorieCarte;
    int pretCarte;
    bool stocCarte;
    int inventarCarte;

public:
    //Constructori
    Carti();  // Constructor fara parametrii
    Carti(char* titluCarte, char* autorCarte, char categorieCarte, int pretCarte, bool stocCarte, int inventarCarte); // Constructor parametrizat
    Carti(const Carti& obj);   // Copy constructor

    //Operator
    Carti& operator = (const Carti&);
    friend ostream& operator <<(ostream& out, const Carti& obj);
    friend istream& operator >>(istream& in, Carti& obj);
    Carti& operator++();
    Carti operator++(int);
    Carti operator+(const Carti& obj);
    Carti operator+(int);
    friend Carti operator+(int, Carti obj);
    bool operator==(const Carti&);
    char operator[](int);
    operator int();
    operator int() const {return this->inventarCarte;}


    //Get+Set
    static int getcontorIdCarte(){return Carti::contorIdCarte;}
    const char getcategorieCarte()const{return categorieCarte;}
    const int getpretCarte()const{return pretCarte;}
    const bool getstocCarte()const{return stocCarte;}
    const int getinventarCarte()const{return inventarCarte;}
    const char* getTitluCarte() const {return titluCarte;}



    //Destructor
    ~Carti();

};

int Carti::contorIdCarte = 1000;

Carti::Carti():idCarte(contorIdCarte++)
{
    titluCarte = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(titluCarte, "Anonim");  // Initializam variabila
    autorCarte = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(autorCarte, "Anonim");  // Initializam variabila
    categorieCarte = '-';
    pretCarte = 0;
    stocCarte = false;
    inventarCarte=0;
}

Carti::Carti(char* titluCarte,char* autorCarte,char categorieCarte, int pretCarte, bool stocCarte, int inventarCarte): idCarte(contorIdCarte++)
{
    this->titluCarte = new char[strlen(titluCarte) + 1];
    strcpy(this->titluCarte, titluCarte);
    this->autorCarte = new char[strlen(autorCarte) + 1];
    strcpy(this->autorCarte, autorCarte);
    this->categorieCarte = categorieCarte;
    this->pretCarte = pretCarte;
    this->stocCarte = stocCarte;
    this->inventarCarte=inventarCarte;
}

Carti::Carti(const Carti& obj): idCarte(contorIdCarte++)
{
    this->titluCarte = new char[strlen(obj.titluCarte) + 1];
    strcpy(this->titluCarte, obj.titluCarte);
    this->autorCarte = new char[strlen(obj.autorCarte) + 1];
    strcpy(this->autorCarte, obj.autorCarte);
    this->categorieCarte = obj.categorieCarte;
    this->pretCarte = obj.pretCarte;
    this->stocCarte = obj.stocCarte;
    this->inventarCarte=obj.inventarCarte;
}

Carti& Carti::operator = (const Carti& obj)
{
    if(this != &obj)
    {
        if(this->titluCarte != NULL)
        {
            delete[] this->titluCarte;
            this->titluCarte = NULL;
        }

        if(this->autorCarte != NULL)
        {
            delete[] this->autorCarte;
            this->autorCarte = NULL;
        }

        this->titluCarte = new char[strlen(obj.titluCarte) + 1];
        strcpy(this->titluCarte, obj.titluCarte);
        this->autorCarte = new char[strlen(obj.autorCarte) + 1];
        strcpy(this->autorCarte, obj.autorCarte);
        this->categorieCarte = obj.categorieCarte;
        this->pretCarte = obj.pretCarte;
        this->stocCarte = obj.stocCarte;
        this->inventarCarte=obj.inventarCarte;
    }
    return *this;
}
Carti& Carti::operator++(){
    this->inventarCarte++;
    return *this;
}

Carti Carti::operator++(int){
    Carti aux(*this);
    ++*this;
    return aux;
}

Carti Carti::operator+(const Carti& obj){
    Carti aux(*this);
    aux.categorieCarte += obj.categorieCarte;
    aux.inventarCarte += obj.inventarCarte;
    return aux;
}

Carti Carti::operator+(int x){
    Carti aux(*this);
    aux.inventarCarte += x;
    return aux;
}

Carti operator+(int x, Carti obj){
    return obj+x;
}

bool Carti::operator==(const Carti& obj){
    return this->inventarCarte == obj.inventarCarte;
}

char Carti::operator[](int i){
    if(this->titluCarte == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > strlen(this->titluCarte)){
        throw runtime_error("Index invalid");
    }
    else
        return this->titluCarte[i];

    if(this->autorCarte == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > strlen(this->autorCarte)){
        throw runtime_error("Index invalid");
    }
    else
        return this->autorCarte[i];
}

Carti::operator int(){
    return this->inventarCarte;
}

ostream& operator <<(ostream& out, const Carti& obj)
{
    out << "ID: " << obj.idCarte << endl;
    out << "Titlu carte: " << obj.titluCarte << endl;
    out << "Autor carte: " << obj.autorCarte << endl;
    out << "Categorie: " << obj.categorieCarte << endl;
    out << "Pretul cartii: " << obj.pretCarte << " lei"<<endl;
    out << "Valabilitatea in stoc a cartii: " << obj.stocCarte << endl;
    out << "Inventarul cartii: " << obj.inventarCarte<<endl;
    return out;
}

istream& operator >>(istream& in, Carti& obj)
{
    cout << "Introduceti titlul cartii: " << endl;
    char titluCarte[100];
    in >> titluCarte;
    if(obj.titluCarte != NULL)
    {
        delete obj.titluCarte;
        obj.titluCarte = NULL;
    }
    obj.titluCarte = new char[strlen(titluCarte) + 1];
    strcpy(obj.titluCarte, titluCarte);

    cout << "Introduceti autorul cartii: " << endl;
    char autorCarte[100];
    in >> autorCarte;
    if(obj.autorCarte != NULL)
    {
        delete obj.autorCarte;
        obj.autorCarte = NULL;
    }
    obj.autorCarte = new char[strlen(autorCarte) + 1];
    strcpy(obj.autorCarte, autorCarte);


    cout << "Introduceti categoria cartii: " << endl;
    in >> obj.categorieCarte;

    cout << "Introduceti pretul cartii: " << endl;
    in >> obj.pretCarte;

    cout << "Introduceti daca e valabila cartea: " << endl;
    in >> obj.stocCarte;

    cout << "Introduceti inventarul cartii: " << endl;
    in >> obj.inventarCarte;
    return in;
}

Carti::~Carti()
{
    if(this->titluCarte != NULL)
    {
        delete[] this->titluCarte;
        this->titluCarte = NULL;
    }

    if(this->autorCarte != NULL)
    {
        delete[] this->autorCarte;
        this->autorCarte = NULL;
    }
}
/////////////////////////////////////////////////////////////////

class Boardgames
{
 private:
    static int contorIdJoc;
    const int idJoc;
    char* numeJoc;
    int categorieVarsta;
    int pretJoc;
    bool stocJoc;
    int inventarJoc;

 public:
    //Constructori
    Boardgames();  // Constructor fara parametrii
    Boardgames(char* numeJoc, int categorieVarsta, int pretJoc, int stocJoc, int inventarJoc); // Constructor parametrizat
    Boardgames(const Boardgames& obj);   // Copy constructor

    //Operator
    Boardgames& operator = (const Boardgames&);
    friend ostream& operator <<(ostream& out, const Boardgames& obj);
    friend istream& operator >>(istream& in, Boardgames& obj);
    Boardgames& operator++();
    Boardgames operator++(int);
    Boardgames operator+(const Boardgames& obj);
    Boardgames operator+(int);
    friend Boardgames operator+(int, Boardgames obj);
    bool operator==(const Boardgames&);
    char operator[](int);
    operator int();
    operator int() const {return this->inventarJoc;}


    //Get+Set
    static int getcontorIdJoc(){return Boardgames::contorIdJoc;}
    const int getcategorieVarsta()const{return categorieVarsta;}
    const int getpretJoc()const{return pretJoc;}
    const bool getstocJoc()const{return stocJoc;}
    const int getinventarJoc()const{return inventarJoc;}
    const char* getNumeJoc() const {return numeJoc;}

    //Destructor
    ~Boardgames();
};
int Boardgames::contorIdJoc = 2000;

Boardgames::Boardgames():idJoc(contorIdJoc++)
{
    numeJoc = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(numeJoc, "Anonim");  // Initializam variabila
    categorieVarsta=0;
    pretJoc = 0;
    stocJoc = false;
    inventarJoc=0;
}
Boardgames::Boardgames(char* numeJoc,int categorieVarsta, int pretJoc, int stocJoc, int inventarJoc):idJoc(contorIdJoc++)
{
    this->numeJoc = new char[strlen(numeJoc) + 1];
    strcpy(this->numeJoc, numeJoc);
    this->categorieVarsta=categorieVarsta;
    this->pretJoc=pretJoc;
    this->stocJoc=stocJoc;
    this->inventarJoc=inventarJoc;
}
Boardgames::Boardgames(const Boardgames& obj): idJoc(contorIdJoc++)
{
    this->numeJoc = new char[strlen(obj.numeJoc) + 1];
    strcpy(this->numeJoc, obj.numeJoc);
    this->categorieVarsta=obj.categorieVarsta;
    this->pretJoc=obj.pretJoc;
    this->stocJoc=obj.stocJoc;
    this->inventarJoc=obj.inventarJoc;

}
Boardgames& Boardgames::operator=(const Boardgames& obj)
{
    if(this != &obj)
    {
        if(this->numeJoc != NULL)
        {
            delete[] this->numeJoc;
            this->numeJoc = NULL;
        }
    this->numeJoc = new char[strlen(obj.numeJoc) + 1];
    strcpy(this->numeJoc, obj.numeJoc);
    this->categorieVarsta=obj.categorieVarsta;
    this->pretJoc=obj.pretJoc;
    this->stocJoc=obj.stocJoc;
    this->inventarJoc=obj.inventarJoc;
    }
    return *this;
}

Boardgames& Boardgames::operator++(){
    this->inventarJoc++;
    return *this;
}

Boardgames Boardgames::operator++(int){
    Boardgames aux(*this);
    ++*this;
    return aux;
}

Boardgames Boardgames::operator+(const Boardgames& obj){
    Boardgames aux(*this);
    aux.categorieVarsta += obj.categorieVarsta;
    aux.inventarJoc += obj.inventarJoc;
    return aux;
}

Boardgames Boardgames::operator+(int x){
    Boardgames aux(*this);
    aux.inventarJoc += x;
    return aux;
}

Boardgames operator+(int x, Boardgames obj){
    return obj+x;
}

bool Boardgames::operator==(const Boardgames& obj){
    return this->categorieVarsta == obj.categorieVarsta;
}

char Boardgames::operator[](int i)
{
    if(this->numeJoc == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > strlen(this->numeJoc)){
        throw runtime_error("Index invalid");
    }
    else
        return this->numeJoc[i];
}

Boardgames::operator int(){
    return this->inventarJoc;
}


ostream& operator <<(ostream& out,const Boardgames& obj)
{
    out<<"ID Joc: "<<obj.idJoc<<endl;
    out<<"Numele jocului: "<<obj.numeJoc<<endl;
    out<<"Categoria de varsta: >"<<obj.categorieVarsta<<endl;
    out<<"Pretul jocului: "<<obj.pretJoc<<" lei"<<endl;
    out<<"Valabilitate in stoc a jocului: "<<obj.stocJoc<<endl;
    out<<"Inventarul jocului: "<<obj.inventarJoc<<endl;
    return out;
}
istream& operator >>(istream& in, Boardgames& obj)
{
    cout << "Introduceti numele jocului: " << endl;
    char numeJoc[100];
    in >> numeJoc;
    if(obj.numeJoc != NULL)
    {
        delete obj.numeJoc;
        obj.numeJoc = NULL;
    }
    obj.numeJoc = new char[strlen(numeJoc) + 1];
    strcpy(obj.numeJoc, numeJoc);

    cout<<"Introduceti categoria de varsta a jocului: "<<endl;
    in>>obj.categorieVarsta;

    cout << "Introduceti pretul jocului: " << endl;
    in >> obj.pretJoc;

    cout << "Introduceti daca e valabil jocul: " << endl;
    in >> obj.stocJoc;

    cout << "Introduceti inventarul jocului: " << endl;
    in >> obj.inventarJoc;

    return in;
}

Boardgames::~Boardgames()
{
    if(this->numeJoc != NULL)
    {
        delete[] this->numeJoc;
        this->numeJoc = NULL;
    }
}

///////////////////////////////////////////////////////////
class Muzica
{
 private:
    static int contorIdMuzica;
    const int idMuzica;
    char* titluProdus;
    string categorieProdus;
    int pretMuzica;
    bool stocMuzica;
    int inventarMuzica;
public:
    //Constructori
    Muzica();  // Constructor fara parametrii
    Muzica(char* titluProdus,string categorieProdus, int pretMuzica, int stocMuzica, int inventarMuzica); // Constructor parametrizat
    Muzica(const Muzica& obj);   // Copy constructor

    //Operator
    Muzica& operator = (const Muzica&);
    friend ostream& operator <<(ostream& out, const Muzica& obj);
    friend istream& operator >>(istream& in, Muzica& obj);
    Muzica& operator++();
    Muzica operator++(int);
    Muzica operator+(const Muzica& obj);
    Muzica operator+(int);
    friend Muzica operator+(int, Muzica obj);
    bool operator==(const Muzica&);
    char operator[](int);
    operator int();
    operator int() const {return this->inventarMuzica;}

    //Get+Set
    static int getcontorIdMuzica(){return Muzica::contorIdMuzica;}
    const string getcategorieProdus()const{return categorieProdus;}
    const int getpretMuzica()const{return pretMuzica;}
    const bool getstocMuzica()const {return stocMuzica;}
    const int getinventarMuzica()const{return inventarMuzica;}
    const char* getTitluProdus() const {return titluProdus;}
    //Destructor
    ~Muzica();
};
int Muzica::contorIdMuzica = 3000;

Muzica::Muzica():idMuzica(contorIdMuzica++)
{
    titluProdus = new char[strlen("Anonim") + 1]; // Alocat memorie fara sa initializam
    strcpy(titluProdus, "Anonim");  // Initializam variabila
    categorieProdus= "Anonim";
    pretMuzica = 0;
    stocMuzica = false;
    inventarMuzica=0;
}
Muzica::Muzica(char* titluProdus,string categorieProdus, int pretMuzica, int stocMuzica, int inventarMuzica):idMuzica(contorIdMuzica++)
{
    this->titluProdus = new char[strlen(titluProdus) + 1];
    strcpy(this->titluProdus, titluProdus);
    this->categorieProdus=categorieProdus;
    this->pretMuzica=pretMuzica;
    this->stocMuzica=stocMuzica;
    this->inventarMuzica=inventarMuzica;
}
Muzica::Muzica(const Muzica& obj): idMuzica(contorIdMuzica++)
{
    this->titluProdus = new char[strlen(obj.titluProdus) + 1];
    strcpy(this->titluProdus, obj.titluProdus);
    this->categorieProdus=obj.categorieProdus;
    this->pretMuzica=obj.pretMuzica;
    this->stocMuzica=obj.stocMuzica;
    this->inventarMuzica=obj.inventarMuzica;
}
Muzica& Muzica::operator=(const Muzica& obj)
{
    if(this != &obj)
    {
        if(this->titluProdus != NULL)
        {
            delete[] this->titluProdus;
            this->titluProdus = NULL;
        }
    this->titluProdus = new char[strlen(obj.titluProdus) + 1];
    strcpy(this->titluProdus, obj.titluProdus);
    this->categorieProdus=obj.categorieProdus;
    this->pretMuzica=obj.pretMuzica;
    this->stocMuzica=obj.stocMuzica;
    this->inventarMuzica=obj.inventarMuzica;
    }
    return *this;
}

Muzica& Muzica::operator++(){
    this->inventarMuzica++;
    return *this;
}

Muzica Muzica::operator++(int){
    Muzica aux(*this);
    ++*this;
    return aux;
}

Muzica Muzica::operator+(const Muzica& obj){
    Muzica aux(*this);
    aux.categorieProdus += obj.categorieProdus;
    aux.inventarMuzica += obj.inventarMuzica;
    return aux;
}

Muzica Muzica::operator+(int x){
    Muzica aux(*this);
    aux.inventarMuzica += x;
    return aux;
}

Muzica operator+(int x, Muzica obj){
    return obj+x;
}

bool Muzica::operator==(const Muzica& obj){
    return this->categorieProdus == obj.categorieProdus;
}

char Muzica::operator[](int i){
    if(this->titluProdus == NULL)
        throw runtime_error("Nu exista elemente in vector");
    if(i < 0 || i > strlen(this->titluProdus)){
        throw runtime_error("Index invalid");
    }
    else
        return this->titluProdus[i];
}

Muzica::operator int(){
    return this->inventarMuzica;
}

ostream& operator <<(ostream& out,const Muzica& obj)
{
    out<<"ID Muzica: "<<obj.idMuzica<<endl;
    out<<"Titlul muzical: "<<obj.titluProdus<<endl;
    out<<"Categoria produsului muzical: "<<obj.categorieProdus<<endl;
    out<<"Pret produs muzical: "<<obj.pretMuzica<<" lei"<<endl;
    out<<"Valabilitate in stoc a produsului: "<<obj.stocMuzica<<endl;
    out<<"Inventarul produsului:"<<obj.inventarMuzica<<endl;
    return out;
}
istream& operator >>(istream& in, Muzica& obj)
{
    cout << "Introduceti titlul dorit: " << endl;
    char titluProdus[100];
    in >> titluProdus;
    if(obj.titluProdus != NULL)
    {
        delete obj.titluProdus;
        obj.titluProdus = NULL;
    }
    obj.titluProdus = new char[strlen(titluProdus) + 1];
    strcpy(obj.titluProdus, titluProdus);

    cout<<"Introduceti categoria produsului: "<<endl;
    in>>obj.categorieProdus;

    cout << "Introduceti pretul cd-ului/vinylului: " << endl;
    in >> obj.pretMuzica;

    cout << "Introduceti daca e valabil produsul: " << endl;
    in >> obj.stocMuzica;

    cout << "Introduceti inventarul produsului: "<<endl;
    in >> obj.inventarMuzica;
    return in;
}

Muzica::~Muzica()
{
    if(this->titluProdus != NULL)
    {
        delete[] this->titluProdus;
        this->titluProdus = NULL;
    }
}
int main()
{

    int nrcarti=4;
    vector<Carti>listaCarti;
    Carti c1("Micul Print", "Antoine de Saint-Exupéry", 'F', 30, true, 12),c2("Mandrie si prejudecata", "Jane Austen", 'R', 40, true, 20),
       c3("Cimitirul Animalelor", "Stephen King", 'H', 60, true, 14),c4("Crima pe terenul de golf", "Agatha Christie", 'M', 40, true, 15);

    listaCarti.push_back(c1);
    listaCarti.push_back(c2);
    listaCarti.push_back(c3);
    listaCarti.push_back(c4);

    int nrjocuri=4;
    vector<Boardgames>listaBoardgames;
    Boardgames b1("Catan", 10 , 145, true, 17),b2("Activity Club Edition",18, 180, true, 12),
       b3("Twister",6, 159, true, 22),b4("What do you meme?", 17, 179, true, 21);

    listaBoardgames.push_back(b1);
    listaBoardgames.push_back(b2);
    listaBoardgames.push_back(b3);
    listaBoardgames.push_back(b4);

    int nrmuzica=4;
    vector<Muzica>listaMuzica;
    Muzica m1("Fine line - Harry Styles", "CD" , 80, true, 4),m2("AM - Arctic Monkeys", "Vinyl", 128, true, 9),
          m3("Pray for the wicked - Panic! at the disco", "Vinyl", 140, true, 16),m4("Rare - Selena Gomez", "CD", 45, true, 19);

    listaMuzica.push_back(m1);
    listaMuzica.push_back(m2);
    listaMuzica.push_back(m3);
    listaMuzica.push_back(m4);

    Clienti x;
    cin >>x;
    int choice;
    cout<<endl<<endl<<endl<<endl;
    do {
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "         Carturesti       " << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1. Doresc sa cumpar o carte" << endl;
        cout << "2. Doresc sa cumpar un joc" << endl;
        cout << "3. Doresc sa cumpar un CD/Vinyl" << endl;
        cout << "4. Quit" << endl;
        cout << endl << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
               {
                cout<<endl<<endl;
                float vouchermaxi=0;
                cout<<"Voucherele dumneavoastra sunt de reduceri de ";
                for(int i = 0; i < x.getnrVouchere(); i++)
                {
                    cout<<x.getvoucher()[i]*100<<"%  ";
                    if (vouchermaxi<x.getvoucher()[i])
                        vouchermaxi=x.getvoucher()[i];
                }
                cout<<endl<<"Voucherul maxim este "<<vouchermaxi*100<<"% "<<endl<<endl;

                int pretnou;
                do
                {   cout<<endl<<endl<<endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "         Bine ati venit la categoria de carti!<3       " << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl<<endl<<endl;
                    cout<<"Ce carte doriti sa cumparati?"<<endl;
                    for(int i=0; i<nrcarti; i++)
                    cout <<i+1<< ". Doresc sa cumpar '"<<listaCarti[i].getTitluCarte()<<"'"<< endl;
                    cout << "5. Quit" << endl;
                    cout << endl << "Enter your choice: ";
                    cin >> choice;
                    cout << endl;

                    switch (choice)
                    {
                    case 1:
                    {

                        pretnou=listaCarti[0].getpretCarte()-(vouchermaxi*listaCarti[0].getpretCarte());
                        cout<<endl<<endl;
                        cout<<"Pretul cartii dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara cartea '"<<listaCarti[0].getTitluCarte()<<"'"<<endl<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara cartea '"<<listaCarti[0].getTitluCarte()<<"'"<<endl<<endl<<endl;

                        break;
                    }
                    case 2:
                    {

                        pretnou=listaCarti[1].getpretCarte()-(vouchermaxi*listaCarti[1].getpretCarte());
                        cout<<"Pretul cartii dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara cartea '"<<listaCarti[1].getTitluCarte()<<"'"<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara cartea '"<<listaCarti[1].getTitluCarte()<<"'"<<endl<<endl;

                        break;
                    }
                    case 3:
                    {

                        pretnou=listaCarti[2].getpretCarte()-(vouchermaxi*listaCarti[2].getpretCarte());
                        cout<<"Pretul cartii dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara cartea '"<<listaCarti[2].getTitluCarte()<<"'"<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara cartea '"<<listaCarti[2].getTitluCarte()<<"'"<<endl<<endl;

                        break;
                    }
                    case 4:
                    {

                        pretnou=listaCarti[3].getpretCarte()-(vouchermaxi*listaCarti[3].getpretCarte());
                        cout<<"Pretul cartii dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara cartea '"<<listaCarti[3].getTitluCarte()<<"'"<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara cartea '"<<listaCarti[3].getTitluCarte()<<"'"<<endl<<endl;

                        break;
                    }
                    case 5:
                        {
                            cout<<"La revedere! Ne bucuram ca ne-ati vizitat categoria de Carti!"<<endl<<endl;
                            break;
                        }
                    }
                }while (choice!=5);


                break;
            }

        case 2:
            {
                cout<<endl<<endl;
                float vouchermaxi=0;
                cout<<"Voucherele dumneavoastra sunt de reduceri de ";
                for(int i = 0; i < x.getnrVouchere(); i++)
                {
                    cout<<x.getvoucher()[i]*100<<"%  ";
                    if (vouchermaxi<x.getvoucher()[i])
                        vouchermaxi=x.getvoucher()[i];
                }
                cout<<endl<<"Voucherul maxim este "<<vouchermaxi*100<<"% "<<endl<<endl;

                int pretnou;
                do
                {   cout<<endl<<endl<<endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "         Bine ati venit la categoria de boardgames!<3       " << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl<<endl<<endl;
                    cout<<"Ce joc doriti sa cumparati?"<<endl;
                    for(int i=0; i<nrjocuri; i++)
                    cout <<i+1<< ". Doresc sa cumpar '"<<listaBoardgames[i].getNumeJoc()<<"'"<< endl;
                    cout << "5. Quit" << endl;
                    cout << endl << "Enter your choice: ";
                    cin >> choice;
                    cout << endl;

                    switch (choice)
                    {
                    case 1:
                    {

                        pretnou=listaBoardgames[0].getpretJoc()-(vouchermaxi*listaBoardgames[0].getpretJoc());
                        cout<<endl<<endl;
                        cout<<"Pretul jocului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara jocul '"<<listaBoardgames[0].getNumeJoc()<<"'"<<endl<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara jocul '"<<listaBoardgames[0].getNumeJoc()<<"'"<<endl<<endl<<endl;

                        break;
                    }
                    case 2:
                    {

                        pretnou=listaBoardgames[1].getpretJoc()-(vouchermaxi*listaBoardgames[1].getpretJoc());
                        cout<<"Pretul jocului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara jocul '"<<listaBoardgames[1].getNumeJoc()<<"'"<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara jocul '"<<listaBoardgames[1].getNumeJoc()<<"'"<<endl<<endl;

                        break;
                    }
                    case 3:
                    {

                        pretnou=listaBoardgames[2].getpretJoc()-(vouchermaxi*listaBoardgames[2].getpretJoc());
                        cout<<"Pretul jocului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara jocul '"<<listaBoardgames[2].getNumeJoc()<<"'"<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara jocul '"<<listaBoardgames[2].getNumeJoc()<<"'"<<endl<<endl;

                        break;
                    }
                    case 4:
                    {

                        pretnou=listaBoardgames[3].getpretJoc()-(vouchermaxi*listaBoardgames[3].getpretJoc());
                        cout<<"Pretul cartii dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                        if (x.getbuget() > pretnou)
                            cout<<"Aveti buget pentru a cumpara jocul '"<<listaBoardgames[3].getNumeJoc()<<"'"<<endl<<endl;
                        else
                            cout<<"Nu aveti buget pentru a cumpara jocul '"<<listaBoardgames[3].getNumeJoc()<<"'"<<endl<<endl;

                        break;
                    }
                    case 5:
                        {
                            cout<<"La revedere! Ne bucuram ca ne-ati vizitat categoria de Boardgames!"<<endl<<endl;
                            break;
                        }
                    }
                }while (choice!=5);
                break;
            }

        case 3:
            {
                cout<<endl<<endl;
                float vouchermaxi=0;
                cout<<"Voucherele dumneavoastra sunt de reduceri de ";
                for(int i = 0; i < x.getnrVouchere(); i++)
                {
                    cout<<x.getvoucher()[i]*100<<"%  ";
                    if (vouchermaxi<x.getvoucher()[i])
                        vouchermaxi=x.getvoucher()[i];
                }
                cout<<endl<<"Voucherul maxim este "<<vouchermaxi*100<<"% "<<endl<<endl;

                int pretnou;
                do
                {   cout<<endl<<endl<<endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "         Bine ati venit la categoria de muzica!<3       " << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl<<endl<<endl;
                    cout<<"Ce CD/Vinyl doriti sa cumparati?"<<endl;
                    for(int i=0; i<nrjocuri; i++)
                    cout <<i+1<< ". Doresc sa cumpar '"<<listaMuzica[i].getTitluProdus()<<"'"<< endl;
                    cout << "5. Quit" << endl;
                    cout << endl << "Enter your choice: ";
                    cin >> choice;
                    cout << endl;

                    switch (choice)
                    {
                    case 1:
                    {

                            pretnou=listaMuzica[0].getpretMuzica()-(vouchermaxi*listaMuzica[0].getpretMuzica());
                            cout<<endl<<endl;
                            cout<<"Pretul CD-ului/Vinyl-ului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                            if (x.getbuget() > pretnou)
                                cout<<"Aveti buget pentru a cumpara "<<listaMuzica[0].getcategorieProdus()<<" '"<<listaMuzica[0].getTitluProdus()<<"' "<<endl<<endl;
                            else
                                cout<<"Nu aveti buget pentru a cumpara "<<listaMuzica[0].getcategorieProdus()<<" '"<<listaMuzica[0].getTitluProdus()<<"' "<<endl<<endl;
                            break;
                        }
                    case 2:
                    {
                            pretnou=listaMuzica[1].getpretMuzica()-(vouchermaxi*listaMuzica[1].getpretMuzica());
                            cout<<"Pretul CD-ului/Vinyl-ului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                            if (x.getbuget() > pretnou)
                                cout<<"Aveti buget pentru a cumpara "<<listaMuzica[1].getcategorieProdus()<<" '"<<listaMuzica[1].getTitluProdus()<<"' "<<endl<<endl;
                            else
                                cout<<"Nu aveti buget pentru a cumpara "<<listaMuzica[1].getcategorieProdus()<<" '"<<listaMuzica[1].getTitluProdus()<<"' "<<endl<<endl;
                            break;
                        }
                    case 3:
                    {

                        pretnou=listaMuzica[2].getpretMuzica()-(vouchermaxi*listaMuzica[2].getpretMuzica());
                            cout<<"Pretul CD-ului/Vinyl-ului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                            if (x.getbuget() > pretnou)
                                cout<<"Aveti buget pentru a cumpara "<<listaMuzica[2].getcategorieProdus()<<" '"<<listaMuzica[2].getTitluProdus()<<"' "<<endl<<endl;
                            else
                                cout<<"Nu aveti buget pentru a cumpara "<<listaMuzica[2].getcategorieProdus()<<" '"<<listaMuzica[2].getTitluProdus()<<"' "<<endl<<endl;
                            break;
                    }
                    case 4:
                    {

                        pretnou=listaMuzica[3].getpretMuzica()-(vouchermaxi*listaMuzica[3].getpretMuzica());
                            cout<<"Pretul CD-ului/Vinyl-ului dupa aplicarea voucherului este: "<<pretnou<<" lei"<<endl;
                            if (x.getbuget() > pretnou)
                                cout<<"Aveti buget pentru a cumpara "<<listaMuzica[3].getcategorieProdus()<<" '"<<listaMuzica[3].getTitluProdus()<<"' "<<endl<<endl;
                            else
                                cout<<"Nu aveti buget pentru a cumpara "<<listaMuzica[3].getcategorieProdus()<<" '"<<listaMuzica[3].getTitluProdus()<<"' "<<endl<<endl;
                            break;
                    }
                    case 5:
                        {
                            cout<<"La revedere! Ne bucuram ca ne-ati vizitat categoria de Muzica!"<<endl<<endl;
                            break;
                        }
                    }
                }while (choice!=5);

                break;
            }

            case 4: {
                cout<<"La revedere! Ne bucuram ca ne-ati vizitat!"<<endl;
                break;
            }

            default: {
                cout << "Alegere invalida. Incercati din nou." << endl;
                break;
            }
        }

        cout << endl;

    } while (choice != 4);


    return 0;
}
