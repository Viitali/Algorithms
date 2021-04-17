﻿// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
int resolver(const vector<int> & l1, const vector<int> & l2, int ini , int fin) {

	if (ini>=fin) //un elemento
	{
		if (l1[fin]==l2[fin])
		{
			return -1;
		}
		else
		{
			return l1[fin];
		}
	}
	else
	{
		int mid = (ini + fin) / 2;
		if (l1[mid] == l2[mid]) //si son iguales hasta el mid, el elemento esta a la derecha
			return resolver(l1, l2, mid+1, fin);
		else //si en mid difieren es que el elem perdido esta a la izq
		{
			return resolver(l1, l2, 0, mid);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n = 0;
	cin >> n; 
	vector<int> l1(n);
	vector<int> l2(n);
	for (int i = 0; i < n; i++)
		cin >> l1[i];
	for (int i = 0; i < n-1; i++)
		cin >> l2[i];
	
	int sol = resolver(l1, l2, 0, n - 1);

	// escribir sol
	cout << sol << endl;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}