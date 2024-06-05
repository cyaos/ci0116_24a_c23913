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

    /// @brief Conseguir la clave del nodo
    /// @return la clave del nodo
    int GetKey() {
        return this->key;
    }

    /// @brief Colocar el padre del nodo
    /// @param y nodo padre por ingresar
    void SetPadre(rbtnode<T>* w) {
        this->p = w;
    };

    /// @brief Conseguir el padre del nodo
    /// @return el padre del nodo
    rbtnode<T>* GetPadre(){
        return this->p;
    }

    /// @brief Colocar nodo hijo izquierdo
    /// @param y nodo izquierdo por ingresar
    void SetLeft(rbtnode<T>* y) {
        this->left = y;
    };

    /// @brief Conseguir el nodo del hijo izquierdo
    /// @return hijo izquierdo del nodo
    rbtnode<T>* GetLeft() {
        return this->left;
    }

    /// @brief Colocar nodo hijo derecho
    /// @param z nodo derecho por ingresar
    void SetRight(rbtnode<T>* z) {
        this->right = z;
    }

    /// @brief Conseguir el nodo del hijo derecho
    /// @return hijo derecha del nodo
    rbtnode<T>* GetRight() {
        return this->right;
    }

    /// @brief Colocar el color del nodo
    /// @param c el color por ingresar
    void SetColor(colors c){
        this->color = c;
    }

    /// @brief Conseguir el color del nodo
    /// @return el color del nodo
    colors GetColor(){
        return this->color;
    }
};

// Arbol rojinegro:
template <typename T>
class rbtree {
public:
    /// raíz del árbol
    rbtnode<T> *root;
    /// nodo nil (hoja) del árbol
    rbtnode<T> *nil;
    
    /// @brief Constructor del árbol rojinegro
    /// @details crea un árbol vacío.
    rbtree() {
        // Inicializa el nodo nil y lo vuelve negro
        this->nil = new rbtnode<T>();
        nil->SetColor(BLACK);
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
            delete n;
        }
    }
    
    /// @brief Inserta el nodo z en la posición que le corresponde en el árbol.
    void Insert(rbtnode<T>* z) {
        // Atributos auxiliares
        rbtnode<T>* x = root;
        rbtnode<T>* y = nil;
        // Mientras x no sea nulo
        while (x != nil) {
            y = x;
            // Comparar la clave de x con el nuevo nodo
            // Si es menor, iterar al hijo izquierdo
            // Si es mayor, iterar al hijo derecho
            if (z->GetKey() < x->key){
                x = x->GetLeft();
            } else {
                x = x->right();
            }
        }

        // Hacer y el padre de z
        z->SetPadre(y);

        // Si y es nulo, hacer z la raíz del árbol
        if (y == nil) {
            root = z;
        // Si la clave de z es menor que la clave de y, hacer z el hijo
        // izquierda de y. Si no, hijo derecho.
        } else if (z->GetKey() < y->GetKey()) {
            y->SetLeft(z);
        } else {
            y->SetRight(z);
        }

        // Volver los hijos de Z negro y nulo
        z->SetLeft(nil);
        z->SetRight(nil);
        // Volver z en un nodo rojo
        z->SetColor(RED);

        // Arreglar el árbol para que cumpla todos los requerimientos de un árbol rojinegro
        InsertFixUp(z);
    };

    void InsertFixUp(rbtnode<T>* z) {
        // Si el padre del nodo es rojo
        while(z->GetPadre()->GetColor() == RED){
            // Si el padre es hijo izquierdo
            if (z->GetPadre() == z->GetPadre()->GetPadre()->GetLeft()){
                // y guarda al tio de z
                rbtnode<T>* y = z->GetPadre()->GetPadre()->GetRight();
                // Si el tio es un nodo rojo
                if (y->GetColor() == RED) {
                    // Hacer el padre y el tio negro
                    z->GetPadre()->SetColor(BLACK);
                    y->SetColor(BLACK);
                    // Hacer el abuelo rojo
                    z->GetPadre()->GetPadre()->SetColor(RED);
                    // z se vuelve en el abuelo
                    z = z->GetPadre()->GetPadre();
                } else {
                    // Si z es un hijo derecho
                    if (z == z->GetPadre()->GetRight()){
                        // z se vuelve en su padre
                        z = z->GetPadre();
                        // Se rota z a la izquierda
                        RotateLeft(z);
                    }
                    // Cambiar el color del padre a negro y el del abuelo a rojo
                    z->GetPadre()->SetColor(BLACK);
                    z->GetPadre()->GetPadre()->SetColor(RED);
                    // Rotar el abuelo de z a la derecha
                    RotateRight(z->GetPadre()->GetPadre());
                }
            } else {
                // ES LO MISMO QUE LO ANTERIOR PERO SE INTERCAMBIA DERECHA CON IZQUIERDA
                rbtnode<T>* y = z->GetPadre()->GetPadre()->GetLeft();
                if (y->GetColor() == RED) {
                    z->GetPadre()->SetColor(BLACK);
                    y->SetColor(BLACK);
                    z->GetPadre()->GetPadre()->SetColor(RED);
                    z = z->GetPadre()->GetPadre();
                } else {
                    if (z == z->GetPadre()->GetLeft()){
                        z = z->GetPadre();
                        RotateRight(z);
                    }
                    z->GetPadre()->SetColor(BLACK);
                    z->GetPadre()->GetPadre()->SetColor(RED);
                    RotateLeft(z->GetPadre()->GetPadre());
                }

            }
        }
        // Volver la raíz del árbol negro
        root->SetColor(BLACK);
    };

    /// @brief Hace rotación del nodo a la izquierda
    /// @param z nodo por rotar
    void RotateLeft(rbtnode<T>* z) {};

    /// @brief Hace rotación del nodo a la derecha
    /// @param z nodo por rotar
    void RotateRight(rbtnode<T>* z) {};

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
