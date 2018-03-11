//
// Created by Jesus Anaya on 09/03/2018.
//

#ifndef PROYECTO_2_ALUMNO_H
#define PROYECTO_2_ALUMNO_H

#include <string>

using namespace std;

class Alumno{

    public:
    //Constructor por dafult y por parametros
    Alumno();
    Alumno(int, int, string);

    //Metodos de acceso y modificacion
    string getNombre();
    int getMatricula();
    int getSemestre();
    void setNombre(string);
    void setMatricula(int);
    void setSemestre(int);

    //Metodos de operacion
    void muestra();

    private:
    int matricula;
    int semestre;
    string nombre;

};

Alumno::Alumno() {
    matricula = 0;
    semestre = 0;
    nombre = "s/n";

}

Alumno::Alumno(int matricula, int semestre, string nombre) {
    this -> nombre = nombre;
    this -> semestre = semestre;
    this -> matricula = matricula;
}

string Alumno::getNombre() {
    return nombre;
}

int Alumno::getMatricula() {
    return matricula;
}

int Alumno::getSemestre() {
    return semestre;
}

void Alumno::setNombre(string nombre) {
    this -> nombre = nombre;
}

void Alumno::setMatricula(int matricula) {
    this -> matricula = matricula;
}

void Alumno::setSemestre(int semestre) {
    this -> semestre = semestre;
}

void Alumno::muestra() {
    cout << "nombre: " << nombre << "       matricula: " << matricula << "       semestre: " << semestre << endl;
}


#endif //PROYECTO_2_ALUMNO_H
