//
// Created by Jesus Anaya on 09/03/2018.
//

#ifndef PROYECTO_2_HORA_H
#define PROYECTO_2_HORA_H

using namespace std;

class Hora{

    public:
    //Constructores por default y por parametros
    Hora();
    Hora(int, int);

    //Metodos de acceso
    int getHora();
    int getMinutos();
    void setHora(int);
    void setMinutos(int);

    //Metodos de operacion
    void muestra();

    private:
    int minutos;
    int hora;
};

Hora::Hora(int hora, int minutos) {
    this -> hora = hora;
    this -> minutos = minutos;
}

Hora::Hora() {
    minutos = 0;
    hora = 0;
}

int Hora::getHora() {
    return hora;
}

int Hora::getMinutos() {
    return minutos;
}

void Hora::setMinutos(int minutos) {
    this -> minutos = minutos;
}

void Hora::setHora(int hora) {
    this -> hora = hora;
}

void Hora::muestra() {
    cout << hora << (minutos > 9 ? ":" : ":0") << minutos;
}


#endif //PROYECTO_2_HORA_H
