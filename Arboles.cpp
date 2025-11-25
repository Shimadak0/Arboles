#include<iostream>
using namespace std;
struct arbol {
	int dato;
	arbol* izquierdo;
	arbol* derecho;
};
arbol* crearNodo(int,arbol*);
void insertar(arbol*&, int);
void mostrar(arbol*, int);
bool buscar(arbol*, int);
void preorden(arbol*);
void inorden(arbol*);
void postorden(arbol*);
arbol* minimo(arbol*);
void eliminar(arbol*, int);


arbol* nuevoarbol = NULL;

int main() {

	int opcion, numero, contador=0;
	do {
		system("cls");
		cout << "----------------------------MENU-----------------------------" << endl;
		cout << "1. Insertar nodo en arbol" << endl;
		cout << "2. Mostrar arbol completo" << endl;
		cout << "3. Buscar un elemento en el arbol" << endl;
		cout << "4. Mostrar datos del arbol en preorden" << endl;
		cout << "5. Mostrar datos del arbol en inorden" << endl;
		cout << "6. Mostrar datos del arbol en postorden" << endl;
		cout << "7. Eliminar un nodo del arbol" << endl;
		cout << "8. Salir" << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			cout << "Digite un numero entero: ";
			cin >> numero;
			insertar(nuevoarbol, numero);
			break;
		case 2:
			cout << "Mostrando arbol completo. " << endl;
			mostrar(nuevoarbol, contador);
			system("PAUSE");
			break;
		case 3:
			cout << "Digita el numero a buscar";
			cin >> numero;
			buscar(nuevoarbol, numero);
			if (buscar(nuevoarbol, numero) == true) {
				cout << "El valor " << numero << " ha sido encontrado";
			}
			else {
				cout << "El valor " << numero << "no se encontro en el arbol";

			}
			cout << endl;
			system("PAUSE");
			break;
		case 4:
			cout << "Mostrando datos del arbol en Preorden: ";
			cout << endl;
			cout << "el listado en preorden es: ";
			preorden(nuevoarbol);
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "Mostrando datos del arbol en Inorden: ";
			cout << endl;
			cout << "el listado en Inorden es: ";
			inorden(nuevoarbol);
			cout << endl;
			system("pause");
			break;
		case 6:
			cout << "Mostrando datos del arbol en Postorden: ";
			cout << endl;
			cout << "el listado en Postorden es: ";
			postorden(nuevoarbol);
			cout << endl;
			system("pause");
			break;
		case 7:
			cout << "Teclea el nodo a eliminar: ";
			cin >> numero;
			cout << "Eliminando nodo...";
			eliminar(nuevoarbol, numero);
		case 8:
			break;
		default:
			cout << "La opcion no existe, elija otra opcion.";
			system("pause");

		}

	} while (opcion != 8);


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
		arbol* nuevo_nodo = crearNodo(n, arbolf);
		arbolf = nuevo_nodo;
	}
	else {
		int valorRaiz = arbolf->dato;
		if (n == valorRaiz) {//Evita insertar duplicados
			return;
		}
		else if (n < valorRaiz) {
			insertar(arbolf->izquierdo, n);
		}
		else {
			insertar(arbolf->derecho, n);
		}
	}
}

void mostrar(arbol* arbol, int contador) {
	if (arbol == NULL) {
		return;
	}
	else {
		mostrar(arbol->derecho, contador + 1);
		for (int i = 0; i < contador; i++) {
			cout << "     ";
			}
		cout << arbol->dato << endl;
		mostrar(arbol->izquierdo, contador + 1);
	}

}

bool buscar(arbol* arbol, int n){
	if (arbol == nullptr) {
		return false;
	}
	else if(arbol->dato == n) {
		return true; //El valor se encuentra en la raiz del arbol
	}
	else if (n < arbol->dato) {
		return buscar(arbol->izquierdo, n); //Busca el nodo por el lado izquierdo
	}
	else {
		return buscar(arbol->derecho, n); //Busca el nodo por el lado derecho
	}

}

void preorden(arbol* arbol) {
	if (arbol == nullptr) {
		return;
	}
	else {
		cout << arbol->dato << " - ";
		preorden(arbol->izquierdo);
		preorden(arbol->derecho);
	}
}

void inorden(arbol* arbol) {
	if (arbol == nullptr) {
		return;
	}
	else {
		preorden(arbol->izquierdo);
		cout << arbol->dato << " - ";
		preorden(arbol->derecho);
	}
}

void postorden(arbol* arbol) {
	if (arbol == nullptr) {
		return;
	}
	else {
		preorden(arbol->izquierdo);		
		preorden(arbol->derecho);
		cout << arbol->dato << " - ";
	}
}

void eliminar(arbol* arbolel, int dato) {
	if (arbolel == nullptr) {
		return;
	}
	if (dato < arbolel->dato) { //buscar lado izquierdo
		eliminar(arbolel->izquierdo, dato);
	}
	else if (dato > arbolel->dato) {//buscar derecha
		eliminar(arbolel->derecho, dato);
	}
	else {//Se encuentra el dato

		//Cuando es nodo hoja
		if (arbolel->izquierdo == nullptr && arbolel->derecho == nullptr) {
			delete arbolel;
			arbolel = nullptr;
		}
		//Cuando es nodo con una sola hoja
		else if (arbolel->izquierdo == nullptr) {
			arbol* temp = arbolel;
			arbolel = arbolel->derecho;
			delete temp;
		}
		else if (arbolel->derecho == nullptr) {
			arbol* temp = arbolel;
			arbolel = arbolel->izquierdo;
			delete temp;
		}
		else {
			arbol* sucesor = minimo(arbolel->derecho);
			arbolel->dato = sucesor->dato;
			eliminar(arbolel->derecho, sucesor->dato);
		}
	}
}

//sacar el minimo
arbol* minimo(arbol* arbolM) {
	if (arbolM == nullptr) {
		return nullptr;
	}
	while (arbolM->izquierdo != nullptr) {
		arbolM = arbolM->izquierdo;
		
	}
	return arbolM;
}