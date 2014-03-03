/*
p = posicionador
list = lista
sList = aLista
next = sigAlumno

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
    void InitList( lista *aLista );
  //Agregar Valor al inicio
    void InsertarAlInicio( lista *aLista , int boleta );

//Funciones
  //Inicialisa la lista de structs
    void InitList( lista *aLista ){
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

int main(){

}