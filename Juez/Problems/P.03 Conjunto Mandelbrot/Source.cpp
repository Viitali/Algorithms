#include "complejo.h"




void resuelveCaso() {
	// leer los datos de la entrada
	float r, i;
	int n;
	std::cin >> r >> i >> n;

	Complejo z(r, i);
	// escribir sol
	if (z.iteracion(n)) std::cout << "SI" << endl;
	else std::cout << "NO" << endl;
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