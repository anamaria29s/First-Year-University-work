#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;
ifstream f("gramatica.in");
ifstream f2("cuvinte.in");
ofstream g("verif.out");

vector<string> gramatica;

bool acceptare(vector<string> gramatica, char simbol, string cuvant)
{

    // Verificăm dacă cuvântul este acceptat de gramatica regulată
    if(cuvant.size()==0) //se verifica daca cuvantul null apartine gramaticii
    {
        for (auto regula:gramatica )//verificam daca este in gramatica si are o tranzitie care sa genereze lambda
        {
            if(regula[0]==simbol && regula.substr(3)=="lambda")
                return true;

        }
        return false;
    }

    for (auto regula:gramatica)
    {
        // daca lungimea este mai mare ca 1 verificam daca apartine gramaticii
        if (cuvant.size()>1 && regula[3] == cuvant[0] && regula[0] == simbol)
        {
            string restcuvant = cuvant.substr(1);
            if (acceptare(gramatica, regula[4], restcuvant))//apelam recursiv functia pentru restul cuvantului
                return true;

        }
        // daca lungimea este egala cu 1 verificam daca este egala cu prima litera a cuvantului
        else if (cuvant.size()==1 && regula[0]==simbol && regula[3]==cuvant[0])
            return true;
    }


    // daca nicio conditie nu se respecta atunci inseamna ca acel cuvant nu este generat de gramatica
    return false;
}


int reguli;
char simbol = 'S';
string n, cuv;
int main()
{

    f >> reguli;
    f.ignore();
    for (int i = 0; i < reguli; i++)
    {
        getline(f, n); // citim o linie intreaga din fisier (cu ajutorul functiei getline)
        gramatica.push_back(n);  // adaugam linia la finalul vectorului de reguli
    }

    while (f2>>cuv)
    {
        string cuvant = cuv;
        if (acceptare(gramatica, simbol, cuvant))
            g << "Cuvantul " << cuvant << " este acceptat de gramatica" << endl;
        else
            g << "Cuvantul " << cuvant << " nu este acceptat de gramatica" << endl;

    }


    return 0;
}
