#include "Coordenada.h"

bool operator == (tCoor c1, tCoor c2) {
	return c1.col == c2.col && c1.fila == c2.fila;
}

bool operator != (tCoor c1, tCoor c2) {
	return !operator == (c1, c2);
}

tCoor operator + (tCoor c1, tCoor c2) {
	tCoor res;
	res.fila = c1.fila + c2.fila;
	res.col = c1.col + c2.col;
	return res;
}