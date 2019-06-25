#include "Matriz.h"
#include <vector>
using std::vector;
#include <string>
using std::string; 
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
int main(){ 
    vector<int>valores;
    vector<Matriz*>matrices;
    int** matriz=NULL;
    int** matriz2=NULL;
    char resp='s';
    int opcion=0;
    string operacion="";
    while(resp=='s'){
        cout<<"Ingrese su opcion"<<endl
            <<"1.Crear Matrices"<<endl
            <<"2.Listar matrices"<<endl
            <<"3.Eliminar matrices"<<endl
            <<"4.Operar con matrices"<<endl;
            cin>>opcion;
            switch (opcion)
            {
            case 1:{
                 
                matriz=new int*[2];           
                for(int i=0;i<2;i++){
                matriz[i]=new int[2];
                    }
                
                matriz2=new int*[3];
                for(int i=0;i<3;i++){
                matriz2[i]=new int[3];
                }
                string nombre;
                int size,valoractual;
                cout<<"Ingrese el nombre de la matriz a crear:"<<endl;
                cin>>nombre;
                cout<<"Ingrese la dimension(solamente un numero por que es cuadrada)"<<endl;
                cin>>size;
                for(int i=0;i<size*2;i++){
                    cout<<"numero "<<i+1<<":"<<endl;
                    cin>>valoractual;
                    cout<<valoractual<<endl;
                    valores.push_back(valoractual);
                }
                    
                if(size==2){
                    matriz[0][0]=1;
                    matriz[0][1]=valores[1];
                    matriz[1][0]=valores[2];
                    matriz[1][1]=valores[3];
                    matrices.push_back(new Matriz(nombre,matriz,size));
                }else{
                    matriz2[0][0]=valores[0];
                    matriz2[0][1]=valores[1];
                    matriz2[0][2]=valores[2];
                    matriz2[1][0]=valores[3];
                    matriz2[1][1]=valores[4];
                    matriz2[1][2]=valores[5];
                    matriz2[2][0]=valores[6];
                    matriz2[2][1]=valores[7];
                    matriz2[2][2]=valores[8];
                matrices.push_back(new Matriz(nombre,matriz2,size));
                }
                
            }
                break;
            
            case 2:{
                for(int i=0; i<matrices.size();i++){
                    cout<<i<<"."<<endl;
                    matrices[i]->impresion(matrices[i]->getmatriz());
                    cout<<endl;
                }
            }
                break;
            case 3:{
                int eliminar=0;
                cout<<"Ingrese posicion a eliminar"<<endl;
                cin>>eliminar;
                matrices.erase(matrices.begin()+eliminar);
            }
                break;
            case 4:{
                cout<<"Ingrese el numero de la matriz 1,la operacion a realizar, el numero de la matriz 2"<<endl;
                cin>>operacion;
                switch(operacion[1]){
                    case '|':{
                        cout<<(int)operacion[2]-48<<endl;
                        int referenciapos=(int)operacion[2]-48;
                        int referenciapos2=(int)operacion[0]-48;
                        matrices[referenciapos2]->suma(matrices[referenciapos]->getmatriz());
                        }break;
                    case '+':{
                        matrices[(int)operacion[0]-48]->incremento();
                        }break;
                    case '-':{
                        matrices[(int)operacion[0]-48]->decremento();
                        }break;
                     case '>':{
                         int escalar=0;
                        cout<<"Ingrese el escalar deseado"<<endl;
                        cin>>escalar;
                        matrices[(int)operacion[0]-48]->multiplicacion(escalar);
                        }break;
                }
            }
                break;
            }
    }
    // liberar memorias
        for(int i=0;i<2;i++){
            delete[]matriz[i];
            matriz[i]=NULL;
                }
        //liberar ultimo vector
        if(matriz!=NULL){
            delete[]matriz;
            matriz=NULL;
               }
               // liberar memorias
        for(int i=0;i<3;i++){
            delete[]matriz2[i];
            matriz2[i]=NULL;
                }
        //liberar ultimo vector
        if(matriz2!=NULL){
            delete[]matriz2;
            matriz2=NULL;
               }

    return 0;
}
/*
1. Crear matrices
2. Listar matrices
3. Eliminar matrices
4. Operar con matrices
*/
