//
// Created by fredi on 2023-05-18.
//


using namespace std;
#include "Habitacion.h"
#include "string"
#ifndef OOP_HOTEL_H
#define OOP_HOTEL_H

class Hotel{
private:
    string nombre;
    int numHabitaciones = 50;
    Habitacion * habitaciones[50] = {nullptr};
public:
    Hotel(string);
    int checkin(string, int, int, double);
    bool checkout(int);
    bool realizarCargosHabitacion(int, double);
    double getTotalXTarifaBase();
    void imprimeOcupacion();
};

Hotel::Hotel(string _nombre) {
    nombre = _nombre;
    numHabitaciones = 50;

}

int Hotel::checkin(string _nombreHuesped, int _adultos, int _infantes, double _credito) {

    //Create Habitacion object and store it on the first empty element of the Array//

    int i;
    for (i = 0; i <= numHabitaciones; i++)
    {
        if (habitaciones[i] == nullptr) //Check if there's and empty array element al habitaciones[i]
        {

            habitaciones[i] = new Habitacion(100+i); //Room number = 100 + array index
            habitaciones[i]->checkin(_nombreHuesped,_adultos,_infantes,_credito); //Call the CheckIn Method
            return habitaciones[i]->getNumero();
        }

    }
    //If Array is full, return -1
    return-1;

}

bool Hotel::checkout(int _numero) {
    //Validate room number
    if (_numero >= 100 && _numero <= 149)
    {
        habitaciones[_numero - 100] = nullptr; //get array element (0 to 49) by subtracting 100 from room number
        return true;
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int _numero, double _monto) {

    //get array element (0 to 49) by subtracting 100 from room number

    if (_numero > 99 && _numero<150){
        if (!habitaciones[_numero -100]->getDisponible()) //Validate room is Checked in
        {
            habitaciones[_numero -100]->realizarCargo(_monto);
            //DEBUG
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }




}

double Hotel::getTotalXTarifaBase() {
    double total = 0;
    for (int i = 0; i<numHabitaciones; i++)
    {
        if (habitaciones[i] != nullptr) //If there's an empty array element, don't add it to the sum
        {
            total += habitaciones[i]->getTarifaBase();
        }
    }

    return total;
}

void Hotel::imprimeOcupacion() {
    for (int i = 0; i<numHabitaciones; i++)
    {
        if (habitaciones[i] != nullptr) //If there's and empty array element, don't print it
        {
            cout << habitaciones[i]->toString()<<endl;
        }
    }
}


#endif //OOP_HOTEL_H
