#include <iostream>
using namespace std;

class cola{
  private:
    int frente;
    int fondo;
    int Cola[5];
  public:
    cola(){
      frente = 0;
      fondo = -1;
      for(int i = 0;i>5;i++){
        Cola[i] = 0;
      }
    }
    bool ColaVacia(){return fondo <frente;}
    void insertar(int v);
    void eliminar();
    void imprimir();
};

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

class pila{
  private:
  int Tope;
  int Pila[5];
public:

    pila(){
    Tope = -1;
    for (int i = 0; i<5 ; i++){
      Pila[i] = 0;
      }
    }

    bool pilaVacia(){return Tope < 0;}
    void push (int v);
    void pop ();
    void imprimir ();
  };
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
