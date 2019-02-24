#include <iostream>
#include "Estudiant.hh"
#include <vector>

using namespace std;

int main (){
int n,m,l;
cin>>n>>m>>l;

vector <int> as(l);

for (int i=0;i<l;++i){
    
    cin>>as[i];
}
vector <Estudiant> v(n);

for (int k=0;k<n;++k){
    v[k].llegir();
    vector <double> nota(m);
    nota[0]=v[k].consultar_nota();
    double suma=0,mitj;
    for (int i=1;i<m;++i){
    cin>>nota[i];
    }


    for (int j=0;j<l;++j){
        
        suma = suma + nota[as[j]-1];

    }

    mitj=suma/l;

    
    v[k].modificar_nota(mitj);

}

for (int i=0;i<v.size();++i){
    v[i].escriure();
}
    
}
