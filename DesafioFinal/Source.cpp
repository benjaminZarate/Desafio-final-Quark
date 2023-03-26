#include <iostream>
#include <string>

using namespace std;

class Vendedor 
{
private:
	string nombre;
	string apellido;
	int id;
	//lista de cotizaciones
public:
	string ObtenerNombre();
	string ObtenerID();
	string ObtenerHistorial();
};

class Cotizacion 
{
private:
	int id;
	string fechaCotizacion;
	int idVendedor;
	Prenda prendaCotizada;
	int cantidadPrendas;
public:
	int ObtenerID();
	string ObtenerFechaCotizacion();
	int AsignarIDVendedor();
	int ObtenerIDVendedor();
	void MostrarPrendaCotizada();
	int ObtenerCantidadPrendas();
};

class Prenda 
{
	
};
