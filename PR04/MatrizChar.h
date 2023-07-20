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
bool swapD(tMatrizChar& mat, int d);
bool voltearF(tMatrizChar& mat, int f);
bool voltearC(tMatrizChar& mat, int c);
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);
bool VoltearID(tMatrizChar& mat);

#endif