//
// Created by aribo on 7/3/2025.
//

#include "tablero.h"

Tablero::Tablero(int n) {
    dimensiones = n;
    lineas_horizontal = crear_lineas(n, n-1);
    lineas_vertical = crear_lineas(n-1, n);
    casillas = crear_casillas(n-1);
}

int menu() {
    int opcion = 0;
    std::cout << "Dots & Boxes\n =-=-=-=-=-=-\n"
                 "1. Tablero 6 x 6\n2. Tablero 10 x 10\n"
                 "0. Salir\nSeleccione una opcion:";
    std::cin >> opcion;
    return opcion;
}

vec_tablero crear_lineas(int n, int a) {
    vec_tablero lineas;
    std::vector<bool> casillas(a);

    for (int i = 0; i < n; i++) {
        lineas.emplace_back(casillas);
    }
    return lineas;
}

vec_casillas crear_casillas(int n) {
    vec_casillas lineas;
    std::vector<char> casillas(n, ' ');

    for (int i = 0; i < n; i++) {
        lineas.emplace_back(casillas);
    }
    return lineas;
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
    for (int i = 0; i < dimensiones; i++) {
        std::cout << i+1 << "   ";
    }
    std::cout << "\n";
    for (int i = 0; i < dimensiones-1; i++) {
        imprimir_horizontal(lineas_horizontal[i]);
        imprimir_vertical(lineas_vertical[i], casillas[i]);
    }
    imprimir_horizontal(lineas_horizontal[dimensiones-1]);
}

void cambiar_jugador(char &c) {
    if (c == 'A') {
        c = 'B';
    } else {
        c = 'A';
    }
}