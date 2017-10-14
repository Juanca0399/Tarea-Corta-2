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

class pila{
public:
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
    void push (string v);
    void pop ();
    void imprimir ();
    void vaciarPila();
  };

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
    void LeerArchivosEInsertarlosEnLaCola();
    void CompararExpresiones(pila &pilaNumeros, pila &pilaOperadores);
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

  void pila::push (string v)
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

  void pila::vaciarPila(){
    while (pilaVacia() == false){
      pop();
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

string LeerContenidoDelArchivo(string archivo){
  //Antes se llamaba LeerArchivos pero para mayor claridad y poder implementar un nuevo método le cambie el nombre
  string expresion;

  std::ifstream Archivo(archivo);
	std::string str;
  while (std::getline(Archivo, str)) {
    expresion = str;
  }
  return expresion;
}

void cola::LeerArchivosEInsertarlosEnLaCola(){
  //Es una funcion invocadora la cual lee todos los archivos e inserta a la cola (el metodo está en esta parte del código para que todas las funciones a las que invoca estén declaradas)
  int cont = 1;
  std::string contEnStr;
  std::string siguienteACont;
  string archivo = "Arch1.txt";
  string expresion;
  while (cont <= 5){
    expresion = LeerContenidoDelArchivo(archivo);
    IngresarExpresion(expresion);
    contEnStr = std::to_string(cont);
    siguienteACont = std::to_string(cont+1);
    archivo.replace(archivo.find(contEnStr), contEnStr.length(), siguienteACont);
    cont++;
  }
}

int validarPFP(string v) {
  //Metodo con las prioridades fuera de la pila
	if (v == "^")
		return 4;
	else if (v == "*" || v == "/")
		return 2;
	else if (v == "+" || v == "-")
		return 1;
  else
  	return 5;
}

int validarPDP(string v) {
  //Metodo con las prioridades dentro de la pila
	if (v == "^")
		return 3;
	else if (v == "*" || v == "/")
		return 2;
	else if (v == "+" || v == "-")
		return 1;
	else
		return 0;
}

void cola::CompararExpresiones(pila &pilaNumeros, pila &pilaOperadores){
  //Este metodo (aun no terminafo) va a comparar, en todas las expresiones, sus distintas prioridades y las va a insertar en las pilas
  //NOTA: Al inicio del ciclo for se limbian las pilas enconces cuando se quiera insertar cosas a los arboles se tiene que tomar en cuenta eso
  int PDP, PFP;
  for(int i = frente;i<fondo+1;i++){
    pilaNumeros.vaciarPila();
    pilaOperadores.vaciarPila();
    pnodo aux = Cola[i];
    while(aux != NULL){
      string v = aux->valor;
      if (isdigit(v[0])){
        pilaNumeros.push(v);
      }
      else{
        if (pilaOperadores.pilaVacia())
          pilaOperadores.push(aux->valor);
        else{
          if (aux->valor == ")"){
            //Aqui va el proceso que sucede cuando el string es ")"
          }
          else{
            PDP = validarPDP(pilaOperadores[Tope]);
            PFP = validarPFP(aux->valor);
            if (PFP > PDP)
              pilaOperadores.push(aux->valor);
            else{
              //Aqui va el proceso que sucede cuando PDP >= PFP
            }
          }
        }
      }
      aux = aux->siguiente;
    }
  }
}

int main(){
  bool opcionIncorrecta = true;
  while (opcionIncorrecta){
    string opcionMenu;
    cout << "¿Que desea hacer?" << endl << "    1. Crear nuevos archivos y leerlos" << endl << "    2. Leer archivos preexistentes" << endl;
    cin >> opcionMenu;
    if (opcionMenu != "1" && opcionMenu != "2"){
      cout << "---------------------------------------" << endl << "Digite una opcion valida" << endl << "---------------------------------------" << endl << endl;
    }
    else if (opcionMenu == "1"){
      CrearArchivos();
      opcionIncorrecta = false;
    }
    else
      opcionIncorrecta = false;
  }
  cola cola;
  cola.LeerArchivosEInsertarlosEnLaCola();
  cola.imprimir();

  cin.get();
  return 0;
}
