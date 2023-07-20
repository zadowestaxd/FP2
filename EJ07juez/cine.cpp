
// ****************************************************

// Prueba de evaluación del día 12 de junio de 2020
// Alumno/a: 
// email:  @ucm.es
// Grupo:
// ****************************************************

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "cine.h"

void inicializarListaEntradas(tListaPeticiones& listaEntradas) {
	listaEntradas.numEntradasPendientes = 0;
	listaEntradas.capacidad = 20;
	listaEntradas.arrayEntradas = new tEntradas[listaEntradas.capacidad];
}

void inicializarListaPelis(tListaPelis& listaPelis) {
	listaPelis.numPelis = 0;
}

bool cargar(tListaPelis& listaPelis, tListaPeticiones& listaEntradas) {

	string titulo;
	cin >> titulo;

	if (!cin)
		return false;

	while (titulo != "---") {
		listaPelis.arrayPelis[listaPelis.numPelis] = new tPeli;
		listaPelis.arrayPelis[listaPelis.numPelis]->titulo = titulo;
		cin >> listaPelis.arrayPelis[listaPelis.numPelis]->precio;
		cin >> listaPelis.arrayPelis[listaPelis.numPelis]->annyo;
		cin >> listaPelis.arrayPelis[listaPelis.numPelis]->num_disponibles;
		listaPelis.numPelis++;
		cin >> titulo;
	}

	cin >> titulo;

	while (titulo != "000") {
		if (listaEntradas.numEntradasPendientes == listaEntradas.capacidad)
			ampliar(listaEntradas);
		listaEntradas.arrayEntradas[listaEntradas.numEntradasPendientes].titulo = titulo;
		cin >> listaEntradas.arrayEntradas[listaEntradas.numEntradasPendientes].num_solicitadas;
		listaEntradas.numEntradasPendientes++;
		cin >> titulo;
	}
	return true;
}



void visualizarPelis(const tListaPelis& listaPelis) {
	cout << endl ;
	cout << "   *****   Lista de pelis   *****   " << endl << endl;

	for (int i = 0; i < listaPelis.numPelis; i++) {
		cout << listaPelis.arrayPelis[i]->titulo << " - "
			<< listaPelis.arrayPelis[i]->precio << " euros - "
			<< listaPelis.arrayPelis[i]->annyo << " - "
			<< listaPelis.arrayPelis[i]->num_disponibles << " localidades disponibles." << endl;
	}
	cout << endl;
}


void visualizarPeticiones(const tListaPeticiones& listaEntradas) {

	cout << "   *****   Lista de entradas pendientes por procesar   *****" << endl << endl;

	for (int i = 0; i < listaEntradas.numEntradasPendientes; i++) {
		cout << listaEntradas.arrayEntradas[i].titulo << " - "
			<< listaEntradas.arrayEntradas[i].num_solicitadas << " entradas solicitadas." << endl;
	}
	cout << endl;
}



void ampliar(tListaPeticiones& lista) {

	tEntradas* aux = new tEntradas[2 * lista.capacidad];

	for (int i = 0; i < lista.numEntradasPendientes; i++)
	{
		aux[i] = lista.arrayEntradas[i];
	}

	delete[] lista.arrayEntradas; //OJO! usar [] para vectores din�micos
	lista.arrayEntradas = aux;
	lista.capacidad *= 2;
	aux = nullptr;
}



