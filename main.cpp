#include "tablero.h"

int main() {
    int opcion = menu();
    while (opcion != 0 && opcion != 1 && opcion != 2) {
        std::cout << "Opcion incorrecta\nSeleccione una opcion:";
        std::cin >> opcion;
    }

    int dimensiones = 0;

    if (opcion == 1) {
        dimensiones = 6;
    }
    else if (opcion == 2) {
        dimensiones = 10;
    }
    else {
        std::cout << "Hasta luego! ^_^";
        return 0;
    }

    Tablero juego(dimensiones);
    int stop = 0;

    while (!juego.lleno()) {
        juego.imprimir_tablero();
        std::cin >> stop; // esto es para que no imprima mil tableros por segundo XD

        // TODO: Sistema de turnos (A / B)
        // TODO: Input de linea a dibujar
        // TODO: Verificación de movimiento a dibujar (NO DIAGONALES)
        // TODO: Dibujar las lineas (vertical / horizontal)
    }

    return 1;
}