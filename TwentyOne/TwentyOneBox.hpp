//
//  TwentyOneBox.hpp
//  TwentyOne

//  Die jeweiligen Karten für Dealer und Spieler*in werden in sogenannten Boxes verwaltet.
//  Damit werden auch die Punkte der einzelnen Karten bestimmt und deren Summe ermittelt. Dazu ist die Klasse TwentyOneBox zu erstellen. Sie besitzt die folgende Schnittstelle:


//  Created by MacJay on 16.02.24.
//

#ifndef TwentyOneBox_hpp
#define TwentyOneBox_hpp

#include <stdio.h>
#include "CardDeck.hpp"

class TwentyOneBox {
    size_t max = 0;
    std::vector<std::unique_ptr<PlayingCard>> box;
public:
//    leere Box für die Aufnahme von Max-Karten
    TwentyOneBox(const size_t max) noexcept;
    ~TwentyOneBox() = default;
    
    /*fügt eine neue Karte in die Box ein und gibt true zurück;
     gibt false zurück, wenn das Einfügen nicht möglich war.
     */
    const bool insert(std::unique_ptr<PlayingCard>&& card) noexcept;
//     Löscht alle Karten
    void clear();
    
    /*
        Berrechnet die Summe aller Kartenwerte in der Box
        Ass – 11 Punkte; König, Dame, Bube – 10 Punkte;
        2 bis 10 – Punkte gemäß ihrem Kartenwert
     */
    [[nodiscard]] const size_t getBoxValue() const noexcept;
    
    /*
        String-Darstellung aller Karten – die Karten sind durch
        zwei Leerzeichen voneinander getrennt.
     */
    [[nodiscard]] std::ostream& print(std::ostream& os) const noexcept;
    friend std::ostream& operator<<(std::ostream& os, const TwentyOneBox& box) noexcept;
    
};

#endif /* TwentyOneBox_hpp */
