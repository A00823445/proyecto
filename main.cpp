#include <iostream>
#include <fstream>


using namespace std;

#include "Hora.h"
#include "Alumno.h"
#include "Salon.h"
#include "Clases.h"

int main() {

    int op,clavesalon;
    bool flag;
    ifstream archEnt1,archEnt2;
    Clases arrclases[10];
    Alumno arralumno[15];
    Salon arrsalon[5];

    archEnt1.open("Alumno");
    archEnt2.open("Salon");

    /////////////////////////////
    int edificio,piso,salon,clave;

    for(int i = 0; i < 5 && archEnt2.eof() ; i++){

        archEnt2 >> edificio >> piso >> salon >> clave;

        Salon aux(edificio,piso,salon,clave);

        arrsalon[i] = aux;

    }
    archEnt2.close();





    archEnt1.close();








    do {

        // MOSTRAR EL MENU
        cout << " 1) Consulta de todas las clases. " << endl;
        cout << " 2) Dar de alta un alumno en una clase. " << endl;
        cout << " 3) Consulta de clases por hora de entrada. " << endl;
        cout << " 4) Consulta por clave de clase. " << endl;
        cout << " 5) Consulta de clases en un Salon. " << endl;
        cout << " 6) Consulta la lista de clases que cursa un Alumno. " << endl;
        cout << " 7) Salir. " << endl;

        cout << endl;

        cin >> op;
        cout << endl;


        //CASOS
        switch (op) {

            ///Consulta de todas las clases
            case 1:

                arrsalon->muestra();

                cout << endl;

                break;

            case 2:

                cout << "Ingrese clave de la clase:  ";
                cin >> clavesalon;

                cout << "Ingrese clave de la clase:  ";
                cin >> clavesalon;



                flag = false;

                for(int i = 0; i < 10; i++){

                    if(clavesalon == i){
                        flag = true;
                    }

                }

                break;
        }

    }while(op != 7);





    return 0;
}