#include "Sistemaudeatunes.h"
#include <iostream>

using namespace std;

SistemaUdeATunes::SistemaUdeATunes()
{
    usuarioActual = nullptr;
    contadorIteraciones = 0;
}

void SistemaUdeATunes::cargarDatos()
{
    cout << " === CARGANDO DATOS ===" << endl;

    // Crear Usuarios

    Usuario user1(1, "carlos_music", "Carlos Garcia", 25, ESTANDAR, "Medellin");
    Usuario user2(2, "ana_premium", "Ana Lopez", 28, PREMIUM, "Bogota");
    Usuario user3(3, "luis_beats", "Luis Rodriguez", 22, ESTANDAR, "Cali");
    Usuario user4(4, "maria_sound", "Maria Torres", 30, PREMIUM, "Cartagena");

    usuarios.agregar(user1);
    usuarios.agregar(user2);
    usuarios.agregar(user3);
    usuarios.agregar(user4);

    // Crear artistas

    Artista art1(12345, "Claudia Lorelle", 28, "Colombia");
    Artista art2(67890, "Diego Urban", 32, "Argentina");
    Artista art3(11111, "Sofia Electro", 26, "Mexico");

    artistas.agregar(art1);
    artistas.agregar(art2);
    artistas.agregar(art3);

    // Crear mensajes publicitarios

    MensajePublicitario msg1("Cansado de los anuncios? Prueba UdeATunes Premium!", A);
    MensajePublicitario msg2("Descubre nueva musica cada dia en UdeATunes.", B);
    MensajePublicitario msg3("Compra los mejores audifonos en TechStore.", C);

    mensajes.agregar(msg1);
    mensajes.agregar(msg2);
    mensajes.agregar(msg3);

    cout << "Datos cargados correctamente. " << endl;
    cout << "Usuarios: " << usurios.obtenerTemario() << endl;
    cout << "Artistas: " << artistas.obtenerTemario() << endl;
    cout << "Mensajes: " << mensajes.obtenerTemario() << endl;
}

void SistemaUdeATunes::iniciarSecion()
{
    cout << "\n === INICIAR SESION === " << endl;
    cout << "Usuarios Disponibles: " << endl;

    for (int i = 0; i < usuarios.obtenerTemario(); i++)
    {
        Usuarios *user = usuarios.obtener(i);
        if (user)
        {
            cout << "_ " << user->getNickname() << " (" << user->getNombre() << " )" << endl;
        }
    }

    string nickname;
    cout << "\n Ingresa su nickname: ";
    getline(cin, nickname);

    // Buscar Usuario

    for (int i = 0; i < usuarios.obtenerTemario(); i++)
    {
        contadorIteraciones++;
        Usuario *user = usuarios.obtener(i);
        if (user && user->getNickname() == nickname)
        {
            usuarioActual = user;
            cout << "\n Login Exitoso! " << endl;
            user->login();
            return;
        }
    }
    cout << "Usuario no encontrado." << endl;
    cout << "Use la opcion 2 del menu para registrar un usuario nuevo." << endl;
}

void SistemaUdeATunes::reproduccionAleatoria()
{
    cout << "\n === REPRODUCIION ALEATORIA ===" << ENDL;

    if (!usuarioActual)
    {
        cout << " Debe Iniciar Sesion Primero. " << endl;
        return;
    }

    cout << " Simulando reproduccion de 3 canciones... " << end;

    // Simulad la reproduccion de canciones

    for (int i = 1, i <= 3; i++)
    {
        contadorIteraciones++;
        cout << "\n [Cancion " << i << "]" << endl;
        cout << " Reproducciendo: Cancion Example " << i << endl;
        cout << " Artista: Artista Ejemplo " << endl;
        cout << " Duracion: 3:45 " << endl;

        // Muestra Publicidad

        if (usuariActual->getMembresia() == ESTANDAR && i == 2)
        {
            cout << " \n === PUBLICIDAD === " << endl;
            if (!mensajes.estaVacia())
            {
                MensajePublicitario *msg = mensajes.obtener(0);
                if (msg)
                {
                    msg->mostrar();
                }
            }
        }

        cout << " Presione ENTER para continuar... ";
        cin.get();
    }

    cout << " \n Reproduccion Completada. " endl;
}