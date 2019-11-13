#include <iostream>
#include <vector>

using namespace std;
class empleado{

    string nombre;
    string apellido;
    int salario;
public:
    empleado(string _nombre,string _apellido,int _salario){
        nombre=_nombre;
        apellido=_apellido;
        salario=_salario;
    }
    void bajar_sueldo();
    void salario_anual();
    string getNombre(){
        return nombre;
    }
    string getApellido(){
        return apellido;
    }
    int getSalario(){
        return salario;
    }

};
void empleado::salario_anual(){
    cout<<"salario anual: "<<salario*12;
}
void empleado::bajar_sueldo(){
    salario=salario+1-(0.1*salario);
}
int main()
{
    string aux;
    empleado e1("raul","aelos",100);
    empleado e2("zinedine","aabhue",50000);
    empleado e3("Pierremerick","aubameyang",100000);

    cout<<e1.getNombre()<<endl;
    cout<<e1.getApellido()<<endl;
    cout<<e1.getSalario()<<endl;
    e1.salario_anual();
    cout<<e1.getSalario()<<endl;
    e1.bajar_sueldo();
    cout<<e1.getSalario()<<endl;
    string arr[]={e1.getApellido(),e2.getApellido(),e3.getApellido()};
    for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(arr[i]>arr[j]){
                    aux=arr[i];
                    arr[i]=arr[j];
                    arr[j]=aux;
                }


            }

    }
    for(int i=0;i<3;i++){
        cout<<arr[i]<<endl;
    }



    return 0;
}
