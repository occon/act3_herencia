#include <iostream>

using namespace std;
 
 // clases
class Persona{
    public:
        Persona();
        Persona(string, int);
        string getNombre();
        void setNombre();
        int getEdad();
        void setEdad();
    protected:
        string nombre;
        int edad;
};

class Estudiante: public Persona{
    public:
        Estudiante();
        Estudiante(string, int, string);
        string getCarrera();
        void setCarrera();
        void muestraDatos();
    private:
        string carrera;
};

// metodos Persona
string Persona::getNombre(){return nombre;}
int Persona::getEdad(){return edad;}

Persona::Persona(){
    nombre = "nobody";
    edad = 0;
};
Persona::Persona(string n, int e){
    nombre = n;
    edad = e;
};

// metodos Estudiante
string Estudiante::getCarrera(){return carrera;}
void Estudiante::muestraDatos(){
    cout << "Nombre\tEdad\tCarrera" << endl;
    cout << nombre << "\t" << edad << "\t" << carrera << endl;
};

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