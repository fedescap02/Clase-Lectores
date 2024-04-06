// claseLibrito.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "cLector.h"
using namespace std;
//cLector(string nombre, string dni, string apellido, string fecha_nac,cLibrito* librito);
//cLibrito(string nombre, int cant_pags, int indice, string comentarios,string autor,string editorial);
int main()
{
    cLibrito* librito1 = new cLibrito();
    cLector* Lector1 = new cLector("Francisco", "44321603", "Cabrera", "2003-04-29", librito1);
    Lector1->imprimir();
    getchar();
    Lector1->leer_libro(10);
    cout << "Vas por la pagina nro:" << librito1->get_indice() << endl;
    Lector1->leer_libro(100);
    //librito1->imprimir();
    getchar();


    cLibrito librito2("Hary Postre", 600, 50, "Se lava la carita con agua y con jabon", "Almada", "Sunchales");
    cLector  Lector2("Sol", "42314015", "Insegura", "2001-24-06", &librito2);
    Lector2.imprimir();
    getchar();
    Lector2.leer_libro(40);
    cout << "Vas por la pagina nro:" << librito2.get_indice() << endl;
    Lector2.leer_libro(190);
    cout << "Vas por la pagina nro:" << librito2.get_indice() << endl;
    getchar();
    //librito2.imprimir();

    cout << Lector1->get_nombre() << " tiene " << Lector1->get_edad() << " años"<<endl;
    getchar();

    delete Lector1;
    delete librito1;

    return 0;
}

