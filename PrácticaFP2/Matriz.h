#include <iostream>
#include <fstream>
#include <string>
#include "Coordenada.h"
#include "UtilidadesSys.h"

#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

const int DIM_MAX = 64;
const int incF[] = { 1,1,0,-1,-1,-1,0,1 };
const int incC[] = { 0,1,1,1,0,-1,-1,-1 };

typedef struct {
	int numFilas, numCols;
	int elementos[DIM_MAX][DIM_MAX];
}tMatrizChar;

bool cargar(tMatrizChar& mat, istream& ent);
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);
bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool swapF(tMatrizChar& mat, int f1, int f2);
bool swapC(tMatrizChar& mat, int c1, int c2);
bool swapD(tMatrizChar& mat, int d);
bool voltearF(tMatrizChar& mat, int f);
bool voltearC(tMatrizChar& mat, int c);
bool voltearD(tMatrizChar& mat, int d);
void voltearV(tMatrizChar& mat);
void voltearH(tMatrizChar& mat);
void rotarD(tMatrizChar& mat);
bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2);
bool VoltearID(tMatrizChar& mat);
bool coorInRange(tMatrizChar mat, tCoor pos);

#endif