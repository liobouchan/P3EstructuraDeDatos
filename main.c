#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definimos los Struct
  //Estructura de Alumno
    typedef struct Alumno{
      int boleta;
      struct Alumno *sigAlumno;
    }nodoAlumno;
  //Estructura de Listas que contienen Alumno
    typedef struct Lista {
      struct Alumno *start;
    }Lista;

//Funciones
  //Comparar Listas
    int compararListas( nodoAlumno *lista1 , nodoAlumno *lista2 ){
      int val = 1;
      nodoAlumno *iterador1 = lista1;
      nodoAlumno *iterador2 = lista2;

    while(iterador1 != NULL && iterador2 != NULL){
      //Mientras los valores no sean nulos comparamos los valores de boleta
      if(iterador1 -> boleta != iterador2 -> boleta){
        val=0;
        break;
      }
      iterador1 = iterador1 -> sigAlumno;
      iterador2 = iterador2 -> sigAlumno;
    }
    if( (iterador1!=NULL && iterador2==NULL) || (iterador1==NULL && iterador2!=NULL) ){
      val=0;
    }
    return val;
    }
  //Concatenar
    nodoAlumno* concatenar( nodoAlumno *lista1 , nodoAlumno *lista2, int orden ){
    /*Si el usuario introduce 1 la primer lista irá primero
      Por el contrario si el usuario introduce 2, se pone la lista2 primero
      y el último nodo recibe como siguienteALumno todos los valores de la
      lista numero 1*/
    if(orden==1){
      if(lista1==NULL){
        return lista2;
      }else{
          nodoAlumno*iterador=lista1;
          while(iterador->sigAlumno!=NULL){
            iterador = iterador -> sigAlumno;
          }
          iterador->sigAlumno=lista2;
          return lista1;
        }
      }
    if(orden==2){
      if(lista2==NULL){
        return lista1;
      }else{
          nodoAlumno*iterador=lista2;
          while(iterador->sigAlumno!=NULL){
            printf("%d\n", iterador -> boleta);
            iterador = iterador -> sigAlumno;
          }
          iterador->sigAlumno=lista1;
          return lista2;
        }
      }
    }
  //Inicialisa la lista de structs
    void InicializarLista( Lista *aLista ){
      aLista -> start = NULL;
    }
  //Insertar Valor al Inicio
    void InsertarAlInicio( Lista *aLista , int boleta ){
      nodoAlumno *posicionador;
      posicionador = malloc( sizeof( nodoAlumno ));
      posicionador -> boleta = boleta;
      posicionador -> sigAlumno = aLista -> start;
      aLista -> start = posicionador;
    }
  //Insertar un Elemento al final
    nodoAlumno* InsertarAlFinal(){
      int val=0;
      nodoAlumno *posicionador;
      posicionador = malloc( sizeof( nodoAlumno ));

      puts("Escribe la boleta de este alumno");
      scanf("%d",&(posicionador -> boleta));
      setbuf(stdin,NULL);
      posicionador -> sigAlumno = NULL;
      nodoAlumno *iterador;
      iterador=posicionador;
      puts("Desea agragar otro alumno, 0 para no");
      scanf("%d",&val);
      setbuf(stdin,NULL);
      while(val!=0){
        iterador->sigAlumno= malloc( sizeof( nodoAlumno ));
        iterador=iterador->sigAlumno;
        puts("Escribe la boleta de este alumno");
        scanf("%d",&(iterador -> boleta));
        setbuf(stdin,NULL);
        iterador->sigAlumno=NULL;   
        puts("Desea agragar otro alumno, 0 para no");
        scanf("%d",&val);
        setbuf(stdin,NULL);
      }
      return posicionador;
    }
  //Intercalar Nodos
    nodoAlumno* intercalarNodos(nodoAlumno* lista1,nodoAlumno* lista2){
    nodoAlumno* iterador1=lista1;
    nodoAlumno* iterador2=lista2;
    nodoAlumno* lista3=NULL;  
    lista3=malloc( sizeof( nodoAlumno ));
    
    if(iterador1!=NULL){
      lista3->boleta=iterador1->boleta;
      iterador1=iterador1->sigAlumno;
    }else{
      if(iterador2!=NULL){
        lista3->boleta=iterador2->boleta;
        iterador2=iterador2->sigAlumno;
      }
    }
    lista3->sigAlumno=NULL;
    nodoAlumno* iterador3;
    iterador3=lista3;
    while(iterador1!=NULL || iterador2!=NULL){
      if(iterador2!=NULL){
        iterador3->sigAlumno=malloc( sizeof( nodoAlumno )); 
        iterador3=iterador3->sigAlumno;
        iterador3->boleta=iterador2->boleta;
        iterador2=iterador2->sigAlumno;
        iterador3->sigAlumno=NULL;
      }
      if(iterador1!=NULL){
        iterador3->sigAlumno=malloc( sizeof( nodoAlumno ));
        iterador3=iterador3->sigAlumno;
        iterador3->boleta=iterador1->boleta;
        iterador1=iterador1->sigAlumno;
        iterador3->sigAlumno=NULL;
      }
    }
      return lista3;
    }
  //Invertir Lista
    void invertirLista(nodoAlumno*lista, Lista *aLista){
      nodoAlumno *iterador=lista;
        while(iterador!=NULL){
          /*La funcion se va a encargar que todo siguiente alumno
            sea asignado al inicio de la lista hasta que no existan más alumnos*/
          nodoAlumno *posicionador;
          posicionador = malloc( sizeof( nodoAlumno ));
          posicionador -> boleta = iterador->boleta;
          posicionador -> sigAlumno = aLista -> start;
          aLista -> start = posicionador;
          iterador=iterador->sigAlumno;
        }
    }
  //Imprimir Lista
    void imprimirLista ( Lista *aLista ){
      nodoAlumno *posicionador = aLista -> start;
      while( posicionador != NULL ){
        printf("%d\n", posicionador -> boleta);
        posicionador = posicionador -> sigAlumno;
      }
    }
  //ImprimirLista cuando tenemos un IterardorNodoALumno
    void ImprimirLista2(nodoAlumno*posicionador){
      nodoAlumno*iterador=posicionador;
      while(iterador!=NULL){
        printf("%d\n", iterador -> boleta);
        iterador = iterador -> sigAlumno;
      }
    }
  //Eliminar toda la lista
    void EliminarListaCompleta( Lista *aLista ){
      /*Debemos usar un for para eliminar nodo por nodo y liberar memoria*/
      if( aLista -> start != NULL ){
        nodoAlumno *posicionador = aLista -> start;
        aLista -> start = aLista -> start -> sigAlumno;
        free(posicionador);
      }
    }
  //Eliminar toda la lista ALUMNO
    void EliminarListaCompletaA( nodoAlumno **lista ){
      if( (*lista) -> sigAlumno != NULL ){
        nodoAlumno *posicionador = (*lista) -> sigAlumno;
        (*lista) -> sigAlumno = (*lista) -> sigAlumno -> sigAlumno;
        free(posicionador);
      }
    }
  //Buscar Elemento
  int buscarElemento(nodoAlumno*lista1,int num_boleta){
    /*Esta funcion buscara que el elemento seleccionado exista
      lo usaremos en la función sublista*/
    nodoAlumno*iterador=lista1;
    int val=-1;
    while(iterador!=NULL){
      if(iterador->boleta==num_boleta){
      val=1;
      break;
    }
    iterador=iterador->sigAlumno;
    }
    return val;
  }
  //InsertarElemento
  void insertarElemento(nodoAlumno** lista1,int numBoleta){
    /*Esta función nos sirve para insertar un elemento después de haberlo buscado
      Como se mostrará en la función subLista*/
    (*lista1)= malloc( sizeof( nodoAlumno ));
    (*lista1)-> boleta = numBoleta;
    (*lista1)-> sigAlumno = NULL;
  }
  //Crear una Sublista
  nodoAlumno* subLista(nodoAlumno*lista1,nodoAlumno*lista2){
    nodoAlumno*iterador=lista1;
    int numBoleta,val;
    puts("Estos son los elementos de la Lista:");
    ImprimirLista2(iterador);
    puts("Elije los elmentos de la sublista");
    scanf("%d",&numBoleta);
    setbuf(stdin,NULL);
    if(buscarElemento(lista1,numBoleta)==1){
      insertarElemento(&lista2,numBoleta);
    }else{
      puts("La boleta no se encuentra en la Lista");
    }
    nodoAlumno* iterador2=lista2;
    puts("Deseas agregar otra boleta?, presione 1 para si");
    scanf("%d",&val);
    setbuf(stdin,NULL);
    while(val==1){
      puts("Escriba la boleta");
      scanf("%d",&numBoleta);
      if(buscarElemento(lista1,numBoleta)==1){
        insertarElemento(&(iterador2->sigAlumno),numBoleta);
      }else{
        puts("La boleta no se encuentra en la Lista");
      }
      puts("Deseas agregar otra boleta?, presione 1 para si");
      scanf("%d",&val);
      setbuf(stdin,NULL);
    }
    return lista2;
  }

