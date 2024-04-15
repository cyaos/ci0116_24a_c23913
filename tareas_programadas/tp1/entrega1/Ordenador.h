#ifndef Ordenador_h
#define Ordenador_h

#include <stdio.h>
#include <iostream>
#include <string>

class Ordenador{
	private:
    // Defina aqui los metodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos metodos quiera.
	
	public:
	Ordenador(){};
	~Ordenador(){};
	// Si piensa no implementar algunos de los metodos de ordenamiento, no los borre,
	// simplemente dejelos con el cuerpo vacio para evitar errores de compilacion, ya
	// que se va a ejecutar el mismo main para todas las tareas.
    // Implemente los algoritmos en este archivo  (no en un CPP aparte).
	void seleccion(int *A, int n){
		int menor;
		for (int i = 0; i < n-1; i++){
			menor = i;
			for (int j = i+1; j < n; j++){
				if (A[j] < A[menor]){
					menor = j;
				}
			}
			int aux = A[i];
			A[i] = A[menor];
			A[menor] = aux;
		}
	}

	void insercion(int *A, int n){
		int i, j, key;

		for (i = 1; i < n; i++){
			key = A[i];
			j = i - 1;
			while (j >= 0 && A[j] > key){
				A[j+1] = A[j];
				j = j - 1;
			}
			A[j + 1] = key;
		}
	}

	std::string ImprimirDatosDeTarea(){
		return "C23913 Tarea 1 Etapa 1";
	}

	void mergesort(int *A, int n);
	void heapsort(int *A, int n);
	void quicksort(int *A, int n);
	void radixsort(int *A, int n);
};



#endif
