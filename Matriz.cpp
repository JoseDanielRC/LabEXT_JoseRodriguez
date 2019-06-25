
#include "Matriz.h"

Matriz::Matriz(){
}
Matriz::Matriz(string nombre ,int** matriz  ,int size){
this->size=size;
this->nombre=nombre;
this->matriz=matriz;
this->determinante=determinante;
}
string Matriz::getnombre(){
return nombre;
}
void Matriz::setnombre(string nombre){
this->nombre=nombre;
}

int** Matriz::getmatriz(){
return matriz;
}
void Matriz::setmatriz(int** matriz){
this->matriz=matriz;
}

int Matriz::getdeterminante(){
return determinante;
}
void Matriz::setdeterminante(int determinante){
this->determinante=determinante;
}

int Matriz::gettamano(){
return size;
}
void Matriz::settamano(int size){
this->size=size;
}
void Matriz::suma(int** matrizB){
    int** sumada=NULL;
    sumada=new int*[size];
    for(int i=0;i>size;i++){
        sumada[i]=new int[size];
    }

    for (int i = 0; i < size; i++){
        for(int j=0;j<size;j++){
            sumada[i][j]=matriz[i][j]+matrizB[i][j];
       }
    }
    impresion(matriz);
    
}
void Matriz::decremento(){
    int valorbase=determinante-size;
    for (int i = 0; i < size; i++){
        for(int j=0;j<size;j++){
           matriz[i][j]=matriz[i][j]-valorbase;
       }
    }
    impresion(matriz);
}
void Matriz::incremento(){
    int valorbase=determinante-size;
    for (int i = 0; i < size; i++){
        for(int j=0;j<size;j++){
           matriz[i][j]=matriz[i][j]+valorbase;
       }
    }
    impresion(matriz);
}
void Matriz::determinantecalculo(){
    if(size==2){
                determinante=matriz[0][0]*matriz[1][1]-matriz[1][0]*matriz[0][1];
    }else{
                determinante=matriz[0][0]*(matriz[1][1]*matriz[2][2]-matriz[2][1]*matriz[1][2])-matriz[0][1]*(matriz[1][0]*matriz[2][2]-matriz[1][2]*matriz[2][0])+matriz[0][2]*(matriz[1][0]*matriz[2][1]-matriz[1][1]*matriz[2][0]);
    }
    
}
void Matriz::multiplicacion(int escalar){
    int valorbase=determinante-size;
    for (int i = 0; i < size; i++){
        for(int j=0;j<size;j++){
           matriz[i][j]=matriz[i][j]*escalar;
       }
    }
    impresion(matriz);
}

void Matriz:: impresion(int**referencia){
    for (int i = 0; i < size; i++){
        for(int j=0;j<size;j++){
            cout<<"["<<referencia[i][j]<<"]";
       }
       cout<<endl;
    }
}
Matriz::~Matriz(){
    for(int i=0;i<2;i++){
            delete[]matriz[i];
            matriz[i]=NULL;
                }
        //liberar ultimo vector
        if(matriz!=NULL){
            delete[]matriz;
            matriz=NULL;
               }
}
string Matriz::toString(){
string MatrizStr;
MatrizStr="";
return MatrizStr;
}
/*
suma(int**);
incremento(int);
decremento(int);
multiplicacion(int);
sumavectorial(int**);
*/