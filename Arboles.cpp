#include<iostream>
using namespace std;
struct arbol {
	int dato;
	arbol* izquierdo;
	arbol* derecho;
};
arbol* crearNodo(int);
void insertar(arbol*&, int);
void mostrar(arbol*);
void buscar(arbol*);
void preorden(arbol*);
void inorden(arbol*);
void postorden(arbol*);
void eliminar(arbol*);


arbol* nuevoarbol = NULL;

int main() {

	int opcion;
	menu:
	cout << "----------------------------MENU-----------------------------";
	cout << "1. Insertar nodo en arbol";
	cout << "2. Mostrar arbol completo";
	cout << "3. Buscar un elemento en el arbol";
	cout << "4. Mostrar datos del arbol en preorden";
	cout << "5. Mostrar datos del arbol en inorden";
	cout << "6. Mostrar datos del arbol en postorden";
	cout << "7. Eliminar un nodo del arbol";
	cout << "8. Salir";
	cout << "Elija una opcion: ";
	cin >> opcion;

	switch (opcion) {
	case 1:
		int numero;
		cout << "Digite un numero entero";
		cin >> numero;
		insertar(nuevoarbol, numero);
	case 2:
		mostrar();
	case 3:
		buscar();
	case 4:
		preorden();
	case 5:
		inorden();
	case 6:
		postorden();
	case 7:
		eliminar();
	case 8:
		break;
	default:
		cout << "La opcion no existe, elija otra opcion.";
		goto menu;

	}




}


//Funciones
//Crear nodos
arbol* crearNodo(int n, arbol* npadre) {
	arbol* nuevo_nodo = new arbol;

	nuevo_nodo->dato = n;
	nuevo_nodo->derecho = NULL;
	nuevo_nodo->izquierdo = NULL;

	return nuevo_nodo;
	


}


//Insertar nodos al arbol
void insertar(arbol*& arbolf, int n) {
	
	if (arbolf == nullptr) {
		arbol* nuevo_nodo = crearNodo(n);
		arbolf = nuevo_nodo;
	}
	else {
		int valorRaiz = arbolf->dato;
		if (n < valorRaiz) {
			insertar(arbolf->izquierdo, n);
		}
		else {
			insertar(arbolf->derecho, n);
		}
	}
	



}




