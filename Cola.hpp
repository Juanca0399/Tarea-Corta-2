#ifndef COLA_HPP
#define COLA_HPP
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
#endif
