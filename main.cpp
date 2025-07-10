#include "tablero.h"
#include <cmath>

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
    char jugador = ' ';

    int xi = 0;
    int yi = 0;
    int xf = 0;
    int yf = 0;

    int dx = 0;
    int dy = 0;

    while (!juego.lleno()) {
        juego.imprimir_tablero();
        cambiar_jugador(jugador);
        std::cout << "// Turno de jugador " << jugador << " //\n";

        do {
            std::cout << "Ingrese origen (x y): ";
            std::cin >> xi >> yi;
            std::cout << "Ingrese destino (x y): ";
            std::cin >> xf >> yf;

            dx = xf - xi;
            dy = yf - yi;
        }
        while (!((abs(dx) == 1 && dy == 0) || (abs(dy) == 1 && dx == 0)));

        // TODO: Dibujar las lineas (vertical / horizontal)
        // TODO: Hacerlo con un método de juego (despues de verificación esa)
        // TODO: Conversion cuando movimiento es negativo (dx < 0 || dy < 0)
        // TODO: Verificación de línea vacía (despues de conver. mov)

        // TODO: vs. PC
    }

    return 1;
}