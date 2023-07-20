#include "MatrizChar.h"

bool cargar(tMatrizChar& mat, istream& ent) {
	bool ok = true;
	ent >> mat.filas;
	ent >> mat.cols;
	for (int i = 0; i < mat.filas; i++) {
		for (int j = 0; j < mat.cols; j++) {
			ent >> mat.matriz[i][j];
		}
	}
	return ok;
}

void rotarD(tMatrizChar& mat) {
	tMatrizChar aux = mat;

	for (int i = 0; i < mat.cols; i++) {
		for (int j = 0; j < mat.filas; j++) {
			mat.matriz[i][j] = aux.matriz[mat.filas - j - 1][i];
		}
	}

	mat.filas = aux.cols;
	mat.cols = aux.filas;
}