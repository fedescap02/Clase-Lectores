#pragma once
#include  <string>
using namespace std;
class cLibrito
{
private:
	string nombre;
	int cant_pags;
	int indice;
	string comentarios;
	string autor;
	string editorial;
public:
	cLibrito(string nombre, int cant_pags, int indice, string comentarios,string autor,string editorial);
	cLibrito();
	cLibrito(string nombre, int indice, string comentarios);
	string get_nombre();
	int get_Cant_Pags();
	void set_indice(int Pag_new);
	int get_indice();
	string to_string();
	void imprimir();
	~cLibrito();

};

