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
    std::cout << "+ ";
    for (const auto &linea:v_lineas) {
        if (linea) {
            std::cout << "-";
        }
        else {
            std::cout << " ";
        }

        std::cout << " + ";
    }
    std::cout << "\n";
}

void imprimir_vertical(const std::vector<bool> &v_lineas, const std::vector<char> &casillas) {
    for (int i = 0; i < v_lineas.size(); i++) {
        if (v_lineas[i]) {
            std::cout << "|";
        }
        else {
            std::cout << " ";
        }

        if (i != v_lineas.size() - 1) {
            std::cout << " " << casillas[i] << " ";
        }
    }
    std::cout << "\n";
}

void Tablero::imprimir_tablero() const {
    std::cout << "   ";
    for (int i = 0; i < dimensiones; i++) {
        std::cout << i+1 << "   ";
    }
    std::cout << "\n";
    for (int i = 0; i < dimensiones-1; i++) {
        std::cout << i + 1;
        if (i < 10) {
            std::cout << " ";
        }
        std::cout << " ";
        imprimir_horizontal(lineas_horizontal[i]);
        if (i < 10) {
            std::cout << " ";
        }
        std::cout << "  ";
        imprimir_vertical(lineas_vertical[i], casillas[i]);
    }
    std::cout << dimensiones << " ";
    imprimir_horizontal(lineas_horizontal[dimensiones-1]);
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
    } else if (y < 1 || y > 6) {
        return false;
    }
    return true;
}

void intercambio(int &x, int &y) {
    const int temp = x;
    x = y;
    y = temp;
}
