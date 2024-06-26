﻿#include <iostream>
#include <vector>
#include <locale>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>    
#include <time.h>  
using namespace std;
// este código imprime el vector poniendo un corchete al principio y al final.
void ImprimirVector(vector <int> Vector) {
	for (int i = 0; i < Vector.size(); i++) {
		cout << (i == 0 ? "[" : "") << " " << Vector[i] << (i == Vector.size() - 1 ? " ]\n" : "");
	}
}
/*
* este código recurcivo elimina elementos de vector Intercalada mente sumando un cunado va de derecha a izquierda y restado 2  izquierda a derecha 
*/
int ElecciónIntercalada(vector <int> Vector, int Entrar, int Valor, int Detener) {
	// este if else busca si el tamaño del vector es par o impar.
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
	while (TamañoVector < 5 || TamañoVector >15){ // este while valida si el tamaño esta en le rango de 5 al 15 
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
void CálculoEuclidiano() {
	cout << "Ingrese el tamaño de los arreglos: ";
	int Tamaño;
	cin >> Tamaño;
	while (Tamaño < 2 || Tamaño >10) { // este while valida si el tamaño esta en le rango de 2 al 10 
		cout << "El tamaño esta fuera de rango." << "\n";
		cout << "Ingrese el tamaño de los arreglos: ";
		cin >> Tamaño;
	}
	int* PtrArreglo1 = new int[Tamaño];
	int* PtrArreglo2 = new int[Tamaño];
	int punto1 = 0, punto2 = 0;
	for (size_t i = 0; i < Tamaño; i++) {
		int NumeroAleatorio = 1 + rand() % 20;
		PtrArreglo1[i] = NumeroAleatorio;
		NumeroAleatorio = 1 + rand() % 20;
		PtrArreglo2[i] = NumeroAleatorio;
	}

}
void CálculoPuntoMedio() {
	cout << "Ingrese el tamaño de los arreglos: ";
	int Tamaño;
	cin >> Tamaño;
	while (Tamaño < 2 || Tamaño >10) { // este while valida si el tamaño esta en le rango de 2 al 10 
		cout << "El tamaño esta fuera de rango." << "\n";
		cout << "Ingrese el tamaño de los arreglos: ";
		cin >> Tamaño;
	}
	int* PtrArreglo1 = new int[Tamaño];
	int* PtrArreglo2 = new int[Tamaño];
	int punto1 = 0, punto2 = 0;
	for (size_t i = 0; i < Tamaño; i++) {
		int NumeroAleatorio = 1 + rand() % 20;
		PtrArreglo1[i] = NumeroAleatorio;
		NumeroAleatorio = 1 + rand() % 20;
		PtrArreglo2[i] = NumeroAleatorio;
	}
	for (int i = 0; i < Tamaño; i++) {
		cout << (i == 0 ? "Puntos generado en X generados : [" : "") << " " << PtrArreglo1[i] << (i == Tamaño - 1 ? " ]\n" : "");
	}
	for (int i = 0; i < Tamaño; i++) {
		cout << (i == 0 ? "Puntos generado en Y generados : [" : "") << " " << PtrArreglo2[i] << (i == Tamaño - 1 ? " ]\n" : "");
	}
	cout << "Ingrese el punto 1: ";
	cin >> punto1;
	cout << "Ingrese el punto 2: ";
	cin >> punto2;
	double ResultadoX = (PtrArreglo1[punto1-1] + PtrArreglo1[punto2-1]) / 2;
	double ResultadoY = (PtrArreglo2[punto1-1] + PtrArreglo2[punto2-1]) / 2;
	cout << "El punto medio de los puntos " << punto1 << " y " << punto2 << "es X = " << ResultadoX << ", Y = " << ResultadoY;
	delete PtrArreglo1;
}
void CálculoColineal() {
	cout << "Ingrese el tamaño de los arreglos: ";
	int Tamaño;
	cin >> Tamaño;
	while (Tamaño < 2 || Tamaño >10) { // este while valida si el tamaño esta en le rango de 2 al 10 
		cout << "El tamaño esta fuera de rango." << "\n";
		cout << "Ingrese el tamaño de los arreglos: ";
		cin >> Tamaño;
	}
	int* PtrArreglo1 = new int[Tamaño];
	int* PtrArreglo2 = new int[Tamaño];
	int punto1 = 0, punto2 = 0;
	for (size_t i = 0; i < Tamaño; i++) {
		int NumeroAleatorio = 1 + rand() % 20;
		PtrArreglo1[i] = NumeroAleatorio;
		NumeroAleatorio = 1 + rand() % 20;
		PtrArreglo2[i] = NumeroAleatorio;
	}
	for (int i = 0; i < Tamaño; i++) {
		cout << (i == 0 ? "Puntos generado en X generados : [" : "") << " " << PtrArreglo1[i] << (i == Tamaño - 1 ? " ]\n" : "");
	}
	for (int i = 0; i < Tamaño; i++) {
		cout << (i == 0 ? "Puntos generado en Y generados : [" : "") << " " << PtrArreglo2[i] << (i == Tamaño - 1 ? " ]\n" : "");
	}
	cout << "Ingrese el punto 1: ";
	cin >> punto1;
	cout << "Ingrese el punto 2: ";
	cin >> punto2;
	double Resultado= PtrArreglo1[punto1-1]*(PtrArreglo2[punto2-1] - 0) - PtrArreglo2[punto1-1]*(PtrArreglo1[punto2-1] - 0);
	if (Resultado<0) {
		Resultado = Resultado * -1;
	}
	Resultado = Resultado / 2;
	cout << "Area de los puntos " << punto1 << " y " << punto2 << "es = "<< Resultado;
	if (Resultado==0){
		cout << "los puntos son colineales.";
	}
	else {
		cout << "los puntos no son colineales.";
	}
	delete PtrArreglo1;
}
void ejercicio2() {
	int OpcionesMenu = 0;
	do {
		srand(time(NULL));
		cout << "---- Menú Operaciones ----" << "\n";
		cout << "1. Cálculo Euclidiano" << "\n" << "2. Cálculo Colineal"<<"\n" << "3. Cálculo Punto Medio" << "\n" << "4. Salir" << "\n" << "\n";
		cout << "Ingrese la opción que desea realizar:";
		cin >> OpcionesMenu;
		switch (OpcionesMenu) {
		case 1:

			CálculoEuclidiano();
			break;
		case 2:
			CálculoColineal();
			break;
		case 3:
			CálculoPuntoMedio();
			break;
		case 4:
			cout << " ";
			break;
		default:
			cout << endl << "Opción incorrecta Vuelve a Intentar." << endl << endl;
			break;
		}
	} while (OpcionesMenu != 4);
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