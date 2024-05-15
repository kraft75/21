//
//  PlayingCard.hpp
//  TwentyOne
//
//  Created by MacJay on 12.02.24.
//

#ifndef PlayingCard_hpp
#define PlayingCard_hpp

#include <stdio.h>
#include <string_view>
#include <string>
#include <iostream>
#include <memory>

class PlayingCard {
    size_t picture;
    std::string name;
    
public:
//    Konstruktor, um die Farbe auf name und das Bild auf picture zu setzen
    PlayingCard(std::string_view name = "", const size_t picture = 0) noexcept;
//    Destruktor
    ~PlayingCard() = default;
//    Move-Konstruktor
    PlayingCard(PlayingCard&&) noexcept;
//    Move-Zuweisungsoperator
    PlayingCard& operator=(PlayingCard&&) noexcept;
//    Copy-Konstruktor und Copy-Zuweisungsoperator sind gelöscht
    PlayingCard(const PlayingCard&) = delete;
    PlayingCard& operator=(const PlayingCard&) = delete;
    
//    Rückgabe der Kartenfarbe
    [[nodiscard]] const std::string getColor() const noexcept;
    
//    Rückgabe der Kartennummer
    [[nodiscard]] const size_t getCardNumber() const noexcept;
    
//    String-Darstellung im Format color-picture
    [[nodiscard]] std::ostream& print(std::ostream& os) const noexcept;
    
//    Globale Überladung des <<-Operators
   friend std::ostream& operator<<(std::ostream& os, const std::unique_ptr<PlayingCard>& card) noexcept;
};

#endif /* PlayingCard_hpp */
