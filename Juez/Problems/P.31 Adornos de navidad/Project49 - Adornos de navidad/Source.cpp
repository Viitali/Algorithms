// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tObj
{
	int tam;
	int coste;
};
bool esValida(const vector<tObj> &d, int k, const int &presu, int presloc)
{
	if (presloc+d[k].coste > presu)
		return false;
	return true;
}
// función que resuelve el problema
void resolver(const vector<tObj> &d, int k, int &smax, int sloc, vector<bool> &solmej, vector<bool> &solloc, const int &presu, int presloc) {
	solloc[k] = true;
	if (esValida(d,k,presu,presloc)) //añadimos objeto
	{
		sloc += d[k].tam;
		presloc += d[k].coste;

		if (k == d.size() - 1) //hemos reccorido todo el vector?
		{
			if (smax < sloc)
			{
				smax = sloc;
				solmej = solloc;
			}
		}
		else
		{
			resolver(d, k + 1, smax, sloc, solmej, solloc,presu,presloc);
		}
		sloc -= d[k].tam;
		presloc -= d[k].coste;
	}
	solloc[k] = false; //no lo cogemos
	if (k == d.size() - 1) //hemos recorrido todo el vector?
	{
		if (smax < sloc)
		{
			smax = sloc;
			solmej = solloc;
		}
	}
	else
	{
		resolver(d, k + 1, smax, sloc, solmej, solloc,presu,presloc);
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, presu;
	cin >> n >> presu;
	if (!std::cin)
		return false;
	vector<tObj> d(n);
	for (int i = 0; i < n; i++)
		cin >> d[i].coste >> d[i].tam;

	int k = 0;
	int smax = 0, sloc = 0, presloc = 0;
	vector<bool> solmej(n);
	vector<bool> solloc(n);
	resolver(d,k,smax,sloc,solmej,solloc,presu,presloc);

	// escribir sol
	cout << smax << endl;
	/*for (int i = 0; i < solmej.size(); i++)
	{
		if (solmej[i])
			cout << "Elemento: " << i << " SI" << endl;
		else
		{
			cout << "Elemento: " << i << " NO" << endl;
		}
	}
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