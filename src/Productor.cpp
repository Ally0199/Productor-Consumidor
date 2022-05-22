#include "Productor.h"

Productor::Productor() //Inicializa Estado y Posicion en 0
{
    Estado=0;
    Posicion=0;
}

Productor::~Productor()
{
    //dtor
}
void Productor::setEstado(int Valor) //Recibe un Valor y se lo asigna a Estado
{
    Estado=Valor;
}

int Productor::getEstado() //Devuelve el Estado
{
    return Estado;
}

void Productor::setPosicion(int Valor) //Recibe un Valor y se lo asigna a Posicion
{
    Posicion=Valor;
}

int Productor::getPosicion() //Devuelve la Posicion
{
    return Posicion;
}
