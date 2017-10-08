#include <iostream>
#include <stdlib.h>
#include "C:\Users\Equipo\Documents\GitHub\Tarea-Corta-2\Cola.hpp"
#include "C:\Users\Equipo\Documents\GitHub\Tarea-Corta-2\CrearYLeerArchivos.hpp"
#include "C:\Users\Equipo\Documents\GitHub\Tarea-Corta-2\Pila.hpp"
using namespace std;
int main(){
  cola cola;
  cola.insertar(1);
  cola.insertar(3);
  cola.insertar(5);
  cola.imprimir();

  cout << endl;

  pila pila;

  pila.push(2);
  pila.push(3);
  pila.push(4);
  pila.push(5);
  pila.push(10);
  pila.imprimir();

  cin.get();
  return 0;
}
