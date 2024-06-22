# Jazz Jackrabbit 2

![Image](docs/portada_juego.jpg)

## Comenzando 🚀

### Pre-requisitos 📋

Antes que nada, aseguragte de correr el `installer.sh` que se encargará de bajar todas las librerías y dependencias necesarias para correr el juego.

Luego, será necesario crear una carpeta build usando: `mkdir build`. (En caso de tenerla previamente, borrarla con `rm -r build` y luego crearla nuevamente).

Se tiene que entrar en la carpeta creada con: `cd build`.

Una vez adentro de la carpeta build, se tiene que crear el archivo makefile usando el comando: `cmake ../`.

Por último, se compila el programa con el comando `make`.

Para ejecutar el servidor o cliente siempre hay que estar en la carpeta build [para más información sobre cómo correr el juego, vaya a "A jugar"]

### A jugar 🌟

Vamos a necesitar de 1 consola para el server:

```shell
./server <puerto>
```

y luego de 1 consola por cada cliente que quiera conectarse al juego:

```shell
./client <IP> <puerto>
```

## Ejecutando las pruebas ⚙️

En la misma carpeta de build que creamos para correr el juego, vamos a abrir 2 consolas.

En una corremos: `./protocol_server_test`

Y en la otra corremos: `./test_consola_cliente`

## Construido con 🛠️

* [C++](https://cplusplus.com)
* [SDL2](https://www.libsdl.org/)
* [Makefile](https://www.gnu.org/software/make/manual/make.html)
* [CMake](https://cmake.org/)
* [YAML](https://yaml.org/)
* [Gtest](https://github.com/google/googletest)

## Autores ✒️

* **Camila Belén Sebellin** - 100.204 - [camiSebe](https://github.com/camiSebe)
* **Pablo Martin Alejando** - 98.021 - [Pabloale96](https://github.com/Pabloale96)
