// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;



// función que resuelve el problema
void resolver(const vector<vector<int>> &d, int k, vector<int>& sol, vector<int>& solmejor, int &sumtot, int sumloc, vector<bool>&marcafuncionario, vector<bool>&marcatrabajo) {
	for (int i = 0; i < d.size(); i++)
	{
		
		if (!marcafuncionario[i] && !marcatrabajo[k])
		{
			sol[k] = i; //k- trabajo , i- funcionario 
			sumloc += d[i][k];
			marcafuncionario[i] = true;
			marcatrabajo[k] = true;
			if (k == sol.size() - 1) //hemos llegado al final
			{
				if (sumtot > sumloc)
				{
					sumtot = sumloc;
					solmejor = sol;
				}
			}
			else
			{
				resolver(d, k + 1, sol, solmejor, sumtot, sumloc, marcafuncionario, marcatrabajo);
			}
			sumloc -= d[i][k];
			marcafuncionario[i] = false;
			marcatrabajo[k] = false;
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (n==0)
		return false;
	vector<vector<int>> datos(n,vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> datos[i][j];
	int k = 0;
	vector<int>sol(n);
	vector<int> solmejor(n);
	vector<bool> marcafunci(n, false);
	vector<bool> marcatrabajo(n, false);
	int sumtot = 500000, sumloc = 0;
	resolver(datos,k,sol,solmejor,sumtot,sumloc,marcafunci, marcatrabajo);

	// escribir sol
	cout << sumtot << endl;
	/*for (int i = 0; i < solmejor.size(); i++)
		cout << solmejor[i] << " ";
	cout << endl;*/
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
