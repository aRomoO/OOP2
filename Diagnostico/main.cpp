//
// Created by fredi on 2023-05-18.
//

#include <iostream>
#include "Habitacion.h"
#include "Hotel.h"
#include "string"
using namespace std;

int main() {

    Habitacion a1(100);

    a1.setNumero(200);
    a1.getNumero();
    a1.setDisponible(true);
    a1.getDisponible();
    a1.checkin("Alfredo Romo Osorno", 2, 2, 5000);
    a1.getTarifaBase();
    a1.realizarCargo(1000);
    a1.toString();
    a1.checkOut();

    Hotel h1("FRHOTEL");
    cout << h1.checkin("Fredi Romo", 3, 3, 5050) << endl;
    cout << h1.checkin("Juan Perez", 4, 3, 2500) << endl;
    h1.imprimeOcupacion();


    return 0;
}
