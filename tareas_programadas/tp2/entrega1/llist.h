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
    
    ~llist() {
        // Destructor (borra la lista)
    };
    
    void Insert(llnode<T>* x) {
        // Inserta el nodo x en la lista.
    };

    llnode<T>* Search(const T& k) {
        // Busca la llave iterativamente. Si la encuentra, devuelve un apuntador al nodo que la contiene; sino devuelve el nodo nil (el centinela).
    };
        
    void Delete(llnode<T>* x) {
        // Saca de la lista la llave contenida en el nodo apuntado por x.
    };    
};

#endif /* llist_h */
