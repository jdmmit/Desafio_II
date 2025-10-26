#include "Sistemaudeatunes.h"
#include <iostream>
#include <fstream>
#include <string>

SistemaUdeATunes::SistemaUdeATunes()
{
    usuarioActual = nullptr;
    contadorIteraciones = 0;
}

void SistemaUdeATunes::cargarDatos()
{
    cout << "=== CARGANDO DATOS ===" << endl;

    // Crear usuarios simples
    Usuario user1(1, "carlos_music", "Carlos Garcia", 25, ESTANDAR, "Medellin");
    Usuario user2(2, "ana_premium", "Ana Lopez", 28, PREMIUM, "Bogota");
    Usuario user3(3, "luis_beats", "Luis Rodriguez", 22, ESTANDAR, "Cali");
    Usuario user4(4, "maria_sound", "Maria Torres", 30, PREMIUM, "Cartagena");

    usuarios.agregar(user1);
    usuarios.agregar(user2);
    usuarios.agregar(user3);
    usuarios.agregar(user4);

    // Crear artistas simples
    Artista art1(12345, "Claudia Lorelle", 28, "Colombia");
    Artista art2(67890, "Diego Urban", 32, "Argentina");
    Artista art3(11111, "Sofia Electro", 26, "México");

    artistas.agregar(art1);
    artistas.agregar(art2);
    artistas.agregar(art3);

    // cargar las canciones de los archivos txt
    cout << "\nCargando canciones..." << endl;

    string nombreArchivos[8] = {
        "cancion_1230101.txt",
        "cancion_1230102.txt",
        "cancion_1230103.txt",
        "cancion_6789001.txt",
        "cancion_6789002.txt",
        "cancion_1111101.txt",
        "cancion_1111102.txt",
        "cancion_1111103.txt"};

    // intentar diferentes rutas base
    string rutasBases[3] = {
        "canciones/",
        "../canciones/",
        "../../canciones/"};

    // leer cada archivo
    for (int i = 0; i < 8; i++)
    {
        Cancion cancion;
        bool cargado = false;

        // intentar con cada ruta base
        for (int j = 0; j < 3 && !cargado; j++)
        {
            string rutaCompleta = rutasBases[j] + nombreArchivos[i];
            if (cancion.cargarDesdeArchivo(rutaCompleta))
            {
                canciones.agregar(cancion);
                cout << "- " << cancion.getNombre() << " (ID: " << cancion.getId() << ")" << endl;
                cargado = true;
            }
        }

        if (!cargado)
        {
            cout << "Error abriendo: " << nombreArchivos[i] << endl;
        }
    }

    // Crear mensajes publicitarios
    MensajePublicitario msg1("Cansado de los anuncios? Prueba UdeATunes Premium!", A);
    MensajePublicitario msg2("Descubre nueva musica cada dia en UdeATunes.", B);
    MensajePublicitario msg3("Compra los mejores audifonos en TechStore.", C);

    mensajes.agregar(msg1);
    mensajes.agregar(msg2);
    mensajes.agregar(msg3);

    cout << "\n=== RESUMEN ===" << endl;
    cout << "Usuarios: " << usuarios.obtenerTamanio() << endl;
    cout << "Artistas: " << artistas.obtenerTamanio() << endl;
    cout << "Canciones: " << canciones.obtenerTamanio() << endl;
    cout << "Mensajes: " << mensajes.obtenerTamanio() << endl;
}

void SistemaUdeATunes::iniciarSesion()
{
    cout << "\n=== INICIAR SESION ===" << endl;
    cout << "Usuarios disponibles:" << endl;

    for (int i = 0; i < usuarios.obtenerTamanio(); i++)
    {
        Usuario *user = usuarios.obtener(i);
        if (user)
        {
            cout << "- " << user->getNickname() << " (" << user->getNombre() << ")" << endl;
        }
    }

    string nickname;
    cout << "\nIngrese su nickname: ";
    getline(cin, nickname);

    // Buscar usuario
    for (int i = 0; i < usuarios.obtenerTamanio(); i++)
    {
        contadorIteraciones++;
        Usuario *user = usuarios.obtener(i);
        if (user && user->getNickname() == nickname)
        {
            usuarioActual = user;
            cout << "\nLogin exitoso!" << endl;
            user->login();
            return;
        }
    }

    cout << "Usuario no encontrado." << endl;
    cout << "Use la opcion 2 del menu para registrar un usuario nuevo." << endl;
}

