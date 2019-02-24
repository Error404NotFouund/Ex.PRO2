#include <iostream>
#include "Estudiant.hh"
#include <vector>
#include <algorithm>

using namespace std;

bool comp (Estudiant a, Estudiant b){
    return a.consultar_DNI() < b.consultar_DNI();
}

int main (){
int n;
cin>>n;

vector <Estudiant> v(n);
vector <Estudiant> v2(n);
for (int k=0;k<n;++k){
    v[k].llegir();
    }
for (int k=0;k<n;++k){
    v2[k].llegir();
    }
    
int j=0;

for (int k=0;k<2*n;++k){
    if (v[j].consultar_DNI() == v2[k].consultar_DNI() and j!=k){
        if (v[j].consultar_nota()< v2[k].consultar_nota() ) {
            v[j].modificar_nota (v2[k].consultar_nota());
        }
    }
    ++j;
    }
    
sort (v.begin(),v.end(),comp);
for (int i=0;i<v.size();++i){
    v[i].escriure();
}
    
}
