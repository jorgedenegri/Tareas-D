#include <string>
#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

using namespace std;

class Persona{
    protected:
    string apellido, nombre, dni, sexo ;
    int edad;
    public:
    Persona(){
        std::cout<<"APELLIDO: ";
        std::getline(std::cin , apellido);
        std::cout<<"NOMBRE: ";
        std::getline(std::cin , nombre);
        std::cout<<"EDAD: ";
        std::cin>>edad;
        std::cout<<"DNI: ";
        std::cin.ignore();
        std::getline(std::cin , dni) ;
        std:: cout<< "SEXO: ";
        std::getline(std::cin, sexo) ;
    }

    virtual string getApellido(void)
    {
        return apellido;
    }
    virtual string getNombre(void){
        return nombre;
    }
    virtual string getDni(void){
        return dni;
    }
    virtual string getSexo(void){
        return sexo;
    }
    virtual int getEdad(void){
        return edad;
    }
};

#endif // PERSONA_H_INCLUDED
