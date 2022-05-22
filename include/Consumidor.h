#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H

using namespace std;

class Consumidor
{
    public:
        Consumidor();
        virtual ~Consumidor();
        void setEstado(int Valor);
        int getEstado();
        void setPosicion(int Valor);
        int getPosicion();

    protected:

    private:
        int Estado; //Semaforo Binario para Consumidor
        int Posicion;
};

#endif // CONSUMIDOR_H
