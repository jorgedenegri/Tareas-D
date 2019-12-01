#ifndef PACIENTE_H
#define PACIENTE_H
#include <string>
#include <iostream>
#include <sstream>
#include <istream>

using namespace std;

class Paciente : public virtual Persona, public Usuario
{
   int codRegistro = 0;
public:
   Paciente() : Persona() , Usuario() 
   {
	   ++codRegistro;
   }
   string getRegistro(){
	   int codRegistro;
	   stringstream c;
	   c << codRegistro;
	   string cod;
	   c >> cod;
	   return cod;
    }
};

#endif // PACIENTE_H