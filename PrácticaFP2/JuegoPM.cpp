#include "JuegoPM.h"

void mainJuegoPM() {
	tJuegoPM jpm;
	bool end = false;
	switch (menu()) {
	case(1): {jpm.modo = "1D"; break; }
	case(2): {jpm.modo = "2D"; break; }
	case(0): {end = true; break; }
	}
	iniciar(jpm, jpm.modo);
	jugar(jpm);
}

int menu() {
	int opcion;
	cout << "Elija una opcion (1 - Modo 1D, 2 - Modo 2D, 0 - Salir): ";
	cin >> opcion;
	return opcion;
}

bool iniciar(tJuegoPM& jpm, string modo){
	bool ok = false;
	jpm.contador = 0;
	jpm.modo = modo;
	if(cargar(jpm)) ok = true;
	return ok;
}

bool cargar(tJuegoPM& jpm) {
	bool ok = false;
	string imag;
	cout << "Escriba el nombre de la imagen: ";
	cin >> imag;
	ifstream im(imag + "_" + jpm.modo + ".txt");
	if (cargar(jpm.imagen, im) && cargar(jpm.imagenFinal, im)) ok = true;
	im >> jpm.maxAcciones;
	return ok;
}

void mostrar(tJuegoPM const& jpm) {
	
	for (int i = 0; i < jpm.imagen.numFilas; i++) {
		for (int j = 0; j < jpm.imagen.numCols; j++) {
			colorCTA(jpm.imagen.elementos[i][j], jpm.imagen.elementos[i][j]);
			cout << (jpm.imagen.elementos[i][j]);
		}
		colorCTA(0, 15);
		cout << endl;
	}
	
	cout << endl << endl;
	for (int i = 0; i < jpm.imagenFinal.numFilas; i++) {
		for (int j = 0; j < jpm.imagenFinal.numCols; j++) {
			colorCTA(jpm.imagenFinal.elementos[i][j], jpm.imagenFinal.elementos[i][j]);
			cout << (jpm.imagenFinal.elementos[i][j]);
		}
		colorCTA(0, 15);
		cout << endl;
	}
	colorCTA(0, 15);
	cout << "Numero de intentos restantes: " << jpm.maxAcciones - jpm.contador << endl;
}

bool jugar(tJuegoPM& jpm) {
	bool end = false;
	
	while (!end) {
		mostrar(jpm);
		accion(jpm);
		jpm.contador++;
		if (jpm.contador == jpm.maxAcciones) {
			end = true;
			cout << "Limite de movimientos alcanzado, ha perdido";
			pausa();
		}
		// borrar();
	} 
	return end;
}

void accion(tJuegoPM& jpm) {
	string opcion;
	
	cout << "Escriba la accion deseada: ";
	cin >> opcion;
	if (opcion == "SF" || opcion == "sf") {
		int f1, f2;
		cout << "Escriba las filas a cambiar: ";
		cin >> f1;
		cin >> f2;
		swapF(jpm.imagen, f1, f2);
	}
	else if (opcion == "SC" || opcion == "sc") {
		int c1, c2;
		cout << "Escriba las columnas a cambiar: ";
		cin >> c1;
		cin >> c2;
		swapC(jpm.imagen, c1, c2);
	}
	else if (opcion == "SD" || opcion == "sd") {
	int d;
		cout << "Escriba la diagonal a cambiar: ";
		cin >> d;
		swapD(jpm.imagen, d);
	}
	else if (opcion == "VF" || opcion == "vf") {
		int f;
		cout << "Escriba la fila a voltear: ";
		cin >> f;
		voltearF(jpm.imagen, f);
	}
	else if (opcion == "VC" || opcion == "vc") {
		int c;
		cout << "Escriba la columna a voltear: ";
		cin >> c;
		voltearC(jpm.imagen, c);
	}
	else if (opcion == "VD" || opcion == "vd") {
		int d;
		cout << "Escriba la diagonal a voltear: ";
		cin >> d;
		voltearD(jpm.imagen, d);
	}
	else if (opcion == "VV" || opcion == "vv") {
		voltearV(jpm.imagen);
	}
	else if (opcion == "VH" || opcion == "vh") {
		voltearH(jpm.imagen);
	}
	else if (opcion == "RD" || opcion == "rd") {
		rotarD(jpm.imagen);
	}
	else if (opcion == "SA" || opcion == "sa") {
	tCoor coor1, coor2;
	int fila, columna;
		cout << "Escriba las coordenadas a cambiar: ";
		cout << "coor1 fila:";
		cin >> coor1.fila;
		cout << "coor1 columna:";
		cin >> coor1.col;
		cout << "coor2 fila:";
		cin >> coor2.fila;
		cout << "coor2 columna:";
		cin >> coor2.col;
		swap(jpm.imagen, coor1, coor2);
	}
	else if (opcion == "VD" || opcion =="vd") {
		VoltearID(jpm.imagen);
	}
	else {
		cout << "Operacion desconocida";
		pausa();
		jpm.contador -= 1;
	}
}