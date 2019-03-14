//Vitaliy Savchenko

#include <iostream>
#include <fstream>
#include "bin_tree.h"
using namespace std;


void gruposRescate(bintree<int>a, int &ne, int &ng)
{
	//Si el arbol es vacio
	ng = 0;
	ne = 0;
	if (a.left().empty() && a.right().empty()) //es hoja
	{
		if (a.root() != 0) //tiene excursionistas
		{
			ng = 1;
			ne = a.root();
		}
	}

	else
	{ //tiene algun hijo
		int ngi = 0; //num grupos izq
		int ngd = 0; //num grupos der
		int nei = 0; //num excursionistas izq
		int ned = 0; //num excursionistas der

		if (!a.left().empty()) //tiene izquierdo
			gruposRescate(a.left(), nei,ngi);

		if (!a.right().empty()) //tiene derecho
			gruposRescate(a.right(), ned, ngd);

		//calcular ne
		ne = a.root() + max(ned, nei);

		//calcular ng
		if (ngi != 0 || ngd != 0) //si alguno de los hijos requiere un grupo , el nodo ya no necesita otro
			ng = ngi + ngd;

		else
		{ //en caso de que los hijos son 0
			if (a.root() != 0) //si el nodo es distinto de 0 necesita un grupo
				ng = 1;
			else
				ng = 0;
		}
	}
}
void resuelveCaso() {

	int ne, ng;//num excursionistas , num grupos de rescarte
	int cu;
	bintree<int>a;

	//leemos arbol
	a = leerArbol(-1);
	//obtener ne,ng
	gruposRescate(a, ne, ng);
	cout << ng << " " << ne << endl;
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
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}


#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}