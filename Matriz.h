#ifndef MATRIZ_H
#define MATRIZ_H
#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::cin;
class Matriz{
private:
string nombre;
int** matriz;
int determinante;
int size;

public:
Matriz();
Matriz(string, int**, int);

string getnombre();
void setnombre(string);

int** getmatriz();
void setmatriz(int**);

int getdeterminante();
void setdeterminante(int);

int gettamano();
void settamano(int);

void suma(int**);
void incremento();
void decremento();
void multiplicacion(int);
void impresion(int**);
void determinantecalculo();
~Matriz();

string toString();
};
#endif
    