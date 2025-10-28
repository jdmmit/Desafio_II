
# Informe Proyecto UdeATunes

## Curso: Informatica II – Universidad de Antioquia Semestre: 2025-2 

## Fecha: 27 de Octubre de 2025 

## Autores: Juan David Murillo Mejia & Camilo Medina


## 1. Analisis del Problema

El proyecto consiste en hacer un sistema de streaming de musica como Spotify. El profe pidio que fuera orientado a objetos y que las canciones estuvieran en archivos de texto individuales para que se pueda acceder a ellas por su ruta.

Lo principal era:
- Tener usuarios (estandar y premium)
- Cargar canciones desde archivos txt
- Reproducir musica
- Listas de favoritos para usuarios premium
- Mostrar publicidad a usuarios gratis
- Medir la memoria que usa el programa

## 2. Como lo Resolvi

### 2.1 Estructura de Clases

Hice varias clases para representar las cosas del sistema:

**Cancion**: Guarda la info de cada cancion (nombre, artista, duracion, etc). Lo importante es que tiene una funcion para cargar los datos desde un archivo txt.

**Usuario**: Representa a los usuarios. Puede ser estandar o premium. Los premium tienen una lista de canciones favoritas.

**Artista**: Guarda la info del artista (nombre, edad, pais).

**Album**: Tiene las canciones que pertenecen a un album.

**SistemaUdeATunes**: Es la clase principal que maneja todo. Carga los datos, controla el menu y coordina todo.

**Lista**: Es una plantilla generica para guardar cualquier tipo de dato. La use para todo (usuarios, canciones, favoritos).

### 2.2 Como Funcionan las Canciones con Archivos

Esta fue la parte mas importante. Cada cancion esta en un archivo txt en la carpeta canciones/. 

El formato es asi:
```
ID: 1230101
Nombre: A tu lado
Artista: Claudia Lorelle
Album: Lugar Secreto
Duracion: 225
Ubicacion: /users/storage/musica/claudia_lorelle/audio/a_tu_lado
Creditos: Juan Perez,Maria Lopez,Pedro Garcia
```

En la clase Cancion hice una funcion cargarDesdeArchivo() que:
1. Abre el archivo con ifstream
2. Lee linea por linea
3. Busca el caracter : para separar el campo del valor
4. Guarda cada dato en su variable correspondiente
5. Para los creditos los separa por comas con un for

Es codigo bien basico, use un while para leer las lineas y un if-else largo para ver que campo es.

### 2.3 Sistema de Carga

Cuando arranca el programa, en la funcion cargarDatos() hice un array con las rutas de los 8 archivos de canciones. Luego con un for las voy cargando una por una y las agrego a la lista.

Asi el sistema tiene todas las canciones disponibles para reproducir.

### 2.4 Reproduccion

Para reproducir puse que agarre las canciones de la lista y las vaya mostrando. Cuando reproduce una cancion muestra de que archivo se cargo, para cumplir con el requisito de mostrar la ruta.

Para los usuarios estandar cada 2 canciones les muestro un mensaje publicitario. Lo hice con un if que revisa el tipo de usuario y cuenta las canciones con modulo.

### 2.5 Lista de Favoritos

Solo los usuarios premium pueden tener favoritos. Hice un menu donde pueden:
- Ver sus favoritos
- Agregar canciones (busca por ID)
- Quitar canciones

Cuando agregan una cancion verifico que exista en la lista de canciones cargadas y que no este repetida en favoritos.

## 3. Decisiones de Diseño

**Usar archivos txt**: Era requisito del profe. Lo bueno es que es facil de modificar, solo editas el txt y listo. Lo malo es que si hay muchas canciones toca cargarlas todas al inicio.

**Array de rutas**: Use un array simple con las rutas hardcodeadas porque es mas facil. Si quisiera agregar mas canciones solo agrego otra ruta al array.

**No usar STL**: El profe dijo que no se podia, por eso hice la plantilla Lista con memoria dinamica.

**Creditos como strings**: En vez de usar la clase Credito los puse como strings separados por comas. Es mas simple y cumple con guardar quien participo en la cancion.

## 4. Problemas que Tuve

**Leer archivos**: Al principio intente con stringstream para separar los creditos pero luego lo cambie por un for simple que va caracter por caracter. Quedo mas basico.

**Rutas de archivos**: Tuve que tener cuidado con las rutas relativas. Las canciones estan en canciones/ entonces la ruta es "canciones/cancion_1230101.txt".

**Memoria dinamica**: La plantilla Lista usa new y delete. Tuve que tener cuidado con los destructores para no tener memory leaks.

## 5. Codigo Importante

### cargarDesdeArchivo() en Cancion.cpp

```cpp
bool Cancion::cargarDesdeArchivo(string rutaArchivo) {
    ifstream archivo(rutaArchivo);
    
    if (!archivo.is_open()) {
        cout << "Error abriendo: " << rutaArchivo << endl;
        return false;
    }
    
    archivoRuta = rutaArchivo;
    string linea;
    
    // leer todo el archivo
    while (getline(archivo, linea)) {
        int pos = linea.find(':');
        if (pos != string::npos) {
            string campo = linea.substr(0, pos);
            string valor = linea.substr(pos + 2);
            
            // ver que campo es y guardarlo
            if (campo == "ID") {
                id_cancion = stoi(valor);
            }
            else if (campo == "Nombre") {
                nombre = valor;
            }
            // ... mas campos
        }
    }
    
    archivo.close();
    return true;
}
```

Esta funcion lee el txt linea por linea. Usa find para buscar el : y substr para separar. Es simple pero funciona.

### cargarDatos() en SistemaUdeATunes.cpp

```cpp
string rutasArchivos[8] = {
    "canciones/cancion_1230101.txt",
    "canciones/cancion_1230102.txt",
    // ... mas rutas
};

for (int i = 0; i < 8; i++) {
    Cancion cancion;
    if (cancion.cargarDesdeArchivo(rutasArchivos[i])) {
        canciones.agregar(cancion);
    }
}
```

Aqui cargo todas las canciones con un for. Si alguna falla no se agrega a la lista.

## 6. Como Compilar y Usar

1. Abrir Qt Creator
2. Abrir el archivo UdeATunes_Modular.pro
3. Darle a Build
4. Run

El programa muestra un menu donde puedes:
- Registrar usuarios
- Hacer login
- Reproducir canciones
- Manejar favoritos (si eres premium)
- Ver cuanta memoria usa

## 7. Que Mejoraria

Si tuviera mas tiempo:
- Leer los archivos de canciones automaticamente sin tener que poner las rutas en el codigo
- Guardar los favoritos en archivos para que no se pierdan al cerrar
- Agregar shuffle de verdad en vez de ir en orden
- Hacer que los usuarios estandar puedan saltar canciones pero con limite

## 8. Conclusion

El proyecto cumplio con los requisitos. Las canciones estan en archivos txt individuales y se puede ver la ruta de donde se cargaron. Use POO con clases, herencia, plantillas y memoria dinamica. El codigo es simple porque apenas estoy aprendiendo C++ pero funciona bien.

Lo mas interesante fue aprender a leer archivos y manejar memoria dinamica con punteros. Al principio era confuso pero ahora lo entiendo mejor.
