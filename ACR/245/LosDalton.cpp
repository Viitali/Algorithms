#include <iostream>
#include <fstream>
using namespace std;



void resuelveCaso() {

	int n;
	cin >> n;
	while (n != 0)
	{
		unsigned long long int a, b;
		bool cre = true;
		bool decre = true;
		int i = 0; //contador de 0 hasta n para recorrer la secuencia de hermanos
		cin >> a;
		i++;
		while (i<n)
		{
			cin >> b;
			if (a >= b&&cre)  //comparamos los hermanos para ver si estan ordenados
				cre = false;
			if (a <= b&&decre)
				decre = false;
			a = b;
			i++;
		}
		if (cre || decre) 
			cout << "DALTON" << endl;
		if (!cre && !decre)
		{
			cout << "DESCONOCIDOS" << endl;
		}
		cin >> n;
	}
}

int main() {
	// Para la entrada por fichero.
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

		resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}