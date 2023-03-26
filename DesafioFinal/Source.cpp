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
	void ObtenerHistorial();
	void AgregarCotizacion(Cotizacion cotizacion);
};

Vendedor::Vendedor(string nombre, string apellido, int id)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->id = id;
}

//TODO: Agregar destructor

string Vendedor::ObtenerNombre() 
{
	return nombre + " " + apellido;
}

int Vendedor::ObtenerID() 
{
	return id;
}

void Vendedor::ObtenerHistorial() 
{
	
}

void Vendedor::AgregarCotizacion(Cotizacion cotizacion) 
{
	
}

class Cotizacion 
{
private:
	int id;
	string fechaCotizacion;
	int idVendedor;
	Prenda* prendaCotizada;
	int cantidadPrendas;
public:
	int ObtenerID();
	string ObtenerFechaCotizacion();
	int ObtenerIDVendedor();
	void MostrarPrendaCotizada();
	int ObtenerCantidadPrendas();
	int CalculoCotizacion();
};

Cotizacion::Cotizacion(int id, string fechaCotizacion, int idVendedor, int cantidadPrendas, Prenda* prendaCotizada) 
{
	this->id = id;
	this->fechaCotizacion = fechaCotizacion;
	this->idVendedor = idVendedor;
	this->cantidadPrendas = cantidadPrendas;
	this->prendaCotizada = prendaCotizada;
}

int Cotizacion::ObtenerID() 
{
	return id;
}

string Cotizacion::ObtenerFechaCotizacion() 
{
	return fechaCotizacion;
}

int Cotizacion::ObtenerIDVendedor() 
{
	return idVendedor;
}

void Cotizacion::MostrarPrendaCotizada() {}

int Cotizacion::ObtenerCantidadPrendas() 
{
	return cantidadPrendas;
}

int Cotizacion::CalculoCotizacion() 
{
	return 0;
}


class Prenda 
{
public:
	enum Calidad { STANDARD, PREMIUM };
	Calidad calidadPrenda;
	int precio;
};

class Camisa: public Prenda
{
public:
	enum Cuello {MAO, COMUN}
	Cuello cuello;
	enum Manga {CORTA, LARGA}
	Manga manga;
};

Camisa::Camisa(Calidad calidadPrenda, int precio, Cuello cuello, Manga manga) 
{
	this->calidadPrenda = calidadPrenda;
	this->precio = precio;
	this->Cuello = cuello;
	this->Manga = manga;
}

class Pantalon : public Prenda 
{
public:
	enum Ajuste {COMUN, CHUPINES}
	Ajuste ajuste;
};

Pantalon::Pantalon(Calidad calidadPrenda, int precio, Ajuste ajuste)
{
	this->calidadPrenda = calidadPrenda;
	this->precio = precio;
	this->Ajuste = ajuste;
}

class Tienda
{
private:
	string nombre;
	string direccion;
	//Lista prendas
	//Lista vendedores
public:
	string ObtenerNombre();
	string ObtenerDireccion();
};

Tienda::Tienda(string nombre, string direccion) 
{
		
}
