//
// Created by aribo on 7/3/2025.
//

#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>

typedef std::vector<std::vector<bool>> vec_tablero;
typedef std::vector<std::vector<char>> vec_casillas;


class Tablero {
private:
    int dimensiones = 0;
    vec_tablero lineas_horizontal;
    vec_tablero lineas_vertical;
    vec_casillas casillas;
    int casillas_llenas = 0;
public:
    Tablero(int n);

    bool lleno() {
        return casillas_llenas == (dimensiones-1)*(dimensiones-1);
    }

    void imprimir_tablero() const;
};

// Creación de tablero
int menu();
vec_tablero crear_lineas(int n, int a);
vec_casillas crear_casillas(int n);

// Impresión de tablero
void imprimir_horizontal(const std::vector<int> &v_lineas);
void imprimir_vertical(const std::vector<int> &v_lineas);

// Sistema de turnos
void cambiar_jugador(char &c);

bool verificar_punto(int x, int y);
void intercambio(int &x, int&y);

#endif //TABLERO_H