#include <iostream>
#include <string>
using namespace std;

// CLASE BASE: VEHICULO
class Vehiculo {
protected:
    string numeroPlaca;
    string color;
    string marca;
    int velocimetro;

public:
    Vehiculo(string, string, string, int);
    void mostrarDatos();
    void CambiarVelocidad(int);
};

Vehiculo::Vehiculo(string numP, string col, string mar, int vel) {
    numeroPlaca = numP;
    color = col;
    marca = mar;
    velocimetro = vel;
}

void Vehiculo::mostrarDatos() {
    cout << "Vehiculo de marca " << marca << " del color " << color
         << " va a una velocidad de " << velocimetro << " con la placa " << numeroPlaca << endl;
}

void Vehiculo::CambiarVelocidad(int cambv) {
	velocimetro = cambv;
}


// CLASE DERIVADA: AUTOMOVIL
class Automovil : public Vehiculo {
private:
    int cantidadPuertas;
    int cantidadPasajeros;

public:
    Automovil(string, string, string, int, int, int);
    void mostrarAutomovil();
    void subirPasajeros(int);
    void bajarPasajeros(int);

};

Automovil::Automovil(string numP, string col, string mar, int vel, int cantPue, int cantPas)
    : Vehiculo(numP, col, mar, vel) {
    cantidadPuertas = cantPue;
    cantidadPasajeros = cantPas;
}

void Automovil::mostrarAutomovil() {
    mostrarDatos();
    cout << "Numero de Puertas " << cantidadPuertas
         << " y Numero de Pasajeros " << cantidadPasajeros << endl;
}

void Automovil::subirPasajeros(int sub) {
	cantidadPasajeros = sub + cantidadPasajeros;
}

void Automovil::bajarPasajeros(int baj) {
	cantidadPasajeros = cantidadPasajeros - baj;
}

// CLASE DERIVADA: CAMION
class Camion : public Vehiculo {
private:
    string carga;
    
public:
    Camion(string, string, string, int, string);
    void mostrarCamion();
    void cambiarCarga(string);
    
};

Camion::Camion(string numP, string col, string mar, int vel, string c): Vehiculo(numP, col, mar, vel) {
    carga = c;
}

void Camion::mostrarCamion() {
    mostrarDatos();

    cout << "Tiene una carga de " << carga;

    cout << endl;
}

void Camion::cambiarCarga(string cambc) {
	carga = cambc;
}

// PROGRAMA PRINCIPAL
int main() {

    Vehiculo v("AXGH56QR2", "Rojo", "Toyota", 45);
    v.CambiarVelocidad(20);
    v.mostrarDatos();
	cout << endl;

    Automovil a("UT43E9FG1", "Amarillo", "Nissan", 75, 4, 20);
    a.subirPasajeros(5);
    a.bajarPasajeros(2);
    a.mostrarAutomovil();
    cout << endl;
    
    Camion c("FV328JF4L", "Blanco", "Volvo", 60, "Cemento");
    c.cambiarCarga("Tierra");
	c.mostrarCamion();
    cout << endl;

    return 0;
}

