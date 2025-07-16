//
// Created by aribo on 7/3/2025.
//

#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<bool>> vec_lineas;
typedef std::vector<std::vector<char>> vec_casillas;


class Tablero {
private:
    int dimensiones = 0;
    vec_lineas lineas_horizontal;
    vec_lineas lineas_vertical;
    vec_casillas casillas;
    int casillas_llenas = 0;
public:
    Tablero(int n);

    bool lleno() {
        return casillas_llenas == (dimensiones-1)*(dimensiones-1);
    }

    void imprimir_tablero() const;

    bool disponibilidad(int x, int y, bool horizontal);
    bool comprobar_caja(int i, int j);
    int dibujar_linea(int x, int y, bool horizontal, char jugador);
};

// Creación de tablero
int menu();

// Impresión de tablero
void imprimir_horizontal(const std::vector<bool> &v_lineas);
void imprimir_vertical(const std::vector<bool>& v_lineas, const std::vector<char>& casillas);

// Sistema de turnos
void cambiar_jugador(char &c);

// Verificación de input
bool verificar_punto(int x, int y, int dimensiones);
void intercambio(int &x, int&y);

#endif //TABLERO_H