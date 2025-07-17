#include "tablero.h"

int main() {
    int opcion = menu();
    while (opcion != 0 && opcion != 1 && opcion != 2) {
        std::cout << "Opcion incorrecta\nSeleccione una opcion:";
        std::cin >> opcion;
    }

    if (opcion == 0) {
        std::cout << "Hasta luego! Gracias por jugar ^_^\n";
        return 0;
    }

    int dimensiones = opcion == 1? 6:10;

    Tablero juego(dimensiones);
    char jugador = 'A';

    int xi = 0;
    int yi = 0;
    int xf = 0;
    int yf = 0;

    int dy = 0;
    int dx = 0;

    bool mov_valido = false;
    bool es_horizontal = false;
    int turnos = 0;

    while (!juego.lleno()) {
        juego.imprimir_tablero();
        std::cout << "\n// Turno del jugador " << jugador << " //\n";

        do {
            mov_valido = true;
            std::cout << "Ingrese origen (fil col): ";
            if (!(std::cin >> yi >> xi)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Entrada invalida. Intente de nuevo.\n";
                mov_valido = false;
                continue;
            }

            std::cout << "Ingrese destino (fil col): ";
            if (!(std::cin >> yf >> xf)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Entrada invalida. Intente de nuevo.\n";
                mov_valido = false;
                continue;
            }

            if (yf < yi || xf < xi) {
                intercambio(yi, yf);
                intercambio(xi, xf);
            }

            dy = yf - yi;
            dx = xf - xi;

            es_horizontal = (dy == 0 && dx == 1);
            bool es_vertical = (dy == 1 && dx == 0);

            if (!(es_horizontal || es_vertical)) {
                std::cout << "Error: Movimiento debe ser horizontal (---) o vertical (|)\n";
                mov_valido = false;
            }

            if (mov_valido && !verificar_punto(yi, xi, dimensiones)) {
                std::cout << "Error: Punto origen (" << yi << "," << xi << ") fuera de rango\n";
                mov_valido = false;
            }

            if (mov_valido && !verificar_punto(yf, xf, dimensiones)) {
                std::cout << "Error: Punto destino (" << yf << "," << xf << ") fuera de rango\n";
                mov_valido = false;
            }

            if (mov_valido) {
                bool disponible = juego.disponibilidad(yi, xi, es_horizontal);
                if (!disponible) {
                    std::cout << "Error: Linea ya ocupada\n";
                    mov_valido = false;
                }
            }
        } while (!mov_valido);

        juego.dibujar_linea(yi, xi, es_horizontal, jugador);
        cambiar_jugador(jugador);
        ++turnos;
    }

    juego.imprimir_tablero();
    char ganador = juego.elegir_ganador();

    if (ganador == 'X') {
        std::cout << "Hubo un empate! :O\n";
    }
    else {
        std::cout << "El ganador es el jugador " << ganador << ", felicidades!!\n";
    }

    return 1;
}