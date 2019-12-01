#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "date.h"
#include "usuario.h"
#include "persona.h"
#include "medico.h"
#include "enfermeros.h"
#include "paciente.h"
#include "medicamentos.h"
#include "main.h"
#include "cita.h"

using namespace std;


void agregarPaciente(void){

    ostringstream aux;
    string text;

    Paciente tem ;

    aux << tem.getApellido() << "___" << tem.getNombre() << "___" << tem.getDni() << "___" << tem.getRegistro() << "___" <<
     tem.getUsuario() << "___" << tem.getContra() << "*****" ;

    text = aux.str();

    ofstream archivo;

    archivo.open("pacientes.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    archivo<< text;

    archivo.close();

}

void agregarMedico(void){

    ostringstream aux;
    string text;
    Usuario x;
    Medico tem ;

    aux << tem.getApellido() << "___" << tem.getNombre() << "___" << tem.getDni() << "___" << tem.getEspecialidad() <<  "___" <<
     tem.getUsuario() << "___" << tem.getContra() <<"*****" ;

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

    archivo.open("medicamentos.txt",ios::app);
    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    archivo<< text;

    archivo.close();

}
/*
void crearFicha()
{
	ostringstream aux;
	string text;
	Paciente x;
    Cita x2;

	aux << "*****" << x.getRegistro() << "___" << x.getApellido() << "___" <<
		x.getNombre() << "___"  << x2.getCita() << "___";
	
	text = aux.str();

	ofstream archivo;

	archivo.open("fichaMedica.txt", ios::app);
	if (archivo.fail())
		std::cout << "No se puedo abrir el archivo" << endl;

	archivo << text;

	archivo.close();
}
*/


// void lecturaUsuario( string usuario , string contra ){

//     ifstream archivo;
//     string texto;

//     archivo.open("usuarios.txt",ios::in);

//     if (archivo.fail())
//         std::cout<<"No se puedo abrir el archivo"<<endl;

//     string tem;
//     while (getline(archivo,tem))
//         texto +=tem;

//     cout << texto << '\n';

// }

vector <string> separar(string fichero ){
    ifstream archivo;
    string texto;

    if ( fichero == "paciente" ){
        archivo.open("pacientes.txt",ios::in);
    }

    else if ( fichero == "medico" ){
        archivo.open("medicos.txt",ios::in);
    }

    else if ( fichero == "usuario" ){
        archivo.open("usuarios.txt",ios::in);
    }
    else if ( fichero == "medicamento" ){
        archivo.open("medicamentos.txt",ios::in);
    }


    if (archivo.fail())
        std::cout<<"No se puedo abrir el archivo"<<endl;

    string tem;
    while (getline(archivo,tem))
        texto +=tem;

    vector <string> myVector = {};
    string temp , operador = "_* " ;
    temp.clear();

    int i = 0;
    while ( i < texto.size() ){ 
        if( (texto[i] != operador[0] ) and (texto[i] != operador[1] ) and (texto[i] != operador[2] )){
            temp +=texto[i];
            i++;
        }
        if ( texto[i] == operador[2]  ){
            myVector.push_back(temp);
            temp.clear();
            i += 1 ;
        }
        if ( texto[i] == operador[0]  ){
            myVector.push_back(temp);
            temp.clear();
            i += 3 ;
        }
        if ( texto[i] == operador[1] ) {
            i += 5; 
            myVector.push_back(temp);
            myVector.push_back("*****");
            temp.clear();
        }
    }
    return myVector;
}

vector <int> buscar( vector <string> myVector  , string palabra){
    vector <int> pos = {};

    string pause = "*****";
    int i = 0;
    while( i < myVector.size() ){
        if (myVector[i] == palabra){
            while ( myVector[i] != pause ){
                i--;
            }
            i++; 
            pos.push_back(i);
            while ( myVector[i] != pause ){
                i++;
            }
        }
        i++;
    }
    return pos;
}

void mostrar(vector <string> lista , vector <int> pos ){
    string pause = "*****";

    cout<< endl;

    for (int i = 0 ; i < pos.size() ; i++ ){
        int  aux = pos[i];
        int j = aux;

        while ( lista[j] != pause ){  
            cout << lista[j] << "       ";
            j++;
        }
        cout<<endl;
    }
}
bool confirmar_usuario( vector <string> vec){
string aux_usuario , aux_contra , pause = "*****";;
cout<<"Nombre de usuario: ";getline(cin,aux_usuario);
cout<<"Contrasenia: ";getline(cin,aux_contra);
bool val = false;

for (int i = 2 ; i < vec.size() ; i++ ){
string aux = vec[i];

if ( aux == pause ){
i -= 2;
if ( (vec[i] == aux_usuario and vec[i + 1] == aux_contra)) {
val = true;
break;
}
else {
i += 3;
}
}
}
return val;
}
/*bool confirmar(vector <string> vec){
    string aux_usuario,aux_contra;
    cout<<"Nombre de usuario: "<<endl;getline(cin,aux_usuario);
    cout<<"Contrasenia: "<<endl;getline(cin,aux_contra);
    vector<string> vec;
    vec={"***","jorge","denegri","72554584","gaa999","pepsi007","***","raul","perez","29746332","clarope","mascota","***","roberto","carlos","29719632","trakas","123456","***"};
    int num_usuarios=(vec.size-1)/6;
    for(int i=0;i<num_usuarios;i++){
        if(aux_usuario == vec[4] && aux_contra == vec[5]){
                return true;
        }
        vec.erase(vec.begin(),vec.begin()+6);

        cout<<endl;

    }
    return false;
}*/
void inicio(void)
{
   std::cout << '\n' << '\t' << "BIENVENIDO A NUESTRA BASE DE DATOS" << endl;
   std::cout << '\n' << "SELECCIONE LA OPERACION QUE DESEA REALIZAR" << endl;
   int num;
   std::cout << '\n' << "      2    INGRESAR        ";
   std::cout << '\n' << "      1    REGISTRARSE        ";
   std::cout << '\n' << "      0    SALIR                  " << '\n';
   std::cout << '\n' << "DIGITE NUMERO: " ; std::cin >> num;
   switch(num){
       case 0 : {
           system("clear");
           break;
        }

       case 1 :
           {
           system("clear");
           std::cin.ignore();
           int n;
           std::cout << '\n' << " REGISTRAR COMO:  ";
           std::cout << '\n' << "      3    PACIENTE         ";
           std::cout << '\n' << "      2    ENFERMERO        ";
           std::cout << '\n' << "      1    MEDICO           ";
           std::cout << '\n' << "      0    SALIR            ";
           std::cout << '\n' << "DIGITE NUMERO: " ; std::cin >> n;
           if (n==0)
           {
               system("clear");
               break;
           }
           if (n==1)
           {
               system("clear");
               std::cin.ignore();
               agregarMedico();
           }
           if (num==2)
           {
               system("clear");
               std::cin.ignore();
               agregarEnfermeros();
           }
           if (num==3)
           {
               system("clear");
               std::cin.ignore();
               agregarPaciente();
               
           }
       }
       case 2 :{
           system("clear");
           std::cin.ignore();
           int n;
           std::cout << '\n' << " ...  ";
           std::cout << '\n' << "      3    PACIENTE         ";
           std::cout << '\n' << "      2    ENFERMERO        ";
           std::cout << '\n' << "      1    MEDICO           ";
           std::cout << '\n' << "      0    SALIR            ";
           std::cout << '\n' << "DIGITE NUMERO: " ; std::cin >> n;
           if (n==0)
           {
               system("clear");
               break;
           }
           if (n==1)
           {
               system("clear");
               std::cin.ignore();
		        vector <string> texto = separar("medicos");
               if (confirmar_usuario(texto))
		
               {
                   int num;
                   std::cout << '\n' << " BUSCAR: ";
                   std::cout << '\n' << "      3    FICHAS MEDICAS   ";
                   std::cout << '\n' << "      2    PACIENTE         ";
                   std::cout << '\n' << "      1    ENFERMERO        ";
                   std::cout << '\n' << "      0    SALIR            ";
                   std::cout << '\n' << "DIGITE NUMERO: " ; std::cin >> num;
                   if (num==0)
                   {
                       system("clear");
                       std::cin.ignore();
                       break;
                   }
                   if (num==1)
                   {
                       vector <string> texto = separar("enfermeros");
                       string palabra;
		               cout << "BUSQUE COMENZANDO CON MAYÚSCULA LOS NOMBRES Y APELLIDOS: "; cin >> palabra;
                       vector <int> pos = buscar(texto, palabra);
                   }
                   if (num==2)
                   {
                       vector <string> texto = separar("pacientes");
                       string palabra;
                       cout << "BUSQUE COMENZANDO CON MAYÚSCULA LOS NOMBRES Y APELLIDOS: "; cin >> palabra;
                       vector <int> pos = buscar(texto, palabra);
                   }
                   if (num==3)
                   {
                       //funcion que ingrese al txt de ficha tecnica
                       string n;
                       //funcion buscar
                   }
                   else{
                       std::cout << "DIGITE EN EL RANGO DE NUMEROS";
                       break;
                   }
               }
           }
           if (num==2)
           {
               system("clear");
               std::cin.ignore();
               vector <string> texto = separar("enfermeros");
               if (confirmar_usuario(texto))
               {
                   int num;
                   std::cout << '\n' << " BUSCAR: ";
                   std::cout << '\n' << "      3    FICHAS MEDICAS   ";
                   std::cout << '\n' << "      2    PACIENTE         ";
                   std::cout << '\n' << "      1    MEDICOS        ";
                   std::cout << '\n' << "      0    SALIR            ";
                   std::cout << '\n' << "DIGITE NUMERO: " ; std::cin >> num;
                   if (num==0)
                   {
                       system("clear");
                       std::cin.ignore();
                       break;
                   }
                   if (num==1)
                   {
                       vector <string> texto = separar("medicos");
                       string palabra;
                       cout << "BUSQUE COMENZANDO CON MAYÚSCULA LOS NOMBRES Y APELLIDOS: "; cin >> palabra;
                       vector <int> pos = buscar(texto, palabra);
                   }
                   if (num==2)
                   {
                       vector <string> texto = separar("pacientes");
                       string palabra;
                       cout << "BUSQUE COMENZANDO CON MAYÚSCULA LOS NOMBRES Y APELLIDOS: "; cin >> palabra;
                       vector <int> pos = buscar(texto, palabra);
                   }
                   if (num==3)
                   {
                       //funcion que ingrese al txt de ficha tecnica
                       string n;
                       //funcion buscar
                   }
		       }
		   }
		   if (num==3)
		   {
		       system("clear");
		       std::cin.ignore();
		       vector <string> texto = separar("pacientes");
		       if (confirmar_usuario(texto))
		        {
                    std::cout << "Hola paciente" << endl;
                }
               
           
       }
       default: {
           std::cout << "DIGITE EN EL RANGO DE NUMEROS" <<'\n';
           num = 100;
           break;
        }
        }
   inicio();
}
}

int main()
{
    inicio();
    return 0;
}

    

