// Autor/a: Daniel Juan y Alejandro Valencia
// email: danijuan@ucm.es avalen04@ucm.es
// Compilador y S.O. utilizado Visual Studio 2019, Windows 10
// Nombre del problema PR02
// Comentario general sobre la solución : usamos módulos
// explicando como se resuelve el problema
#include "MatrizChar.h"

// Introduce más librerías si son necesarias    
using namespace std;

void resolver(tMatrizChar& matriz);
void mostrar(tMatrizChar& mat);
void resuelveCaso();

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("datos.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("datos.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
    system("PAUSE");
#endif
    return 0;
}

// función que resuelve el problema
void resolver(tMatrizChar& matriz) {
    string op;
    int cont;
    cin >> cont;
    for (int i = 0; i < cont; i++) {
        cin >> op;
        if (op == "VV") {
           
                voltearV(matriz);
        }
        else if (op == "VH") {
            
                voltearH(matriz);
        }
        else if (op == "VD") {
            if (matriz.filas != matriz.cols) {
                cout << "DATOS INCORRECTOS" << endl;
            }
            else {
                VoltearID(matriz);
            }
        }
    }
}

void mostrar(tMatrizChar& mat) {
    for (int i = 0; i < mat.filas; i++) {
        for (int j = 0; j < mat.cols; j++) {
            cout << mat.matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---" << endl;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    tMatrizChar m;
    // leer los datos de la entrada
    if (cargar(m, cin)) {
        resolver(m);
        mostrar(m);
    }
}