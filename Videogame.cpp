#include "Videogame.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

Videogame::Videogame(){}
Videogame::Videogame(const std::string &n){
    NickName=n;
}


void Videogame::addCivilization(const Civilizacion &c) { civilizaciones.push_back(c); }

void Videogame::insertX(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin() + pos, c);
}
void Videogame::show()
{   
    //encabezado
    cout<<"El jugador"<<NickName<<" Posee :"<<civilizaciones.size()<<" Civilizaciones"<<endl;;
    cout << left;
    cout << setw(20) << "Nombre"
         << "||";
    cout << setw(20) << "Posicion X"
         << "||";
    cout << setw(20) << "Posicion Y"
         << "||";
    cout << setw(20) << "Puntuacion"
         << "||" << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c << endl;
    }
}

void Videogame::backup()
{
    ofstream archivo("Civilizaciones.txt");
    if (archivo.is_open())
    {

        for (int i = 0; i < civilizaciones.size(); i++)
        {
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            archivo << c.getPosX() << endl;
            archivo << c.getPosY() << endl;
            archivo << c.getPuntuacion() << endl;
        }
    }

    archivo.close();
}

void Videogame::recover()
{
    ifstream archivo("Civilizaciones.txt");
    if (archivo.is_open())
    {
        string temporal;
        int x;

        Civilizacion c;

        while (true)
        {
            getline(archivo, temporal);

            if (archivo.eof())
            {
                break;
            }
            c.setNombre(temporal);

            getline(archivo, temporal);
            x = stoi(temporal); //string a entero
            c.setPosX(x);

            getline(archivo, temporal);
            x = stoi(temporal); //string a entero
            c.setPosY(x);

            getline(archivo, temporal);
            x = stoi(temporal); //string a entero
            c.setPuntuacion(x);

            addCivilization(c);
        }
    }

    archivo.close();
}

void Videogame::erase(size_t p)
{
    civilizaciones.erase(civilizaciones.begin() + p);
}

void Videogame::start(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videogame::sortName()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getNombre() < c2.getNombre(); });
}
void Videogame::sortX()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPosX() < c2.getPosX(); });
}
void Videogame::sortY()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPosY() < c2.getPosY(); });
}
void Videogame::sortPunt()
{

    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPuntuacion() < c2.getPuntuacion(); });
}

Civilizacion *Videogame::findex(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        //accede a la direccion de memoria y me regresa desreferenciandola
        return &(*it);
    }
}
    void Videogame::last(){
        size_t ultimo=size();
        Civilizacion &c = civilizaciones[ultimo-1];
        cout << c << endl;
    }
    void Videogame::first(){Civilizacion &c = civilizaciones[0];
        cout << c << endl;}


size_t Videogame::size() { return civilizaciones.size(); }
