//
//  CardDeck.cpp
//  TwentyOne
//
//  Created by MacJay on 14.02.24.
//

#include "CardDeck.hpp"

CardDeck::CardDeck() noexcept {
    initializeDeck();
}
//----------------------------------------------------------------------
void CardDeck::initializeDeck() {
    const std::vector<std::string> colors = {"Herz", "Pik", "Karo", "Kreuz"};
    const size_t numCardValues = 13;
    
    for (const auto& color : colors) {
        for (size_t i = 1; i <= numCardValues; ++i) {
            deck.emplace_back(std::make_unique<PlayingCard>(color, i));
//       alternativ, aber unsicherer: deck.emplace_back(new PlayingCard(color, i));
        }
    }
}
//----------------------------------------------------------------------

void CardDeck::shuffle() noexcept {
    
    std::uniform_int_distribution<size_t> mix(0, 51);
    
    for (size_t i = 0; i < deck.size(); ++i) {
        size_t j = mix(engine);
        std::swap(deck[i], deck[j]);
    }
    
//    Zum Testen
//    for (const auto& d : deck) {
//        std::cout << d << "\n";
//    }
}
//----------------------------------------------------------------------

[[nodiscard]] std::unique_ptr<PlayingCard> CardDeck::getNextCard() noexcept {
    if (deck.empty()) {
        return nullptr;
    }
    
    std::unique_ptr<PlayingCard> first = std::move(deck.front());
    deck.erase(deck.begin());
    
    return first;
}
