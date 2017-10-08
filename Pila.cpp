#include <iostream>
#include "C:\Users\Equipo\Documents\GitHub\Tarea-Corta-2\Pila.hpp"
using namespace std;

void pila::push (int v)
{
  if (Tope < (5-1))
  {
    Tope++;
    Pila[Tope] = v;
  }
  else
    cout << "La pila esta llena";
}
void pila::pop (){
  if (!pilaVacia()){
    Tope--;
  }
  else{
    cout << "La pila esta vacia";
  }
}

void pila::imprimir()
{
  for (int i = Tope; i >= 0; i--)
  {
    cout << Pila[i] << "->";
  }
}
