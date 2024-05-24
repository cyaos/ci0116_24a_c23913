//
//  bstree.h
//

#ifndef bstree_h
#define bstree_h

#include <iostream>

// Nodos del árbol:
template <typename T>
class bstnode
{
private:
    /// Llave del nodo actual
    T key;
    /// Punteros al padre, hijo izquierdo e hijo derecho
    bstnode<T> *p, *left, *right;

public:
    /// @brief Constructor por omisión
    bstnode() {
    };
    
    /// @brief Inicialización de datos miembro
    /// @param k llave del nodo actual
    /// @param w puntero al nodo padre
    /// @param y puntero al nodo hijo izquierdo
    /// @param z puntero al nodo hijo derecho
    bstnode(const T& k, bstnode<T> *w = nullptr, bstnode<T> *y = nullptr, bstnode<T> *z = nullptr):key(k), p(w), left(y), right(z) {};
    
    /// @brief Destructor
    ~bstnode() {
    };
};

// Árbol de búsqueda binario:
template <typename T>
class bstree
{
private:
    /// Raíz del árbol
    bstnode<T> *root;

public:

    /// @brief Constructor
    /// @details Crea un árbol vacío
    bstree() {
    };
    
    /// @brief Destructor
    /// @details Borra el árbol
    ~bstree() {
    };
    
    /// @brief Inserta el nodo z en la posición que le corresponde en el árbol.
    /// @param z nodo a insertar al árbol
    void Insert(bstnode<T>* z) {
    };
    
    /// @brief Recorre en orden el subárbol con raíz x, imprimiendo
    /// la llave de cada nodo en en una nueva línea de la salida
    /// estándar después de recorrido el subárbol izquierdo y
    /// antes de recorrer el subárbol derecho.
    /// @param x nodo raíz del subárbol
    void InorderWalk(bstnode<T> *x) {
    };
    
    /// @brief Busca la llave k recursivamente en el subárbol con raíz x.
    /// @param x la raíz del subárbol por recorrer
    /// @param k la llave por buscar
    /// @return Si la encuentra devuelve un apuntador al nodo que la contiene,
    /// sino devuelve nullptr.
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
    };
    
    /// @brief Busca la llave k iterativamente en el subarbol con raíz x.
    /// @param x la raíz del subárbol por recorrer
    /// @param k la llave por buscar
    /// @return si la encuentra devuelve un apuntador al nodo que la contiene,
    /// sino devuelve nullptr.
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
    };
    
    /// @brief Busca el nodo que tiene la llave menor
    /// @param x nodo raíz del subárbol por recorrer
    /// @return devuelve el nodo con la llave menor
    /// si el árbol está vacío, devuelve nullptr.
    bstnode<T>* Minimum(bstnode<T> *x) {
    };
    
    /// @brief Busca el nodo que tiene la llave mayor
    /// @param x nodo raíz del subárbol por recorrer
    /// @return retorna el nodo mayor y si el árbol esta vacío devuelve nullptr.
    bstnode<T>* Maximum(bstnode<T> *x) {
    };
    
    /// @brief Busca el nodo que le sigue al nodo x
    /// @param x el nodo al cual se le buscara el sucesor 
    /// @return el nodo cuya llave es la que le sigue a la del nodo x.
    /// Si no existe el nodo, devuelve nullptr.
    bstnode<T>* Successor(bstnode<T> *x) {
    };
    
    /// @brief Saca del árbol la llave contenida en el nodo apuntado por z.
    /// @param z el nodo por eliminar
    void Delete(bstnode<T>* z) {
    };  
};

#endif /* bstree_h */

