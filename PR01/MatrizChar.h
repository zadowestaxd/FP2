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
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);

#endif 

