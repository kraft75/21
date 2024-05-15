//
//  CardDeck.hpp
//  TwentyOne
//
//  Created by MacJay on 14.02.24.
//

#ifndef CardDeck_hpp
#define CardDeck_hpp

#include <stdio.h>
#include "PlayingCard.hpp"
#include <vector>
#include <random>

class CardDeck {
    std::vector<std::unique_ptr<PlayingCard>> deck;
    
    // Generator für Zufallszahlen
    std::random_device rn;
    std::mt19937 engine{rn()};
    
    //    Initialize the deck with 52 cards
        void initializeDeck();
    
public:
//    Konstruktor zur Erstellung eines Decks mit 52 nicht gemischten Karten
    explicit CardDeck() noexcept;
//    Destruktor
    ~CardDeck() = default;
    
//    mischt alle Karten im Stapel (deck).
    void shuffle() noexcept;
    
//    gibt die oberste Karte des Decks zurück; gibt nullptr zurück, wenn das Deck leer ist.
    [[nodiscard]] std::unique_ptr<PlayingCard> getNextCard() noexcept;
    
//    Getter-Methode für den -vector zwecks Code-Tests
     /*const std::vector<std::unique_ptr<PlayingCard>>& getDeck() {
        return deck;
    }*/
    


};

#endif /* CardDeck_hpp */
