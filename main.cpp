#include <iostream>
#include <fstream>
#include <string>


using namespace std;

#include "Alumno.h"
#include "Salon.h"
#include "Clases.h"

int main(){

    //Declaracion de variables
    int op, clavesalon, minutose, minutoss, pos = 0, pos2 = 0;
    bool flag = true, flag2 = true, flag3 = false, flag4 = false, flag5 = true, flag6 = true, flag7 = true, flag8 = true, flag9 = true;
    int edificio, piso, salon, clave, matricula, semestre, numclases, claveclase, horae, horas;
    string nombre;
    ifstream archEnt1, archEnt2;

    Clases clases[10];
    Alumno alumnos[15];
    Salon salones[5];

    //Abrir archivos de texto a leer
    archEnt1.open("Alumno.txt");
    archEnt2.open("Salon.txt");




    //Lectura de archivos
    for (int i = 0; i < 5 && !archEnt2.eof(); i++) {

        //Lectura de archivos
        archEnt2 >> edificio >> piso >> salon >> clave;

        //Declaracion de variable auxiliar
        Salon aux(edificio, piso, salon, clave);
        salones[i] = aux;
    }

    for (int i = 0; i < 15 && !archEnt1.eof(); i++) {

        //Lectura de archivos
        archEnt1 >> matricula >> semestre;
        getline(archEnt1, nombre);

        //Declaracion de variable auxiliar
        Alumno aux2(matricula, semestre, nombre);
        alumnos[i] = aux2;
    }


    //Cerrar archivos
    archEnt2.close();
    archEnt1.close();

    //Preguntar cuantas clases se van a dar de alta
    cout << "Ingrese el numero de clases a dar de alta: ";
    cin >> numclases;

    while (numclases < 1 || numclases > 10) {
        //Verificar si escribio un numero correcto
        cout << "Numero incorrecto ingrese un valor entre 1 y 10: ";
        cin >> numclases;

    }

    //Dar de alta clases
    for (int i = 0; i < numclases; i++) {

        //Preguntar nombre de la clase:
        cout << "Ingrese el nombre de la materia:  ";
        cin >> nombre;

        //Preguntar clave de la clase y verificar si ya existe
        cout << "Ingrese la clave de la clase: ";
        cin >> claveclase;

        flag2 = true;

        for (int k = 0; k < i && flag2; k++) {
            if(claveclase == clases[k].getClaveClase())
                flag2 = false;
        }

        while (!flag2){
            cout << "Clave de clase ya registrada por favor ingrese otra clave: ";
            cin >> claveclase;

            flag2 = true;

            for (int k = 0; k < i && flag2; k++) {
                if(claveclase == clases[k].getClaveClase())
                    flag2 = false;
            }

        }

        //Preguntar hora de entrada y de salida validando que este entre un valor de 0 a 23
        cout << "Ingrese la hora y minutos de entrada el valor de a hora entre 0 y 23 el valor de los minutos entre 0 y 59: ";
        cin >> horae >> minutose;

        while (horae < 0 || horae > 23 || minutose < 0 || minutose > 59) {
            cout << "Ingreso una hora incorrecta por favor ingrese de nuevo: ";
            cin >> horae >> minutose;
        }


        cout << "Ingrese la hora y minutos de salida el valor de a hora entre 0 y 23 el valor de los minutos entre 0 y 59: ";
        cin >> horas >> minutoss;

        while (horas < 0 || horas > 23 || minutoss < 0 || minutoss > 59) {
            cout << "Ingreso una hora incorrecta por favor ingrese de nuevo: ";
            cin >> horas >> minutoss;
        }

        //Preguntar por la clave del salon
        cout << "Ingrese la clave del salon: ";
        cin >> clave;

        flag = true;

        for (int j = 0; j < 5 && flag; j++) {
            if (clave == salones[j].getClavesalon()) {
                flag = false;
            }
            pos = j;
        }
        //Comprobar si existe la clave
        while (flag) {
            cout << "Clave no encontrada ingrese otra clava por favor: ";
            cin >> clave;

            flag = true;

            for (int j = 0; j < 5 && flag; j++) {
                if (clave == salones[j].getClavesalon()) {
                    flag = false;
                }
                pos = j;
            }
        }

        //LLenado de clases:
        clases[i].setNombreMateria(nombre);
        clases[i].setClaveClase(claveclase);
        clases[i].setClaveSalon(clave);
        clases[i].setHoraEnt({horae, minutose});
        clases[i].setHoraSal({horas, minutoss});
        clases[i].setPos(pos);
    }


    do {

        // MOSTRAR EL MENU
        cout << " 1) Consulta de todas las clases. " << endl;
        cout << " 2) Dar de alta un alumno en una clase. " << endl;
        cout << " 3) Consulta de clases por hora de entrada. " << endl;
        cout << " 4) Consulta por clave de clase. " << endl;
        cout << " 5) Consulta de clases en un Salon. " << endl;
        cout << " 6) Consulta la lista de clases que cursa un Alumno. " << endl;
        cout << " 7) Salir. " << endl;
        cout << "Ingrese su opcion: ";
        cin >> op;



        //CASOS
        switch (op) {

            ///Consulta de todas las clases
            case 1:
                //Imprimir los datos de las clases sin los alumnos inscritos
                for (int i = 0; i < numclases; ++i) {
                    cout << "Clase " << i+1 << ": " << endl;
                    cout << "Nombre: " << clases[i].getNombreMateria() << "     claveClase: "
                         << clases[i].getClaveClase() << endl;
                    cout << "Hora de entrada: ";
                    clases[i].getHoraEnt().muestra();
                    cout << "       Hora de salida: ";
                    clases[i].getHoraSal().muestra();
                    cout << "\n";
                    salones[clases[i].getPos()].muestra();
                }
                break;
            case 2:

                //Pedir la matricula del alumno
                cout << "Ingrese la matricula del alumno a dar de alta: ";
                cin >> matricula;

                //Pedir la clave de la clase
                cout << "Ingresar la clave de la clase: ";
                cin >> claveclase;

                //Pedir la clave del salon;
                cout << "Ingrese la clave del salon: ";
                cin >> clavesalon;

                flag3 = false;
                flag4 = false;
                //Buscar si existe la clave de la clase a solicitar
                for (int j = 0; j < numclases && !flag3; j++) {
                    if(claveclase == clases[j].getClaveClase()){
                        flag3 = true;
                        pos2 = j;
                    }
                }

                if(flag3){
                    for (int i = 0; i < 15 && !flag4; i++) {
                        if(matricula == alumnos[i].getMatricula())
                        {
                            flag4 = true;
                        }
                    }

                    if(flag4){
                        if(clases[pos2].agregar(clavesalon,matricula)){
                            cout << "Agregado correctamente\n";
                        }
                    } else{
                        cout << "Matricula incorrecta\n";
                    }

                }
                else{
                    cout << "No existe la clase ingresada\n";
                }

                break;
            case 3:

                //Preguntar hora de entrada validadando si esta en el formato correcto:
                cout << "Ingrese la hora y minutos de entrada el valor de a hora entre 0 y 23 el valor de los minutos entre 0 y 59: ";
                cin >> horae >> minutose;

                while (horae < 0 || horae > 23 || minutose < 0 || minutose > 59) {
                    cout << "Ingreso una hora incorrecta por favor ingrese de nuevo: ";
                    cin >> horae >> minutose;
                }

                flag5 = true;

                for (int i = 0; i < numclases; i++) {
                    if(horae == clases[i].getHoraEnt().getHora() && minutose == clases[i].getHoraEnt().getMinutos()){
                        flag5 = false;
                        cout << "Clase " << i+1 << ": " << endl;
                        cout << "Nombre: " << clases[i].getNombreMateria() << "     claveClase: "
                             << clases[i].getClaveClase() << endl;
                        cout << "Hora de entrada: ";
                        clases[i].getHoraEnt().muestra();
                        cout << "       Hora de salida: ";
                        clases[i].getHoraSal().muestra();
                        cout << "\n";
                        salones[clases[i].getPos()].muestra();
                    }
                }

                if(flag5){
                    cout << "No hay clases a esa hora\n";
                }

                break;

            case 4:

                cout << "Ingrese la clave de la clase a buscar: ";
                cin >> claveclase;

                flag6 = true;
                for (int i = 0; i < numclases && flag6; i++) {
                    if(claveclase == clases[i].getClaveClase()){

                        cout << "Clase " << i+1 << ": " << endl;
                        cout << "Nombre: " << clases[i].getNombreMateria() << "     claveClase: "
                             << clases[i].getClaveClase() << endl;
                        cout << "Hora de entrada: ";
                        clases[i].getHoraEnt().muestra();
                        cout << "       Hora de salida: ";
                        clases[i].getHoraSal().muestra();
                        cout << "\n";
                        salones[clases[i].getPos()].muestra();
                        cout << "Alumnos inscritos\n";

                        for (int j = 0; j < clases[i].getNumLugares(); j++) {

                            for (int k = 0; k < 15; k++) {
                                if(clases[i].getListaAlumno(j) == alumnos[k].getMatricula()){
                                    alumnos[k].muestra();
                                    break;
                                }
                            }
                        }

                        flag6 = false;
                    }
                }

                break;

            case 5:

                //Preguntar por la clave del salon
                cout << "Ingrese la clave del salon: ";
                cin >> clave;

                flag = true;

                for (int j = 0; j < 5 && flag; j++) {
                    if (clave == salones[j].getClavesalon()) {
                        flag = false;
                    }
                    pos = j;
                }
                //Comprobar si existe la clave
                while (flag) {
                    cout << "Clave no encontrada ingrese otra clava por favor: ";
                    cin >> clave;

                    flag = true;

                    for (int j = 0; j < 5 && flag; j++) {
                        if (clave == salones[j].getClavesalon()) {
                            flag = false;
                        }
                        pos = j;
                    }
                }

                flag7 = true;

                for (int i = 0; i < numclases; i++) {
                    if(salones[pos].getClavesalon() == clases[i].getClaveSalon()){
                        cout << "Clase " << i+1 << ": " << endl;
                        cout << "Nombre: " << clases[i].getNombreMateria() << "     claveClase: "
                             << clases[i].getClaveClase() << endl;
                        cout << "Hora de entrada: ";
                        clases[i].getHoraEnt().muestra();
                        cout << "       Hora de salida: ";
                        clases[i].getHoraSal().muestra();
                        cout << "\n";
                        salones[clases[i].getPos()].muestra();
                        flag7 = false;
                    }
                }

                if(flag7){
                    cout << "No hay ninguna clase registrada con esa clave de salon\n";
                }
                break;

            case 6:
                //Pedir la matricula del alumno
                cout << "Ingrese la matricula del alumno a buscar: ";
                cin >> matricula;
                flag8 = true;
                flag9 = true;
                for(int i = 0; i < 15 && flag8; i++){
                    if(matricula == alumnos[i].getMatricula()){
                        alumnos[i].muestra();

                        for (int j = 0; j < numclases; j++) {
                            for (int k = 0; k < clases[j].getNumLugares(); ++k) {
                                if(matricula == clases[j].getListaAlumno(k)){
                                    cout << "Clase " << j+1 << ": " << endl;
                                    cout << "Nombre: " << clases[j].getNombreMateria() << "     claveClase: "
                                         << clases[j].getClaveClase() << endl;
                                    cout << "Hora de entrada: ";
                                    clases[j].getHoraEnt().muestra();
                                    cout << "       Hora de salida: ";
                                    clases[j].getHoraSal().muestra();
                                    cout << "\n";
                                    salones[clases[j].getPos()].muestra();
                                    flag9 = false;
                                }
                            }
                        }


                        flag8 = false;
                    }
                }

                if(flag8){
                    cout << "La matricula que proporciono no esta asociada a ningun alumno\n";
                }
                if(flag9){
                    cout << "El alumno no tiene materias inscritas\n";
                }
                break;
            default:
                cout << "Opcion incorrecta ingrese otro numero\n";
                break;
        }

    } while (op != 7);

    cout << "Gracias por usar nuestro programa\n";

    return 0;
}
