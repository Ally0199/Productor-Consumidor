#ifndef PRODUCTOR_H
#define PRODUCTOR_H

using namespace std;

class Productor
{
    public:
        Productor();
        virtual ~Productor();
        void setEstado(int Valor);
        int getEstado();
        void setPosicion(int Valor);
        int getPosicion();

    protected:

    private:
        int Estado; //Semaforo Binario para Productor
        int Posicion;
};

#endif // PRODUCTOR_H
