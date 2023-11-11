#include <iostream>
#include <conio.h>
#include <malloc.h>

using namespace std;

struct contenedor{
	
	int codigo, prioridad;
	contenedor *izq, *der;
	
	};
	
contenedor *raiz, *nuevo , *aux1;

void menu();
int posicionar(contenedor *);
int insertar();
int recorre(contenedor *);
int mostrarPriorida(contenedor *);
int preorden(contenedor *);
contenedor *busca(contenedor *, int);
int eliminar();
int sinhijos();
int conhijo();
int buspadre(contenedor *);

int main(){
	
	menu();
	
	getch();
	return 0;
	}
	
void menu(){
	
	int op=0;
	
	do{
		
		cout<<"--------Menu----------"<<endl
		<<"1.Regitrar contenedor"<<endl
		<<"2.mostrar contenedo po orden"<<endl
		<<"3.mostrar por  prioridades"<<endl
		<<"4.eliminar contenedor"<<endl
		<<"5.salir"<<endl<<endl
		<<"opcion: ";
		cin>>op;
		switch(op){
			case 1: insertar(); break;
			case 2:recorre(raiz); break;
			case 3: mostrarPriorida(raiz);break;
			case 4: eliminar();break;
			case 5: break;
			default: break;
			}
		}while(op != 5);
	}

int posicionar(contenedor *tempo){
			if(nuevo->prioridad <= tempo->prioridad){
				if(tempo->izq != NULL){
				posicionar(tempo->izq);
				}
				else{
					nuevo->prioridad = tempo->prioridad - 1;
					tempo->izq = nuevo;
					nuevo = NULL;
					free(nuevo);
					}
			}
			else if(nuevo->prioridad >= tempo->prioridad){
				if(tempo->der != NULL){
					posicionar(tempo->der);
					}
					else{
						nuevo->prioridad = tempo->prioridad + 1;
						tempo->der = nuevo;
						nuevo = NULL;
						free(nuevo);
						}
				}
				
				return 0;
		}
		
int insertar(){
		nuevo = (struct contenedor * )malloc(sizeof(struct contenedor));
		nuevo->izq = nuevo->der= NULL;
		cout<<"Ingrese el codigo del contenedor: ";
		cin>>nuevo->codigo;
		cout<< "Dentro del rango del 1 al 100 ingrese la prioridad: ";
		cin>>nuevo->prioridad;
		
		if(!raiz){
			raiz = nuevo;
			nuevo = NULL;
			free(nuevo);
			}
			else{
				posicionar(raiz);
				}
				
			return 0;
		}
		
int recorre(contenedor *itera){
			cout<<"Codigo del contendor: "<<itera->codigo<<endl;
			cout<<"prioridad: "<<itera->prioridad<<endl;
			cout<<"--------------------------------"<<endl;
			if(itera->izq != NULL){
				recorre(itera->izq);
				}
			if(itera->der != NULL){
				recorre(itera->der);
				}
				
				return 0;
			}
			
/*int preorden(contenedor *orden){
				cout<<"Codigo del contendor: "<<orden->codigo<<endl;
				cout<<"prioridad: "<<orden->prioridad<<endl;
				cout<<"--------------------------------"<<endl;
				if(orden->izq != NULL){
					preorden(orden->izq);
					}
					else if(orden->der != NULL){
						preorden(orden->der);
						}
						
				return 0;
			}*/
			
int mostrarPriorida(contenedor *aux2){
			
			if(aux2 != NULL){
				recorre(aux2->der);
				cout<<"Codigo del contendor: "<<aux2->codigo<<endl;
				cout<<"prioridad: "<<aux2->prioridad<<endl;
				cout<<"--------------------------------"<<endl;
				recorre(aux2->izq);
				}
				
				return 0;
	}
contenedor *busca(contenedor *aux2, int encontrado){
	if(aux2->codigo == encontrado){
		nuevo = aux2;
		return 0;
		}else{
		if(aux2->izq != NULL){
			busca(aux2->izq, encontrado);
			}
		if(aux2->der != NULL){
			busca(aux2->der, encontrado);
			}
		}
		aux2 = NULL;
		return aux2;
}

int buspadre(contenedor *itera){
	
	if((itera->izq != NULL) && (itera->izq != nuevo)){
		buspadre(itera->izq);
		}
	if(itera->izq == nuevo){
		aux1 = itera; 
		}
	if((itera->der != NULL) && (itera->der != nuevo)){
		buspadre(itera->der);
		}
	if(itera->der == nuevo){
		aux1 = itera; 
		}
				
		return 0;
	}

int sinhijos(){
	if(nuevo != raiz){
		buspadre(raiz);
	}
	if(aux1->izq == nuevo){
		aux1->izq = NULL; 
		}
		else if(aux1->der == nuevo){
		aux1->der = NULL; 
		}
	}

int conhijo(){
	if(nuevo != raiz){
		buspadre(raiz);
	}
	if(aux1->izq == nuevo){
		if(nuevo->izq != NULL){
			aux1->izq = nuevo->izq;
			}
			else if(nuevo->der != NULL){
				aux1->izq = nuevo->der; 
				}
		}
		else if(aux1->der == nuevo){
		if(nuevo->izq != NULL){
			aux1->der = nuevo->izq;
			}
			else if(nuevo->der != NULL){
				aux1->der = nuevo->der; 
				}
		}
	}
	
int eliminar(){
	
	int buscar = 0;
	
	cout<<"Ingrese el codigo del contenedor: ";
	cin>>buscar;
	
	busca(nuevo,buscar);
	if((nuevo->der == NULL) && (nuevo->izq == NULL) ){
			sinhijos();
			}
			else if( ((nuevo->der == NULL) && (nuevo->izq != NULL)) || ((nuevo->der == NULL) && (nuevo->izq != NULL)) ){
				conhijo();
				}
			
			
			return 0;
	
	}		