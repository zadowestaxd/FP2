
typedef struct {
	int fila;
	int col;
}tCoor;

bool operator == (tCoor c1, tCoor c2);
bool operator != (tCoor c1, tCoor c2);
tCoor operator + (tCoor c1, tCoor c2);