void SistemaUdeATunes::reproduccionAleatoria()
{
    cout << "\n=== REPRODUCCION ALEATORIA ===" << endl;

    if (!usuarioActual)
    {
        cout << "Debe iniciar sesion primero." << endl;
        return;
    }

    if (canciones.estaVacia())
    {
        cout << "No hay canciones disponibles." << endl;
        return;
    }

    cout << "Reproduciendo canciones desde archivos..." << endl;
    cout << "Total de canciones disponibles: " << canciones.obtenerTamanio() << endl;

    int numCanciones = 3;
    if (canciones.obtenerTamanio() < 3)
    {
        numCanciones = canciones.obtenerTamanio();
    }

    // reproducir las canciones
    for (int i = 0; i < numCanciones; i++)
    {
        contadorIteraciones++;

        Cancion *cancion = canciones.obtener(i);
        if (cancion)
        {
            cout << "\n[Cancion " << (i + 1) << " de " << numCanciones << "]" << endl;
            cancion->reproducir();
        }

        // mostrar publicidad cada 2 canciones si es usuario estandar
        if (usuarioActual->getMembresia() == ESTANDAR && (i + 1) % 2 == 0)
        {
            cout << "\n--- PUBLICIDAD ---" << endl;
            if (!mensajes.estaVacia())
            {
                int indiceMensaje = i % mensajes.obtenerTamanio();
                MensajePublicitario *msg = mensajes.obtener(indiceMensaje);
                if (msg)
                {
                    msg->mostrar();
                }
            }
            cout << "-------------------" << endl;
        }

        if (i < numCanciones - 1)
        {
            cout << "\nPresione ENTER para siguiente cancion...";
            cin.get();
        }
    }

    cout << "\n=== REPRODUCCION COMPLETADA ===" << endl;
    cout << "Canciones reproducidas: " << numCanciones << endl;
}

void SistemaUdeATunes::menuListaFavoritos()
{
    cout << "\n=== LISTA DE FAVORITOS ===" << endl;

    if (!usuarioActual)
    {
        cout << "Debe iniciar sesion primero." << endl;
        return;
    }

    if (usuarioActual->getMembresia() != PREMIUM)
    {
        cout << "Esta funcion es solo para usuarios Premium." << endl;
        return;
    }

    cout << "Gestion de lista de favoritos para: " << usuarioActual->getNombre() << endl;
    cout << "Canciones favoritas actuales: " << usuarioActual->getFavorito().obtenerTamanio() << endl;

    cout << "\nOpciones:" << endl;
    cout << "1. Ver canciones favoritas" << endl;
    cout << "2. Agregar cancion a favoritos" << endl;
    cout << "3. Remover cancion de favoritos" << endl;
    cout << "0. Volver" << endl;

    int opcion;
    cout << "Seleccione opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion)
    {
    case 1:
        mostrarFavoritos();
        break;
    case 2:
        agregarCancionFavorita();
        break;
    case 3:
        removerCancionFavorita();
        break;
    case 0:
        cout << "Volviendo al menu principal..." << endl;
        break;
    default:
        cout << "Opcion no valida." << endl;
    }
}

long SistemaUdeATunes::calcularMemoria()
{
    cout << "\n=== MEDICION DE MEMORIA ===" << endl;

    long memoria = 0;
    memoria += usuarios.obtenerTamanio() * sizeof(Usuario);
    memoria += artistas.obtenerTamanio() * sizeof(Artista);
    memoria += mensajes.obtenerTamanio() * sizeof(MensajePublicitario);

    cout << "Usuarios en memoria: " << usuarios.obtenerTamanio() << endl;
    cout << "Artistas en memoria: " << artistas.obtenerTamanio() << endl;
    cout << "Mensajes en memoria: " << mensajes.obtenerTamanio() << endl;
    cout << "Iteraciones realizadas: " << contadorIteraciones << endl;
    cout << "Memoria total calculada: " << memoria << " bytes" << endl;

    return memoria;
}

