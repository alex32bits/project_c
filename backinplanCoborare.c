#include <stdio.h>
#define N 4

typedef struct coordonate
{
int linie, coloana;
}coordonate;
coordonate pos[4];
coordonate a[N * N];
int lungime=0;
int matrice[N][N] = { {2,5,8,5},
				      {4,4,3,7},
				      {1,2,8,1},
				      {9,3,1,8} };

void initializare() //int pos[] variabila globala
{	//initializarea posibilitatilor de deplasare Posibilitățile de deplasare sunt Nord, Est, Sud, Vest
	pos[0].coloana = 0; // Nord
	pos[0].linie = -1;// y scade spre Nord
	pos[1].coloana = 1; // Est – x creste spre Est
	pos[1].linie = 0;
	pos[2].coloana = 0; // Sud
	pos[2].linie = 1; // y creste spre Sud
	pos[3].coloana = -1;// Vest – x scade spre Vest
	pos[3].linie = 0;
}
int solutie(coordonate c)
{
	if (c.coloana == 0 || c.linie == 0 || c.coloana == N - 1 || c.linie == N - 1) //daca am ajuns la margine
		return 1;
	else
		return 0;
}
int acceptabil(coordonate c, coordonate urm)
{
	if (urm.linie >= 0 && urm.coloana >= 0 && urm.linie < N && urm.coloana < N) //daca este liber si coordonata se afla in dimensiunile matricei
	{
        if(matrice[c.linie][c.coloana]>matrice[urm.linie][urm.coloana])
        return 1;
    }
	 return 0;
}

void afiseaza_solutia(int k)
{
	
	printf("traseu: \n");
	for (int i = 0; i < k; i++)
		printf("(%d-%d) ", a[i].linie, a[i].coloana);
	printf("\n");
}

void back(int x,int y)
{
    coordonate aux;
    a[lungime].linie=x;
    a[lungime].coloana=y;
    lungime++;
    if(solutie(a[lungime-1]))
    {
        afiseaza_solutia(lungime);
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            aux.coloana=a[lungime-1].coloana+pos[i].coloana;
            aux.linie=a[lungime-1].linie+pos[i].linie;

            if(acceptabil(a[lungime-1],aux))
                back(aux.linie,aux.coloana);
        }
    }
    lungime--;
 
}

int main()
{
    initializare();
    back(2,2);

return 0;
}