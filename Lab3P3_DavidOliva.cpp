#include <iostream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>  
using namespace std;
void ImprimirVector(vector <int> Vector) {
	for (int i = 0; i < Vector.size(); i++) {
		cout << (i == 0 ? "[" : "") << " " << Vector[i] << (i == Vector.size() - 1 ? " ]\n" : "");
	}
}
int ElecciónIntercalada(vector <int> Vector, int Entrar, int Valor, int Detener) {
	if (Vector.size() % 2 == 1) {
		Detener = (Vector.size() / 2) + 1;
	}
	else {
		Detener = Vector.size() / 2;
	}

	if (Entrar) {
		return ElecciónIntercalada(Vector, 0, 1, 0);
	}

	if (Vector.size() - 1 == 0) {
		cout << "Último sobreviviente : [" << Vector[0] << "]" << "\n";
		return 0;
	}
	else if (Valor == 1) {
		int Contador = 0;
		for (size_t i = 0; i < Vector.size(); i++) {
			if (Detener == Contador)
			{
			}
			if (Detener != Contador) {
				Vector.erase(Vector.begin() + Contador);
				Contador++;
			}
			else {
				break;
			}
		}
		ImprimirVector(Vector);
		ElecciónIntercalada(Vector, 0, 2, 0);
	}
	else if (Valor == 2) {
		int Contador = Vector.size() - 1;
		for (int i = Vector.size() - 1; i >= 0; i--) {
			if (Contador >= 0) {
				Vector.erase(Vector.begin() + Contador);
				Contador -= 2;
			}
		}
		ImprimirVector(Vector);
		return ElecciónIntercalada(Vector, 0, 1, 0);
	}
}
void ejercicio1() {
	srand(time(NULL));
	cout << "El último sobreviviente." << endl << endl;
	cout << "Ingrese el tamaño del vector:";
	int TamañoVector;
	cin >> TamañoVector;
	while (TamañoVector < 5 || TamañoVector >15)
	{
		cout << "El valor esta fuera de rango." << "\n";
		cout << "Ingrese el tamaño del vector:";
		cin >> TamañoVector;
	}
	vector <int> ListaVectores;
	for (size_t i = 0; i < TamañoVector; i++) {
		int NumeroAleatorio = 1 + rand() % 10;;
		ListaVectores.push_back(NumeroAleatorio);
	}
	for (int i = 0; i < TamañoVector; i++) {
		cout << (i == 0 ? "Vector generado : [" : "") << " " << ListaVectores[i] << (i == TamañoVector - 1 ? " ]\n" : "");
	}
	ElecciónIntercalada(ListaVectores, 1, 0, 0);
}
void ejercicio2() {

}
void menu() {
	int OpcionesMenu = 0;
	do {
		setlocale(LC_ALL, "Spanish");
		cout << "---- Menú ----" << "\n";
		cout << "1. El último sobreviviente" << "\n" << "2. Operaciones con puntos." << "\n" << "3. Salir" << "\n" << "\n";
		cout << "Ingrese la opción que desea realizar:";
		cin >> OpcionesMenu;
		switch (OpcionesMenu) {
		case 1:
			ejercicio1();
			break;
		case 2:
			ejercicio2();
			break;
		case 3:
			cout << " ";
			break;
		default:
			cout << endl << "Opción incorrecta Vuelve a Intentar." << endl << endl;
			break;
		}
	} while (OpcionesMenu != 3);
}
int main() {
	menu();
	return 0;
}