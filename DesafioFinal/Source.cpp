#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum Calidad { STANDARD, PREMIUM };

namespace camisas 
{
	enum Cuello { MAO, COMUN };
	enum Manga { CORTA, LARGA };
}

namespace pantalones 
{
	enum Ajuste { COMUN, CHUPINES };
}

using namespace camisas;
using namespace pantalones;

#pragma region Prenda
class Prenda
{
public:
	string nombre;
	Calidad calidadPrenda;
	int precio = 0;
};

class Camisa : public Prenda
{
public:
	camisas::Cuello cuello;
	camisas::Manga manga;
	Camisa(Calidad calidadPrenda, camisas::Cuello cuello, camisas::Manga manga, string nombre);
};

Camisa::Camisa(Calidad calidadPrenda, camisas::Cuello cuello, camisas::Manga manga, string nombre)
{
	this->calidadPrenda = calidadPrenda;
	this->cuello = cuello;
	this->manga = manga;
	this->nombre = nombre;
}

class Pantalon : public Prenda
{
public:
	Ajuste ajuste;
	Pantalon(Calidad calidadPrenda, Ajuste ajuste, string nombre);
};

Pantalon::Pantalon(Calidad calidadPrenda, Ajuste ajuste, string nombre)
{
	this->calidadPrenda = calidadPrenda;
	this->ajuste = ajuste;
	this->nombre = nombre;
}
#pragma endregion

#pragma region Cotizacion
class Cotizacion
{
private:
	int id = 0;
	string fechaCotizacion = "";
	int idVendedor = 0;
	Prenda* prendaCotizada;
	int cantidadPrendas = 0;
	int precioFinal = 0;
public:
	Cotizacion(string fechaCotizacion, int idVendedor);
	string ObtenerFechaCotizacion();
	int ObtenerID();
	void CalculoCotizacion(int precio);
	int ObtenerIDVendedor();
	int ObtenerCantidadPrendas();
	bool esCamisa; //true es camisa y false es pantalon
	bool esCuelloComun; //true es cuello de camisa comun y false es cuello Mao
	bool esMangaCorta; //true es manga corta y false es manga larga
	bool esPantalonComun; //true si es un pantalon de ajuste comun y false si son chupines
	bool calidadPrenda; //true si es standard y false si es premium
	void AsignarID(int nuevoID);
	void AsignarCantidadPrendas(int cantidad);
	void MostrarPrendaCotizada();
	void AsignarPrecioPrenda(int precio);
	void InicializarPrenda();

};

Cotizacion::Cotizacion(string fechaCotizacion, int idVendedor)
{
	this->fechaCotizacion = fechaCotizacion;
	this->idVendedor = idVendedor;
}

void Cotizacion::AsignarCantidadPrendas(int cantidad) 
{
	cantidadPrendas = cantidad;
}