int main(){
  int opcion,val,x;
  /*En este main lo principal es el menú de opciones para que el usuario
    nos indique que operacion quiere realizar y así nosotros poder llamar
    a las funciones anteriormente desarrolladas*/
  do{
    puts("Escriba la opcion que desea realizar:");
    puts("1° Concatenar dos listas");
    puts("2° Invertir lista");
    puts("3° Intercalar nodos de 2 listas");
    puts("4° Comparar listas");
    puts("5° Generar subLista");
    scanf("%d",&opcion);
    setbuf(stdin,NULL);
    /*El menu se realizó con un IF ANIDADO*/
    if(opcion==1){
      int orden;
      puts("Escriba la primera lista");
      nodoAlumno* lista1=InsertarAlFinal();
      puts("Escriba la segunda lista");
      nodoAlumno* lista2=InsertarAlFinal();
      puts("Escriba el orden de la concatenacion 1 para la lista1 y 2 para la lista2");
      scanf("%d",&orden);
      setbuf(stdin,NULL);
      nodoAlumno* lista_concatenada=concatenar(lista1,lista2,orden);
      puts("La lista concatenada es:");
      ImprimirLista2(lista_concatenada);
    }else{
      if(opcion==2){
        Lista MiLista;
        InicializarLista( &MiLista );
        puts("Escriba la lista");
        nodoAlumno* lista=InsertarAlFinal();
        invertirLista(lista,&MiLista);
        puts("La lista invertida es:");
        imprimirLista(&MiLista);
        
      }else{
        if(opcion==3){
          puts("Escriba la primera lista");
          nodoAlumno* lista1=InsertarAlFinal();
          puts("Escriba la segunda lista");
          nodoAlumno* lista2=InsertarAlFinal();
          nodoAlumno* lista3=intercalarNodos(lista1,lista2);
          puts("La lista resultante es:");
          EliminarListaCompletaA(&lista1);
          EliminarListaCompletaA(&lista2);
          ImprimirLista2(lista3);
  
        }else{
          if(opcion==4){
            puts("Escriba la primera lista");
            nodoAlumno* lista1=InsertarAlFinal();
            puts("Escriba la segunda lista");
            nodoAlumno* lista2=InsertarAlFinal();
            int comparacion=compararListas(lista1,lista2);
            if(comparacion==1){
              puts("Las listas son iguales");
            }else{
              puts("Las listas no son iguales");
            }
          }else{
            if(opcion==5){
              puts("Escriba la primera lista");
              nodoAlumno* lista1=InsertarAlFinal();
              nodoAlumno* lista2=NULL;
              lista2=subLista(lista1,lista2);
              puts("La sublista generada es:");
              ImprimirLista2(lista2);
            }else{
              printf("%s\n", "Opcion no valida");
            }
          }
        }
      }
    }
    puts("¿Desea realizar otra operacion? Presione 1 para si");
    scanf("%d",&val);
    setbuf(stdin,NULL);
  }while(val==1);
}