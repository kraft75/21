//
//  main.cpp
//  TwentyOne
//
//  Created by MacJay on 12.02.24.
//

#include <iostream>
#include "TwentyOne.hpp"

int main(int argc, const char * argv[]) {
    /*
//    Anzahl Karten, die entfernt werden
    int cards = 0;
    
//    Kartenstapel
    CardDeck decks;
    
    std::cout << std::endl;
//    Karten mischen
    decks.shuffle();
    
    std::cout << "Wieviel Karten sollen entfernt werden?\n";
    std::cin >> cards;
    
//    Anzeige der entnommenen Karten
    for (int i = 0; i < cards; ++i) {
        std::unique_ptr<PlayingCard> c = decks.getNextCard();
        std::cout << c << std::endl;
//        c.reset();
    }
    */
    TwentyOne game;
    game.play();
    
    return 0;
}
