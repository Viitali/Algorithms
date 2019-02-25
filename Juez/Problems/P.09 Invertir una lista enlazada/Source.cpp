#include "queueMod.h"

bool resuelveCaso() {

	int valor;
	queue<int>lista;
	cin >> valor;

	while (valor != 0) //carga la cola
	{
		lista.push(valor);
		cin >> valor;
	}

	if (!std::cin)
		return false;

	lista.invierte();

	if (lista.empty()) {
		cout << "" << endl;
	}
	else
		cout << lista<< endl;

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