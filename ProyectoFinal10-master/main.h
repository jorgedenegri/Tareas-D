#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "date.h"
#include "usuario.h"
#include "persona.h"
#include "medico.h"
#include "enfermeros.h"
#include "paciente.h"
#include "medicamentos.h"

void agregarPaciente(void){

    ostringstream aux;
    string text;

    Paciente tem ;

    aux << tem.getApellido() << "___" << tem.getNombre() << "___" << tem.getDni() << "___" << tem.getRegistro()  << "*****" ;

    text = aux.str();

    ofstream archivo;

    archivo.open("pacientes.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    archivo<< text;

    archivo.close();

}

void agregarMedico(){

    ostringstream aux;
    string text;
    Usuario x;

    Medico tem ;

    aux << tem.getApellido() << "___" << tem.getNombre() << "___" << tem.getDni() << "___" << tem.getEspecialidad() << "*****" ;

    text = aux.str();

    ofstream archivo;

    archivo.open("medicos.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    archivo<< text;

    archivo.close();

}

void agregarEnfermeros(){

    ostringstream aux;
    string text;
    Usuario x;

    Enfermero tem;

    aux << tem.getApellido() << "___" << tem.getNombre() << "___" << tem.getDni() << "___" << tem.getEspecialidad() << "*****" ;

    text = aux.str();

    ofstream archivo;

    archivo.open("enfermeros.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    archivo<< text;

    archivo.close();

}

void agregarMedicamentos(){

    ostringstream aux;
    string text;
    Medicamento x;

    aux << x.getNombre() << "__" << x.getCantidad() <<"*****";

    text = aux.str();

    ofstream archivo;

    archivo.open("usuarios.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    archivo<< text;

    archivo.close();
}