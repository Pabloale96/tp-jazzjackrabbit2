# tp-jazzjackrabbit2

## Para compilar y correr con cmake

Es necesario crear una carpeta build usando: `mkdir build`. (En caso de tenerla previamente, borrarla con `rm -r build` y luego crearla)

Se tiene que entrar en la carpeta con: `cd build`.

Una vez adentro de la carpeta build, se tiene que crear el archivo makefile usando el comando: `cmake ../`

Por ultimo se compila el programa con `make`

Para ejecutar el servidor o cliente hay que estar en la carpeta build.

## Para correr el TP

Server:

```shell
./server 8080

valgrind --tool=memcheck --leak-check=full --leak-resolution=med --show-reachable=yes --trace-children=yes --track-fds=yes --track-origins=no --time-stamp=yes --num-callers=20 ./server 8080
```

Tiburoncin:

```shell
tiburoncin -o -A 127.0.0.1:9095 -B 127.0.0.1:8080 -o
```

Client:

```shell
./client 127.0.0.1 9095

valgrind --tool=memcheck --leak-check=full --leak-resolution=med --show-reachable=yes --trace-children=yes --track-fds=yes --track-origins=no --time-stamp=yes --num-callers=20 ./client 127.0.0.1 9095

./client 127.0.0.2 8080

./client 127.0.0.3 8080
```

Pasar el pre-commit:

```shell
pre-commit run --all-files
```

## Para correr los tests

```shell
./testing/run_tests.sh ./ testing/casos/ multi-client no-valgrind  60 10 yes
./testing/compare_outputs.sh testing/casos testing/salidas
```
