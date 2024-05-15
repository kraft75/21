//
//  TwentyOne.hpp
//  TwentyOne
//
//  Created by MacJay on 16.02.24.
//

#ifndef TwentyOne_hpp
#define TwentyOne_hpp

#include <stdio.h>
#include "CardDeck.hpp"
#include "TwentyOneBox.hpp"

class TwentyOne {
    int oneMore;
    CardDeck deck;
    TwentyOneBox boxComp;
    TwentyOneBox boxPlayer;
//    Das eigentliche Spiel
    void playGame();
    void selct();
    
public:
    /*
        Konstruktor: erstellt leere Boxes für den Dealer und den/die
        Spieler*in und erstellt ein vollständiges gemischtes Kartendeck.
     */
    explicit TwentyOne() noexcept;
    ~TwentyOne() = default;
    
//    Spiel 21 wird gestartet
    void play() noexcept;
};

#endif /* TwentyOne_hpp */
