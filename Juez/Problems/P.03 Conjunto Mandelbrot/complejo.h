
# ifndef COMPLEJO
# define COMPLEJO
# include <iostream>
# include <iomanip>
# include <fstream>
# include <stdexcept>
# include <math.h>
using namespace std; //El conjunto de Mandelbrot
class Complejo
{
public:

	Complejo(float r, float i) : real(r), imag(i) {};

	float get_re() const { return real; };
	float get_im() const { return imag; };

	Complejo operator+(Complejo const &a) {
		float re = real + a.get_re();
		float im = imag + a.get_im();

		Complejo suma(re, im);
		return suma;
	}
	Complejo operator*(Complejo const &a) {
		float re = (real*a.get_re()) - (imag*a.get_im());
		float im = (real*a.get_im()) + (imag*a.get_re());
		Complejo resultado(re, im);
		return resultado;
	}
	float mod() {
		return sqrt(this->real*this->real + this->imag*this->imag);
	}
	bool iteracion(int n) { //realiza las operaciones matematicas descritas en el enunciado
		if (n == 0) {
			return true;
		}
		else 
		{
			Complejo c(this->get_re(), this->get_im());
			Complejo z = c;
			if (z.mod() > 2) return false;
			int i = 0;
			while (i<n-1)
			{
				z = (z*z) + c;
				if (z.mod() > 2) return false;
				i++;
			}
			return true;
		}
	}


private:
	float real, imag;

};
#endif
