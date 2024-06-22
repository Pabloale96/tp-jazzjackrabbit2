# RESUMEN COMANDOS

## COMPILACION

```shell
rm -r build
mkdir build
cd build
cmake ../
make
```

## VAGRANTFILE

```shell
vagrant up
```

## EJECUCIÓN

```shell
./server 8080

valgrind --tool=memcheck --leak-check=full --leak-resolution=med --show-reachable=yes --trace-children=yes --track-fds=yes --track-origins=no --time-stamp=yes --num-callers=20 ./server 8080

tiburoncin -o -A 127.0.0.1:9095 -B 127.0.0.1:8080 -o

./client 127.0.0.1 9095

./client 127.0.0.2 8080

./client 127.0.0.3 8080
```

## PRE-COMMIT

```shell
pre-commit run --all-files
```

## TEST

```shell
./test_consola_cliente
./protocol_server_test
```
