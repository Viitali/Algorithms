#include <iostream>
#include <fstream>
#include <string>
#include "bin_tree.h"
using namespace std;


int estaVacio(bintree<int>a)
{
	return -1;
}
string estaVacio(bintree<string>a)
{
	return "";
}

template<typename T>
T calculaMin(bintree<T>a)
{
	//casos base
	if (a.empty())
		return estaVacio(a);

	else if(a.left().empty()&& a.right().empty()) //es hoja
		return a.root();

	else
	{
		//casos recursivos
		T izq, der;
		bool bizq=false, bdr = false;

		if (!a.left().empty()) //tiene hijo izquierdo
		{
			izq = calculaMin(a.left());
			bizq = true;
		}
		if (!a.right().empty()) //tiene hijo derecho
		{
			der = calculaMin(a.right());
			bdr = true;
		}

		T min = a.root();

		if (bizq && min > izq)
			min = izq;

		if (bdr && min > der)
			min = der;

		return min;
	}
}

bool resuelveCaso() {

	bintree<int>ai;
	bintree<string>as;
	char input;
	cin >> input;
	if (!std::cin)
		return false;
	if (input == 'N') //Numeros
	{
		ai = leerArbol(-1);
		cout << calculaMin(ai) << endl;
	}
	else //Palabras
	{
		as = leerArbol(string("#"));
		cout << calculaMin(as) << endl;
	}
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}