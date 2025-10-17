# Analisis Inicial - UdeATunes
## Sistema de Streaming Musical en C++

**Autor:** Camilo Medina & Juan David Murillo. 
**Institución:** Universidad de Antioquia.  
**Fecha:** 17 de Octubre, 2025.  
**Proyecto:** Desafío II - Informática II 2025-2.

## ¿Que tengo que hacer?

Basicamente se necesita crear un programa que simule una plataforma de musica como Spotify. El programa debe permitir a los usuarios escuchar musica en streaming.

## Usuarios del sistema

Se identificaron que hay dos tipos de usuarios:

**Usuarios normales o estandar:**
- Tiene que ver anuncios cada cierto tiempo.
- la musica se escucha en calidad normal (128 kbps).
- Puede tener una lista de canciones favoritas.
- pueden seguir las listas de otros usuarios premium.

**Usuarios Premium:**
- No ven anuncios.
- Musica en alta calidad (320 kbps).
- Pueden tener una lista de canciones favoritas.
- Pueden seguir las listas de otros usuarios premium.


## Componentes que se nesecitan.

**1. Sistemas de musica.**
- Nesecita que el artista tenga albunes.
- Cada album tiene varias canciones.
- Cada cancion debe tener informacion como duracion, nombre, etc.

**2. Sistemas de usuarios.**
- Login con nombre de usuario.
- Diferentes permisos segun el tipo de cuenta.
- Historial de lo que han escuchado.

**3. Sistema de publicidad.**
- Solo para usuarios normales.
- Diferentes tipos de anuncios con prioridades.
- No repetir el mismo anuncio seguido.

**4.Reproduccion de musica.**
- Modo aleatorio que escoja canciones al azar.
- Mostrar informacion de lo que se esta reproduciendo.
- Diferentes calidades segun el usuario.


## Como se va a organizar.

Se va a usar POO o Programacion Orientada a Objetos, ya que es mas facil de organizar y estructurar el proyecto:

- Clase `Usuario` para manejar los datos de cada persona.
- Clase `Cancion` para manejar cada tema musical.
- Clase `Album` para agrupar las canciones.
- Clase `Artista` para manejar los musicos.
- Clase `MensajePublicitario` para manejar los anuncios publicitarios.
- Clase Principal `SistemaUdeATunes`para manejar todas las otras clases.


## Funcionalidades.

**Menu Principal:**
1. Login de usuarios.
2. Reproducir musica.
3. Gestionar favoritos (Solo Premium).
4. Salir.

**Reproduccion:**
- Elegir 5 canciones al azar.
- Mostrar informacion de cada cancion (nombre, artistas, duracion).
- Para usuarios normales: mostrar anuncios cada 2 canciones.
- Contar cuantas operaciones hace el programa.

**Lista de favoritos (Premium):**

