# Proyecto Final - 2025-1: Juego Dots and Boxes

Nuestro proyecto consiste en recrear el juego [Timbiriche](https://es.wikipedia.org/wiki/Timbiriche_(juego)) (también conocido como Dots and Boxes) en C++.

## Características principales

Para crear el tablero, hemos implementado la clase `Tablero`, la cual tiene los siguientes atributos:  
1. `dimensiones`: Un valor entero con las dimensiones del tablero (6 o 10).  
2. `lineas_horizontal`: Un vector de vectores de booleanos, representando las lineas horizontales existentes en el tablero.  
3. `lineas_vertical`: Un vector de vectores de booleanos, representando las lineas verticales existentes en el tablero.
4. `casillas`: Un vector de vectores de caracteres, representando los caracteres (' ', 'A' o 'B') existentes en el tablero.
5. `casillas_llenas`: Un valor entero que contea cuantas casillas del tablero están ocupadas en total.  

## Requisitos de instalación

**Compilador de C++:** `Versión C++ 17` o superior  
**Administrador de código fuente:** `CMake versión 3.10` o superior  
**Sistema Operativo:** `MS Windows (7 a más), OS Mac o Linux`

## Consideraciones del proyecto
1. El juego cuenta con un menú y un tablero.
2. El juego se realiza entre dos jugadores externos (A / B).
3. Dos tamaños de tablero (6 x 6) y (10 x 10).

**Compilador de C++:** `Versión C++ 17` o superior  

## Guía de instalación
1. Si tienes MinGW ([preferible](https://www.youtube.com/watch?v=GxFiUEO_3zM)):
    1. Descargar el proyecto como un .ZIP
    2. Extraer el .ZIP en un folder de su preferencia.
    3. Ejecutar `timbiriche.exe` (permitir que la aplicación se ejecute).  
       
2. Si no tienes MinGW:
    1. Importar el proyecto en un entorno como CLion.
    2. Ejecutar `main.cpp`.

## Instrucciones o reglas de uso

El usuario es presentado con las siguientes 3 opciones:
1. Tablero de `6 x 6`
2. Tablero de `10 x 10`
3. Salir del juego

Tras escoger una de las primeras dos opciones, el tablero es impreso en la consola al inicio de cada turno, y es llenado según el input del jugador (A o B).
Al llenarse todas las casillas, el juego imprime el ganador.

## Diagrama de clases
<img width="640" height="720" alt="Diagrama en blanco (4)" src="https://github.com/user-attachments/assets/0f642652-4b6a-4f3e-9e46-77228e57b7d1" />

## Link a video de presentación


## Autores

Ariana Ximena Condori Escobedo  
Jose Carlos Moscoso Saldamando  
Maricielo Briggite Oré Reyes  
Yadhira Mayza Lariena Vasquez  
Yelsie Sasha Pintado Perea

## Bibliografía
1] Wikipedia, “Dots and boxes.” https://en.wikipedia.org/wiki/Dots_and_Boxes, 2022.
