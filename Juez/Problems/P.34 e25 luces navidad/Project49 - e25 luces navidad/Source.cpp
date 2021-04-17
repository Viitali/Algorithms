// Vitaliy Savchenko
// E68


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct  tDatos
{
	int l;
	int ncol;
	int w;
};
bool esValida(const tDatos &d, const vector<int> &bb, vector<int>&sol, int k, int wloc, int &ncomb,vector<int>&nluces,int nlucescol, int i)
{
	if (k >= 2)
	{
		if (sol[k] == sol[k - 1] && sol[k] == sol[k - 2])
			return false;
	}
	if (wloc > d.w)
		return false;
	if (nluces[i] > nlucescol - nluces[i] + 1)
		return false;
	return true;

}

// función que resuelve el problema
void resolver(const tDatos &d, const vector<int> &bb,vector<int>&sol, int k, int wloc, int &ncomb, vector<int>&nluces, int nlucescol) {
	for (int i = 0; i < bb.size(); i++)
	{
		sol[k] = i;
		wloc += bb[i];
		nlucescol++;
		nluces[i]++;
		if (esValida(d,bb,sol,k,wloc,ncomb,nluces,nlucescol,i))
		{
			
			if (k == sol.size() - 1)
			{
				ncomb++;
				/*for (int i = 0; i < sol.size(); i++)
					cout << sol[i] << " ";
				cout << endl;*/
			}
			else
			{
				resolver(d, bb, sol, k + 1, wloc, ncomb, nluces, nlucescol);
			}
		}
		wloc -= bb[i];
		nlucescol--;
		nluces[i]--;

	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	tDatos d;
	cin >> d.l;
	if (d.l == 0)
		return false;
	cin >> d.ncol >> d.w;
	vector<int> bb(d.ncol);
	vector<int> sol(d.l);
	vector<int> nluces(d.ncol,0);

	for (int i = 0; i < d.ncol; i++)
		cin >> bb[i];

	int k = 0, wloc = 0, ncomb = 0, nlucescol = 0;
	resolver(d,bb,sol,k,wloc,ncomb,nluces,nlucescol);

	// escribir sol
	cout << ncomb << endl;
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
