#include <iostream>
#include "Videogame.h"
#include "Civilizacion.h"
using namespace std;
Videogame vid1;
int main()
{

    string opc;
    do
    {
        cout << "1) Agregar Civilizacion" << endl;
        cout << "2) Mostrar Civilizaciones" << endl;
        cout << "3) Respaldar" << endl;
        cout << "4) Recuperar" << endl;
        cout << "5) Insertar en pos" << endl;
        cout << "6) inicializar Civilizaciones" << endl;
        cout << "7) borrar" << endl;
        cout << "8) ordenar" << endl;
        cout << "9) buscar" << endl;
        cout << "10) Ultima civilizacion" << endl;
        cout << "11) Primera civilizacion" << endl;

        cout << "0) Salir" << endl;
        getline(cin, opc);
        if (opc == "1")
        {
            Civilizacion c1;
            cin >> c1;
            cin.ignore();
            vid1.addCivilization(c1);
        }

        else if (opc == "2")
        {
            vid1.show();
        }

        else if (opc == "3")
        {
            vid1.backup();
        }

        else if (opc == "4")
        {
            vid1.recover();
        }

        else if (opc == "5")
        {
            Civilizacion c1;
            cin >> c1;
            size_t pos;
            cout << "En que posicion quieres insertar" << endl;
            cin >> pos;
            cin.ignore();
            if (pos >= vid1.size())
            {
                cout << "posicion invalida" << endl;
                system("PAUSE");
            }
            else
            {
                vid1.insertX(c1, pos);
            }
        }

        else if (opc == "6")
        {
            Civilizacion c1;
            cin >> c1;
            size_t n;
            cout << "cuantas veces lo vas a querer" << endl;
            cin >> n;
            cin.ignore();
            vid1.start(c1, n);
        }

        else if (opc == "7")
        {

            size_t n;
            cout << "que posicion quiere borrar" << endl;
            cin >> n;
            cin.ignore();
            if (n >= vid1.size())
            {
                cout << "La posicion es invalida" << endl;
            }
            else
            {
                vid1.erase(n);
            }
        }

        else if (opc == "8")
        {
            int opcordenar;
            cout << "1) Ordenar por Nombre:" << endl;
            cout << "2) Ordenar por Pos en X:" << endl;
            cout << "3) Ordenar por Pos en Y:" << endl;
            cout << "4) Ordenar por Puntuacion:" << endl;
            cout << "5) Salir:" << endl;
            cin >> opcordenar;
            

            switch (opcordenar)
            {
            case 1:
                vid1.sortName();
                break;
            case 2:
                vid1.sortX();
                break;
            case 3:
                vid1.sortY();
                break;
            case 4:
                vid1.sortPunt();
                break;

            default:
            cin.ignore();
                break;
            }
            fflush(stdin);
        }

        else if (opc == "9")
        {
            Civilizacion c1;
            cin >> c1;
            Civilizacion *cb = vid1.findex(c1);
            if (cb == nullptr)
            {
                cout << "no se encontro la computadora" << endl;
            }
            else
            {
                cout << *cb << endl;
            }
        }
        
        else if (opc == "10")
        {
            vid1.last();
        }
        else if (opc == "11")
        {
            vid1.first();
        }
        else if (opc == "0")
        {
            break;
        }

    } while (true);

    return 0;
}
