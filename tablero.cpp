//
// Created by aribo on 7/3/2025.
//

#include "tablero.h"

Tablero::Tablero(int n) {
    dimensiones = n;
    lineas_horizontal = vec_lineas(n, std::vector<bool>(n-1, false));
    lineas_vertical = vec_lineas(n-1, std::vector<bool>(n, false));
    casillas = vec_casillas(n-1, std::vector<char>(n-1, ' '));
    casillas_llenas = 0;
}

int menu() {
    int opcion = 0;
    std::cout << "Dots & Boxes\n =-=-=-=-=-=-\n"
                 "1. Tablero 6 x 6\n2. Tablero 10 x 10\n"
                 "0. Salir\nSeleccione una opcion:";
    std::cin >> opcion;
    return opcion;
}

void imprimir_horizontal(const std::vector<bool> &v_lineas) {
    std::cout << "+";
    for (const auto &linea : v_lineas) {
        std::cout << (linea ? "---" : "   ") << "+";
    }
    std::cout << "\n";
}

void imprimir_vertical(const std::vector<bool> &v_lineas, const std::vector<char> &casillas){
    for (int i = 0; i < v_lineas.size(); i++) {
        std::cout << (v_lineas[i] ? "|" : " ");
        if (i < casillas.size()) {
            std::cout << " " << casillas[i] << " ";
        }
    }
    std::cout << "\n";
}

void Tablero::imprimir_tablero() const {
    // Encabezado de columnas
    std::cout << " ";
    for (int i = 0; i < dimensiones; i++) {
        std::cout << "  " << i+1 << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < dimensiones; i++) {
        // Número de fila con alineación fija
        std::cout << std::setw(2) << i+1;

        // Línea horizontal
        std::cout << " ";
        imprimir_horizontal(lineas_horizontal[i]);

        // Línea vertical (excepto última fila)
        if (i < dimensiones - 1) {
            std::cout << "   ";
            imprimir_vertical(lineas_vertical[i], casillas[i]);
        }
    }
}

bool Tablero::disponibilidad(int x, int y, bool horizontal) {
    if (x < 1 || y < 1 || x > dimensiones || y > dimensiones)
        return false;

    if (horizontal) {
        if (y-1 >= lineas_horizontal[x-1].size())
            return false;
        return !lineas_horizontal[x-1][y-1];
    } else {
        if (x-1 >= lineas_vertical.size())
            return false;
        return !lineas_vertical[x-1][y-1];
    }
}

bool Tablero::comprobar_caja(int i, int j) {
    if (i < 0 || i >= dimensiones-1 || j < 0 || j >= dimensiones-1)
        return false;

    return lineas_horizontal[i][j] &&
           lineas_horizontal[i+1][j] &&
           lineas_vertical[i][j] &&
           lineas_vertical[i][j+1];
}

int Tablero::dibujar_linea(int x, int y, bool horizontal, char jugador) {
    int completadas = 0;
    x--;
    y--;

    if (horizontal) {
        lineas_horizontal[x][y] = true;
    } else {
        lineas_vertical[x][y] = true;
    }

    // Llenar casilla si hay todas las lineas
    if (horizontal) {
        if (x > 0 && comprobar_caja(x-1, y)) {
            casillas[x-1][y] = jugador;
            casillas_llenas++;
            completadas++;
        }
        if (x < dimensiones-1 && comprobar_caja(x, y)) {
            casillas[x][y] = jugador;
            casillas_llenas++;
            completadas++;
        }
    } else {
        if (y > 0 && comprobar_caja(x, y-1)) {
            casillas[x][y-1] = jugador;
            casillas_llenas++;
            completadas++;
        }
        if (y < dimensiones-1 && comprobar_caja(x, y)) {
            casillas[x][y] = jugador;
            casillas_llenas++;
            completadas++;
        }
    }

    return completadas;
}

void cambiar_jugador(char &c) {
    if (c == 'A') {
        c = 'B';
    } else {
        c = 'A';
    }
}

bool verificar_punto(int x, int y, int dimensiones) {
    return (x >= 1 && x <= dimensiones) &&
            (y >= 1 && y <= dimensiones);
}

void intercambio(int &x, int &y) {
    const int temp = x;
    x = y;
    y = temp;
}