void Cotizacion::AsignarID(int nuevoID) 
{
	id = nuevoID;
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

void Cotizacion::MostrarPrendaCotizada() 
{
	cout << "Numero de identificacion: " << ObtenerID() << "\n";
	cout << "Fecha y hora de la cotizacion: " << ObtenerFechaCotizacion() << "\n";
	cout << "Codigo del vendedor: " << ObtenerIDVendedor() << "\n";
	cout << "Prenda cotizada: " << prendaCotizada->nombre << " \n";
	cout << "Precio unitario: $" << prendaCotizada->precio << "\n";
	cout << "Cantidad de unidades cotizadas: " << ObtenerCantidadPrendas() << "\n";
	cout << "Precio final: $" << precioFinal * cantidadPrendas << "\n";
	cout << "\n";
	cout << "\n";
}

int Cotizacion::ObtenerCantidadPrendas()
{
	return cantidadPrendas;
}

void Cotizacion::CalculoCotizacion(int precio)
{
	prendaCotizada->precio = precio;
	if (esCamisa) 
	{
		if (esMangaCorta) 
		{
			precio *= .9;
		}
		if (!esCuelloComun) 
		{
			precio += (precio * 0.03);
		}
	}
	else 
	{
		if (!esPantalonComun) 
		{
			precio *= .88;
		}
	}

	if (!calidadPrenda) 
	{
		precio += (precio * 0.3);
	}
	precioFinal = precio;
}



void Cotizacion::AsignarPrecioPrenda(int precio) 
{
	cout << esCamisa;
	cout << esCuelloComun;
	cout << esMangaCorta;
	cout << calidadPrenda;
	InicializarPrenda();
	CalculoCotizacion(precio);	
}

void Cotizacion::InicializarPrenda() 
{
	if (esCamisa)
	{
		if (esMangaCorta)
		{
			if (esCuelloComun)
			{
				if (calidadPrenda)
				{
					prendaCotizada = new Camisa(STANDARD, Cuello::COMUN, Manga::CORTA, "Camisa - Cuello comun - Manga Corta - Standard");
				}
				else
				{
					prendaCotizada = new Camisa(PREMIUM, Cuello::COMUN, Manga::CORTA, "Camisa - Cuello comun - Manga Corta - Premium");
				}
			}
			else
			{
				if (calidadPrenda)
				{
					prendaCotizada = new Camisa(STANDARD, Cuello::MAO, Manga::CORTA, "Camisa - Cuello Mao - Manga Corta - Standard");
				}
				else
				{
					prendaCotizada = new Camisa(PREMIUM, Cuello::MAO, Manga::CORTA, "Camisa - Cuello Mao - Manga Corta - Premium");
				}
			}
		}
		else
		{
			if (esCuelloComun)
			{
				if (calidadPrenda)
				{
					prendaCotizada = new Camisa(STANDARD, Cuello::COMUN, Manga::LARGA, "Camisa - Cuello Comun - Manga Larga - Standard");
				}
				else
				{
					prendaCotizada = new Camisa(PREMIUM, Cuello::COMUN, Manga::LARGA, "Camisa - Cuello Comun - Manga Larga - Premium");
				}
			}
			else
			{
				if (calidadPrenda)
				{
					prendaCotizada = new Camisa(STANDARD, Cuello::MAO, Manga::LARGA, "Camisa - Cuello Mao - Manga Larga - Standard");
				}
				else
				{
					prendaCotizada = new Camisa(PREMIUM, Cuello::MAO, Manga::LARGA, "Camisa - Cuello Mao - Manga Larga - Premium");
				}
			}
		}
	}
	else 
	{
		if (esPantalonComun) 
		{
			if (calidadPrenda) 
			{
				prendaCotizada = new Pantalon(STANDARD, Ajuste::COMUN, "Pantalon - Comun - Standard");
			}
			else 
			{
				prendaCotizada = new Pantalon(PREMIUM, Ajuste::COMUN, "Pantalon - Comun - Premium");
			}
		}
		else 
		{
			if (calidadPrenda)
			{
				prendaCotizada = new Pantalon(STANDARD, Ajuste::CHUPINES, "Pantalon - Chupines - Standard");
			}
			else
			{
				prendaCotizada = new Pantalon(PREMIUM, Ajuste::CHUPINES, "Pantalon - Chupines - Premium");
			}
		}
	}
}

#pragma endregion

#pragma region Vendedor
class Vendedor 
{
private:
	string nombre = "";
	string apellido = "";
	int id = 0;

	class Nodo {
	public:
		Cotizacion* cotizacion;
		Nodo* sig;
	};

	Nodo* raiz;
	int numeroCotizaciones;
public:
	Vendedor(string nombre, string apellido, int id);
	string ObtenerNombre();
	int ObtenerID();
	void ObtenerHistorial();
	void AgregarCotizacion(Cotizacion* cotizacion);
	Cotizacion* cotizacionActual;
};

Vendedor::Vendedor(string nombre, string apellido, int id)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->id = id;
	raiz = NULL;
}

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
	if (raiz == NULL) 
	{
		cout << "NO HAY COTIZACIONES DISPONIBLES \n";
		return;
	}

	Nodo* reco = raiz;
	while (reco != NULL) 
	{
		Cotizacion* nuevaCotizacion = reco->cotizacion;
		nuevaCotizacion->MostrarPrendaCotizada();
		reco = reco->sig;
	}
}

