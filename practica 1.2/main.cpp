#include <iostream>
#include <vector>
using namespace std;

class estudiante{
private:
string nombre , apellido , codigo;
public:
estudiante(){}
estudiante(string nombre,string apellido,string codigo){
this -> nombre = nombre;
this -> apellido = apellido;
this -> codigo = codigo;
}
string getNombre(){
return nombre;
}
string getApellido(){
return apellido;
}
string getCodigo(){
return codigo;
}
};
class curso{
private:
string nombre , codigo;
int cant;
estudiante *arr;
public:
curso(string nombre , string codigo ,estudiante *arreglo ,int cant){
this -> nombre = nombre;
this -> codigo = codigo;
this -> cant = cant;
arr = new estudiante[this -> cant];
for (int i = 0 ; i < this->cant;i++ ){
arr[i] = arreglo[i];
}
}
curso(string &nombre , string &codigo ,estudiante *arreglo ,int &cant){
this -> nombre = nombre;
this -> codigo = codigo;
this -> cant = cant;
arr = new estudiante[this -> cant];
for (int i = 0 ; i < this->cant;i++ ){
arr[i] = arreglo[i];
}
}
void modificar(){
cout<<"nombre de la clase: ";getline(cin,nombre);
cout<<"codigo de la clase: ";getline(cin,codigo);
}
string getnombre(){
return nombre;
}
string getcodigo(){
return codigo;
}
int getcant(){
return cant;
}
void incrementar(estudiante e){
cant++;
estudiante *tem = new estudiante[cant];
for (int i = 0 ; i < cant ; i++){
tem[i] = arr[i];
}
tem[cant - 1] = e;
delete[] arr;
arr = tem;
}
void lista_estudiante(){
for (int i = 0 ; i < cant ; i++ ){
cout<< arr[i].getNombre() <<'\n';
}
}

};

int main(){

estudiante a("jorge","denegri","12345");
estudiante b("miguel","motta","67890");

estudiante f[2] = {a,b};

curso c("ccomp","404040",f,2);

// cout<<c.getnombre()<<'\n';
// cout<<c.getcodigo()<<'\n';

// c.modificar();

// cout<<c.getnombre()<<'\n';
// cout<<c.getcodigo()<<'\n';

c.lista_estudiante();

return 0;
}
