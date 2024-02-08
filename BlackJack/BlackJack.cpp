#include <iostream>
#include <ctime>
#include <cstdlib>



int generarValorCarta() {
    return rand() % 10 + 1;
}




int main() {
    srand(time(0));
        
    std::cout << 
        ".------.            _     _            _    _            _    \n"
        "|A_  _ |.          | |   | |          | |  (_)          | |   \n"
        "|( \\/ ).-----.     | |__ | | __ _  ___| | ___  __ _  ___| | __\n"
        "| \\  /|K /\\  |     | '_ \\| |/ _` |/ __| |/ / |/ _` |/ __| |/ /\n"
        "|  \\/ | /  \\ |     | |_) | | (_| | (__|   <| | (_| | (__|   < \n"
        "`-----| \\  / |     |_.__/|_|\\__,_|\\___|_|\\_\\ |\\__,_|\\___|_|\\_\\\n"
        "      |  \\/ K|                            _/ |                \n"
        "      `------'                           |__/           \n";

    int cartaJugador1 = generarValorCarta();
    int cartaJugador2 = generarValorCarta();
    int cartaCroupier = generarValorCarta();

    int puntuacionJugador = cartaJugador1 + cartaJugador2;
    int puntuacionCroupier = cartaCroupier;

    std::cout << "Tienes " << puntuacionJugador << " puntos.\n";

    while (puntuacionJugador < 21) {
        char decision;
        std::cout << "Quieres otra carta? (s/n): ";
        std::cin >> decision;
    
        if (decision == 's') {
            int nuevaCarta = generarValorCarta();
            puntuacionJugador += nuevaCarta;
            std::cout << "Has obtenido un " << nuevaCarta << ". Ahora tienes " << puntuacionJugador << " puntos.\n";
        }
        else {
            break;
        }
    }

    if (puntuacionJugador > 21) {
        std::cout << "Te has pasado de 21. El croupier gana.\n";
    }
    else {
        while (puntuacionCroupier < puntuacionJugador && puntuacionCroupier < 21) {
            int nuevaCarta = generarValorCarta();
            puntuacionCroupier += nuevaCarta;
        }

        if (puntuacionCroupier > 21) {
            std::cout << "El croupier se ha pasado de 21. Tú ganas.\n";
        }
        else if (puntuacionCroupier == puntuacionJugador) {
            std::cout << "Empate. Los dos tienen " << puntuacionJugador << " puntos.\n";
        }
        else {
            std::cout << "El croupier tiene " << puntuacionCroupier << " puntos y gana.\n";
        }
    }

    return 0;
}
