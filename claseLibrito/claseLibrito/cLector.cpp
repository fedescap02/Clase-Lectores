#define _CRT_SECURE_NO_WARNINGS
#include "cLector.h"
#include <iostream>
#include <ctime>
tm cLector::convertirFecha()
{
    // Variables para almacenar a�o, mes y d�a como enteros
    int anio_nacimiento, mes_nacimiento, dia_nacimiento;

    // Crear un stringstream para analizar la cadena
    stringstream ss(this->fecha_nac);

    // Extraer a�o, mes y d�a de la cadena
    char delim;
    ss >> anio_nacimiento >> delim >> mes_nacimiento >> delim >> dia_nacimiento;

    tm fnac;
    fnac.tm_year = anio_nacimiento;
    fnac.tm_mon = mes_nacimiento;
    fnac.tm_mday = dia_nacimiento;

    return fnac;
}
cLector::cLector(string nombre, string dni, string apellido, string fecha_nac,cLibrito* librito)
{
    this->nombre = nombre;
    this->dni = dni;
    this->apellido = apellido;
    this->fecha_nac = fecha_nac;
    this->email = "0";
    this->celular = "0";
    this->librito = librito;
}


string cLector::get_dni()
{
    return this->dni;
}

string cLector::get_nombre()
{
    return this->nombre;
}

string cLector::get_apellido()
{
    return this->apellido;
}

string cLector::get_email()
{
    return this->email;
}

string cLector::get_celular()
{
    return this->celular;
}

string cLector::ger_Fnacimiento()
{
    return this->fecha_nac;
}

string cLector::to_string()
{
    stringstream ss;
    ss << "El dni del lector es: " << dni << endl;
    ss << "Su nombre completo es: " << nombre << " " << apellido << endl;
    ss << "Su email es: " << email << endl;
    ss << "Nacio el: " << fecha_nac << endl;
    ss << "El libro que esta leyendo es: "<<endl;
    ss << librito->to_string() << endl;
    
    return ss.str();
}

void cLector::imprimir()
{
    cout << to_string();
}

void cLector::set_libro(cLibrito* New_librito)
{
    this->librito = New_librito;
}

int cLector::get_edad()
{
    // Fecha en formato de cadena (string)

    tm fecha_nac = convertirFecha();
    
    // Obtener el tiempo actual en segundos desde el 1 de enero de 1970
    time_t now = time(0);

    // Convertir el tiempo actual en una estructura de tiempo
    tm* local_time = localtime(&now);

    // Extraer el a�o, mes y d�a de la estructura de tiempo
    
    int anio_actual = 1900 + local_time->tm_year;
    int mes_actual = 1 + local_time->tm_mon;
    int dia_actual = local_time->tm_mday;

    int edad = anio_actual - fecha_nac.tm_year;

    // Verificar si el mes y d�a actual son antes del mes y d�a de nacimiento
    if (mes_actual < fecha_nac.tm_mon || (mes_actual == fecha_nac.tm_mon && dia_actual < fecha_nac.tm_mday)) {
        edad--; // Restar un a�o si a�n no se ha cumplido el cumplea�os
    }
    return edad;
}

void cLector::set_Email(string n_Email)
{
    this->email = n_Email;
}

bool cLector::set_celular(string n_Celular)
{
    bool flag = true;
    for (int i = 0; i < n_Celular.length(); i++)
    {
        if (n_Celular[i] >= '0' && n_Celular[i] <= '9') flag = false;
       
    }

    if (!flag)
    {
        this->celular = n_Celular;
       
    }
    return flag;
}

void cLector::leer_libro(int paginas_leidas)
{
    if (paginas_leidas + this->librito->get_indice() >= this->librito->get_Cant_Pags())
    {
        this->librito->set_indice(this->librito->get_Cant_Pags());
        std::cout << "Felicidades terminaste el libro elegi uno nuevo : )" << std::endl;
    }else this->librito->set_indice(paginas_leidas + this->librito->get_indice());
}

cLector::~cLector(){}
 

