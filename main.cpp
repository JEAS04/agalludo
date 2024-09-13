#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int lanzarDado() {
    return rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6
}

int main() {
    srand(time(0)); // Inicializa la semilla para generar números aleatorios

    int puntosJugador1 = 0;
    int puntosJugador2 = 0;
    int ronda = 1;

    while (puntosJugador1 < 30 && puntosJugador2 < 30) {
        cout << "Ronda " << ronda << endl;

        // Turno del jugador 1
        int puntosTurnoJugador1 = 0;
        bool jugador1Retirado = false;
        while (!jugador1Retirado) {
            cout << "Jugador 1, turno " << ronda << ". ¿Desea lanzar el dado? (s/n)" << endl;
            char respuesta;
            cin >> respuesta;

            if (respuesta == 's' || respuesta == 'S') {
                int dado = lanzarDado();
                cout << "Ha sacado un " << dado << endl;

                if (dado == 6) {
                    cout << "Ha sacado un 6, pierde todos los puntos de esta ronda." << endl;
                    puntosTurnoJugador1 = 0;
                    jugador1Retirado = true;
                } else {
                    puntosTurnoJugador1 += dado;
                    cout << "Puntos actuales: " << puntosTurnoJugador1 << endl;
                }
            } else {
                jugador1Retirado = true;
            }
        }

        puntosJugador1 += puntosTurnoJugador1;

        // Turno del jugador 2
        int puntosTurnoJugador2 = 0;
        bool jugador2Retirado = false;
        while (!jugador2Retirado) {
            cout << "Jugador 2, turno " << ronda << ". ¿Desea lanzar el dado? (s/n)" << endl;
            char respuesta;
            cin >> respuesta;

            if (respuesta == 's' || respuesta == 'S') {
                int dado = lanzarDado();
                cout << "Ha sacado un " << dado << endl;

                if (dado == 6) {
                    cout << "Ha sacado un 6, pierde todos los puntos de esta ronda." << endl;
                    puntosTurnoJugador2 = 0;
                    jugador2Retirado = true;
                } else {
                    puntosTurnoJugador2 += dado;
                    cout << "Puntos actuales: " << puntosTurnoJugador2 << endl;
                }
            } else {
                jugador2Retirado = true;
            }
        }

        puntosJugador2 += puntosTurnoJugador2;

        cout << "Puntos actuales: Jugador 1 - " << puntosJugador1 << ", Jugador 2 - " << puntosJugador2 << endl;

        ronda++;
    }

    if (puntosJugador1 >= 30) {
        cout << "El jugador 1 ha ganado con " << puntosJugador1 << " puntos." << endl;
    } else {
        cout << "El jugador 2 ha ganado con " << puntosJugador2 << " puntos." << endl;
    }

    return 0;
}
