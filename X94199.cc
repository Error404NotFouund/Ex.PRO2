#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;


void simplificar_vector(vector<Estudiant>& v, int& pos){
    double max = -1;
    int k = v.size();
    if(v.size() > 1){
    vector <Estudiant> vfinal;
    for(int i = 1; i < k; ++i){
        if(v[i-1].consultar_DNI() != v[i].consultar_DNI()){
            if (i == k - 1){
                Estudiant a(v[i - 1].consultar_DNI());
                if (max >= 0 and max <= 10) a.afegir_nota(max);
                vfinal.push_back(a);

                Estudiant b(v[i].consultar_DNI());
                if (v[i].te_nota()) b.afegir_nota(v[i].consultar_nota());
                vfinal.push_back(b);
            }
            else {
                Estudiant a(v[i - 1].consultar_DNI());
                if (max >= 0 and max <= 10) a.afegir_nota(max);
                if (i - 1 == 0 and v[i - 1].te_nota()) a.afegir_nota(v[i-1].consultar_nota());
                vfinal.push_back(a);
                if(v[i].te_nota()) max = v[i].consultar_nota();
                if(not v[i].te_nota()) max = -1;
            }
        }
        else {
            if(k - 1 == i){
                if(v[i].te_nota()){
                    if(v[i].consultar_nota() > max) max = v[i].consultar_nota();
                }
                Estudiant a(v[i].consultar_DNI());
                if(max >= 0 and max <= 10) a.afegir_nota(max);
                vfinal.push_back(a);
            }
            else{
                if(v[i].te_nota()){
                    if(v[i].consultar_nota() > max) max = v[i].consultar_nota();
                }
            }
        }
    }
        v = vfinal;
    }
    pos = v.size() - 1;
}
