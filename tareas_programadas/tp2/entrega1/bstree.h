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
        this->root = nullptr;
    };
    
    /// @brief Destructor
    /// @details Borra el árbol
    ~bstree() {
        clearTree(root);
    };
    
    /// @brief Método recursivo para eliminar nodos del árbol
    /// @param x nodo raíz del subárbol por eliminar
    void clearTree(bstnode<T>* x){
        if (x) {
            // Recorre el subárbol izquierdo de x
            clearTree(x->left);
            // Recorrel el subárbol derecho de x
            clearTree(x->right);
            // Elimina el nodo x
            delete x;
        }
    }
    
    /// @brief Inserta el nodo z en la posición que le corresponde en el árbol.
    /// @param z nodo a insertar al árbol
    void Insert(bstnode<T>* z) {
        // Se inicializa x como la raīz del árbol para poder recorrerlo
        bstnode<T>* x = root;
        // Va a ser el puntero padre del nuevo nodo z
        bstnode<T>* y = nullptr;
        // Iteración a través del árbol hasta encontrar la posición 
        // correcta de z
        while (x != nullptr) {
            // Sigue el rastro del último nodo no nulo en x
            y = x;
            // Si la llave de z es mayor que la llave en el nodo actual,
            // se mueve x al hijo izquierdo
            if (z->key < x->key){
                x = x->left;
            // Si no, se mueve al lado derecho
            } else {
                x = x->right;
            }
        }
        // Se establece y como el padre de z
        z->p = y;
        // Si el árbol estaba vacío, y es nulo, z se vuelve en la nueva raíz
        if (y == nullptr) {
            root = z;
        // Si la llave de z es menor a la de y, se vuelve en su hijo izquierdo
        } else if (z->key < y->key) {
            y->left = z;
        // Si no, se vuelve en el hijo derecho
        } else {
            y->right = z;
        }
    };
    
    /// @brief Recorre en orden el subárbol con raíz x, imprimiendo
    /// la llave de cada nodo en en una nueva línea de la salida
    /// estándar después de recorrido el subárbol izquierdo y
    /// antes de recorrer el subárbol derecho.
    /// @param x nodo raíz del subárbol
    void InorderWalk(bstnode<T> *x) {
        // Si x actual no es nulo, seguir con el recorrido
        if (x != nullptr) {
            // Recorrer el subárbol izquierdo de manera recursiva
            InorderWalk(x->left);
            // Imprimir la clave del nodo actual
            std::cout << x->key << std::endl;
            // Recorrer el subárbol derecho de manera recursiva
            InorderWalk(x->right);
        }
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

    std::string ImprimirDatosDeTarea(){
        return "C23913 Tarea 2 Etapa 1";
    };
};

#endif /* bstree_h */

