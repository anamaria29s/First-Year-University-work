#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");

int n,i,j,k,initial,finn,nr,nrf,n1,n2,fin[100],ok,sol[100];
char cuv[100],s,m[100][100];

int main()
{
    f>>n; /// nr de stari
    f>>nr; ///nr de muchii
    f>>nrf; ///nr de stari finale
    f>>cuv; ///cuvantul
    f>>initial;///starea initala
    for(i=0; i<nrf; i++)
    {
        f>>finn;
        fin[i]=finn;///construiesc un vector cu toate starile finale
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            m[i][j]='-';///umplu matricea de adiacenta cu acest simbol

    for(i=0; i<nr; i++)
    {
        f>>n1>>n2>>s;
        m[n1][n2]=s;///realizez matricea de adiacenta cu muchiile automatului
    }
    ok=1;

    int stareActuala=(int)initial;///retin starea initiala

    if(strcmp(cuv,"/")==0)///verific daca cuvantul e vid
    {
        for(int i=0; i<nrf; i++)
            if(fin[i] == stareActuala)///daca starea initiala este una dintre starile finale
            {
                g<<"Cuvantul vid este acceptat";
                return 0;
            }
    }

    for(int i=0; i<strlen(cuv); i++)///parcurg cuvantul caracter cu caracter
        for(int j=0; j<n; j++)///parcurg matricea de adiacenta pe linii
        {
            if(m[stareActuala][j] == cuv[i])///daca caracterul din cuvant se afla in matrice pe linia respectiva
            {
                stareActuala = j;///reactualizez starea actuala
                sol[++k]=j;///adaug starea intr-un vector solutie care va reprezenta drumul parcurs
                break;
            }
        }

    ok=0;
    for(int i=0; i<nrf; i++)///parcurg vectorul cu stari finale
    {
        if(fin[i] == stareActuala)///daca ultima stare actuala se regaseste in vector,cuvantul e acceptat
        {
            g<<"Cuvantul este acceptat, iar drumul este"<<endl;
            for(i=0; i<k; i++)
                g<<sol[i]<<" ";
            ok=1;
            break;
        }
    }
    if(!ok) g<<"Cuvant neacceptat";

    return 0;
}
