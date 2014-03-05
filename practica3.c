#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno{
	int boleta;
	struct Alumno *sigAlumno;
}nodoAlumno;

typedef struct Lista{
	struct Alumno *start;
}Lista;

void InicializarLista( Lista *aLista ){
      aLista -> start = NULL;
    }
	
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

void imprimirLista ( Lista *aLista ){
      nodoAlumno *posicionador = aLista -> start;
      while( posicionador != NULL ){
        printf("%d\n", posicionador -> boleta);
        posicionador = posicionador -> sigAlumno;
      }
    }

void ImprimirLista2(nodoAlumno*posicionador){
		nodoAlumno*iterador=posicionador;
		while(iterador!=NULL){
		printf("%d\n", iterador -> boleta);
        iterador = iterador -> sigAlumno;
		}
	}

nodoAlumno* concatenar(nodoAlumno* lista1 , nodoAlumno*lista2, int orden){
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

void invertirLista(nodoAlumno*lista, Lista *aLista){
	nodoAlumno *iterador=lista;
	while(iterador!=NULL){
	nodoAlumno *posicionador;
      posicionador = malloc( sizeof( nodoAlumno ));
      posicionador -> boleta = iterador->boleta;
      posicionador -> sigAlumno = aLista -> start;
      aLista -> start = posicionador;
	  iterador=iterador->sigAlumno;
	}
	
}

int compararListas(nodoAlumno* lista1,nodoAlumno*lista2){
	int val=1;
	nodoAlumno* iterador1=lista1;
	nodoAlumno* iterador2=lista2;
	while(iterador1!=NULL && iterador2!=NULL){
		if(iterador1->boleta!=iterador2->boleta){
			val=0;
			break;
		}
		iterador1=iterador1->sigAlumno;
		iterador2=iterador2->sigAlumno;
	}
	if((iterador1!=NULL && iterador2==NULL)||(iterador1==NULL && iterador2!=NULL)){
		val=0;
	}
	return val;
}

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

int main(){
	int opcion,val;
	do{
		puts("Escriba la opcion que desea realizar:");
		puts("1° Concatenar dos listas");
		puts("2° Invertir lista");
		puts("3° Intercalar nodos de 2 listas");
		puts("4° Comparar listas");
		puts("5° Generar subLista");
		scanf("%d",&opcion);
		setbuf(stdin,NULL);
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

						}else{
							puts("Opcion no valida");
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

