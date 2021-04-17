// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct tSong
{
	int duracion;
	int sati;
	bool marcada = false;
};

// función que resuelve el problema
void resolver(const vector<tSong> &d, vector<int>&id, vector<int>&vu, int k) {
	for (int i = 0; i < d.size(); i++)
	{




	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int songs, t1, t2;
	cin >> songs >> t1 >> t2;
	vector<tSong> datos(songs);
	if (songs==0 && t1==0 && t2==0)
		return false;

	for (int i = 0; i < songs; i++)
	{
		cin >> datos[i].duracion >> datos[i].sati;
	}
	vector<int> ida(songs,-1); //vector sol de lista de canciones ida , inicializados a -1
	vector<int> vuelta(songs,-1); //vector sol de lista de canciones vuelta
	int k = 0;

	resolver(datos,ida,vuelta,k);


	// escribir sol
	if (ida[0] == -1 || vuelta[0] == -1)
		cout << "Imposible" << endl;
	else
	{
		cout << "Canciones Ida: ";
		for (int i = 0; i < ida.size() - 1; i++)
			cout << ida[i] << ", ";
		cout << ida[ida.size() - 1] << endl;
		cout << "Canciones Vuelta: ";
		for (int i = 0; i < vuelta.size() - 1; i++)
			cout << vuelta[i] << ", ";
		cout << vuelta[vuelta.size() - 1] << endl;
	}

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