void SistemaUdeATunes::registrarUsuario()
{
    cout << "\n=== REGISTRAR NUEVO USUARIO ===" << endl;

    string nickname, nombre, ciudad;
    int edad, tipoMem;

    cout << "Ingrese nickname: ";
    getline(cin, nickname);

    // Verificar que no exista el nickname
    for (int i = 0; i < usuarios.obtenerTamanio(); i++)
    {
        Usuario *user = usuarios.obtener(i);
        if (user && user->getNickname() == nickname)
        {
            cout << "Error: El nickname ya existe." << endl;
            return;
        }
    }

    cout << "Ingrese nombre completo: ";
    getline(cin, nombre);

    cout << "Ingrese edad: ";
    cin >> edad;
    cin.ignore();

    cout << "Ingrese ciudad: ";
    getline(cin, ciudad);

    cout << "Tipo de membresia:" << endl;
    cout << "1. Estandar" << endl;
    cout << "2. Premium" << endl;
    cout << "Seleccione: ";
    cin >> tipoMem;
    cin.ignore();

    TipoMembresia membresia = (tipoMem == 2) ? PREMIUM : ESTANDAR;

    // Generar nuevo ID
    int nuevoId = usuarios.obtenerTamanio() + 1;

    // Crear y agregar el usuario
    Usuario nuevoUsuario(nuevoId, nickname, nombre, edad, membresia, ciudad);
    usuarios.agregar(nuevoUsuario);

    cout << "\nUsuario registrado exitosamente!" << endl;
    cout << "ID: " << nuevoId << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Membresia: " << (membresia == PREMIUM ? "Premium" : "Estandar") << endl;

    // Hacer login automatico con el nuevo usuario
    Usuario *usuarioRecienCreado = usuarios.obtener(usuarios.obtenerTamanio() - 1);
    if (usuarioRecienCreado)
    {
        usuarioActual = usuarioRecienCreado;
        cout << "\nIniciando sesion automaticamente..." << endl;
        usuarioRecienCreado->login();
    }
}

void SistemaUdeATunes::mostrarFavoritos()
{
    cout << "\n=== MIS CANCIONES FAVORITAS ===" << endl;

    if (usuarioActual->getFavorito().estaVacia())
    {
        cout << "No tienes canciones favoritas aun." << endl;
        return;
    }

    cout << "Tus canciones favoritas:" << endl;
    for (int i = 0; i < usuarioActual->getFavorito().obtenerTamanio(); i++)
    {
        int *idCancion = usuarioActual->getFavorito().obtener(i);
        if (idCancion)
        {
            cout << "- Cancion ID: " << *idCancion << " (" << "Titulo Example" << ")" << endl;
        }
    }
}

void SistemaUdeATunes::agregarCancionFavorita()
{
    cout << "\n=== AGREGAR A FAVORITOS ===" << endl;

    if (canciones.estaVacia())
    {
        cout << "No hay canciones disponibles." << endl;
        return;
    }

    cout << "Canciones disponibles:" << endl;
    cout << "------------------------" << endl;

    // mostrar todas las canciones
    for (int i = 0; i < canciones.obtenerTamanio(); i++)
    {
        Cancion *c = canciones.obtener(i);
        if (c)
        {
            cout << c->getId() << " - " << c->getNombre()
                 << " (" << c->getArtista() << ")" << endl;
        }
    }

    int idCancion;
    cout << "\nIngrese ID de la cancion: ";
    cin >> idCancion;
    cin.ignore();

    // buscar la cancion
    bool existe = false;
    for (int i = 0; i < canciones.obtenerTamanio(); i++)
    {
        Cancion *c = canciones.obtener(i);
        if (c && c->getId() == idCancion)
        {
            existe = true;
            break;
        }
    }

    if (!existe)
    {
        cout << "No existe esa cancion." << endl;
        return;
    }

    // Verificar que no este ya en favoritos
    if (usuarioActual->getFavorito().contiene(idCancion))
    {
        cout << "Esta cancion ya esta en tus favoritos." << endl;
        return;
    }

    // Agregar a favoritos
    usuarioActual->getFavorito().agregar(idCancion);
    cout << "Cancion agregada a favoritos exitosamente!" << endl;
    cout << "Total de favoritos: " << usuarioActual->getFavorito().obtenerTamanio() << endl;
}

void SistemaUdeATunes::removerCancionFavorita()
{
    cout << "\n=== REMOVER DE FAVORITOS ===" << endl;

    if (usuarioActual->getFavorito().estaVacia())
    {
        cout << "No tienes canciones favoritas para remover." << endl;
        return;
    }

    mostrarFavoritos();

    int idCancion;
    cout << "\nIngrese ID de la cancion a remover: ";
    cin >> idCancion;
    cin.ignore();

    if (usuarioActual->getFavorito().remover(idCancion))
    {
        cout << "Cancion removida de favoritos exitosamente!" << endl;
        cout << "Total de favoritos: " << usuarioActual->getFavorito().obtenerTamanio() << endl;
    }
    else
    {
        cout << "No se encontro esa cancion en tus favoritos." << endl;
    }
}

