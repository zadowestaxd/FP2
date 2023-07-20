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

bool voltearF(tMatrizChar& mat, int f) {
	bool ok = false;
	tCoor a, b;
	if (f < mat.filas && f >= 0) {
		for (int i = 0; i < mat.cols / 2; i++) {
			a.fila = f;
			a.col = i;
			b.fila = f;
			b.col = mat.cols - i - 1;
			swap(mat, a, b);
		}
		ok = true;
	}
	return ok;
}

bool voltearC(tMatrizChar& mat, int c) {
	bool ok = false;
	tCoor a, b;

	if (c < mat.cols && c >= 0) {
		for (int i = 0; i < mat.filas / 2; i++) {
			a.fila = i;
			a.col = c;
			b.fila = mat.filas - i - 1;
			b.col = c;
			swap(mat, a, b);
		}
		ok = true;
	}
	return ok;
}