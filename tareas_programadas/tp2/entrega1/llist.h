//
//  llist.h
//

#ifndef llist_h
#define llist_h

// Nodos de la lista:
template <typename T>
class llnode
{
private:
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    T key;
    llnode<T> *prev, *next;

public:
    // Esta clase es usada por otras clases. 
    // Constructor por omisión.
    llnode() {
        this->prev = nullptr;
        this->next = nullptr;
    };
    
    // Inicialización de los datos miembro.
    llnode (const T& k, llnode<T> *w = nullptr, llnode<T> *y = nullptr):key(k), prev(w), next(y)  {};

    // Destructor
    ~llnode() {};
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist
{
private:
    // Modifique los atributos para que sean privados y se accedan solo mediante métodos públicos de la clase.
    // Nodo centinela
    llnode<T> *nil;

public:
    // Esta clase es usada por otras clases. 
    // Constructor (crea una lista vacía)
    llist() {
        // Creación de un nodo centinela
        nil = new llnode<T>();
        // Se apunta a si mismo
        nil->prev = nil;
        nil->next = nil;
    };
    
    // Destructor (borra la lista)
    ~llist() {
    };
    
    // Inserta el nodo x en la lista.
    void Insert(llnode<T>* x) {
        // Ingresa el nuevo nodo después del nodo centinela
        x->next = nil->next;
        x->prev = nil;
        // Actualiza los punteros de nil y el nodo "next" anterior
        nil->next->prev = x;
        nil->next = x;
    };

    // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
    llnode<T>* Search(const T& k) {
    };
        
    // Saca de la lista la llave contenida en el nodo apuntado por x.
    void Delete(llnode<T>* x) {
    };    
};

#endif /* llist_h */
