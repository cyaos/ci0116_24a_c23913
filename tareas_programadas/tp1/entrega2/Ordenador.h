#ifndef Ordenador_h
#define Ordenador_h

#include <stdio.h>
#include <iostream>
#include <string>

class Ordenador{
	private:

	/**
	 * @brief Ordena un arreglo de enteros utilizando el algoritmo de ordenación por intercalación.
	 * 
	 * @param A el arreglo de enteros a ordenar.
	 * @param tmp un arreglo temporal para almacenar los elementos intercalados durante el proceso de ordenación.
	 * @param izq el índice izquierdo del subarreglo a ordenar.
	 * @param der el índice derecho del subarreglo a ordenar.
	 */
	void ord_intercalacion(int * A, int * tmp, int izq, int der){
		if (izq < der){
			// Calcular el índice central del subarreglo.
      		int centro = (izq + der) / 2;
			// Ordenar los subarreglos izquiero y derecho de manera recursiva.
      		ord_intercalacion (A, tmp, izq, centro);
      		ord_intercalacion (A, tmp, centro + 1, der);
			// Intercalar los subarreglos ordenados.
			intercalar (A, tmp, izq, centro + 1, der);
		}
	}

	/**
	 * @brief Intercala dos subarreglos ordenados en uno solo.
	 * 
	 * @param A el arreglo de enteros donde se encuentran los subarreglos a intercalar.
	 * @param tmp un arreglo temporal para almacenar los elementos intercalados.
	 * @param izq el índice izquierdo del primer subarreglo.
	 * @param centro el índice izquierdo del segundo subarreglo.
	 * @param der el índice derecho del segundo subarreglo.
	 */
	void intercalar (int * A, int * tmp, int izq, int centro, int der){
		int ap = izq, bp = centro, cp = izq; 
		// Comparación de los elementos de los subarreglos y se coloca el menor en el arreglo temporal.
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
		// Colocar los elementos restantes del primer arreglo en el arreglo temporal.
  		while (ap < centro){
      		tmp[cp] = A[ap];
      		cp++;
      		ap++;
		}
		// Colocar los elementos restantes del segundo arreglo en el arreglo temporal.
  		while (bp <= der){
      		tmp[cp] = A[bp];
      		cp++;
      		bp++;
		}
		// Copiar los elementos del arreglo temporal de vuelta al arreglo original.
        for (ap = izq; ap <= der; ap++){
           A[ap] = tmp[ap];
		}
	}
    /**
	 * @brief Mantiene la propiedad de un heap máximo en un subárbol dado.
	 * 
	 * @param A el arreglo que representa el heap.
	 * @param n el tamaño del subárbol.
	 * @param i el índice del nodo raíz del subárbol.
	 */
    void max_heapify(int *A, int n, int i){
		int largest = i; 
    	int left = 2 * i + 1; 
    	int right = 2 * i + 2; 

		// Comprobar si el hijo izquierdo es mayor que el nodo actual.
		if (left < n && A[left] > A[largest])
			largest = left;

		// Comprobar si el arreglo derecho es mayor que el nodo actual o el hijo izquierdo.
		if (right < n && A[right] > A[largest])
			largest = right;
		
		// Si el mayor no es el nodo actua;, intercambiar y seguir ajustando.
		if (largest != i) {
			std::swap(A[i], A[largest]); 
			max_heapify(A, n, largest); 
		}
	}

	/**
	 * @brief Construye un heap máximo a partir de un arreglo dado.
	 * 
	 * @param A el arreglo de enteros.
	 * @param n el tamaño del arreglo.
	 */
	void buildMaxHeap(int *A, int n) {
		// Comenzar desde el último nodo que tiene hijos.
		for (int i = n / 2 - 1; i >= 0; i--) {
			// Aplicar max_heapify en cada nodo para asegurar la propiedad del heap máximo.
		    max_heapify(A, n, i);
		}
  	}

	/**
	 * @brief Función auxiliar para ordenar un subarreglo de enteros utilizando el algoritmo de ordenamiento rápido.
	 * 
	 * @param A el arreglo de enteros a ordenar.
	 * @param p el índice del primer elemento del subarreglo.
	 * @param r el índice del último elemento del subarreglo.
	 */
    void quicksortAux(int *A, int p, int r) {
		if (p < r) {
			// Particionar el arreglo y obtener el indice del pivote.
			int q = partition(A, p, r); 
			// Ordenar de manera recursiva los subarreglos antes y después del pivote.
			quicksortAux(A, p, q - 1);
			quicksortAux(A, q + 1, r); 
		}
  	}
	/**
	 * @brief Particiona un subarreglo de enteros utilizando el último elemento como pivote.
	 * 
	 * @param A el arreglo de enteros a particionar.
	 * @param p el índice del primer elemento del subarreglo.
	 * @param r el índice del último elemento del subarreglo.
	 * @return el índice del pivote después de la partición.
	 */
	int partition(int *A, int p, int r) {
		// Seleccionar el último elemento como pivote
		int x = A[r]; 
		int i = p - 1;

		// Iteración del subarreglo, moviendo los elementos menores o iguales al pivote hacia la izquierda.
		for (int j = p; j < r; j++) {
            if (A[j] <= x) {
                i++;
                std::swap(A[i], A[j]);
            }
		}
		// Mover el pivote en su posición correcta del arreglo.
		std::swap(A[i + 1], A[r]); 
		// Devlover la posición del pivote.
		return i + 1; 
	}
	
