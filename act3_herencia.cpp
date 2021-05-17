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
    cout << "Departamento: " << depto ;
};
//main
int main(){

    return 0;
};