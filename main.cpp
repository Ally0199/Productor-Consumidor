#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include "Productor.h"
#include "Consumidor.h"

using namespace std;

Productor* MyProductor= new Productor; //Se crea un Productor
Consumidor* MyConsumidor= new Consumidor; //Se crea un Consumidor
int Contenedor[22]; //Se crea un contenedor con 22 espacios.

//La funcion gotoxy nos permite acomodar a nuestro gusto las salidas a consola.
void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

void IniciarContenedor() //Se inician las casillas del contenedor en 0.
{
    for(int i=0; i<=22; i++)
    {
        Contenedor[i]=0;
    }
}

//La funcion tiempo indicara al productor o consumidor cuanto tiempo trabajar, este tiempo sera random entre 2 y 4.
int Tiempo()
{
    int num;
    num=2+rand()%(5-1);
    return num;
}

//La siguiente funcion nos mostrara los estados del contenedor, el productor y el consumidor.
void ImprimirContenedor()
{

    int i,x=2;
    //Si el Consumidor esta trabajando (Estado->1)
    if(MyConsumidor->getEstado()==1)
        {
            cout<<"Consumidor[0]: TRABAJANDO----------------------------------------Productor[1]: DURMIENDO"<<endl;
        }
    //Si el Productor esta trabajando (Estado->1)
    if(MyProductor->getEstado()==1)
        {
            cout<<"Consumidor[0]: DURMIENDO----------------------------------------Productor[1]: TRABAJANDO"<<endl;
        }
    cout<<endl;
    cout<<endl;
    //For para imprimir el Contenedor
    for(i=0; i<22; i++)
    {
        cout<<"   "<<Contenedor[i];
    }
    //For para imprimir numero de casillas
    for(int a=1; a<23; a++)
    {
        if(x<100)
        {
            gotoxy(x,4);
            cout<<" _"<<endl;
            gotoxy(x,5);
            cout<<" "<<a;
            x=x+4;
        }

    }
        cout<<endl;
        cout<<endl;
        cout<<"                                     PRESIONE ESC PARA SALIR"<<endl;

}

int main()
{
    void IniciarContenedor(); //Se inicializa nuestro contenedor en 0
    int opc;//Variable que recibira la tecla Esc cuando querramos salir
    //Se inicia el ciclo
    do
    {
        //Inicio de la eleccion de turno.
        int num;//Variable que recibira el numero random
        num=1+rand()%(11-1);//Se obtiene un numero entre 1 y 10
        if (num==1 || num==3 || num==5 || num==7 || num==9)
            {
                //Si es impar Consumidor entra
                MyConsumidor->setEstado(1); //El estado (semaforo) de Consumidor cambia a 1
                MyProductor->setEstado(0); //El estado (semaforo) de Productor cambia a 0
            }
        else
            {
                //Si es par Productor entra
                MyConsumidor->setEstado(0); //El estado (semaforo) de Consumidor cambia a 0
                MyProductor->setEstado(1); //El estado (semaforo) de Productor cambia a 1
            }
        //Fin de eleccion del turno

        //Si el productor entrara al Contenedor
        if(MyProductor->getEstado()==1)
        {
            //Se Verifica que el consumidor no este en el contenedor
            if(MyConsumidor->getEstado()==0)
            {
                //Se obtiene la ultima posicion en la que el Productor continuara trabajando y se verifica que este vacia.
                if(Contenedor[MyProductor->getPosicion()]==0)
                {
                    int TimeP=Tiempo(); //La variable TimeP recibe el tiempo que trabajara el Productor desde la funcion Tiempo
                    //Se crea un for en donde b representara el trabajo del Productor y terminara al alcanzar la variable Time
                    for(int b=0; b<TimeP; b++)
                    {
                        //Se verifica que la posicion en la que esta el Productor este vacia
                        if(Contenedor[MyProductor->getPosicion()]==0)
                        {
                            //Si lo esta entonces esa posicion en e Contenedor cambia a 1
                            Contenedor[MyProductor->getPosicion()]=1;
                            int a=MyProductor->getPosicion();//a recibe la posicion actual
                            MyProductor->setPosicion(a+1);//Se actualiza la posicion del Productor como a+1
                            //Se se llega al final del contenedor, la pocision del Productor vuelve a 0
                            if(MyProductor->getPosicion()==22)
                            {
                                MyProductor->setPosicion(0);
                            }
                            //Se limpia pantalla y se imprime el Contenedor
                            Sleep(850);
                            system("cls");
                            ImprimirContenedor();
                        }//Fin del if
                    }//Fin del for

                }//Fin del if
            }//Fin del if
        }//Fin del if
        //Si el Consumidor entrara al Contenedor
        else (MyConsumidor->getEstado()==1);
        {
            //Se verifica que el Productor no este dentro
            if(MyProductor->getEstado()==0)
            {
                //Se verifica que la posicion en la que continuara el trabajo tenga un producto (1)
                if(Contenedor[MyConsumidor->getPosicion()]==1)
                {
                    int TimeC=Tiempo();//TimeC recibira el tiempo que trabajara en Consumidor de la funcion Tiempo
                    //d indicara el trabajo del Consumidor hasta alcanzar a la variable TimeC
                    for(int d=0; d<TimeC; d++)
                    {
                        //Se verifica que la posicion actual del Consumidor tenga un producto
                        if(Contenedor[MyConsumidor->getPosicion()]==1)
                        {
                            //Si tiene producto entonces esa posicion dentro del Contenedor cambia a 0
                            Contenedor[MyConsumidor->getPosicion()]=0;
                            int e=MyConsumidor->getPosicion();//e guardara la posicion actual del Consumidor
                            MyConsumidor->setPosicion(e+1);//Se actualiza la posicion del Consumidor como e+1
                            //Si el Consumidor llega al final del contenedor
                            if(MyConsumidor->getPosicion()==22)
                            {
                                //Su posicion se vuelve 0
                                MyConsumidor->setPosicion(0);
                            }
                            //Se limpia pantalla y se imprime el Contenedor
                            Sleep(850);
                            system("cls");
                            ImprimirContenedor();
                        }//Fin del if

                    }//Fin del for

                }//Fin del if
            }//Fin del if
        }//Fin del if
    }while((opc = getch())!=27); //Si opc recibe la tecla Esc en codigo ASCII entonces sale del programa
    return 0;
}



