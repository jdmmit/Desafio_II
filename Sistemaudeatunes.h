#ifndef SISTEMAUDEATUNES_H
#define SISTEMAUDEATUNES_H

#include <iostream>
#include <string>
#include "Lista.h"
#include "usuario.h"
#include "Artista.h"
#include "Cancion.h"
#include "MensajePublicitario.h"

using namespace std;

class SistemaUdeATunes
{
private:
    Lista<Usuario> usuarios;
    Lista<Artista> artistas;
    Lista<Cancion> canciones;
    Lista<MensajePublicitario> mensajes;
    Usuario *usuarioActual;
    int contadorIteraciones;

public:
    SistemaUdeATunes();

    // Metodos
    void cargarDatos();
    void iniciarSesion();
    void reproduccionAleatoria();
    void menuListaFavoritos();
    long calcularMemoria();
    void registrarUsuario();
    void mostrarFavoritos();
    void agregarCancionFavorita();
    void removerCancionFavorita();
    void menuPrincipal();
    void mostrarUsuariosRegistrados();
};

#endif