	public:
	/**
	 * @brief Constructor del objeto ordenador.
	*/
	Ordenador(){};

	/**
	 * @brief Destructor del objeto ordenador.
	*/
	~Ordenador(){};

	/**
	 * @brief Ordena el arreglo proporcionado utilizando el algoritmo de ordenamiento selección.
	 * @param A puntero al arreglo por ordenar.
	 * @param n numero de datos en el arreglo.
	*/
	void seleccion(int *A, int n){
		int menor;
		// Iteración para definir el pivote.
		for (int i = 0; i < n-1; i++){
			menor = i;
			// Iteración por el subarreglo para encontrar el menor. 
			for (int j = i+1; j < n; j++){
				// Comparación entre A[j] y A[menor].
				if (A[j] < A[menor]){
					// Se guarda la posición del número más pequeño del subarreglo A[i:n] en la variable 'menor'.
					menor = j;
				}
			}
			// Intercambio de datos entre A[i] y A[menor].
			int aux = A[i];
			A[i] = A[menor];
			A[menor] = aux;
		}
	}

	/**
	 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento inserción.
	 * @param A puntero al arreglo por ordenar.
	 * @param n numero de datos en el arreglo.
	*/
	void insercion(int *A, int n){
		int i, j, key;
		// Iteración por el arreglo a partir del segundo elemento.
		for (i = 1; i < n; i++){
			// Selección del elemento clave.
			key = A[i];
			j = i - 1;
			// Mover los elementos mas grandes que el elemento clave hacia adelante.
			while (j >= 0 && A[j] > key){
				A[j+1] = A[j];
				j = j - 1;
			}
			// Colocar la clave en su posición correcta en el arreglo ordenado.
			A[j + 1] = key;
		}
	}

	/**
	 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento inserción.
	 * @details El método llama a otro método para comenzar el ordenamiento.
	 * @param A puntero al arreglo por ordenar.
	 * @param n numero de datos en el arreglo.
	*/
	void mergesort(int *A, int n){
		// Creación de un nuevo arreglo de tamaño n.
		int *tmp = new int[n]; 
  		ord_intercalacion (A, tmp, 0, n - 1);
	}

	/**
	 * @brief Imprime el carné estudiantíl y nombre de la tarea y etapa actual.
	*/
	std::string ImprimirDatosDeTarea(){
		return "C23913 Tarea 1 Etapa 2";
	}

	/**
	 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento montículos.
	 * @param A puntero al arreglo por ordenar.
	 * @param n numero de datos en el arreglo.
	*/
	void heapsort(int *A, int n){
		// Construye un heap max a partir del arreglo dado.
    	buildMaxHeap(A, n);
		// Iteración del arreglo desde el final hasta el principio.
    	for (int i = n - 1; i >= 0; i--) {
			// Intercambio del elemento A[0] (máximo) con el actual A[i].
        	std::swap(A[0], A[i]);
			// Restaurar el heap max en el arból reducido.
            max_heapify(A, i, 0);
    	}    
	}

	/**
	 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento rápido.
	 * @details Utiliza métodos auxiliares para ordenar el algoritmo
	 * @param A puntero al arreglo por ordenar.
	 * @param n numero de datos en el arreglo.
	*/
	void quicksort(int *A, int n){
        quicksortAux(A, 0, n - 1);
	}

	/**
	 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento residuos.
	 * @param A puntero al arreglo por ordenar.
	 * @param n numero de datos en el arreglo.
	*/
	void radixsort(int *A, int n){
		// Array temporal para guardar los datos ordenados.
        int tempArray[n];
		int* temp = tempArray;

		// El numero de bytes de un entero.
		const int numBytes = 4;

		// Iterar sobre cada byte del entero.
		for (int byteIndex = 0; byteIndex < numBytes; byteIndex++) {
			// Contador de ocurrencias de cada byte.
			size_t byteCount[256] = {};
			//Rango de inicio depende del índice del byte.
			size_t inicio = 0;
			if (byteIndex == 3) {
			inicio = 128;
			}

			// Contar la frecuancia de cada byte en el arreglo.
			for (int i = 0; i < n; i++) {
			int byteValue = (A[i] >> (8 * byteIndex)) & 0xFF;
			byteCount[byteValue]++;
			}

			// Calcular la posicion final de cada byte en el arreglo ordenado.
			for (int i = 1 + inicio; i < 256 + inicio; i++) {
			byteCount[i % 256] += byteCount[(i - 1) % 256];
			}

			// Ordenar los elementos en base al byte actual y almacenarlos en el arreglo temporal.
			for (int i = n - 1; i >= 0; i--) {
			int byteValue = (A[i] >> (8 * byteIndex)) & 0xFF;
			temp[--byteCount[byteValue]] = A[i];
			}

			// Intercambiar los punteros para mantener los resultados en el arreglo A.
			std::swap(A, temp);
		}
	}
};


#endif

