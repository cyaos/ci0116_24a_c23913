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

    /// @brief Para conseguir la clave del nodo
    /// @return la clave del nodo
    int GetKey(){
        return key;
    }

    /// @brief Para conseguir el padre del nodo
    /// @return el padre del nodo
    bstnode<T>* GetParent(){
        return p;
    }

    /// @brief Para conseguir el hijo izquierdo del nodo
    /// @return el hijo izquierdo del nodo
    bstnode<T>* GetLeft(){
        return left;
    }

    /// @brief Para conseguir el hijo derecho del nodo
    /// @return el hijo derecho del nodo
    bstnode<T>* GetRight(){
        return right;
    }

    /// @brief Para definir un nuevo padre al nodo
    /// @param p nuevo padre
    void SetParent(bstnode<T>* p){
        this->p = p;
    }

    /// @brief Para definir un nuevo hijo izquierdo del nodo
    /// @param left nuevo hijo izquierdo
    void SetLeft(bstnode<T>* left){
        this->left = left;
    }

    /// @brief Para definir un nuevo hijo derecho
    /// @param right nuevo hijo derecho
    void SetRight(bstnode<T>* right){
        this->right = right;
    }
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
            clearTree(x->GetLeft());
            // Recorrel el subárbol derecho de x
            clearTree(x->GetRight());
            // Elimina el nodo x
            delete x;
        }
    }

    /// @brief Para conseguir el nodo raíz del árbol
    /// @return la raíz del árbol
    bstnode<T>* GetRoot(){
        return root;
    }
    
    /// @brief Método para crear un árbol con inserciónes ordenadas
    /// @param n número de elementos
    void OrderedTree(int n) {
        root = new bstnode<int>(0);
        bstnode<int>* aux = root;

        for (int i = 1; i < n; i++){
            bstnode<int>* newNode = new bstnode<int>(i);
            aux->SetRight(newNode);
            newNode->SetParent(aux);
            aux = newNode;
            std::cout << i << std::endl;
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
            if (z->GetKey() < x->GetKey()){
                x = x->GetLeft();
            // Si no, se mueve al lado derecho
            } else {
                x = x->GetRight();
            }
        }
        // Se establece y como el padre de z
        z->SetParent(y);
        // Si el árbol estaba vacío, y es nulo, z se vuelve en la nueva raíz
        if (y == nullptr) {
            root = z;
        // Si la llave de z es menor a la de y, se vuelve en su hijo izquierdo
        } else if (z->GetKey() < y->GetKey()) {
            y->SetLeft(z);
        // Si no, se vuelve en el hijo derecho
        } else {
            y->SetRight(z);
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
            InorderWalk(x->GetLeft());
            // Imprimir la clave del nodo actual
            std::cout << x->GetKey() << std::endl;
            // Recorrer el subárbol derecho de manera recursiva
            InorderWalk(x->GetRight());
        }
    };
    
    /// @brief Busca la llave k recursivamente en el subárbol con raíz x.
    /// @param x la raíz del subárbol por recorrer
    /// @param k la llave por buscar
    /// @return Si la encuentra devuelve un apuntador al nodo que la contiene,
    /// sino devuelve nullptr.
    bstnode<T>* Search(bstnode<T> *x, const T& k) {
        std::cout << "Search" << std::endl;
        // Si x no es nulo y la clave es la misma que k 
        if (x == nullptr || k == x->GetKey()) {
            // Devolver x
            return x;
        }
        // Si la clave es menor que la llave de x
        if (k < x->GetKey()) {
            // Recorrer el subárbol izquierdo de x recursivamente
            return Search(x->GetLeft(), k);
        } else {
            // Si no, recorrer el subárbol derecho de x recursivamente
            return Search(x->GetRight(), k);
        }
    };
    
    /// @brief Busca la llave k iterativamente en el subarbol con raíz x.
    /// @param x la raíz del subárbol por recorrer
    /// @param k la llave por buscar
    /// @return si la encuentra devuelve un apuntador al nodo que la contiene,
    /// sino devuelve nullptr.
    bstnode<T>* IterativeSearch(bstnode<T> *x, const T& k) {
        // Mientras x no sea puntero nulo y la clave de x no sea igual a k
        while (x != nullptr && k != x->GetKey()) {
            // Si la clave es menor a k
            if (k < x->GetKey()) {
                // Se mueve al hijo izquierdo de x
                x = x->GetLeft();
            } else {
                // Si no, se mueve al hijo derecho de x
                x = x->GetRight();
            }
        }
        // Retornar el nodo con la clave buscada
        return x;
    };
    
    /// @brief Busca el nodo que tiene la llave menor
    /// @param x nodo raíz del subárbol por recorrer
    /// @return devuelve el nodo con la llave menor
    /// si el árbol está vacío, devuelve nullptr.
    bstnode<T>* Minimum(bstnode<T> *x) {
        // Busca el nodo más pequeño del árbol, el más izquierdo
        while (x->GetLeft() != nullptr) {
            x = x->GetLeft();
        }
        return x;
    };
    
    /// @brief Busca el nodo que tiene la llave mayor
    /// @param x nodo raíz del subárbol por recorrer
    /// @return retorna el nodo mayor y si el árbol esta vacío devuelve nullptr.
    bstnode<T>* Maximum(bstnode<T> *x) {
        // Busca el nodo más pequeño del árbol, el más derecho
        while (x->GetRight() != nullptr) {
            x = x->GetRight();
        }
        return x;
    };
    
    /// @brief Busca el nodo que le sigue al nodo x
    /// @param x el nodo al cual se le buscara el sucesor 
    /// @return el nodo cuya llave es la que le sigue a la del nodo x.
    /// Si no existe el nodo, devuelve nullptr.
    bstnode<T>* Successor(bstnode<T> *x) {
        // Si el subárbol derecho no es nulo, devolver el nodo más pequeño
        if (x->GetRight() != nullptr) {
            return Minimum(x->GetRight());
        } else {
            // y es el padre de x
            bstnode<T>* y = x->GetParent();
            // Mientras y no sea nulo y x sea el hijo derecho de y
            while (y != nullptr && x == y->GetRight()) {
                // Subir de nivel en el árbol
                x = y;
                // Seguir subiendo
                y = y->GetParent();
            }
            // Devolver y que es el sucesor de x
            return y;
        }
    };
    
    /// @brief Saca del árbol la llave contenida en el nodo apuntado por z.
    /// @param z el nodo por eliminar
    void Delete(bstnode<T>* z) {
        // Si el hijo izquierdo de z es nulo
        if (z->left == nullptr) {
            // Reemplazar z con su subárbol derecho
            Transplant(z, z->GetRight());
        // Si el hijo derecho de x es nulo
        } else if (z->GetRight() == nullptr) {
            // Reemplazar z con su subárbol izquierdo
            Transplant(z, z->GetLeft());
        // Si ambos subárboles existen
        } else {
            // Buscar el nodo más pequeño del subárbol derecho
            bstnode<T>* y = Minimum(z->GetRight());
            // Si el padre del mínimo no es z
            if (y->GetParent() != z) {
                // Reemplazar y con su subárbol derecho
                Transplant(y, y->GetRight());
                // EL hijo derecho de y es el hijo derecho de z
                y->SetRight(z->GetRight());
                // El padre el hijo izquierdo de y es y
                y->GetRight()->SetParent(y);
            }
            // Reemplazar z con y
            Transplant(z, y);
            // El hijo izquierdo de y es el hijo izquierdo de z
            y->SetLeft(z->GetLeft());
            // El padre del hijo izquierdo de y es y
            y->GetLeft()->SetParent(y);
        }
        // Liberar z de la memoria
        delete z;
    };

    /// @brief Reemplaza el subárbol con raíz u con el subárbol con raíz v.
    /// @details  Función utilizada en delete para que la estructura del 
    /// árbol se mantenga válida después de realizar la eliminación de un nodo.
    /// @param u nodo a ser reemplazado
    /// @param v nodo que reemplazara u
    void Transplant(bstnode<T>* u, bstnode<T>* v) {
        // Si u es la raíz, reemplazar la raíz con v
        if (u->GetParent() == nullptr) {
            root = v;
        // Si u es hijo izquierdo
        } else if (u == u->GetParent()->GetLeft()) {
            // Reemplazar el hijo izquierdo del papa de x con v. (Reemplazar x con v)
            u->GetParent()->SetLeft(v);
        // Si x es hijo derecho
        } else {
            // Reemplazar el hijo derecho del padre de x con v. (Reemplazar x con v)
            u->GetParent()->SetRight(v);
        }
        // Si v no es nulo, el padre de x es el padre de u
        if (v != nullptr) {
            v->SetParent(u->GetParent());
        }
    }

    std::string ImprimirDatosDeTarea(){
        return "C23913 Tarea 2 Etapa 1";
    };
};



#endif /* bstree_h */

