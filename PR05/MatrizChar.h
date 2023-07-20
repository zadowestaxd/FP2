#include <iostream>
#include <fstream>
#include "Coordenada.h"

using namespace std;

#ifndef MATRIZCHAR_H
#define MATRIZCHAR_H

const int DIM_MAX = 64;
typedef unsigned char uint8;

typedef struct {
	int filas, cols;
	uint8 matriz[DIM_MAX][DIM_MAX];
}tMatrizChar;


bool cargar(tMatrizChar& matriz, istream& ent);
void rotarD(tMatrizChar& mat);

#endif