void Vendedor::AgregarCotizacion(Cotizacion* cotizacion) 
{
	Nodo* nuevo;
	nuevo = new Nodo();
	nuevo->cotizacion = cotizacion;
	if (raiz == NULL)
	{
		raiz = nuevo;
		nuevo->sig = NULL;
	}
	else
	{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
	numeroCotizaciones++;
	raiz->cotizacion->AsignarID(numeroCotizaciones);
}

#pragma endregion

#pragma region Tienda

class Tienda
{
private:
	string nombre = "";
	string direccion = "";
	class NodoPrendas 
	{
	public:
		Prenda* prenda;
		NodoPrendas* sig;
	};
public:
	Tienda(string nombre, string direccion);
	NodoPrendas* raizCamisas;
	NodoPrendas* raizPantalones;
	string ObtenerNombre();
	string ObtenerDireccion();
	void AgregarPrenda(Prenda* prenda, NodoPrendas* raiz);
};

Tienda::Tienda(string nombre, string direccion) 
{
	this->nombre = nombre;
	this->direccion = direccion;
	raizCamisas = NULL;
	raizPantalones = NULL;
}

string Tienda::ObtenerNombre() 
{
	return nombre;
}

string Tienda::ObtenerDireccion() 
{
	return direccion;
}
void Tienda::AgregarPrenda(Prenda* prenda, NodoPrendas* raiz)
{
	NodoPrendas* nuevo;
	nuevo = new NodoPrendas();
	nuevo->prenda = prenda;
	if (raiz == NULL)
	{
		raiz = nuevo;
		nuevo->sig = NULL;
	}
	else
	{
		nuevo->sig = raiz;
		raiz = nuevo;
	}
}

#pragma endregion

#pragma region Presentador
class Presentador 
{
private: 
	Tienda* tienda;
	Vendedor* vendedor;
public:
	Presentador();
	string NombreTienda();
	string NombreVendedor();
	void InicializarCotizacionVendedor();
	void VerificarTipoPrenda(bool tipoPrenda);
	void VerificarTipoMangaCamisa(bool manga);
	void VerificarTipoCuelloCamisa(bool cuello);
	void VerificarAjustePantalon(bool ajuste);
	void VerificarCalidadPrenda(bool calidad);
	void VerificarCantidadPrenda(int cantidad);
	void VerificarPrecioPrenda(int precio);
	void MostrarCotizacion();
	void ObtenerHistorial();
};

Presentador::Presentador() 
{
	tienda = new Tienda("Quark Store", "Quark Street");
	vendedor = new Vendedor("Benjamin", "Zarate", 0);
}

string Presentador::NombreTienda() 
{
	return tienda->ObtenerNombre() + " | " + tienda->ObtenerDireccion();
}

string Presentador::NombreVendedor() 
{
	return vendedor->ObtenerNombre() + " | " + to_string(vendedor->ObtenerID());
}

void Presentador::InicializarCotizacionVendedor() 
{
	time_t now = time(nullptr);
	struct tm timeinfo;
	char buffer[80];

	localtime_s(&timeinfo, &now);
	strftime(buffer, 80, "%d/%m/%Y %H:%M", &timeinfo);
	vendedor->cotizacionActual = new Cotizacion((string)buffer, vendedor->ObtenerID());
}

void Presentador::VerificarTipoPrenda(bool tipoPrenda) 
{
	vendedor->cotizacionActual->esCamisa = tipoPrenda;
}

void Presentador::VerificarTipoMangaCamisa(bool manga) 
{
	vendedor->cotizacionActual->esMangaCorta = manga;
}

void Presentador::VerificarTipoCuelloCamisa(bool cuello) 
{
	vendedor->cotizacionActual->esCuelloComun = cuello;
}

void Presentador::VerificarAjustePantalon(bool ajuste) 
{
	vendedor->cotizacionActual->esPantalonComun = ajuste;
}

void Presentador::VerificarCalidadPrenda(bool calidad) 
{
	vendedor->cotizacionActual->calidadPrenda = calidad;
}

void Presentador::VerificarCantidadPrenda(int cantidad) 
{
	vendedor->cotizacionActual->AsignarCantidadPrendas(cantidad);
}

void Presentador::VerificarPrecioPrenda(int precio) 
{
	vendedor->cotizacionActual->AsignarPrecioPrenda(precio);
}

void Presentador::MostrarCotizacion() 
{
	vendedor->AgregarCotizacion(vendedor->cotizacionActual);
	vendedor->cotizacionActual->MostrarPrendaCotizada();
}

void Presentador::ObtenerHistorial() 
{
	vendedor->ObtenerHistorial();
}
#pragma endregion

#pragma region Vista
class Vista 
{
private:
	int volverMenuPrincipal;
	Presentador* presentador;
public:
	Vista();
	void MenuPrincipal();
	void HistorialCotizaciones();
	void SeleccionPrenda();
	void SeleccionMangaCamisa();
	void SeleccionCuelloCamisa();
	void SeleccionAjustePantalon();
	void SeleccionCalidadPrenda();
	void IngresoPrecioPrenda();
	void IngresoCantidadPrendas();
	void MostrarResultadoCotizacion();
};

Vista::Vista() 
{
	presentador = new Presentador();
}

void Vista::MenuPrincipal() 
{
	system("CLS");
	int opcionMenu = 3;
	cout << "COTIZADOR EXPRESS - MENU PRINCIPAL \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << presentador->NombreTienda() << endl;
	cout << "-----------------------------------\n" << endl;
	cout << presentador->NombreVendedor() << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "SELECCION UNA OPCION DEL MENU: \n" << endl;
	cout << "1) Historial de cotizaciones \n";
	cout << "2) Realizar cotizacion \n";
	cout << "3) Salir \n";
	cin >> opcionMenu;

	switch (opcionMenu)
	{
	case 1:
		HistorialCotizaciones();
		break;
	case 2:
		SeleccionPrenda();
		break;
	default:
		exit(0);
		break;
	}
}

void Vista::HistorialCotizaciones() 
{
	system("CLS");
	cout << "COTIZADOR EXPRESS - HISTORIAL COTIZACIONES \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	presentador->ObtenerHistorial();
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cin >> volverMenuPrincipal;
	while (volverMenuPrincipal != 3) 
	{
		cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
		cin >> volverMenuPrincipal;
	}
	MenuPrincipal();
}

void Vista::SeleccionPrenda() 
{
	int seleccionPrenda = 1;
	system("CLS");
	presentador->InicializarCotizacionVendedor();
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	cout << "PASO 1: Seleccion la prenda a cotizar: \n";
	cout << "1) Camisa \n";
	cout << "2) Pantalon \n";
	cout << "-----------------------------------\n" << endl;
	cin >> seleccionPrenda;

	switch (seleccionPrenda)
	{
	case 1:
		presentador->VerificarTipoPrenda(true);
		SeleccionMangaCamisa();
		break;
	case 2:
		presentador->VerificarTipoPrenda(false);
		SeleccionAjustePantalon();
		break;
	default:
		MenuPrincipal();
		break;
	}
}

void Vista::SeleccionAjustePantalon() 
{
	int seleccionAjuste = 1;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	cout << "PASO2: El pantalon a cotizar, ¿Es chupin? \n";
	cout << "1) Si \n";
	cout << "2) No \n";
	cin >> seleccionAjuste;
	switch (seleccionAjuste)
	{
	case 1:
		presentador->VerificarAjustePantalon(false);
		break;
	case 2:
		presentador->VerificarAjustePantalon(true);
		break;
	default:
		MenuPrincipal();
		break;
	}
	SeleccionCalidadPrenda();
}

void Vista::SeleccionMangaCamisa() 
{

	int seleccionManga = 1;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	cout << "PASO 2.a: La camisa a cotizar, ¿Es manga corta? \n";
	cout << "1) Si \n";
	cout << "2) No \n";
	cout << "-----------------------------------\n" << endl;
	cin >> seleccionManga;
	
	switch (seleccionManga)
	{
	case 1:
		presentador->VerificarTipoMangaCamisa(true);
		break;
	case 2:
		presentador->VerificarTipoMangaCamisa(false);
		break;
	default:
		MenuPrincipal();
		break;
	}
	SeleccionCuelloCamisa();
}

void Vista::SeleccionCuelloCamisa() 
{
	int seleccionCuello;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	cout << "PASO 2.b: La camisa a cotizar, ¿Es cuello Mao? \n";
	cout << "1) Si \n";
	cout << "2) No \n";
	cin >> seleccionCuello;

	switch (seleccionCuello)
	{
	case 1: 
		presentador->VerificarTipoCuelloCamisa(false);
		break;
	case 2:
		presentador->VerificarTipoCuelloCamisa(true);
		break;
	default:
		MenuPrincipal();
		break;
	}
	SeleccionCalidadPrenda();
}

void Vista::SeleccionCalidadPrenda() 
{
	int seleccionCalidad = 1;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	cout << "PASO 3: Seleccion la claidad de la prenda \n";
	cout << "1) Standard \n";
	cout << "2) Premium \n";
	cin >> seleccionCalidad;

	switch (seleccionCalidad)
	{
	case 1:
		presentador->VerificarCalidadPrenda(true);
		break;
	case 2:
		presentador->VerificarCalidadPrenda(false);
		break;
	default:
		MenuPrincipal();
		break;
	}
	IngresoPrecioPrenda();
}

void Vista::IngresoPrecioPrenda() 
{
	int precio = 0;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PASO 4: Ingrese el precio unitario de la prenda a cotizar: \n";
	cout << "-";
	cout << "-----------------------------------\n" << endl;
	cin >> precio;
	presentador->VerificarPrecioPrenda(precio);
	IngresoCantidadPrendas();
}

void Vista::IngresoCantidadPrendas() 
{
	int cantidad = 0;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "INFORMACION: \n";
	cout << "EXISTE X CANTIDAD DE UNIDADES EN STOCK DE LA PRENDA SELECCIONADA \n";
	cout << "PASO 5: Ingrese la cantidad de unidades a cotizar \n";
	cout << "-";
	cout << "-----------------------------------\n" << endl;
	cin >> cantidad;
	presentador->VerificarCantidadPrenda(cantidad);
	MostrarResultadoCotizacion();
}

void Vista::MostrarResultadoCotizacion() 
{
	int menuPrincipal = 0;
	system("CLS");
	cout << "COTIZADOR EXPRESS - COTIZAR \n" << endl;
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	presentador->MostrarCotizacion();
	cout << "-----------------------------------\n" << endl;
	cout << "PRESIONE EL 3 PARA VOLVER AL MENU PRINCIPAL \n";
	cout << "-----------------------------------\n" << endl;
	cin >> menuPrincipal;
	if (menuPrincipal == 3) 
	{
		MenuPrincipal();
	}
}

#pragma endregion

int main()
{
	Vista* vista = new Vista();
	vista->MenuPrincipal();
	return 0;
}