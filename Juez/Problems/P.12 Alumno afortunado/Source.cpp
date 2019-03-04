//Vitaliy Savchenko

#include "queue_eda.h"
#include <iostream>
#include <fstream>
using namespace std;


int resuelve(int N, int x)
{
	queue<int> cola = queue<int>();
	int i;
	for (i = 1; i <= N; i++)
	{
		cola.push(i);
	}
	i = x;
	while (cola.size() > 1) //podemos hacerlo ya que pone explicitamente 1<=N<=10000 en el enunciado
	{
		if (i > 0) //no se salva
		{
			cola.push(cola.front()); //lo saco del principio y lo vuelvo a meter al final para que la cola sea ciclica
			cola.pop();
			i--;
		}
		else //se salva
		{
			cola.pop();//alumno sale del sistema "salvado"
			i = x;
		}
	}
	
	return cola.front();
}



bool resuelveCaso() {
	int sol, alumnos, salta;
	cin >> alumnos;
	cin >> salta;
	while (alumnos != 0 && salta != 0)
	{
		sol = resuelve(alumnos, salta);
		cout << sol << endl;
		cin >> alumnos;
		cin >> salta;
	}
	return true;
}


int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	resuelveCaso();

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif
	return 0;
}