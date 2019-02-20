#include <string>
#include <iostream>
#include <fstream>
#include "stack_eda.h"
using namespace std;

/*
Mete todos los parentesis , corchetes o llaves abiertas en una pila y va mirando la ultimo de la pila
y anulandolo si es correcto , en caso de tener [( y viene ] daria false.
*/
bool resuelveCaso()
{
	string frase;
	getline(cin, frase);
	if (!cin)
		return false;
	stack<char> pila;
	bool equilibrada = true;
	char c;
	for (int i = 0; i < frase.length() && equilibrada; i++)
	{
		c = frase.at(i);
		if (c == '(' || c == '[' || c == '{') {//Si es abierto añadimos a pila
			pila.push(c);
		}
		//Comprobamos los cerrados, si no coinciden con su respectivo abierto no es equilibrado
		else if (c == ')') {
			if (!pila.empty() && pila.top() == '(') pila.pop();
			else equilibrada = false;
		}
		else if (c == ']') {
			if (!pila.empty() && pila.top() == '[') pila.pop();
			else equilibrada = false;
		}
		else if (c == '}') {
			if (!pila.empty() && pila.top() == '{') pila.pop();
			else equilibrada = false;
		}
	}
	if (equilibrada && pila.empty()) cout << "SI" << endl;
	else cout << "NO" << endl;
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}