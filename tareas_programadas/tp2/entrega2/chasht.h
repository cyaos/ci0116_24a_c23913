//
//  chtable.h
//

#ifndef chtable_h
#define chtable_h

#include "llist.h"
#include <vector>


template <typename T>
// Tabla de dispersión con encadenamiento
class chtable {
public:
    // Constructor que especifica el tamaño de la tabla
    chtable(int sz) : size(sz) , table(sz) {
    };
        
    // Destructor (borra la tabla)
    ~chtable() {
    };
    
    // Inserta el elemento en la tabla
    void Insert(const T& k) {
        int q = hash(k);
        table[q].Insert(new llnode<T>(k));
    };
    
    // Retorna un puntero a la llave o nullptr si no se encuentra
    T* Search(const T& k) {
        int q = hash(k);
        T* result = new int(table[q].Search(k)->GetKey());
        return result;
    };
    
    
private:
    /// Número de entradas en la tabla
    int size;

    // Función de dispersión
    int hash(const T& key) const {
        return (key) % size;
    }

    /// La tabla es un vector de listas de STL
    std::vector< llist<T> > table;
};

#endif /* chtable_h */
