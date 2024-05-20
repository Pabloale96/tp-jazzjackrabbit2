# Diagrama de clases
![img](https://www.plantuml.com/plantuml/png/fLZ1Rjus3BxxARGUWcrP3hiCGnC4BOfXmB02MzkxeCZS7wMMv5AortPeddss92fcB1VTcaiiagBuVQGewNyMei8usQ7x9jw21Q41fm6Kk_1J78o3xjRq8C2EyODGCQAvcIA4BDK6zG1TDohzLfr0F7an671HMcNS4o7-wOJGWmf1l5m4QRZydQ_QRxzR1f-wJxkvR5eMqSIB4FkdJqD4uqxYreVeb0LIRNK1S3RQ-ABx0ttqsW_5srY6NkeaA5OgAgrmYIiF1u27WR4Z6cjG8eHnWX3LeYfeibSoFR-RJWhhw9wqExGyA2YmmKrMl36ZVwwryQuYVvw2Iqw4214d7SKhYgLQJSR57t-IKO03Qqu-oDdCFXngxGGOIS_OZKi84cPmqQT5AI4KjIzXrwLVU_qMeWZfNo6MSdFZ_I3-Lc4H-m0z4SSPg9I1cur2gH81acVbF00QDPYFrU1WMhNhLRL0qEQ6vv2or0Y5PqjxQnUt6LvWDLgGPoBEquZ0d2_Hm5X70LolXe6627gcONErU8kWUhROcoHA0igOYjuQVRMIV2taMu1HukISSQVBGoiJf1hC39TT3YMxfS1IHw31dJVkGU57-YON5SrKpUx9tH6mTnDCm73zkKeOh6HpzUO7yU9Ql2j8j7SXYia5StBG2-EYiEgz3EOZP8jSQhdCjkZj5E6ziF7zLhXuwqrSgsLMQDJD0681vNoKVqt3y6MMgIqIYma4aH3nWnodSCl63_HjLHjn2hr1t6l06V2mhxAssfpAPcKHqVryhL7LUnIAlWgWR9TZeyv6EIRTOMDhhCjLd-yTr2NudDrcpliTmdR7XqEhgkYXsZCjwoNxHk5l8ZX0kGfxBsiZxM6GDfnsTfiskhFHWAXGSjJxbdJ8CwMDKrobIROZDoHl1trXqwDbBOMo3tvL5dxtVXIdvKCEorUfaRfWen4Cnev68O4BwyQN4T0Qfz3lp0PJkUQzvfujqhms09amDXxfY1FExUP2aEcvx5h7Lf6cJNwLpyfRXT3BCU9LzlJR12V_4bnGTt1zBRAtDUcFI3nBBAua5aMU_XfS3oX2-iSqhq23MKF5ya4jvn70PWStQtsglabiQpwdTniQutQhQF9wzZbYpxw6sJD6ROQo3OULOXiHKSenSTLNeshdd2BcYxNEKMxHW4BE6GWI9j4XhvlRtbAgUOVAzNnMhW-i-5vwPw97OVF_l4rb3_aO3x9PvWaj8QM829Ww8PmKPWUR-OjJwXMr0JLuONV2ynlqgjSgH7YGzHwjUR3mYFznDRP9QlZj1Ep8P_UO6NJqUFLBFYgkw-Lxomsj17UWfyZkjlbWNsLbOYLXik1MkOc0YXrWzVZHoiNy16XfwFhFS3OmiYfWO9ace-ONhiiz4L--ox-_5ddEcgZzXcUBDolhk49uJLG2cCj39aeg6HD5bYHqTAp45mBObNMJCC9Ifl_lX2CiYvdT50XHfVmVOM6CCq1xzQgaP-JFCefSemIm_V8yqbBf4VxzQWIXlhmjoNaXyvr2KXx5aNQt0TfXD8bxuTT6oOkWoEW-FXkCanh4x4qlQ6lJMgIyBvFAGfqWP_d5NtypQJX9OR6dehYwk7XqXhKDwadPTVnbcmpuQnW-Pv9zTOzc99FytJtycC4cUd9UVyLeg_D_SaY_BNMPdIpE17OTZsaFTVluR111NRv58dVTic1LqJBe-BWWOhUlRXDGsu1YR2aPlgO1Hz4qwVPR8DdHmXrhWLML0kE6h9To5G-KQLYnCXMFD2zD0soKA5Cohqn7NzkaThiqvw9x1gwVxF0l)


Codigo PlantUML que genero ese diagrama:

```
@startuml
!theme cerulean-outline
hide empty attributes
hide circle

package "Client_main"  {
  class Main {
     +main()
  }
}

package "Client"  {
  class Client {
     -std::string hostname
     -sstd::string servicio
     -ProtocolClient protocolo_client
     -atacar()
     -leer()
     -imprimir_respuesta()

     +Client()
     +jugar()
     +~Client()
  }
}

package "ProtocolCliente"  {
  enum TipoAccion {
     -Atacar
  }
  struct Respuesta {
     -uint16_t enemigos_vivos
     -uint16_t enemigos_muertos
     -std::string tipo_evento
  }
  class ProtocoloCliente {
     -Socket socket_cliente
     -bool was_closed

     +ProtocolClient()
     +enviar_accion_atacar()
     +serializar_accion()
     +enviar_accion_serializada()
     +recibir_respuesta()
     +~ProtocolClient()
  }
}

package "common_sockets"  {
  class Socket {
    +Socket()
    +accept()
    +sendall()
    +recvall()
  }
}

package "common_thread"  {
  class Thread {
    -std::atomic<bool> _keep_running;
    -std::atomic<bool> _is_alive;

    +Thread()
    +start()
    +join()
    +stop()
    +is_alive()
    +run()
    +~Thread()
  }
}

package "common_queue"  {
  class Queue {
    -std::queue<T, C> q;
    -const unsigned int max_size;
    -bool closed;
    -std::mutex mtx;
    -std::condition_variable is_not_full;
    -std::condition_variable is_not_empty;

    +Queue()
    +try_push()
    +try_pop()
    +push()
    +pop()
    +close()
  }
}

package "Server_main"  {
  class Main {
    +main()
  }
}

package "Server"  {
  class Server {
    -Aceptador aceptador

    +Server()
    +jugar()
    +~Server()
  }
}

package "ProtocolServer"  {
  class ProtocolServer {
     -Socket socket_cliente

     +ProtocolServer()
     +recibir_acciones_serializadas()
     +recibir_acciones()
     +deserializar_acciones()
     +enviar_respuesta()
     +obtener_estado_enemigos_del_msg()
     +obtener_tipo_evento_del_msg()
     +cerrar_socket_cliente()
     +~ProtocolServer()
  }
}

package "Aceptador"  {
  class Aceptador {
    -Socket socket_server
    -std::atomic<bool> was_closed_aceptador;
    -GameLoop game_loop

    +Aceptador()
    +run()
    +limpiar_clientes_que_terminaron()
    +limpiar_lista()
    +stop()
    +~Aceptador()
  }
}

package "ClienteAceptado"  {
  class ClienteAceptado {
    -ProtocolServer protocolo_server;
    -bool was_closed;
    -Queue<std::shared_ptr<ServerJuegoMensaje>> server_msg;
    -GameLoop& gameloop;
    -ServerSender sender;
    -ServerReceiver receiver;

    +ClienteAceptado()
    +start()
    +is_dead()
    +stop()
    +~ClienteAceptado()
  }
}

package "ServerSender"  {
  class ServerSender{
    -ProtocolServer& protocolo_server;
    -bool& was_closed;
    -Queue<std::shared_ptr<ServerJuegoMensaje>>& server_msg;

    +ServerSender()
    +run()
  }
}

package "ServerReceiver"  {
  class ServerReceiver{
    -ProtocolServer& protocolo_server;
    -bool& was_closed;
    -GameLoop& gameloop;

    +ServerReceiver()
    +run()
    +~ServerReceiver()
  }
}

package "GameLoop"  {
  class GameLoop {
    -Queue<std::shared_ptr<std::string>> client_commands;
    -ServerMonitor monitor_lista_de_queues_server_msg;
    -Game game;

    +GameLoop()
    +agregar_queue_server_msg_de_cliente_aceptado()
    +run()
    +atacar()
    +broadcastear()
    +dormir()
    +borrar_queue_server_msg_de_cliente_aceptado()
    +stop()
    +~GameLoop()
  }
}

package "Game"  {
  class Game {
    -std::vector<Enemigo> enemigos;

    +Game()
    +ejecutar_accion()
    +matar_enemigo()
    +aumentar_iteraciones()
    +obtener_cant_vivos()
    +obtener_cant_muertos()
    +~Game()
  }
}

package "ServerMonitor"  {
  class ServerMonitor {
    -std::mutex m;
    -std::vector<Queue<std::shared_ptr<ServerJuegoMensaje>>*> vector_de_server_msg;

    +ServerMonitor()
    +agregar_queue()
    +broadcastear()
    +borrar_queue()
    +~ServerMonitor()
  }
}

package "ServerEnemigo"  {
  class Enemigo {
    -bool vivo;
    -unsigned int iteraciones;

    +Enemigo()
    +matar_enemigo()
    +aumentar_iteraciones()
    +revivir_enemigo()
    +esta_vivo()
  }
}

package "ServerJuegoMensaje"  {
  class ServerJuegoMensaje {
    -uint8_t accion;
    -uint16_t enemigos_vivos;
    -uint16_t enemigos_muertos;

    +ServerJuegoMensaje()
    +imprimir_mensaje()
    +obtener_accion()
    +obtener_enemigos_vivos()
    +obtener_enemigos_muertos()
    +~ServerJuegoMensaje()
  }
}

package "ServerComando"  {
  class Comando {
    +virtual void ejecutar()
    +virtual ~Comando()
  }

   class Atacar {
     +void ejecutar()
   }
}

common_thread <-- ServerReceiver
common_thread <-- ServerSender

common_sockets <-- ProtocolCliente
common_sockets <-- ProtocolServer
ProtocolCliente <-- Client
TipoAccion <-- ProtocoloCliente
Respuesta <-- ProtocoloCliente
Client <-- Client_main
Atacar <-- Comando

ProtocolServer <-- ServerSender
common_queue <-- ServerSender

GameLoop <-- ServerReceiver
ProtocolServer <-- ServerReceiver
ServerComando <-- ServerReceiver

ServerReceiver <-- ClienteAceptado
ServerSender <-- ClienteAceptado
GameLoop <-- ClienteAceptado
common_queue <-- ClienteAceptado
ProtocolServer <-- ClienteAceptado

ServerJuegoMensaje <-- GameLoop
ServerEnemigo <-- Game
Game <-- GameLoop
ServerMonitor <-- GameLoop
common_queue <-- GameLoop
common_thread <-- GameLoop
ClienteAceptado <-- Aceptador
common_sockets <-- Aceptador
common_thread <-- Aceptador
Aceptador <-- Server
Server <-- Server_main
@enduml
```