#include <iostream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>  
using namespace std;
int ElecciónIntercalada(vector <int> Vector,int Entrar) {
	int Valor = ElecciónIntercalada(Vector);
	if (Entrar) {
		Entrar = 0;
		return 1;
	}
	if (Vector.size()-1 == 0) {

	}
	else if (Valor ==1){
		int Contador = 0;
		for (size_t i = 0; i < ; i++) {
			Vector.erase(Vector.begin()+Contador);
			Contador++;
		}
		return 2;
	}
	else if (Valor ==2) {
		int Contador = 0;
		for (size_t i = 0; i < Vector; i++) {
			Vector.erase(Vector.begin() + Contador);
			Contador++;
		}
		return 1;
	}
}
void ejercicio1() {
	cout << "El último sobreviviente." << endl << endl;
	cout << "Ingrese el tamaño del vector:";
	int TamañoVector;
	cin >> TamañoVector;
	vector <int> ListaVectores;
	for (size_t i = 0; i < TamañoVector; i++){
		int NumeroAleatorio= 1 + rand() % 10;;
		ListaVectores.push_back(NumeroAleatorio);
	}
	for (int i = 0; i < TamañoVector; i++) {
		cout << (i == 0 ? "Vector generado : [" : "") << " " << ListaVectores[i] << (i == TamañoVector-1 ? "]\n" : "");
	}

	cout << "Último sobreviviente : [" << "]";
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
			ejercicio1();
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