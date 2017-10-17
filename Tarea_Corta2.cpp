#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <typeinfo>
using namespace std;

class nodo {
   public:
    nodo(string v)
    {
       valor = v;
       siguiente = NULL;
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


   friend class lista;
   friend class pila;
   friend class cola;
};
typedef nodo *pnodo;

class NodoBinario {
   public:

   string valor;
   int FB;
   NodoBinario *Hizq, *Hder, *siguiente, *anterior;


    NodoBinario(string str, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(str), siguiente(sig), anterior(ant), FB(0) {}



    friend class pila;
    friend class Binario;
    friend class cola;

    void InsertaBinario(string str);
};

typedef NodoBinario *pNodoBinario;

class lista {
public:
	lista() { primero = actual = NULL; }
	~lista();

	void InsertarFinal(string v);
  int largoLista();
	bool ListaVacia() { return primero == NULL; }
	void Mostrar();
	void BorrarFinal();
	void vaciar();

protected:
	pnodo primero;
	pnodo actual;
};

lista::~lista()
{
	pnodo aux;

	while (primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
	actual = NULL;
}

void lista::InsertarFinal(string v)
{
	if (ListaVacia())
		primero = new nodo(v);
	else
	{
		pnodo  aux = primero;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->siguiente = new nodo(v);
	}
}

void lista::BorrarFinal()
{
	if (ListaVacia()) {
		cout << "No hay elementos en la lista:" << endl;

	}
	else {
		if (primero->siguiente == NULL) {
			primero = NULL;
		}
		else {

			pnodo aux = primero;
			while (aux->siguiente->siguiente != NULL) {
				aux = aux->siguiente;

			}

			pnodo temp = aux->siguiente;
			aux->siguiente = NULL;


			delete temp;
		}
	}
}

int lista::largoLista() {
	int cont = 0;

	pnodo aux;
	aux = primero;
	if (ListaVacia()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->siguiente;
			cont++;
		}
		return cont;
	}

}

void lista::Mostrar()
{
	nodo *aux;

	aux = primero;
	while (aux!=NULL) {
		cout << aux->valor << "-> ";
		aux = aux->siguiente;
	}
	cout << endl;
}

void lista::vaciar(){
  while (ListaVacia() == false)
    BorrarFinal();
}

class pila : public lista{
  public:
    pnodo Tope;
  public:
    pila() {Tope = NULL;}
    void push(string v);
    void pop();
    bool pilaVacia();
    void imprimir();
    void vaciarPila();
};

void pila::push (string v){
  InsertarFinal(v);
  if (Tope == NULL)
    Tope = primero;
  else{
    Tope = Tope->siguiente;
  }
}

void pila::pop (){
  BorrarFinal();
  Tope = primero;
  while (Tope->siguiente != NULL)
    Tope = Tope->siguiente;
}

bool pila::pilaVacia (){
  return ListaVacia();
}

void pila::imprimir (){
  Mostrar();
}

void pila::vaciarPila (){
  vaciar();
  Tope = NULL;
}

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

