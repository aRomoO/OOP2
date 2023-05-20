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
    int adultos=2;
    int infantes=2;
    double credito=2500;

    //For some reason program crashes when using scanf_s... use std::cin instead

    printf_s("\n---CheckIn:---");
    printf_s("\nIngresa el nombre del huesped: ");
    //scanf_s("%s", &nombre);
    cin >> nombre;

    printf_s("\nIngresa el nombre del adultos: ");
    scanf_s("%d",&adultos);

    printf_s("\nIngresa el numero de infantes: ");
    scanf_s("%d",&infantes);

    printf_s("\nIngresa el credito disponible: ");
    scanf_s("%d",&credito);

    int numHabitacion = hotel->checkin(nombre,adultos,infantes,credito);
    if (numHabitacion != -1)
    {
        printf_s("\n CheckIn exitoso, el numero de habitacion es: #%d\n",numHabitacion);
    }
    else
    {
        printf_s("\nNo fue posible realizar el CheckIn...");
    }


}
void CheckOut(Hotel*hotel)
{
    int numHabitacion = 0;
    printf_s("# de habitaciona hacer CheckOut: ");
    scanf_s("%d",&numHabitacion);
    if (hotel->checkout(numHabitacion))
    {
        printf_s("CheckOut Exitoso!\n");
    }
    else
    {
        printf_s("NO FUE POSIBLE REALIZAR EL CHECKOUT\n");
    }

}
void realizarCargosHabitacion(Hotel*hotel)
{
    int numHabitacion;
    double monto;
    printf_s("Ingresa el numero de habitacion a hacer el cargo\n");
    scanf_s("%d",&numHabitacion);
    printf_s("Ingresa el monto del cargo\n");
    cin >> monto; //Scanf_s doesn't work

    if(hotel->realizarCargosHabitacion(numHabitacion, monto))
    {
        printf_s("CARGO EXITOSO!\n");
    }
    else
    {
        printf_s("NO SE PUEDO REALIZAR EL CARGO");
    }




}
double getTotalXTarifaBase(Hotel*hotel)
{
    return hotel->getTotalXTarifaBase();
}
void imprimeOcupacion(Hotel*hotel)
{
    hotel->imprimeOcupacion();
}

int main() {


    ///// CREATE HOTEL OBJ
    Hotel h1("ELOTEL");

    //2 preexisting  objects for testing
    h1.checkin("Fredi Romo", 3, 3, 5050);
    h1.checkin("Juan Perez", 4, 3, 2500);


    //MENU
    printf_s("----------------------------\n");
    printf_s("  Hotel Management system   \n");
    printf_s("----------------------------\n");
    bool exit = false;
    do
    {
        int opt;

        printf_s("\n----- Opciones -----\n");

        printf_s("1) CheckIn:\n");
        printf_s("2) CheckoOut:\n");
        printf_s("3) Cargos a Habitacion:\n");
        printf_s("4) Total X Tarifa base:\n");
        printf_s("5) Ocupacion del Hotel:\n");
        printf_s("0) Salir\n");
        printf_s("-------------------------\n");
        printf_s(":");

        scanf_s("%d",&opt);


            switch (opt) {
                default:
                    break;
                case 0:
                    exit=true;
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
                    printf_s("Total x Tarifa Base: %f\n", getTotalXTarifaBase(&h1));
                    break;
                case 5:
                    imprimeOcupacion(&h1);
                    break;
            }


        } while (!exit);//END WHILE
        return 1;
}//END MAIN