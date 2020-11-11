#ifndef CIVILIZACION_H_INCLUDED
#define CIVILIZACION_H_INCLUDED
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <istream>
using namespace std;
class Civilizacion
{
private:
    std::string Nombre;
    int PosX;
    int PosY;
    int puntuacion;
public:
    Civilizacion();
    Civilizacion(const std::string&,const int&, const int&, const int&);

    void setNombre(const std::string&);
    void setPosY(const int&);
    void setPosX(const int&);
    void setPuntuacion(const int&);

    std::string getNombre();
    int getPosX();
    int getPosY();
    int getPuntuacion();

    friend std::ostream &operator<<(std::ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(20) << c.Nombre << "||";
        out << setw(20) << c.PosX << "||";
        out << setw(20) << c.PosY << "||";
        out << setw(20) << c.puntuacion << "||";
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Civilizacion &c)
    {
        string temp;

        cout << "Nombre: " << endl;
        getline(cin, c.Nombre);

        cout << "Posicion X : " << endl;
        cin>>c.PosX;

        cout << "Posicion Y" << endl;
        cin >> c.PosY;

        cout << "Puntuacion: " << endl;
        fflush(stdin);
        cin>>c.puntuacion;
    }

     bool operator==(const Civilizacion &c) 
    {
        return Nombre == c.Nombre;
    }
    bool operator==(const Civilizacion &c) const
    {
        return Nombre == c.Nombre;
    }


};


#endif