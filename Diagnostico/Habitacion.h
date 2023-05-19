//
// Created by fredi on 2023-05-18.
//
using namespace std;
#include "string"
#ifndef OOP2_HABITACION_H
#define OOP2_HABITACION_H


class Habitacion {
private:
    int numero;
    string nombre;
    int adultos;
    int infantes;
    double credito;
    double cargo;
    bool disponible;
public:
    Habitacion(); //default constructor
    Habitacion(int); //constructor with room number
    void setNumero(int);
    int getNumero();
    void setDisponible(bool);
    bool getDisponible();
    bool checkin(string, int, int, double);
    bool checkOut();
    int getTarifaBase();
    bool realizarCargo(double);
    string toString();
};

Habitacion::Habitacion() {
    numero = 0;
    nombre = "";
    adultos = 0;
    infantes = 0;
    credito = 0;
    cargo = 0;
    disponible = true;
}
Habitacion::Habitacion(int _numero) {
    numero = _numero;
    disponible = true;
}
void Habitacion::setNumero(int _numero) {
    numero = _numero;
}
int Habitacion::getNumero() {
    return numero;
}
void Habitacion::setDisponible(bool _disponible) {
    disponible = _disponible;
}
bool Habitacion::getDisponible() {
    return disponible;
}
bool Habitacion::checkin(string _nombre, int _adultos, int _infantes, double _credito) {
    /*recibe el nombre del huésped a registrar en la habitación, el número de adultos y de niños que se alojarán en la habitación y cuánto
    crédito dejarán abierto para compras. Inicializa los atributos que se reciben como parámetros y además marca la habitación como no disponible.*/

    //Check if room is available
    if(disponible)
    {
        nombre = _nombre;
        adultos = _adultos;
        infantes = _infantes;
        credito = _credito;
        cargo = 0;
        disponible = false;
        return true;
    }
    //if room is occupied, return false
    else return false;

}
bool Habitacion::checkOut() {
    /*Si estaba ocupada deja el nombre del huésped como un String vacío y los atributos nombre,
        adultos, infantes, cargos y crédito los establece en 0 y marca la habitación como disponible y el método regresa true.*/

    //Check if room is occupied, can't do checkout to an empty room
    if (!disponible) {
        nombre = "";
        adultos = 0;
        infantes = 0;
        cargo = 0;
        credito = 0;
        disponible = true;
        return true;
    }
    //If the room is not occupied, return false
    else return false;
}
int Habitacion::getTarifaBase() {
    //$450.00 pesos y $150.00 por cada niño
    return (450*adultos+150*infantes);
}
bool Habitacion::realizarCargo(double _monto) {
    if (_monto >= 0 || _monto <= credito) //Validate _monto is 0 or more, and it doesn't exceed client credit
    {
        cargo += _monto;
        credito -= _monto;
        return true;
    }
    else
    {
        return false;
    }
}
string Habitacion::toString() {

    return to_string(numero)+",Huesped:"+nombre+",Tarifa Base:"+to_string(getTarifaBase())+",Credito:"+to_string(credito)+",Cargos:"+to_string(cargo);
    // FORMAT: [# habitacion],Huesped:[nombre],Tarifa Base:[tarifaBase],Credito:[Credito],Cargos:[cargos]

    // EXAMPLE:  100,Huesped:Gerardo Salinas,Tarifa Base:800.0,Credito:3000.0,Cargos:2500
};

#endif //OOP2_HABITACION_H
