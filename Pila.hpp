#ifndef PILA_HPP
#define	PILA_HPP
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
#endif
