// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;


// función que resuelve el problema
char resolver(const vector<char> &p, int ini, int fin,const int ref) {


	if (ini>=fin)//queda un elemento
	{
		if (p[ini] - ref > ini) // si la posicion de ini es menor que la que deberia de tener
			return p[ini] - 1;//el elemento que falta esta a la izquierda
		else //y sino
			return p[ini] + 1; //esta a la derecha
	}
	else
	{
		int mid = (ini + fin) / 2;
		if ((p[mid] - ref) == mid)//esta a la derecha
		{
			return resolver(p, mid+1, fin, ref);
		}
		else
		{
			return resolver(p, ini, mid, ref);
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char ini, fin;
	cin >> ini >> fin;
	vector<char> p(fin - ini);
	for (int i = 0; i < p.size(); i++)
	{
		cin >> p[i];
	}
	char sol = resolver(p,0,p.size()-1,ini);
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