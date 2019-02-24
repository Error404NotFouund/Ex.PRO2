#include "Cjt_estudiants.hh"
 
#include <vector>
using namespace std;
 
 
void modify(Cjt_estudiants& Cjt1, const Cjt_estudiants& Cjt2) {
  for (int i = 0; i < Cjt1.mida(); ++i) {
    Estudiant e1 = Cjt1.consultar_iessim(i+1);
    Estudiant e2 = Cjt2.consultar_iessim(i+1);
    if (e1.te_nota()) {
      if (e2.te_nota() && (e2.consultar_nota() > e1.consultar_nota())) {
        Cjt1.modificar_iessim(i+1, e2);
      }
    }
    else if (e2.te_nota()) {
      Cjt1.modificar_iessim(i+1, e2);
    }
  }
}
 
 
int main() {
  Cjt_estudiants Cjt1, Cjt2;
  Cjt1.llegir();
  Cjt2.llegir();
  modify(Cjt1, Cjt2);
  Cjt1.escriure();
} 
