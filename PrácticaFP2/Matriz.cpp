#include "Matriz.h"

bool cargar(tMatrizChar& mat, istream& ent) {
	bool ok = true;
	ent >> mat.numFilas;
	ent >> mat.numCols;
	for (int i = 0; i < mat.numFilas; i++) {
		for (int j = 0; j < mat.numCols; j++) {
			ent >> mat.elementos[i][j];
		}
	}
	return ok;
}

bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {
	bool ok = true;
	if (mat1.numFilas == mat2.numFilas && mat1.numCols == mat2.numCols) {
		for (int i = 0; i < mat1.numFilas; i++) {
			for (int j = 0; j < mat1.numCols; j++) {
				if (mat1.elementos[i][j] != mat2.elementos[i][j]) ok = false;
			}
		}
	}
	return ok;
}

bool swap(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool ok = false;
	int aux;
	aux = mat.elementos[pos1.fila][pos1.col];

	if (coorInRange(mat, pos1) && coorInRange(mat, pos2)) {
		mat.elementos[pos1.fila][pos1.col] = mat.elementos[pos2.fila][pos2.col];
		mat.elementos[pos2.fila][pos2.col] = aux;
		ok = true;
	}
	return ok;
}

bool swapF(tMatrizChar& mat, int f1, int f2) {
	bool ok = false;

	if (f1 <= mat.numFilas && f1 >= 0 && f2 <= mat.numFilas && f2 >= 0) {
		int aux;

		for (int i = 0; i < mat.numCols; i++) {
			aux = mat.elementos[f1][i];
			mat.elementos[f1][i] = mat.elementos[f2][i];
			mat.elementos[f2][i] = aux;
		}
		ok = true;
	}
	return ok;
}

bool swapC(tMatrizChar& mat, int c1, int c2) {
	bool ok = false;

	if (c1 <= mat.numCols && c1 >= 0 && c2 <= mat.numCols && c2 >= 0) {
		int aux;

		for (int i = 0; i < mat.numFilas; i++) {
			aux = mat.elementos[i][c1];
			mat.elementos[i][c1] = mat.elementos[i][c2];
			mat.elementos[i][c2] = aux;
		}
		ok = true;
	}
	return ok;
}
bool swapD(tMatrizChar& mat, int d) {
	bool ok = false;

	int i = d, j = 0, offset = d;
	if (d < 0) offset = -offset; // pasa el la variable a valor absoluto

	while(i < mat.numCols / 2 && j < (mat.numFilas + offset) / 2) {
		char aux;
		if(i>0) {
			if(!ok) ok = true;
			aux = mat.elementos[i][j];
			mat.elementos[i][j] = mat.elementos[mat.numFilas - i - 1][mat.numFilas - j - 1];
			mat.elementos[mat.numFilas - i - 1][mat.numFilas - j - 1] = aux;
		}
		i++;
		j++;
	}

	return ok; 
} 

bool voltearF(tMatrizChar& mat, int f) {
	bool ok = false;
	int aux;

	if (f <= mat.numFilas && f >= 0) {
		for (int i = 0; i < mat.numCols/2; i++) {
			aux = mat.elementos[f][i];
			mat.elementos[f][i] = mat.elementos[f][mat.numCols - i - 1];
			mat.elementos[f][mat.numCols - i - 1] = aux;

		}

		ok = true;
	}
	return ok;
} 

bool voltearC(tMatrizChar& mat, int c) {
	bool ok = false;
	int aux;

	if (c <= mat.numCols && c >= 0) {
		for (int i = 0; i < mat.numFilas/2; i++) {
			aux = mat.elementos[i][c];
			mat.elementos[i][c] = mat.elementos[mat.numFilas - i - 1][c];
			mat.elementos[mat.numFilas - i - 1][c] = aux;
		}

		ok = true;
	}
	return ok;
}

bool voltearD(tMatrizChar& mat, int d) {
	bool ok = false;
	int aux;

	if (d <= mat.numFilas && d <= mat.numCols ) {
		int i = 0, j = 1;
		while (i <= mat.numFilas / 2 && j <= mat.numCols / 2) {
			if (d >= 0) {
				aux = mat.elementos[i][d + i];
				mat.elementos[i][d + i] = mat.elementos[mat.numCols - d - j][mat.numCols - j];
				mat.elementos[mat.numCols - d - j][mat.numCols - j] = aux;
			}
			else {
				d = -d;
				aux = mat.elementos[d + i][i];
				mat.elementos[d + i][i] = mat.elementos[mat.numFilas - j][mat.numFilas - d - j];
				mat.elementos[mat.numFilas - j][mat.numFilas - d - j] = aux;
			}
			i++, j++;
		}
		ok = true;
	}

	return ok;
}

void voltearV(tMatrizChar& mat) {
	for(int i=0; i<mat.numFilas; i++){
		voltearF(mat, i);
	}
}

void voltearH(tMatrizChar& mat) {
	for(int i=0; i<mat.numCols; i++){
		voltearC(mat, i);
	}
}

void rotarD(tMatrizChar& mat) {
	tMatrizChar aux = mat;
    for (int i = 0; i < mat.numFilas; i++)
        for (int j = 0; j < mat.numCols; j++)
            mat.elementos[i][j] = aux.elementos[mat.numFilas - j - 1][i];
}

bool swapAdy(tMatrizChar& mat, tCoor pos1, tCoor pos2) {
	bool ok = false;
	int aux;
	if (coorInRange(mat, pos1) && coorInRange(mat, pos2)) {
		for (int i = 0; i < mat.numFilas; i++) {
			for (int j = 0; j < mat.numCols; j++) {
				aux = mat.elementos[pos1.fila + incF[i]][pos1.col + incC[j]];
				mat.elementos[pos1.fila + incF[i]][pos1.col + incC[j]] = mat.elementos[pos2.fila + incF[i]][pos2.col + incC[j]];
				mat.elementos[pos2.fila + incF[i]][pos2.col + incC[j]] = aux;
			}
		}
	}
	return ok;
}

bool VoltearID(tMatrizChar& mat) {
	bool ok = false;
	if (mat.numFilas == mat.numCols) {
		tMatrizChar aux;
		for (int i = 0; i < mat.numFilas / 2; i++) {
			for (int j = 0; j < mat.numCols / 2; j++) {
				aux.elementos[i][j] = mat.elementos[i][mat.numCols - j - 1];
				mat.elementos[i][mat.numCols - j - 1] = mat.elementos[mat.numFilas - j - 1][i];
				mat.elementos[mat.numFilas - j - 1][i] = aux.elementos[i][j];
			}
		}
	}
	ok = true;
	return ok;
}

bool coorInRange(tMatrizChar mat, tCoor pos) {
	bool ok = false;
	if (pos.fila < mat.numFilas && pos.fila >= 0 && pos.col < mat.numCols && pos.col >= 0) ok = true;
	return ok;
}