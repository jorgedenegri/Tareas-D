#include <iostream>

using namespace std;

class persona{
 private:
    string nombre;
    int edad;
 public:
    persona(string,int);
    void mostrar_persona();
};
persona::persona(string _nombre,int _edad){
    nombre=_nombre;
    edad=_edad;
}
void persona::mostrar_persona(){
    cout<<"nombre: "<<nombre<<endl;
    cout<<"edad: "<<edad<<endl;
}
class alumno: public persona{
 private:
    string codigo_al;
    float nota_final;
 public:
    alumno(string,int,string,float);
    void mostrar_alumno();
};
alumno::alumno(string _nombre,int _edad,string _codigo_al,float _nota_final):persona(_nombre,_edad){
    codigo_al=_codigo_al;
    nota_final=_nota_final;

}
void alumno::mostrar_alumno(){
    mostrar_persona();
    cout<<"codigo de alumno: "<<codigo_al<<endl;
    cout<<"nota final: "<<nota_final<<endl;

}
int main(){
    alumno a1("Jorge",19,"123168",12.5);
    a1.mostrar_alumno();


    return 0;
}
