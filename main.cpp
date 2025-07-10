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
    char jugador = ' ';

    int xi = 0;
    int yi = 0;
    int xf = 0;
    int yf = 0;

    int dx = 0;
    int dy = 0;
    bool mov_real = false;
    bool punto_real = false;

    while (!juego.lleno()) {
        juego.imprimir_tablero();
        cambiar_jugador(jugador);
        std::cout << "\n// Turno de jugador " << jugador << " //\n";

        do {
            std::cout << "Ingrese origen (x y): ";
            std::cin >> xi >> yi;
            std::cout << "Ingrese destino (x y): ";
            std::cin >> xf >> yf;

            if (xf - xi == -1 || yf - yi == -1) {
                intercambio(xi, xf);
                intercambio(yi, yf);
            }

            dx = xf - xi;
            dy = yf - yi;

            mov_real = ((dx == 1 && dy == 0) || (dy == 1 && dx == 0));
            punto_real = verificar_punto(xi, yi) && verificar_punto(xf, yf);
        }
        while (!(mov_real && punto_real));

        // TODO: AÑADIR NUMEROS EN PARTE VERTICAL IZQUIERDA DEL TABLERO
        // TODO: Dibujar las lineas (vertical / horizontal)
        // TODO: Hacerlo con un método de juego (despues de verificación esa)
        // TODO: Verificación de línea disponible

        // TODO: vs. PC
    }

    return 1;
}