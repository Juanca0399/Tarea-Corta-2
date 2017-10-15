#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class nodo {
   public:
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
       anterior = NULL;
    }

nodo(string v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    string valor;
    nodo *siguiente;
    nodo *anterior;


   friend class cola;
};

typedef nodo *pnodo;

class cola{
  private:
    int frente;
    int fondo;
    pnodo Cola[5];
  public:
    cola(){
      frente = 0;
      fondo = -1;
      for(int i = 0;i>5;i++){
        Cola[i] = 0;
      }
    }
    bool ColaVacia(){return fondo <frente;}
    void insertar(pnodo Node);
    void eliminar();
    void imprimir();
    void IngresarExpresion(string expresion);

};

void cola::insertar(pnodo Node){
  if(fondo<=5-1){
    fondo++;
    Cola[fondo] = Node;
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
  string v;
  for(int i = frente;i<fondo+1;i++){
    pnodo aux = Cola[i];
    while(aux != NULL){
      v = aux->valor;
      cout<<v<<"->";
      aux = aux->siguiente;
    }
    cout<<endl;
  }
}
void cola::IngresarExpresion(string expresion){
  //separa la expresion y la mete en un nodo que después se ingresa a la cola
  string v;
  v = expresion[0];
  pnodo aux = new nodo(v);
  insertar(aux);
  for(std::string::size_type cont = 1; cont < expresion.length();cont++){
    v = expresion[cont];
    aux->siguiente = new nodo(v);
    aux = aux->siguiente;
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

string InputExpresion(){//pide el input de la expresion y verifica que no tenga letras
  string insertar;
  while(true){
    cin >> insertar;
    if (std::any_of(std::begin(insertar), std::end(insertar), ::isalpha))
    {
      cout<<"Operación no valida"<<endl;
      cout<<"Ingrese de nuevo la expresion: ";
    }
    else{
      break;
    }
  }
  return insertar;
}

void CrearArchivos(){
  std::ofstream arch1("Arch1.txt");
  std::ofstream arch2("Arch2.txt");
  std::ofstream arch3("Arch3.txt");
  std::ofstream arch4("Arch4.txt");
  std::ofstream arch5("Arch5.txt");

  string insertar;

  cout << "Digite la primera expresion matematica" << endl;
  insertar = InputExpresion();
  arch1 << insertar << std::endl;

  cout << "Digite la segunda expresion matematica" << endl;
  insertar = InputExpresion();
  arch2 << insertar << std::endl;

  cout << "Digite la tercera expresion matematica" << endl;
  insertar = InputExpresion();
  arch3 << insertar << std::endl;

  cout << "Digite la cuarta expresion matematica" << endl;
  insertar = InputExpresion();
  arch4 << insertar << std::endl;

  cout << "Digite la quinta expresion matematica" << endl;
  insertar = InputExpresion();
  arch5 << insertar << std::endl;
}
string LeerArchivos(string archivo){
  string expresion1;

  std::ifstream Archivo(archivo);
	std::string str1;
  while (std::getline(Archivo, str1)) {
    expresion1 = str1;
  }
  return expresion1;
}

int main(){
  string archivo;
  string expresion;
  CrearArchivos();
  archivo = "Arch1.txt";
  expresion = LeerArchivos(archivo);
  cola cola;
  cola.IngresarExpresion(expresion);
  cola.imprimir();
  expresion = LeerArchivos("Arch2.txt");
  cola.IngresarExpresion(expresion);
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
