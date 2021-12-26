#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;
struct nodo {
	int num;
	nodo *sig;
	nodo *ant;
};

//funciones

void funinsertarNodoLD(int numero,nodo *&pcab,nodo *&pfin);
void funmostrarLista(nodo *pcab);
void operaciones(int &op,nodo *&pcab,nodo *&pfin);
void insertarAntes(nodo *&pcab);
nodo *buscarlista(int datobuscar,nodo *pcab);
int menu();

int main(){
	nodo *pcab=NULL;
	nodo *pfin=NULL;
	int respuesta,op;
	int numero;
	do{
		
		op=menu();
		operaciones(op,pcab,pfin);
		
		cout<<"desea registrar realizar otra operacion si(1) no(otro valor):";
		cin>>respuesta;
			
	}while(respuesta==1);

  getch();
  return 0;
}

void funinsertarNodoLD(int numero,nodo *&pcab,nodo *&pfin){
	nodo *nuevonodo;
	nuevonodo=new(nodo);
	nuevonodo->num=numero;
	nuevonodo->sig=NULL;
	nuevonodo->ant=NULL;
	if(pcab==NULL)
	{
		pcab=nuevonodo;
		pfin=nuevonodo;
	}else
	{
		nuevonodo->ant=pfin;
		pfin->sig=nuevonodo;
		pfin=nuevonodo;
	}
}
void funmostrarLista(nodo *pcab)
{
	nodo *nodoactual=pcab;
	while(nodoactual!=NULL)
	{
		cout<<"ANTERIOR:"<<nodoactual->ant<<endl;
		//cout<<"actual:"<<nodoactual<<endl;
		cout<<"dato :"<<nodoactual->num<<" dir actual:/"<<nodoactual <<endl;
		cout<<"SIGUIENTE:"<<nodoactual->sig<<endl;
		cout<<endl;
		nodoactual=nodoactual->sig;
	}
}

int menu()
{
	int respuesta;
	system("cls");
	cout<<"MENU DE OPCIONES"<<endl;
	cout<<"1.insertar"<<endl;
	cout<<"2.listar"<<endl;
	cout<<"3.insertar ANTES del elemento dado"<<endl;
	cout<<"4.insertar DESPUES del elemento dado"<<endl;
	cout<<"5.eliminar un nodo"<<endl;
	cout<<"ingrese su respuesta:";cin>>respuesta;
	return respuesta;
}

void operaciones(int &op,nodo *&pcab,nodo *&pfin){
	int numero,respuesta;
	switch (op){
		case 1:
			do{
				cout<<"ingrese un numero:";
				cin>>numero;
				funinsertarNodoLD(numero,pcab,pfin);
				cout<<"desea ingresar otro numero si(1) no(otro valor):";
				cin>>respuesta;	
			}while(respuesta==1);
			break;
		case 2:
				cout<<"LISTA DE NODOS REGISTRADOS"<<endl;
			funmostrarLista(pcab);
		
			break;
		case 3:
			
				insertarAntes(pcab);
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
	}
}


void insertarAntes(nodo *&pcab){
	int datobuscar,ndato;
    cout<<"ingrese el dato a buscar :";
    cin>>datobuscar;
    cout<<"ingrese el dato a insertar :";
    cin>>ndato;
    nodo *nodoa=NULL;
    
    nodo *nuevonodo;
    nodo *aux=buscarlista(datobuscar,pcab);
    if(aux==NULL){
        cout<<"El dato ingresado no existe"<<endl;
    }else{
        if(aux->num==datobuscar){
            //se inserta antes de la cabecera
                nuevonodo=new(nodo);
                nuevonodo->num=ndato;
                nuevonodo->sig=aux;
                pcab=nuevonodo;
        }else{
            //insertar 
                nuevonodo=new(nodo);
                nuevonodo->num=ndato;
                nuevonodo->sig=aux->sig;
                aux->sig=nuevonodo;           
        }
    }	
}

nodo *buscarlista(int datobuscar,nodo *pcab){
	nodo *nodoActual=pcab;
	nodo *direccion=NULL;
	if(nodoActual!=NULL)
	{
		if((nodoActual->sig==NULL) && (nodoActual->num==datobuscar)){
			direccion=nodoActual;
		}else{
			if(nodoActual->num==datobuscar){
				direccion=nodoActual;
			}else{
				while(nodoActual->sig!=NULL)
				{
					if(nodoActual->sig->num==datobuscar)
					{
						direccion=nodoActual;break;
					}
					nodoActual=nodoActual->sig;
				}
			}
		}
		
	}else{
		direccion=NULL;
	}
    return direccion;
}
