#include <iostream>
#define N 5
using namespace std;
bool solve(int tablero[N][N], int coln);
bool isSafe(int tablero[N][N], int row, int coln);
void print_tablero(int tablero[N][N]);
int main()
{
	int tablero[N][N];
	//Llenamos el tablero con . que significa que la casilla es segura
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tablero[i][j] = 0;
		}
	}

	//Mostramos por pantalla el tablero
	if (solve(tablero, 0) == false)
	{
		cout << "No hay sol";
	}
	else
	{
		print_tablero(tablero);
	}
	
}
void print_tablero(int tablero[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tablero[i][j])
			{
				cout << "Q ";
			}
			else
			{
				cout << ". ";
			}
		}
		cout << endl;
	}
}

bool isSafe(int tablero[N][N], int row, int coln) {
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < coln; i++) {
		if (tablero[row][i]) {
			return false;
		}
	}

	/* Check upper diagonal on left side */
	for (i = row, j = coln; i >= 0 && j >= 0; i--, j--) {
		if (tablero[i][j]) {
			return false;
		}
	}

	/* Check lower diagonal on left side */
	for (i = row, j = coln; j >= 0 && i < N; i++, j--) {
		if (tablero[i][j]){
			return false;
	}
}

	return true;

}
bool solve(int tablero[N][N], int coln) {
	if (coln >=N)
	{
		return true;
	}
	for (int i = 0; i < N; i++)
	{
		if (isSafe(tablero,i,coln))
		{
			tablero[i][coln] = 1;
			if (solve(tablero, coln +1))
			{
				return true;
			}
			tablero[i][coln] = 0;
		}
	}
	return false;
}
