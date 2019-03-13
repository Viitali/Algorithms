//Vitaliy Savchenko


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "bin_tree.h"
using namespace std;


string getFrontier(bintree<int>a)
{
	string result;
	string izq = "", der = "";

	if (a.empty()) //Caso base: arbol vacio
	{
		return "";
	}
	else //Arbol con datos
	{
		if (a.left().empty() && a.right().empty()) //Es hoja
		{
			result = to_string(a.root());
		}
		else //No es hoja
		{
			if (!a.left().empty())//tiene hijo izquierdo
			{
				izq = getFrontier(a.left());
				result = izq;
			}
			if (!a.right().empty())
			{
				der = getFrontier(a.right());
				if (izq != "")//en el caso de que haya algo en el hijo izq
				{
					result = result + " " + der;
				}
				else
				{
					result = der;
				}
			}	
		}
		return result;
	}
}

void resuelveCaso() {
	bintree<int>a;
	
	a = leerArbol(-1);

	cout << getFrontier(a) << endl;
	
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


	unsigned int numCasos;
	std::cin >> numCasos;
	// Resolvemos
	for (unsigned int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}