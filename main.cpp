#include "tablero.h"

int main() {
    int opcion = menu();
    while (opcion != 0 && opcion != 1 && opcion != 2) {
        std::cout << "Opcion incorrecta\nSeleccione una opcion:";
        std::cin >> opcion;
    }

    if (opcion == 0) {
        std::cout << "Hasta luego! ^_^";
        return 0;
    }

    int dimensiones = opcion == 1? 6:10;

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