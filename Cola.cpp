#include <iostream>
#include "C:\Users\Equipo\Documents\GitHub\Tarea-Corta-2\Cola.hpp"
using namespace std;

void cola::insertar(int v){
  if(fondo<=5-1){
    fondo++;
    Cola[fondo] = v;
  }
  else{
    std::cout <<"La cola esta vacia";
  }
}
void cola::eliminar(){
  if(!ColaVacia()){
    frente++;
  }
  else{
    cout<<"La cola esta vacia";
  }
}
void cola::imprimir(){
  for(int i = frente;i<fondo+1;i++){
    cout<<Cola[i]<<"->";
  }
}
