#ifndef LISTA_H
#define LISTA_H

// Estructura para lista enlazada dinamica
template <typename T>
struct Nodo
{
    T dato;
    Nodo<T> *siguiente;

    Nodo(const T &valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class Lista
{
private:
    Nodo<T> *cabeza;
    int tamanio;

public:
    Lista() : cabeza(nullptr), tamanio(0) {}

    ~Lista()
    {
        limpiar();
    }

    void limpiar()
    {
        while (cabeza)
        {
            Nodo<T> *temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        tamanio = 0;
    }

    void agregar(const T &elemento)
    {
        Nodo<T> *nuevo = new Nodo<T>(elemento);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        tamanio++;
    }

    bool remover(const T &elemento)
    {
        if (!cabeza)
            return false;

        if (cabeza->dato == elemento)
        {
            Nodo<T> *temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            tamanio--;
            return true;
        }

        Nodo<T> *actual = cabeza;
        while (actual->siguiente && actual->siguiente->dato != elemento)
        {
            actual = actual->siguiente;
        }

        if (actual->siguiente)
        {
            Nodo<T> *temp = actual->siguiente;
            actual->siguiente = temp->siguiente;
            delete temp;
            tamanio--;
            return true;
        }

        return false;
    }

    bool contiene(const T &elemento) const
    {
        Nodo<T> *actual = cabeza;
        while (actual)
        {
            if (actual->dato == elemento)
                return true;
            actual = actual->siguiente;
        }
        return false;
    }

    T *obtener(int indice) const
    {
        if (indice < 0 || indice >= tamanio)
            return nullptr;

        Nodo<T> *actual = cabeza;
        for (int i = 0; i < indice; i++)
        {
            actual = actual->siguiente;
        }
        return &(actual->dato);
    }

    int obtenerTamanio() const { return tamanio; }

    bool estaVacia() const { return tamanio == 0; }
};

#endif