#include "Civilizacion.h"
using namespace std;
Civilizacion::Civilizacion() {}
Civilizacion::Civilizacion(const string &n, const int &x, const int &y, const int &p)
{
    Nombre = n;
    PosX = x;
    PosY = y;
    puntuacion = p;
}

void Civilizacion::setNombre(const string &n) { Nombre = n; }
void Civilizacion::setPosX(const int &x) { PosX = x; }
void Civilizacion::setPosY(const int &y) { PosY = y; }
void Civilizacion::setPuntuacion(const int &p) {puntuacion=p;}

string Civilizacion::getNombre() {return Nombre;}
int Civilizacion::getPosX() {return PosX;}
int Civilizacion::getPosY() {return PosY;}
int Civilizacion::getPuntuacion() {return puntuacion;}