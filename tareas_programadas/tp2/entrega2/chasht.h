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
    /// @brief Constructor que especifica el tamaño de la tabla.
    /// @param sz tamaño especificado.
    chtable(int sz) : size(sz) , table(sz) {
    };

    /// @brief Destructor. Borra la tabla.
    ~chtable() {};

    /// @brief Inserta el elemento en la tabla.
    /// @param k elemento por insertar.
    void Insert(const T& k) {
        int q = hash(k);
        table[q].Insert(new llnode<T>(k));
    };
    
    // Retorna un puntero a la llave o nullptr si no se encuentra

    /// @brief Busca la llave en la tabla.
    /// @param k la llave por buscar.
    /// @return Puntero a la llave, nulo si no la encuentra.
    T* Search(const T& k) {
        int q = hash(k);
        T* result = new int(table[q].Search(k)->GetKey());
        return result;
    };
    
    std::string ImprimirDatosDeTarea(){
        return "C23913 Tarea 2 Etapa 2";
    };
    
private:
    /// Número de entradas en la tabla
    int size;

    /// @brief Función de dispersión
    /// @param key La llave por ser insertada
    /// @return El resultado tras hacer el hash
    int hash(const T& key) const {
        return (key) % size;
    }

    /// La tabla es un vector de listas doblemente enlazadas
    std::vector< llist<T> > table;
};

#endif /* chtable_h */
