//
// ALFREDO ROMO OSORNO
// a01643235@tec.mx
// DIAGNOSTICO OOP
//

#include <iostream>
#include "Habitacion.h"
#include "Hotel.h"
using namespace std;


void CheckIn(Hotel*hotel)
{
    string nombre;
    int adultos;
    int infantes;
    double credito;

    printf_s("\n---CheckIn:---");
    printf_s("\nIngresa el nombre del huesped: ");
    scanf_s("%s",&nombre);

    printf_s("\nIngresa el nombre del adultos: ");
    scanf_s("%s",&adultos);

    printf_s("\nIngresa el numero de infantes: ");
    scanf_s("%s",&infantes);

    printf_s("\nIngresa el credito disponible: ");
    scanf_s("%s",&credito);

    int numHabitacion = hotel->checkin(nombre,adultos,infantes,credito);
    if (numHabitacion != -1)
    {
        printf_s("\n CheckIn exitoso, el numero de habitacion es: %d",numHabitacion)
    }


}

void CheckOut(Hotel*hotel)
{
    int numHabitacion = 0;
    hotel->checkout(numHabitacion);
}

void realizarCargosHabitacion(Hotel*hotel)
{
    int numHabitacion;
    double monto;
    hotel->realizarCargosHabitacion(numHabitacion, monto);
}
void getTotalXTarifaBase(Hotel*hotel)
{
    printf_s("Total x Tarifa Base: %f\n", hotel->getTotalXTarifaBase());
}
void imprimeOcupacion(Hotel*hotel)
{
    hotel->imprimeOcupacion();
}


int main() {

    //Prueba métodos de Habitación
    /*Habitacion a1(100);
    a1.setNumero(200);
    a1.getNumero();
    a1.setDisponible(true);
    a1.getDisponible();
    a1.checkin("Alfredo Romo Osorno", 2, 2, 5000);
    a1.getTarifaBase();
    a1.realizarCargo(1000);
    a1.toString();
    a1.checkOut();*/
    ///////////

    ///// PUEBA HOTEL
    Hotel h1("ELOTEL");
    /*
    cout << h1.checkin("Fredi Romo", 3, 3, 5050) << endl;
    cout << h1.checkin("Juan Perez", 4, 3, 2500) << endl;
    h1.imprimeOcupacion();
    cout << h1.getTotalXTarifaBase();*/

    //MENU
    printf_s("----------------------------");
    printf_s("  Hotel Management system   ");
    printf_s("----------------------------\n");

    while (true) {
        int opt;

        printf_s("----- Opciones -----\n");

        printf_s("1) CheckIn:\n");
        printf_s("2) CheckoOut:\n");
        printf_s("3) Cargos a Habitacion:\n");
        printf_s("4) Total X Tarifa base:\n");
        printf_s("5) Ocupacion del Hotel:\n");
        printf_s("-------------------------\n");
        printf_s(":");

        scanf_s("%d",&opt);


            switch (opt) {
                default:
                    break;
                case 1:
                    CheckIn(&h1);
                    break;
                case 2:
                    CheckOut(&h1);
                    break;
                case 3:
                    realizarCargosHabitacion(&h1);
                    break;
                case 4:
                    getTotalXTarifaBase(&h1);
                    break;
                case 5:
                    imprimeOcupacion(&h1);
                    break;
            }

        }//END MAIN
        return 0;
}