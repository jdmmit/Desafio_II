#ifndef SISTEMAUDEATUNES_H
#define SISTEMAUDEATUNES_H

#include <iostrem>
#include <string>
#include "Lista.h"
#include "Usuario.h"
#include "Artista.h"
#include "MensajePublicitario.h"

using namespace std;


class SistemaUdeATunes
{
private:
    Lista<Usuario> usuarios;
    Lista<Artista> artista;
    Lista<MensajePublicitario> mensaje;
    Usuario* usuarioActual;
    int contadorIteraciones;

public:
    SistemaUdeATunes();

    // Metodos
    void cargarDatos();
    void iniciarSesion();
    void reproduccionAleatoria();
    void menuListasFavoritos();
    long cularMemoria();
    void registrarUsuario();
    void mostrarFavoritos();
    void agregarCancionFavoritas();
    void removerCancionFavorita();
    void menuPrincipal();
    void mostrarUsuariosRegistrados();


};

#endif
