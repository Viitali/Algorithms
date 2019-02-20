#include "stack_eda.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool resuelveCaso()
{
	
	int k;
	
	cin >> k;
	if (!std::cin)
		return false;

	vector<int> sobr(k);
	stack<int> st;
	int elem, mejorMediano = -1;
	bool premio = true;
	for (int i = 0; i < k; i++)
		cin >> sobr[i];
	int i = k - 1;
	st.push(sobr[i]);
	i--;

	while (i >= 0)
	{
		elem = sobr[i];
		if (elem > mejorMediano)
		{
			while (!st.empty() && st.top() < elem) //en la pila se guardan los valores mayores que el mediano
			{
				mejorMediano = st.top();
				st.pop();
			}
			st.push(elem);
		}
		else
		{	
			premio = false;
		}
		i--;
	}
	if (premio)//esta la terna
		cout << "SIEMPRE PREMIO" << endl;
	else //no esta la terna
		cout << "ELEGIR OTRA" << endl;
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