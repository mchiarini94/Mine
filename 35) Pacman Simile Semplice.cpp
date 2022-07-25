//Semplice giochino simile a Pacman senza nemici
//PERDI quando finisci contro gli ostacoli
//C'è anche il punteggio

#include <iostream>
#include <conio.h>


using namespace std;

void mappa();

int main() {
  mappa();
  return (0);}


void mappa()
{
    string arra[15][15]; //campo da gioco
    int x,y;
    int n=3 ,m=2;
    char movimento;
    int score=0;

    //Creazione della mappa

    for (x=0; x<15 ; x++)
    {  for (y=0; y<15; y++)
        {
            cout<< arra[x][y]<<endl;
        }

    }

    //Fare il design della mappa

     for (x=0; x<15 ; x++)
    {  for (y=0; y<15; y++)
        {
         if (x==0 || x==14) { //se x è il primo elemento o l'ultimo, ossia i confini dell'array x
            arra[x][y]="#"; // sono i confini della mappa, il bordo orizzontale
           }
         else if (y==0 || y==14) { //se y è il primo elemento o l'ultimo, ossia i confini dell'array y
            arra[x][y]="#";//sono i confini della mappa, il bordo verticale
            }
        else if (x==5 && y>2 && y<10)  //ostacolo nella mappa nella riga 6 tra le colonne 3 e 11
            {
                arra[x][y]="#";
                }

        else if (x==9 && y>2 && y<10)  //ALTRO ostacolo nella mappa nella riga 9 tra le colonne 3 e 11
            {
                arra[x][y]="#";
                }

         else if (y==9 && x>2 && x<10)  //ostacolo nella mappa nella colonna 9 tra le righe 3 e 11
            {
                arra[x][y]="#";
                }

        else if (y==12 && x>2 && x<10)  //ALTRO ostacolo nella mappa nella colonna 12 tra le righe 3 e 11
            {
                arra[x][y]="#";
                }

        else if (y==1 && x>2 && x<10)  //ALTRO ostacolo nella mappa nella colonna 2 tra le righe 3 e 11
            {
                arra[x][y]="#";
                }



        else{

            arra[12][12]= "0"; //portale
            arra[x][y]= "."; // i puntini che Pacman dovrà mangiare
             }

        }

    }



    //Stampare la mappa

     arra[n][m]= "@"; //Pacman nella mappam ovvero il suo punto iniziale in 4,3
      //[n][m] saranno responsabili del movimento di pacman

      //PUNTEGGIO

        cout<<"\t\t\tPunteggio: "<<score;
        cout<<endl;

     for (x=0; x<15 ; x++)
    {  for (y=0; y<15; y++)
        {
            cout<< arra[x][y]<<" ";
        }
        cout<<endl;

    }

    //MOVIMENTO PACMAN CON UN CICLO INFINITO

    //faccio muovere Pacman nella mappa prendendo i comandi dall'utente
    while (true) { // loop infinito per far muovere Pacman sempre
         cout<<"\nFai la mossa";
         cin>>movimento;




         //MOVIMENTO VERSO IL BASSO
         if (movimento == 's'){
                n++;
                if (n>0) {
                    arra[n-1][m]=" "; //cancello la posizione precedente di Pacman, così mangia anche il puntino
                }
           system ("cls"); //per riaggiornare la mappa ogni volta
         }
         //MOVIMENTO VERSO L'ALTO
         if (movimento == 'w'){
                n--;
                if (n>0) {
                    arra[n+1][m]=" "; //cancello la posizione precedente di Pacman, così mangia anche il puntino
                }
          system ("cls"); //per riaggiornare la mappa ogni volta
         }


         //MOVIMENTO VERSO SINISTRA

         if (movimento == 'a'){
                m--;
                if (m>0) {
                    arra[n][m+1]=" "; //cancello la posizione precedente di Pacman, così mangia anche il puntino
                }
           system ("cls"); //per riaggiornare la mappa ogni volta

         }

         //MOVIMENTO VERSO DESTRA

         if (movimento == 'd'){
                m++;
                if (m>0) {
                    arra[n][m-1]=" "; //cancello la posizione precedente di Pacman, così mangia anche il puntino
                }
          system ("cls"); //per riaggiornare la mappa ogni volta
         }


         //IL PORTALE, OSSIA LA FINE DEL GIOCO
         if(arra[n][m]=="0") {
             system ("cls");
             cout<<"FINITO"<<endl;
             break;
         }

         if(arra[n][m]=="#") {
             system ("cls");
             cout<<"SEI ANDATO CONTRO L'OSTACOLO COGLIONE"<<endl<< "GAME OVER"<<endl;
             break;
         }

         //PUNTEGGIO AGGIORNATO
        if (arra[n][m]=="."){  //Aumento solo quando prendo il puntino
         score++;} //se non sono andato contro nessun ostacolo, nè sono andato nel portale, e quindi sto continuando a muovermi allora aumento il punteggio
        cout<<"\t\t\tPunteggio: "<<score;
        cout<<endl;










         arra[n][m]= "@";
         for (x=0; x<15 ; x++)
          {  for (y=0; y<15; y++)
             {
                 cout<< arra[x][y]<<" ";
              }
             cout<<endl;

           }

        }


 cout<< "Hai finito con un punteggio di  "<< score<<endl;
}
