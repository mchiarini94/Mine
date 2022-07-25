//============================================================================
// Name        : 29).cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <windows.h> //ha in sè il comando per rilevare i tasti

using namespace std;

string T; //servirà per tenere salvata la grafica
string X= ".........." //questa stringa contiene il campo da gioco
		  ".........." //potevo farlo in una sola riga
		  ".........." //ma è per visualizzarlo meglio
		  ".........."
		  "..........";

void stampa(); //stampa il campo da gioco
int x=0; //indica la posizione

int main() {
	T=X;
	T[0]='y'; //piazzo il cursore alla prima casella

	while (1) //ciclo infinito
	{
	//GetAsyncKeyState serve per identificare quale comando è stato premuto
	  if    ( x>=10 &&  GetAsyncKeyState(VK_UP)) //se premo il tasto su il cursore deve andare su
	       {x=x-10; //perchè il cursore si deve spostare indietro di 10 caselle
	       //dando l'illusione di starsi spostando in alto
	       system ("cls"); //Ogni volta devo ricreare il campo
	       T=X;
	       T[x]='y'; //assegnando la nuova posizione del cursore
	       stampa();

	       }

	  else if (x<=39 && GetAsyncKeyState(VK_DOWN))
	      {x=x+10; //perchè il cursore si deve spostare in avanti di 10 caselle
	       //dando l'illusione di starsi spostando in basso
	       system ("cls");
	       T=X;
	       T[x]='y';
	       stampa();

	      }
	  else if ( x%10 !=0   &&  GetAsyncKeyState(VK_LEFT))
	  {    x--; //perchè il cursore si sposta a sinistra
	       system ("cls");
	       T=X;
	       T[x]='y';
	       stampa();

	  }
	  else if ( (x+1)%10 !=0  && GetAsyncKeyState(VK_RIGHT))
	  {
		  x++; //perchè il cursore si sposta a destra
		  system ("cls");
		  T=X;
		  T[x]='y';
		  stampa();
	  }

	}
	return 0;
}


void stampa (){
	cout<<"Usa le frecce per spostare il cursore \n\n"<<endl; //scritta iniziale alla testa del gioco

	for (int i=0; i<50; i++) //i puntini sono 50 in totale
	{
		cout<< T[i]; //stampa tutti i puntini
		if ((i+1)%10 ==0 && i!=0) cout<< endl; /*ci sono 10 puntini per riga
           per cui in avremo che il cursore può spostarsi dalla posizione 0 a 9
           da 10 a 19, da 20 a 29, da 30 a 39, da 40 a 49.
           Per cui quando arrivo alla posizione 10 vado a capo, in modo da fare
           stampare i puntini in righe di 10*/
       }
}
