#include <iostream>
#include <vector>
#include "Cjt_estudiants.hh"

using namespace std;

double redondear(double r) {
	return int(10.*(r + 0.05)) / 10.0;
}

int main() {
	Cjt_estudiants Cjt;
	Cjt.llegir();

	int n;
	while (cin >> n and n != -6) {
		//añadir nuevo estudiante
		if (n == -1) {
			Estudiant est;
			est.llegir();

			int n_dni = est.consultar_DNI();
			bool existeix = Cjt.existeix_estudiant(n_dni);
			if (existeix) {
				cout << "el estudiante " << n_dni << " ya estaba" << endl << endl;
			}
			else {
				if (Cjt.mida() == 5) {
					cout << "el conjunto esta lleno" << endl << endl;
				}
				else {
					Cjt.afegir_estudiant(est);
				}
			}

		}

		//consultar nota de un estudiante a partir de su DNI
		if (n == -2) {
			int n_dni;
			cin >> n_dni;
			bool existeix = Cjt.existeix_estudiant(n_dni);

			if (existeix) {
				Estudiant est = Cjt.consultar_estudiant(n_dni);
				bool te_nota = est.te_nota();
				if (te_nota) {
					cout << "el estudiante " << n_dni << " tiene nota " << est.consultar_nota() << endl << endl;
				}
				else {
					cout << "el estudiante " << n_dni << " no tiene nota" << endl << endl;
				}
			}
			else {
				cout << "el estudiante " << n_dni << " no esta" << endl << endl;
			}
		}

		//modificar nota de un estudiante
		if (n == -3) {
			Estudiant est;
			est.llegir();

			int n_dni = est.consultar_DNI();
			bool existeix = Cjt.existeix_estudiant(n_dni);
			if (not existeix) {
				cout << "el estudiante " << n_dni << " no esta" << endl << endl;
			}
			else {
				Cjt.modificar_estudiant(est);
			}
		}

		//redondear la nota, a la décima más cercana, a todos los estudiantes del conjunto
		if (n == -4) {
			for (int i = 0; i < Cjt.mida(); ++i) {
				Estudiant est = Cjt.consultar_iessim(i + 1);
				if (est.te_nota()) {
					est.modificar_nota(redondear(est.consultar_nota()));
					Cjt.modificar_iessim(i + 1, est);
				}
			}
		}

		//escribir conjunto
		if (n == -5) {
			Cjt.escriure();
			cout << endl;
		}

	}
}