//
// Created by Jesus Anaya on 10/03/2018.
//

#ifndef PROYECTO_2_SALON_H
#define PROYECTO_2_SALON_H

using namespace std;

class Salon{

    public:
    //Constructores por default
    Salon();
    Salon(int, int, int, int);

    //Metodos de acceso
    int getSalon();
    int getEdificio();
    int getPiso();
    int getClavesalon();

    //Metodos de modificacion
    void setSalon(int);
    void setEdificio(int);
    void setPiso(int);
    void setClavesalon(int);

    void muestra();

    private:
    int edificio;
    int piso;
    int salon;
    int clavesalon;
};

Salon::Salon(int salon, int clavesalon, int edificio, int piso) {
    this -> salon = salon;
    this -> clavesalon = clavesalon;
    this -> edificio = edificio;
    this -> piso = piso;
}

Salon::Salon() {
    edificio = 0;
    piso = 0;
    salon = 0;
    clavesalon = 0;

}

int Salon::getSalon() {
    return salon;
}

int Salon::getEdificio() {
    return edificio;
}

int Salon::getPiso() {
    return piso;
}

int Salon::getClavesalon() {
    return clavesalon;
}

void Salon::setSalon(int salon) {
    this -> salon = salon;
}

void Salon::setEdificio(int edificio) {
    this -> edificio = edificio;
}

void Salon::setPiso(int piso) {
    this -> piso = piso;
}

void Salon::setClavesalon(int clavesalon) {
    this -> clavesalon = clavesalon;
}

void Salon::muestra() {

    cout <<  "Salon: " << salon << "        clave Salon: " << clavesalon << "       edificio: " << edificio << "      salon: " << salon;

}


#endif //PROYECTO_2_SALON_H
