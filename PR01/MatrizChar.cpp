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

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool ok = false;
	uint8 aux;
	
	aux = mat.matriz[pos1.fila][pos1.col];
	mat.matriz[pos1.fila][pos1.col] = mat.matriz[pos2.fila][pos2.col];
	mat.matriz[pos2.fila][pos2.col] = aux;
	
	return ok;
}

bool swapF(tMatrizChar& mat, int f1, int f2) {
	bool ok = false;

	if (f1 < mat.filas && f1 >= 0 && f2 < mat.filas && f2 >= 0) {
		tCoor a, b;
		a.fila = f1;
		b.fila = f2;

		for (int i = 0; i < mat.cols; i++) {
			a.col = i;
			b.col = i;
			swap(mat, a, b);
		}
		ok = true;
	}
	return ok;
}

bool swapC(tMatrizChar& mat, int c1, int c2) {
	bool ok = false;

	if (c1 < mat.cols && c1 >= 0 && c2 < mat.cols && c2 >= 0) {
		tCoor a, b;
		a.col = c1;
		b.col = c2;

		for (int i = 0; i < mat.filas; i++) {
			a.fila = i;
			b.fila = i;
			swap(mat, a, b);
		}
		ok = true;
	}
	return ok;
}