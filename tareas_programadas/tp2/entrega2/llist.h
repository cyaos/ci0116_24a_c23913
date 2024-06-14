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
    /// Llave del nodo
    T key;
    /// Puntero al nodo anterior y al siguiente
    llnode<T> *prev, *next;

public:
    /// @brief Constructor por omisión
    llnode() {
        this->prev = nullptr;
        this->next = nullptr;
    };
    
    /// @brief Inicialización de los datos miembro.
    /// @param k llave del nodo
    /// @param w puntero al nodo siguiente
    /// @param y puntero al nodo anterior
    llnode (const T& k, llnode<T> *w = nullptr, llnode<T> *y = nullptr):key(k), prev(w), next(y)  {};

    /// @brief Destructor
    ~llnode() {};

    /// @brief Método para conseguir el nodo siguiente
    /// @return el puntero al nodo siguiente
    llnode<T>* GetNext() {
        return next;
    }

    /// @brief Método para conseguir el nodo previo
    /// @return el puntero al nodo previo
    llnode<T>* GetPrev() {
        return prev;
    }

    /// @brief Intercambia el puntero al nodo siguiente al nuevo
    /// @param next el nodo por ingresar
    void SetNext(llnode<T>* next){
        this->next = next;
    }

    /// @brief Intercambia el puntero al nodo previo al nuevo
    /// @param prev el nodo por ingresar
    void SetPrev(llnode<T>* prev){
        this->prev = prev;
    }

    /// @brief Método para obtener la clave del nodo
    /// @return la clave del nodo
    T GetKey(){
        return key;
    }

};

// Lista enlazada con nodo centinela:
template <typename T>
class llist
{
private:
    /// Nodo centinela
    llnode<T> *nil;

public:
    /// @brief Constructor
    /// @details Crea una lista vacía
    llist() {
        // Creación de un nodo centinela
        nil = new llnode<T>();
        // Se apunta a si mismo
        nil->SetPrev(nil);
        nil->SetNext(nil);
    };
    
    /// @brief Destructor
    /// @details Borra la lista
    ~llist() {
        // Vaciar la lista hasta que quede solo nil
        while (nil->GetNext() != nil){
            Delete(nil->GetNext());
        }
        // Eliminar nodo nil
        delete nil;
    };
    
    /// @brief Inserta el nodo x en la lista.
    /// @param x el nodo que se va a insertar
    void Insert(llnode<T>* x) {
        // Ingresa el nuevo nodo después del nodo centinela
        x->SetNext(nil->GetNext());
        x->SetPrev(nil);
        // Actualiza los punteros de nil y el nodo "next" anterior
        nil->GetNext()->SetPrev(x);
        nil->SetNext(x);
    };

    /// @brief Busca la llave iterativamente. 
    /// @param k la llave a buscar
    /// @return Si la encuentra, devuelve un apuntador al nodo que la contiene; 
    /// sino devuelve el nodo nil (el centinela).
    llnode<T>* Search(const T& k) {
        // Define un nodo auxiliar
        llnode<T>* x = nil->GetNext();

        // Itera por la lista buscando por el nodo que contiene la llave
        while (x != nil) {
            // Revisa si el nodo actual contiene la llave
            if (x->GetKey() == k) {
                // Retorna el nodo
                return x;
            }
            // Siguiente
            x = x->GetNext();
        }
        // Retorna nil si no encuentra ningún nodo que contenga la llave
        return this->nil;
    };
    
    /// @brief Saca de la lista la llave contenida en el nodo apuntado por x.
    /// @param x nodo a eliminar
    void Delete(llnode<T>* x) {
        // Sacar el nodo de la lista
        x->GetPrev()->SetNext(x->GetNext());
        x->GetNext()->SetPrev(x->GetPrev());
        // Eliminar el nodo completamente
        delete x;
    };

    std::string ImprimirDatosDeTarea(){
        return "C23913 Tarea 2 Etapa 1";
    };

};

#endif /* llist_h */