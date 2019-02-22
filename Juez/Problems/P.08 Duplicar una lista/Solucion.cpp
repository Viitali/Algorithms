#include <iostream>
#include <fstream>

using namespace std;

#include "queueMod.h"

bool resuelveCaso() {
	int valor;
	queue<int> lista;
	cin >> valor;
	while (valor != 0) {
		lista.push(valor);
		cin >> valor;
	}

	if (!std::cin)
		return false;

	lista.duplicaNodos();

	if (lista.empty()) {
		cout << "" << '\n';
	}
	else
		std::cout << lista << '\n';

		return true;
}

int main() {
	while (resuelveCaso());

	return 0;
}