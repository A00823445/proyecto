//
// Created by Jesus Anaya on 10/03/2018.
//

#ifndef PROYECTO_2_CLASES_H
#define PROYECTO_2_CLASES_H

#include "Hora.h"
#include <string>

using namespace std;

class Clases{

    public:
    Clases();

    //Metodos de acceso
    Hora getHoraEnt();
    Hora getHoraSal();
    string getNombreMateria();
    int getClaveSalon();
    int getClaveClase();

    //Metodos de modificacion
    void setHoraEnt(Hora);
    void setHoraSal(Hora);
    void setNombreMateria(string);
    void setClaveSalon(int);
    void setClaveClase(int);

    private:
    Hora horaEnt;
    Hora horaSal;
    string nombreMateria;
    int claveSalon;
    int claveClase;
    int numLugares;
    int listaAlumno[10];


};

Clases::Clases() {
    Hora horaEnt;
    Hora horaSal;
    nombreMateria = "s/n";
    claveSalon = 0;
    claveClase = 0;
    numLugares = 0;

    for (int i = 0; i < 10; i++) {
        listaAlumno[i] = 0;
    }


}

Hora Clases::getHoraEnt() {
    return horaEnt;
}

Hora Clases::getHoraSal() {
    return horaSal;
}

string Clases::getNombreMateria() {
    return nombreMateria;
}

int Clases::getClaveSalon() {
    return claveSalon;
}

int Clases::getClaveClase() {
    return claveClase;
}

void Clases::setHoraSal(Hora horaSal) {
    this -> horaSal = horaSal;
}

void Clases::setHoraEnt(Hora horaEnt) {
    this -> horaEnt = horaEnt;
}

void Clases::setNombreMateria(string nombreMateria) {
    this -> nombreMateria = nombreMateria;
}

void Clases::setClaveSalon(int claveSalon) {
    this -> claveSalon = claveSalon;
}

void Clases::setClaveClase(int claveClase) {
    this -> claveClase = claveClase;
}





#endif //PROYECTO_2_CLASES_H
