#ifndef Ordenador_h
#define Ordenador_h

#include <stdio.h>
#include <iostream>
#include <string>

class Ordenador{
	private:
    // Defina aqui los metodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos metodos quiera.

	void ord_intercalacion(int * A, int * tmp, int izq, int der){
		if (izq < der){
      		int centro = (izq + der) / 2;
      		ord_intercalacion (A, tmp, izq, centro);
      		ord_intercalacion (A, tmp, centro + 1, der);
			intercalar (A, tmp, izq, centro + 1, der);
		}
	}

	void intercalar (int * A, int * tmp, int izq, int centro, int der){
		int ap = izq, bp = centro, cp = izq; 
  		while ((ap < centro) && (bp <= der)){
      		if (A[ap] <= A[bp]){
   				tmp[cp] = A[ap];
   				ap++;
			} else {
   				tmp[cp] = A[bp];
   				bp++;
			}
			cp++;
		}
  		while (ap < centro){
      		tmp[cp] = A[ap];
      		cp++;
      		ap++;
		}
  		while (bp <= der){
      		tmp[cp] = A[bp];
      		cp++;
      		bp++;
		}
        for (ap = izq; ap <= der; ap++){
           A[ap] = tmp[ap];
		}
	}
    
    void max_heapify(int *A, int n, int i){
		int largest = i; 
    	int left = 2 * i + 1; 
    	int right = 2 * i + 2; 

		if (left < n && A[left] > A[largest])
			largest = left;

		if (right < n && A[right] > A[largest])
			largest = right;

		if (largest != i) {
			std::swap(A[i], A[largest]); 
			max_heapify(A, n, largest); 
		}
	}

	void buildMaxHeap(int *A, int n) {
		for (int i = n / 2 - 1; i >= 0; i--) {
		    max_heapify(A, n, i);
		}
  	}

    void quicksortAux(int *A, int p, int r) {
		if (p < r) {
		int q = partition(A, p, r); 
		quicksortAux(A, p, q - 1);
		quicksortAux(A, q + 1, r); 
		}
  	}

	int partition(int *A, int p, int r) {
		int x = A[r]; 
		int i = p - 1;

		for (int j = p; j < r; j++) {
            if (A[j] <= x) {
                i++;
                std::swap(A[i], A[j]);
            }
		}
		std::swap(A[i + 1], A[r]); 
		return i + 1; 
	}
	
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

	void mergesort(int *A, int n){
		int *tmp = new int[n]; 
  		ord_intercalacion (A, tmp, 0, n - 1);
	}

	std::string ImprimirDatosDeTarea(){
		return "C23913 Tarea 1 Etapa 1";
	}

	void heapsort(int *A, int n){
    	buildMaxHeap(A, n);
    	for (int i = n - 1; i >= 0; i--) {
        	std::swap(A[0], A[i]);
            max_heapify(A, i, 0);
    	}    
	}

	void quicksort(int *A, int n){
        quicksortAux(A, 0, n - 1);
	}

	void radixsort(int *A, int n){
	}
};




#endif

