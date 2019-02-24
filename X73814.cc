#include <iostream>
#include "Estudiant.hh"
#include <vector>

using namespace std;

int main (){
int n;
cin>>n;

vector <Estudiant> v(n);
for (int i=0;i<n;++i){
v[i].llegir();
}

vector <Estudiant> v2(1);
v2[0]=v[0];

int j=0;
for (int i=1;i<n;++i){
if (v[i].consultar_DNI() != v2[j].consultar_DNI()){
    
    v2.push_back(v[i]);
    ++j;
}
else {
    if (v[i].te_nota() and not v2[j].te_nota())  v2[j].afegir_nota (v[i].consultar_nota());
    else if (v[i].te_nota() and (v2[j].consultar_nota() < v[i].consultar_nota())){ v2[j].modificar_nota(v[i].consultar_nota());
    }
}
}


for (int i=0;i<v2.size();++i){
    v2[i].escriure();
}
    
}
