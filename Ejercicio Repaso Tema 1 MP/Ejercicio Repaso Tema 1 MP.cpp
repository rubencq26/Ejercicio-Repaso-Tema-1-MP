// Ejercicio Repaso Tema 1 MP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

class socio {
    char* nombre; // Puntero para almacenar dinámicamente el nombre
    int edad;

public:
    socio(); // Constructor por defecto
    socio(const char* nombre, int edad); // Constructor parametrizado
    socio(const socio& s); // Constructor de copia
    ~socio(); // Destructor para liberar la memoria
    void setnombre(const char* nombre); // Establece el nombre
    void ver() const; // Muestra los datos
    socio& operator=(const socio& s); // Sobrecarga del operador de asignación
    friend ostream& operator<<(ostream& os, const socio& s); // Sobrecarga del operador <<
    bool operator==(const socio& s) const; // Sobrecarga del operador ==
};

// Constructor por defecto
socio::socio() {
    nombre = new char[11]; // Asigna memoria para el nombre por defecto
    strcpy(nombre, "Sin Nombre"); // Inicializa el nombre
    edad = 0;
}

// Constructor parametrizado
socio::socio(const char* nombre, int edad) {
    this->nombre = new char[strlen(nombre) + 1]; // Reserva memoria
    strcpy(this->nombre, nombre); // Copia el nombre
    this->edad = edad;
}

// Constructor de copia
socio::socio(const socio& s) {
    nombre = new char[strlen(s.nombre) + 1]; // Reserva memoria
    strcpy(nombre, s.nombre); // Copia el nombre
    edad = s.edad; // Copia la edad
}

// Destructor
socio::~socio() {
    delete[] nombre; // Libera la memoria asignada
}

// Método setnombre
void socio::setnombre(const char* nombre) {
    delete[] this->nombre; // Libera la memoria existente
    this->nombre = new char[strlen(nombre) + 1]; // Reserva nueva memoria
    strcpy(this->nombre, nombre); // Copia el nuevo nombre
}

// Método ver
void socio::ver() const {
    cout << "Nombre: " << nombre << "   Edad: " << edad << endl;
}

// Sobrecarga del operador de asignación
socio& socio::operator=(const socio& s) {
    if (this != &s) { // Evitar autoasignación
        delete[] nombre; // Libera la memoria existente
        nombre = new char[strlen(s.nombre) + 1]; // Reserva memoria
        strcpy(nombre, s.nombre); // Copia el nombre
        edad = s.edad; // Copia la edad
    }
    return *this;
}

// Sobrecarga del operador <<
ostream& operator<<(ostream& os, const socio& s) {
    os << "Nombre: " << s.nombre << ", Edad: " << s.edad;
    return os;
}

// Sobrecarga del operador ==
bool socio::operator==(const socio& s) const {
    return (edad == s.edad && strcmp(nombre, s.nombre) == 0);
}

int main() {
    socio c1("Juan Jose", 27); // socio de nombre "Juan Jose" y edad 27 años
    socio c2("Paloma", 20); // socio de nombre "Paloma" y edad 20 años
    socio c3 = c2; // el socio c3 tendrá el mismo nombre y edad que c2
    c2.setnombre("Paloma Maria"); // cambia el nombre del socio c2
    c1.ver(); c2.ver(); c3.ver(); cout << endl; // muestra por pantalla nombre y edad de socios c1, c2 y c3
    socio c4(c2); // crea el socio c4 con los mismos datos que el socio c2
    c2.ver(); c4.ver(); cout << endl;
    if (c4 == c2) // pregunta si los socios c4 y c2 se llaman igual y tienen la misma edad
        cout << c4 << " == " << c2 << endl;
    c3 = c2 = c1; // los socios c3, c2 y c1 se van a llamar igual y tendrán la misma edad
    cout << c1 << ", " << c2 << ", " << c3 << endl;
    c3.setnombre("Ana");
    c2 = c1;
    c1.setnombre("Luis");
    socio T[3];
    T[0] = c1; T[1] = c2; T[2] = c3;
    for (int i = 0; i < 3; i++)
        cout << "T[" << i << "] objeto " << (long)&T[i] << ": " << T[i] << endl;
    return 0;
}