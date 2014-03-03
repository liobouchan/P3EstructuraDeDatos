/*
p = posicionador
list = lista
sList = aLista
next = sigAlumno
node = Alumno
data = boleta
*/

#include <stdio.h>
#include <stdlib.h>

//Definimos el Struct
  typedef struct Alumno{
    int boleta;
    struct Alumno *sigAlumno;
  }nodoAlumno;

  typedef struct lista {
    struct Alumno *start;
  }lista;

//Funciones Prototipo
  //Inicializar la lista
    void InicializarLista ( lista *aLista );
  //Agregar Valor al inicio
    void InsertarAlInicio ( lista *aLista , int boleta );
  //Imprimir Lista
    void ImprimirLista ( lista *aLista );

//Funciones
  //Inicialisa la lista de structs
    void InicializarLista( lista *aLista ){
      aLista -> start = NULL;
    }
  //Insertar Valor al Inicio
    void InsertarAlInicio( lista *aLista , int boleta ){
      nodoAlumno *posicionador;
      posicionador = malloc( sizeof( nodoAlumno ));
      posicionador -> boleta = boleta;
      posicionador -> sigAlumno = aLista -> start;
      aLista -> start = posicionador;
    }
  //Insertar al Final FALTA FALTA FALTA
    void InsertarAlFinal( lista *aLista , int boleta ){
      nodoAlumno *posicionador;
      posicionador = malloc( sizeof( nodoAlumno ));
      posicionador -> boleta = boleta;
      posicionador -> sigAlumno = NULL;
      //poner el while con iterador despues i-> sigAlum = posicionador
    }
  //Imprimir Lista
    void ImprimirLista ( lista *aLista ){
      nodoAlumno *posicionador = aLista -> start;
      while( posicionador != NULL ){
        printf("%d\n", posicionador -> boleta);
        posicionador = posicionador -> sigAlumno;
      }
    }

int main(){

  int x;
  lista MiLista;
  InicializarLista( &MiLista );

 /* for (x = 0; x < 6; ++x){
    InsertarAlInicio(&MiLista, x);
  }

  ImprimirLista(&MiLista); 
*/
  for (x = 0; x < 6; ++x){
    InsertarAlFinal(&MiLista, x);
  }
  ImprimirLista(&MiLista); 

}