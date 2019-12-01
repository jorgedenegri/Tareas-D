#ifndef ENFERMERO_H
#define ENFERMERO_H


class Enfermero : public Persona, public Usuario{
string especialidad;
int cant;

public:
Enfermero() : Persona(), Usuario() {
cout << "Cantidad de horas disponibles: ";
cin >> cant;
cout << "Especialidad: ";
getline(cin, especialidad);

}
string getEspecialidad() { return especialidad; }
int getCant() { return cant; }

};

#endif //ENFERMERO_H