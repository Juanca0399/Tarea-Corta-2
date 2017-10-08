#include <iostream>
#include <fstream>
#include <string>
#include "C:\Users\Equipo\Documents\GitHub\Tarea-Corta-2\CrearYLeerArchivos.hpp"
using namespace std;

void init() {
  std::ofstream arch1("Arch1.txt");
  std::ofstream arch2("Arch2.txt");
  std::ofstream arch3("Arch3.txt");
  std::ofstream arch4("Arch4.txt");
  std::ofstream arch5("Arch5.txt");

  string insertar;

  cout << "Digite la primera expresion matematica" << endl;
  cin >> insertar;
  arch1 << insertar << std::endl;

  cout << "Digite la segunda expresion matematica" << endl;
  cin >> insertar;
  arch2 << insertar << std::endl;

  cout << "Digite la tercera expresion matematica" << endl;
  cin >> insertar;
  arch3 << insertar << std::endl;

  cout << "Digite la cuarta expresion matematica" << endl;
  cin >> insertar;
  arch4 << insertar << std::endl;

  cout << "Digite la quinta expresion matematica" << endl;
  cin >> insertar;
  arch5 << insertar << std::endl;

  string expresion1, expresion2, expresion3, expresion4, expresion5;

  std::ifstream Archivo1("Arch1.txt");
	std::string str1;
  while (std::getline(Archivo1, str1)) {
    expresion1 = str1;
  }

  std::ifstream Archivo2("Arch2.txt");
	std::string str2;
  while (std::getline(Archivo2, str2)) {
    expresion2 = str2;
  }

  std::ifstream Archivo3("Arch3.txt");
	std::string str3;
  while (std::getline(Archivo3, str3)) {
    expresion3 = str3;
  }

  std::ifstream Archivo4("Arch4.txt");
	std::string str4;
  while (std::getline(Archivo4, str4)) {
    expresion4 = str4;
  }

  std::ifstream Archivo5("Arch5.txt");
	std::string str5;
  while (std::getline(Archivo5, str5)) {
    expresion5 = str5;
  }

  cout << "Expresion 1: " << expresion1 << endl << "Expresion 2: " << expresion2 << endl << "Expresion 3: " << expresion3 << endl;
  cout << "Expresion 4: " << expresion4 << endl << "Expresion 5: " << expresion5 << endl;
}
