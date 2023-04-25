#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;
ifstream f("gramatica.in");
ifstream f2("cuvinte.in");
ofstream g("verif.out");

vector<string> gramatica;

bool acceptare(vector<string> gramatica, char S, string cuv)
{

    // Verificăm dacă cuvântul este acceptat de gramatica regulată
    if(cuv.size()==0) //Verificam daca cuvantul vid apartine gramaticii
    {
        for (auto tranzitie:gramatica )//Verificam daca este in gramatica si are o tranzitie care sa genereze lambda
        {
            if(tranzitie[0]==S && tranzitie.substr(3)=="lambda")
                return true;

        }
        return false;
    }

    for (auto tranzitie:gramatica)
    {
        // daca lungimea este mai mare ca 1 verificam daca apartine gramaticii
        if (cuv.size()>1 && tranzitie[3] == cuv[0] && tranzitie[0] == S)
        {
            string restcuvant = cuv.substr(1);
            if (acceptare(gramatica, tranzitie[4], restcuvant))//apelam recursiv functia pentru restul cuvantului
                return true;

        }
        // daca lungimea este egala cu 1 verificam daca este egala cu prima litera a cuvantului
        else if (cuv.size()==1 && tranzitie[0]==S && tranzitie[3]==cuv[0])
            return true;
    }


    // daca nicio conditie nu se respecta atunci inseamna ca acel cuvant nu este generat de gramatica
    return false;
}


int tranzitii;
char S = 'S';
string n, cuvant,cuv;
int main()
{

    f >> tranzitii;
    f.ignore();
    for (int i = 0; i < tranzitii; i++)
    {
        getline(f, n); // citim o linie intreaga din fisier (cu ajutorul functiei getline)
        gramatica.push_back(n);  // adaugam linia la finalul vectorului de reguli
    }

    while (f2>>cuvant)
    {
        cuv = cuvant;
        if (acceptare(gramatica, S, cuvant))
            g << "Cuvantul " << cuv << " este acceptat de gramatica" << endl;
        else
            g << "Cuvantul " << cuv << " nu este acceptat de gramatica" << endl;

    }

    return 0;
}

