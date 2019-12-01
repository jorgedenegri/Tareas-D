#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <string>
#include "date.h"

using namespace std;


class Medicamento
{
    string nombre;
    int cantidad;
    Time fechaVencimiento;

public:

    Medicamento() {
        std::cout<<"Digite nombre: ";std::getline(cin,nombre);
        std::cout<<"digite cantidad: ";std::cin>>cantidad;

    }
    string getNombre() { return nombre; }
    int getCantidad() { return cantidad; }

    void ModCantidad(int a){
        cantidad += a;
    }

};

#endif //MEDICAMENTO_H