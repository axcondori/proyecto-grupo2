//
// Created by aribo on 7/3/2025.
//

#include "tablero.h"

Tablero::Tablero(int n) {
    dimensiones = n;
    lineas_horizontal = vec_tablero(n, std::vector<bool>(n-1));
    lineas_vertical = vec_tablero(n-1, std::vector<bool>(n));
    casillas = vec_casillas(n, std::vector<char>(n, ' '));
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
        std::cout << (linea ? " - " : "   ") << "+";
    }
    std::cout << "\n";
}

void imprimir_vertical(const std::vector<bool> &v_lineas, const std::vector<char> &casillas) {
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

void cambiar_jugador(char &c) {
    if (c == 'A') {
        c = 'B';
    } else {
        c = 'A';
    }
}

bool verificar_punto(int x, int y) {
    if (x < 0 || x > 6) {
        return false;
    }
    if (y < 1 || y > 6) {
        return false;
    }
    return true;
}

void intercambio(int &x, int &y) {
    const int temp = x;
    x = y;
    y = temp;
}
