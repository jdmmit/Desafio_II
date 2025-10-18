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
- Agregar canciones buscando po ID.
- Quitar canciones que ya no gusten.
- Seguir la lista de favoritos de otros usuarios.
- Reproducir todas las favoritas.


## Aspectos tecnicos.

**Identificacion de canciones:**
Cada cancion va a tener 9 dijitos
- Primeros 5 dijitos: es el codigo del artista.
- Siguientes 2 dijitos: numero de albun.
- Ultimos 2 dijitos: numero de la cancion.

**Calidad de audio.**
- Estandar: archivos terminados en "_128.ogg".
- Premium: archivos terminados en "_320.ogg#.

**Medicion de eficiencia:**
El programa va a contar cuantas operaciones hace y cuanta memoria usa, para demostrar que funciona bien.

## Plan de desarrollo.

1. **Primero:** Crear las clases básicas y la lista enlazada
2. **Segundo:** Implementar el login y menú principal
3. **Tercero:** Hacer funcionar la reproducción aleatoria
4. **Cuarto:** Agregar el sistema de publicidad
5. **Quinto:** Implementar las listas de favoritos
6. **Sexto:** Añadir la medición de recursos
7. **Último:** Mejorar la interfaz para que se vea bien

## Datos de prueba

Voy a crear algunos usuarios, artistas y canciones de ejemplo para poder probar todo:
- 2 usuarios normales y 2 premium
- 3 artistas con sus álbumes
- 8 canciones en total
- 6 mensajes publicitarios de diferentes tipos

## Retos que veo

- **Memoria:** Cuidar bien la memoria dinámica para no tener fugas
- **Interfaz:** Hacer que se vea bonito en la consola
- **Búsquedas:** Que sea rápido encontrar canciones por ID
- **Aleatoriedad:** Que realmente sea aleatorio y no repita patrones
- **Publicidad:** Que los anuncios importantes aparezcan más seguido

Este análisis me da una visión clara de lo que tengo que construir. El objetivo es hacer un sistema funcional que simule una plataforma de música real, pero de forma simple y educativa.
