/*
Lydia Delgado Uriarte A01740532
Hugo Edgar Palomares Estrella A01741537
Actividad 03 - Herencia Persona Estudiante Maestro 
*/

#include <iostream>
using namespace std;
 
 // clases
class Persona{
    public:
        Persona();
        Persona(string, int);
        string getNombre();
        void setNombre(string);
        int getEdad();
        void setEdad(int);
    protected:
        string nombre;
        int edad;
};

class Estudiante: public Persona{
    public:
        Estudiante();
        Estudiante(string, int, string);
        string getCarrera();
        void setCarrera(string);
        void muestraDatos();
    private:
        string carrera;
};

class Maestro: public Persona{
    public:
        Maestro();
        Maestro(string, int, string);
        string getDepto();
        void setDepto(string);
        void muestraDatos();
    private:
        string depto;
};

// metodos Persona

Persona::Persona(){
    nombre = "nobody";
    edad = 0;
};
Persona::Persona(string n, int e){
    nombre = n;
    edad = e;
};

//Getters
string Persona::getNombre(){return nombre;}
int Persona::getEdad(){return edad;}

//Setters
void Persona::setNombre(string _nombre){nombre=_nombre;}
void Persona::setEdad(int _edad){edad=_edad;}


// metodos Estudiante
string Estudiante::getCarrera(){return carrera;}
void Estudiante::muestraDatos(){
    cout << nombre << "\t" << edad << "\t" << carrera << endl;
};
void Estudiante::setCarrera(string _carrera){carrera= _carrera;}

Estudiante::Estudiante(): Persona() {
    nombre = "nobody";
    edad = 0;
    carrera = "ninguna";
};
Estudiante::Estudiante(string n, int e, string c): Persona(n,e){
    nombre = n;
    edad = e;
    carrera = c;
};

//metodos Maestro
Maestro::Maestro(): Persona(){
    depto = "-";
}

Maestro::Maestro(string n , int e, string d): Persona(n, e){
    nombre = n;
    edad = e; 
    depto = d;
}

//Getters
string Maestro::getDepto(){return depto;}
//Setters
void Maestro::setDepto(string _depto){depto= _depto;}

//Imprime datos
void Maestro::muestraDatos(){
    cout << nombre << "\t" << edad << "\t" << depto << endl;
};



//Agregar maestros
void agregarMaestro(Maestro listaMaestros[0], int cantMaestros){
    int i=cantMaestros,edad;
    string nombre, depto;
    cout << endl << "Nombre del maestro a registrar: ";
    cin >> nombre;
    cout << "Edad: " ;
    cin >> edad;
    cout << "Departamento: ";
    cin >> depto;
    listaMaestros[i].setNombre(nombre);
    listaMaestros[i].setEdad(edad);
    listaMaestros[i].setDepto(depto);
    cout << "Escribe * para dejar de registrar, 1 o cualquier otro caracter para continuar " ;
}

//Agregar estudiantes
void agregarEstudiante(Estudiante listaEstudiantes[0],int cantE){
    int i=cantE, edad;
    string nombre, carrera;
    cout << endl << "Nombre del alumno a registrar: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
    cout << "Carrera: ";
    cin >> carrera;
    listaEstudiantes[i].setNombre(nombre);
    listaEstudiantes[i].setEdad(edad);
    listaEstudiantes[i].setCarrera(carrera);
    cout << "Escribe * para dejar de registrar, 1 o cualquier otro caracter para continuar " ;

};


//Mostrar maestros
void mostrarMaestros(Maestro listaMaestros[], int cantM){
    cout << endl << "      Lista de maestros \t" << endl;
     cout << "----------------------------" << endl;
    cout << "Nombre\tEdad\tDepartamento" << endl;
    for (int i=0 ; i<cantM; i++){
        cout << "----------------------------" << endl;
        listaMaestros[i].muestraDatos();
        cout << "----------------------------"<<endl;
    }

}

//Mostrar estudiantes
void mostrarEstudiantes(Estudiante listaEstudiantes[],int cantE){
    cout << endl << "      Lista de estudiantes \t" << endl;
    cout << "Nombre\tEdad\tCarrera" << endl;
    cout << "----------------------------" << endl;
    for (int i=0; i<cantE; i++){
        cout << "----------------------------" << endl;
        listaEstudiantes[i].muestraDatos();
        cout << "----------------------------" << endl;
        cout << endl;
    }
}

int main(){
    int cantMaestros=0, cantEstudiantes=0;
    char opcion;
    char continuar='0';
    Maestro listaMaestros[100];
    Estudiante listaEstudiantes[100];
    do{
        cout << endl;
        cout << "-----------MENU-----------"<< endl;
        cout << " 1) Registrar maestros " << endl;
        cout << " 2) Registrar estudiantes " << endl;
        cout << " 3) Consultar maestros" << endl;
        cout << " 4) Consultar estudiantes"<< endl;
        cout << " 5) Terminar " << endl;
        cin >> opcion; 
        switch (opcion){
            case '1':
                for (int i=cantMaestros; continuar!='*'; i=cantMaestros++){
                    agregarMaestro(listaMaestros, cantMaestros);
                    cin >> continuar;
                }
                continuar='0';
                break;
            case '2':
                for (int i=cantEstudiantes; continuar!='*'; i=cantEstudiantes++){
                    agregarEstudiante(listaEstudiantes, cantEstudiantes);
                    cin >> continuar;
                }
                continuar= '0';
                break;
            case '3':
                if (cantMaestros==0){
                    cout << "No hay ningun maestro registrado" << endl;
                }
                else{
                    mostrarMaestros(listaMaestros, cantMaestros);
                }
                break;
                
            case '4':
                if (cantEstudiantes==0){
                    cout << "No hay ningun estudiante registrado" << endl;
                }
                else{
                    mostrarEstudiantes(listaEstudiantes, cantEstudiantes);
                }
                break;
            case '5':
                break;
            default: 
                cout << endl << "Ingresa una opcion correcta" << endl;
        }
    } while (opcion!= '5');
    return 0;
};