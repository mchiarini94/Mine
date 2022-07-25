//============================================================================
// Name        : 27).cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y){ //permette che una scritta si trova in una determinata posizione nel programma
	COORD coord;
	coord.X = x;
	coord.Y= y;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE) , coord);
}

int main() {
	int x=2, y=4;

	do { //ciclo infinito per fare muovere il cursore
		char tasto= getch(); //registra il tasto premuto da tastiera e la memorizza nella variabile tasto
		if (tasto==75) x--; //75 è il codice corrispondente alla freccia sinistra
		if (tasto==77) x++; //77 è il codice corrispondente alla freccia destra
     	if (tasto==72) y--; //72 è il codice corrispondente alla freccia giù
     	if (tasto==80) y++; //80 è il codice corrispondente alla freccia su
     	gotoxy(x,y); printf ("5"); //sposta il carattere più nelle posizioni di x e y

     	//in questo modo quando sposto il carattere non si creeranno delle sue
     	//copie tracce ma si "cancelleranno", o meglio verranno rimpiazzate
     	//da spazio vuoto. In questo modo sembrerà che si stia spostando lungo il percorso
     	/*gotoxy(x-1,y); printf (" ");
     	gotoxy(x+1,y); printf (" ");
     	gotoxy(x,y-1); printf (" ");
     	gotoxy(x,y+1); printf (" ");*/

	} while (1>0);


	return 0;
}