    friend class pila;
};


void PreordenR(NodoBinario* R);
void InordenR(NodoBinario* R);
void PostordenR(NodoBinario* R);

void NodoBinario::InsertaBinario(string str)
{

}

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
      cout << v << "->";
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
  pNodoBinario x1;
  pNodoBinario x2;
  string topeActual;
  for(int i = frente;i<fondo+1;i++){
    pilaNumeros.vaciarPila();
    pilaOperadores.vaciarPila();
    pnodo aux = Cola[i];
    while(aux != NULL){
      string v = aux->valor;
      if (isdigit(v[0])){
        //Si el caracter es un numero entonces lo inserta en pilaNumeros
        pilaNumeros.push(v);
      }
      else{
        if (pilaOperadores.pilaVacia())
        //Si la pila de operadores está vacía entonces lo inserta en pilaOperadores
          pilaOperadores.push(aux->valor);
        else{
          if (aux->valor == ")"){
            //SI el operador es ")" entonces saca todos los operadores y los inserta en pilaNumeros hasta entontrar "(" y luego lo elimina
            while(pilaOperadores[pilaOperadores.Tope]->valor != "("){
              x1 = pilaNumeros[pilaNumeros.Tope];
              pilaNumeros.pop();
              x2 = pilaNumeros[pilaNumeros.Tope];
              pilaNumeros.pop();
              cout<<"x1 = "<<x1->valor<<endl<<"x2 = "<<x2->valor<<endl;
              topeActual = pilaOperadores[pilaOperadores.Tope]->valor;
              pilaNumeros.push(topeActual);
              pilaNumeros[pilaNumeros.Tope]->Hder = x1;
              pilaNumeros[pilaNumeros.Tope]->Hizq = x2;
              pilaOperadores.pop();
            }
            pilaOperadores.pop();
          }
          else{
            //Se sacan las prioridades dentro y fuera de la pila
            PDP = validarPDP(pilaOperadores[pilaOperadores.Tope]->valor);
            PFP = validarPFP(aux->valor);
            if (PFP > PDP){
            //Si la prioridad fuera de la pila es mayor  que la prioridad dentro de la pila
              pilaOperadores.push(aux->valor);
            }
            else{
              x1 = pilaNumeros[pilaNumeros.Tope];
              pilaNumeros.pop();
              x2 = pilaNumeros[pilaNumeros.Tope];
              pilaNumeros.pop();
              cout<<"x1 = "<<x1->valor<<endl<<"x2 = "<<x2->valor<<endl;
              topeActual = pilaOperadores[pilaOperadores.Tope]->valor;
              pilaNumeros.push(topeActual);
              pilaOperadores.pop();
              pilaOperadores.push(aux->valor);
              pilaNumeros[pilaNumeros.Tope]->Hder = x1;
              pilaNumeros[pilaNumeros.Tope]->Hizq = x2;
            }
          }
        }
      }
      aux = aux->siguiente;
      if (aux == NULL){
        while (pilaOperadores.pilaVacia() == false){
          x1 = pilaNumeros[pilaNumeros.Tope];
          pilaNumeros.pop();
          x2 = pilaNumeros[pilaNumeros.Tope];
          pilaNumeros.pop();
          cout<<"x1 = "<<x1->valor<<endl<<"x2 = "<<x2->valor<<endl;
          topeActual = pilaOperadores[pilaOperadores.Tope]->valor;
          pilaNumeros.push(topeActual);
          pilaNumeros[pilaNumeros.Tope]->Hder = x1;
          pilaNumeros[pilaNumeros.Tope]->Hizq = x2;
          pilaOperadores.pop();
        }
      }
    }
    cout << endl << endl << "postfijo:   ";
    pilaNumeros.imprimir();
    cout<<endl;
    cout<<"Hizq= "<<pilaNumeros[pilaNumeros.Tope]->Hizq->valor<<endl;
    cout<<"Hizq= "<<pilaNumeros[pilaNumeros.Tope]->Hizq->Hizq->valor<<endl;

    cout<<"Recorridos :"<<endl;
    cout<<endl<<"Postorden :  ";
    PreordenR(pilaNumeros[pilaNumeros.Tope]);
  }
}

void PreordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        cout<<R->valor<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<" - ";
        InordenR(R->Hder);
    }
}

void PostordenR(NodoBinario *R){
  if(R==NULL){
    return;
  }else{
      PostordenR(R->Hizq);
      PostordenR(R->Hder);
      cout<<R->valor<<" - ";
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
  cout << endl << "Cola:" << endl << endl;
  cola.imprimir();
  pila pilaOperadores;
  pila pilaNumeros;
  cola.CompararExpresiones(pilaNumeros,pilaOperadores);
  cin.get();
  return 0;
}