void SistemaUdeATunes::menuPrincipal()
{
    int opcion = 0;

    while (opcion != 9)
    {
        cout << "\n"
             << string(50, '=') << endl;
        cout << "           MENU PRINCIPAL UDEATUNES" << endl;
        cout << string(50, '=') << endl;

        if (usuarioActual)
        {
            cout << "Usuario actual: " << usuarioActual->getNickname()
                 << " (" << usuarioActual->getNombre() << ")" << endl;
            cout << "Tipo: " << (usuarioActual->getMembresia() == PREMIUM ? "Premium" : "Estandar") << endl;
            cout << string(50, '-') << endl;
        }
        else
        {
            cout << "No hay usuario logueado" << endl;
            cout << string(50, '-') << endl;
        }

        cout << "OPCIONES DISPONIBLES:" << endl;
        cout << "1. Ver usuarios registrados" << endl;
        cout << "2. Registrar nuevo usuario" << endl;
        cout << "3. Iniciar sesion" << endl;

        if (usuarioActual)
        {
            cout << "4. Reproduccion aleatoria" << endl;
            if (usuarioActual->getMembresia() == PREMIUM)
            {
                cout << "5. Lista de favoritos" << endl;
            }
            cout << "6. Medicion de memoria" << endl;
            cout << "7. Cerrar sesion" << endl;
        }

        cout << "9. Salir del programa" << endl;
        cout << string(50, '=') << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            mostrarUsuariosRegistrados();
            break;
        case 2:
            registrarUsuario();
            break;
        case 3:
            if (!usuarioActual)
            {
                iniciarSesion();
            }
            else
            {
                cout << "Ya hay un usuario logueado. Cierre sesion primero." << endl;
            }
            break;
        case 4:
            if (usuarioActual)
            {
                reproduccionAleatoria();
            }
            else
            {
                cout << "Debe iniciar sesion primero." << endl;
            }
            break;
        case 5:
            if (usuarioActual && usuarioActual->getMembresia() == PREMIUM)
            {
                menuListaFavoritos();
            }
            else if (usuarioActual)
            {
                cout << "Esta funcion es solo para usuarios Premium." << endl;
            }
            else
            {
                cout << "Debe iniciar sesion primero." << endl;
            }
            break;
        case 6:
            if (usuarioActual)
            {
                calcularMemoria();
            }
            else
            {
                cout << "Debe iniciar sesion primero." << endl;
            }
            break;
        case 7:
            if (usuarioActual)
            {
                cout << "Cerrando sesion de: " << usuarioActual->getNickname() << endl;
                usuarioActual = nullptr;
            }
            else
            {
                cout << "No hay sesion activa." << endl;
            }
            break;
        case 9:
            cout << "Gracias por usar UdeATunes!" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
        }

        if (opcion != 9)
        {
            cout << "\nPresione ENTER para continuar...";
            cin.get();
        }
    }
}

void SistemaUdeATunes::mostrarUsuariosRegistrados()
{
    cout << "\n=== USUARIOS REGISTRADOS ===" << endl;

    if (usuarios.estaVacia())
    {
        cout << "No hay usuarios registrados." << endl;
        return;
    }

    cout << "Total de usuarios: " << usuarios.obtenerTamanio() << endl;
    cout << string(45, '-') << endl;

    for (int i = 0; i < usuarios.obtenerTamanio(); i++)
    {
        Usuario *user = usuarios.obtener(i);
        if (user)
        {
            cout << "ID: " << user->getId() << endl;
            cout << "Nickname: " << user->getNickname() << endl;
            cout << "Nombre: " << user->getNombre() << endl;
            cout << "Edad: " << user->getEdad() << " anos" << endl;
            cout << "Ciudad: " << user->getCiudad() << endl;
            cout << "Membresia: " << (user->getMembresia() == PREMIUM ? "Premium" : "Estandar") << endl;

            if (user->getMembresia() == PREMIUM)
            {
                cout << "Canciones favoritas: " << user->getFavorito().obtenerTamanio() << endl;
            }

            cout << string(45, '-') << endl;
        }
    }
}
