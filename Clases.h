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
    int getListaAlumno(int);
    int getPos();
    int getNumLugares();

    //Metodos de modificacion
    void setHoraEnt(Hora);
    void setHoraSal(Hora);
    void setNombreMateria(string);
    void setClaveSalon(int);
    void setClaveClase(int);
    void setPos(int);


    //Metodos de operacion
    bool agregar(int, int);


    private:
    Hora horaEnt;
    Hora horaSal;
    string nombreMateria;
    int claveSalon;
    int claveClase;
    int numLugares;
    int listaAlumno[10];
    int pos;

};

Clases::Clases() {
    Hora horaEnt;
    Hora horaSal;
    nombreMateria = "s/n";
    claveSalon = 0;
    claveClase = 0;
    numLugares = 0;
    pos = 0;
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

bool Clases::agregar(int claveSalon, int matricula) {

    if(claveSalon != this -> claveSalon){
        cout << "La clave del salon es incorrecta" << endl;
        return false;
    }
    if (numLugares >= 10){
        cout << "Ya no hay lugares disponibles: " << endl;
        return false;
    }

    for (int i = 0; i < numLugares; i++) {
        if (listaAlumno[i] == matricula) {
            cout << "Ya hay alguien con esa matricula" << endl;
            return false;
        }
    }

    listaAlumno[numLugares] = matricula;
    numLugares++;

    return true;
}

int Clases::getListaAlumno(int i) {
    return listaAlumno[i];
}

int Clases::getPos() {
    return pos;
}

void Clases::setPos(int pos) {
    this -> pos = pos;
}

int Clases::getNumLugares() {
    return numLugares;
}


#endif //PROYECTO_2_CLASES_H
