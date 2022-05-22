#include "Consumidor.h"

Consumidor::Consumidor() //Inicializa Estado y Posicion en 0
{
    Estado=0;
    Posicion=0;
}

Consumidor::~Consumidor()
{
    //dtor
}
void Consumidor::setEstado(int Valor) //Recibe un Valor y se lo asigna a Estado
{
    Estado=Valor;
}

int Consumidor::getEstado() //Devuelve el Estado
{
    return Estado;
}

void Consumidor::setPosicion(int Valor) //Recibe un Valor y se lo asigna a Posicion
{
    Posicion=Valor;
}

int Consumidor::getPosicion() //Devuelve la Posicion
{
    return Posicion;
}
