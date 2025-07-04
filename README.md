# Proyecto Final - 2025-1: Juego Dots and Boxes

Nuestro proyecto consiste en recrear el juego [Timbiriche](https://es.wikipedia.org/wiki/Timbiriche_(juego)) (también conocido como Dots and Boxes) en C++.

## Características principales

El usuario puede escoger entre 2 tableros, uno de 6 x 6 y de 10 x 10.  
Este es impreso en la consola al inicio de cada turno, y es llenado según el input del jugador (A o B).  
  
Para crear el tablero, hemos implementado la clase `Tablero`, la cual tiene los siguientes atributos:  
1. `dimensiones`: Un valor entero con las dimensiones del tablero (6 o 10).  
2. `lineas_horizontal`: Un vector de vectores de booleanos, representando las lineas horizontales existentes en el tablero.  
3. `lineas_vertical`: Un vector de vectores de booleanos, representando las lineas verticales existentes en el tablero.
4. `casillas`: Un vector de vectores de caracteres, representando los caracteres (' ', 'A' o 'B') existentes en el tablero.
5. `casillas_llenas`: Un valor entero que contea cuantas casillas del tablero están ocupadas en total.  
