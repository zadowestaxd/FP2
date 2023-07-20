#include "Matriz.h"

#ifndef JUEGO_PM
#define JUEGO_PM

typedef struct {
	tMatrizChar imagen, imagenFinal;
	int maxAcciones;
	string modo;
	int contador;
}tJuegoPM;

void mainJuegoPM();
int menu();
bool iniciar(tJuegoPM& jpm, string modo);
bool cargar(tJuegoPM& jpm);
void mostrar(tJuegoPM const& jpm);
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);

#endif