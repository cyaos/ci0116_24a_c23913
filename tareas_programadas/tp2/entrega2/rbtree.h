//
//  rbtree.h
//

#ifndef rbtree_h
#define rbtree_h

#include <iostream>

enum colors {RED, BLACK};

// Nodos del árbol:
template <typename T>
class rbtnode
{
private:
    /// Clave del nodo
    T key;
    rbtnode<T> *p, *left, *right;
    /// Color del nodo
    enum colors color;
    
public:
    /// @brief Constructor por omisión.
    rbtnode() {
    };

    /// @brief Inicialización de datos miembro.
    /// @param k clave del nodo
    /// @param w padre del nodo
    /// @param y hijo izquierdo del nodo
    /// @param z hijo derecho del nodo
    /// @param c color del nodo
    rbtnode (const T& k, rbtnode<T> *w = nullptr, rbtnode<T> *y = nullptr, rbtnode<T> *z = nullptr, colors c = RED): key(k), p(w), left(y), right(z), color(c) {};
    
    /// @brief Destructor del nodo
    ~rbtnode() {
    };

    /// @brief Colocar el padre del nodo
    /// @param y nodo padre por ingresar
    void setPadre(rbtnode<T>* w) {
        this->p = w;
    };

    /// @brief Conseguir el padre del nodo
    /// @return el padre del nodo
    rbtnode<T>* getPadre(){
        return this->p;
    }

    /// @brief Colocar nodo hijo izquierdo
    /// @param y nodo izquierdo por ingresar
    void setLeft(rbtnode<T>* y) {
        this->left = y;
    };

    /// @brief Conseguir el nodo del hijo izquierdo
    /// @return hijo izquierdo del nodo
    rbtnode<T>* getLeft() {
        return this->left;
    }

    /// @brief Colocar nodo hijo derecho
    /// @param z nodo derecho por ingresar
    void setRight(rbtnode<T>* z) {
        this->right = z;
    }

    /// @brief Conseguir el nodo del hijo derecho
    /// @return hijo derecha del nodo
    rbtnode<T>* getRight() {
        return this->right;
    }

    /// @brief Colocar el color del nodo
    /// @param c el color por ingresar
    void setColor(colors c){
        this->color = c;
    }

    /// @brief Conseguir el color del nodo
    /// @return el color del nodo
    colors getColor(){
        return this->color;
    }
};

// Arbol rojinegro:
template <typename T>
class rbtree {
public:
    rbtnode<T> *root;    // raíz del árbol
    rbtnode<T> *nil;     // nodo nil (hoja) del árbol
    
    /// @brief Constructor del árbol rojinegro
    /// @details crea un árbol vacío.
    rbtree() {
        // Inicializa el nodo nil y lo vuelve negro
        this->nil = new rbtnode<T>();
        nil->setColor(BLACK);
        // El nodo nil se vuelve la raíz
        this->root = this->nil;
    };

    /// @brief Destructor del àrbol rojinegro
    /// @details vacía el árbol
    ~rbtree() {
        // Se llama una función que libera memoria de manera recursiva
        destroyTree(root);
        // Se libera la memoria del nodo nulo
        delete nil;
    };

    /// @brief Destructor del árbol recursivo
    /// @param n nodo actual
    void destroyTree(rbtnode<T>* n){
        if (node != nil) {
            // Llama recursivamente los nodos izquierdos 
            destroyTree(node->left);
            // Llama recursivamente los nodos derechos
            destroyTree(node->right);
            // Libera la memoria del nodo actual
            delete node;
        }
    }
    
    void Insert(rbtnode<T>* z) {
        // Inserta el nodo z en la posición que le corresponde en el árbol.
    };
    
    void InorderWalk(rbtnode<T> *x) {
        // Recorre en orden el subarbol con raíz x, imprimiendo la llave de cada nodo en en una nueva linea de la salida estandar despues de recorrido el subarbol izquierdo y antes de recorrer el subarbol derecho.
    };
    
    rbtnode<T>* Search(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* IterativeSearch(rbtnode<T> *x, const T& k) {
        // Busca la llave k iterativamente en el subarbol con raíz x. Si la encuentra devuelve un apuntador al nodo que la contiene, sino devuelve el nodo nil.
    };
    
    rbtnode<T>* Minimum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave menor. Si el árbol esta vacío, devuelve el nodo nil.
    };
    
    rbtnode<T>* Maximum(rbtnode<T> *x) {
        // Devuelve el nodo que tiene la llave mayor. Si el árbol esta vacío devuelve el nodo nil.
    };
    
    rbtnode<T>* Successor(rbtnode<T> *x) {
        // Devuelve el nodo cuya llave es la que le sigue a la del nodo x. Si no existe el nodo, devuelve el nodo nil.
    };
};

#endif /* rbtree_h */
