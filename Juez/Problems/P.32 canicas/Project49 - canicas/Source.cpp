// Vitaliy Savchenko
// E68

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct tJugador
{
	string nombre;
	int canicas;
};

/*Precondicion:
Para todo vector<tJugador> d : d.size() > 0
Para todo n : 0<=n<d.size() => d[n].canicas>=1
Para todo ini, fin : 0 <= ini <= fin < d.size()
*/
/*
Coste: el coste de la funcion es O(log n) siendo n el nº de elemento del vector ya que partimos de un vector 
que vamos dividiendo en cada vuelta
Despegando:
1º vuelta: T(N/2) + c				= T(n/2) + c
2º vuelta: T(N/2)/2) + c + c		= T(n/4) + 2c
3º vuelta: T(N/2)/2)/2) + c + c + c = T(n/8) + 3c
...
k vuelta: T(N/2^k) + kc
Que operandolo matematicamente llegamos a la conclusion de que el coste es O(log n) 
*/
/*
Postcondicion:
Para todo tJugador sol que devuelva la funcion : Existe un i tal que : 0<=i<d.size() => d[i].nombre == sol.nombre
Para todo sol.canicas : 1<=sol.canicas < sumatorio i de (para todo j : 0<=j<d.size() ==> d[j].canicas) // aqui quiero decir
que el valor de sol.canicas va a estar en un rango entre 1 (ya que todos los jug como minimo tienen 1 canica) y como maximo
sol.canicas tiene que ser menor que el sumatorio de todas las canicas de todos los jugadores, ya que cuando gana un jug
solo se puede llevar la mitad de las canicas del rival. Esta bien expresado?
*/

// función que resuelve el problema
tJugador resolver(const vector<tJugador>&d, int ini, int fin) {

	tJugador ganador;
	if (ini==fin)//caso base 1 jugador (ya que en ningun momento nos dicen que el vector tiene minimo 2 jugadores
	{
		return d[ini];
	}
	else if (ini + 1 == fin) //caso base 2 elementos
	{
		if (d[ini].canicas >= d[fin].canicas)
		{
			ganador = d[ini];
			ganador.canicas += (d[fin].canicas / 2);
		}
		else
		{
			ganador = d[fin];
			ganador.canicas += (d[ini].canicas / 2);
		}
		return ganador;
	}
	else //mas de 2
	{
		int mid = (ini + fin) / 2;
		tJugador izq = resolver(d, ini, mid);
		tJugador der = resolver(d, mid + 1, fin);

		if (izq.canicas >= der.canicas)
		{
			ganador = izq;
			ganador.canicas += (der.canicas / 2);
		}
		else
		{
			ganador = der;
			ganador.canicas += (izq.canicas / 2);
		}
		return ganador;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	if (!std::cin)
		return false;
	vector<tJugador> datos(n);
	for (int i = 0; i < n; i++)
	{
		cin >> datos[i].nombre >> datos[i].canicas;
	}

	tJugador sol = resolver(datos, 0 , datos.size()-1);

	// escribir sol
	cout << sol.nombre << " " << sol.canicas << endl;


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