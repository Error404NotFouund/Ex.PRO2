#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
	b = false;
	int posicio = cerca_dicot(vest, 0, nest - 1, est.consultar_DNI());

	if (vest[posicio].consultar_DNI() == est.consultar_DNI()) b = true;
	if (not b) {
		++nest;
		for (int i = nest - 1; i > posicio; --i) {
			vest[i] = vest[i - 1];
		}
		vest[posicio] = est;

		if (est.te_nota()) {
			if (nest_amb_nota == 0) suma_notes = est.consultar_nota();
			else suma_notes = suma_notes + est.consultar_nota();
			++nest_amb_nota;
		}
	} 
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
	b = false;
	int k = 0;

	while (k < nest and not b) {
		if (vest[k].consultar_DNI() == dni) b = true;
		++k;
	}
	if (b) {
		if (vest[k - 1].te_nota()) {
			suma_notes = suma_notes - vest[k - 1].consultar_nota();
			--nest_amb_nota;
		}
		for (int i = k; i < nest; ++i) {
			vest[i - 1] = vest[i];
		}
		--nest;
	}
}