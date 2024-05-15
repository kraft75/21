//
//  PlayingCard.cpp
//  TwentyOne
//
//  Created by MacJay on 12.02.24.
//

#include "PlayingCard.hpp"

PlayingCard::PlayingCard(std::string_view n, const size_t p) noexcept : name(n), picture(p){}
//-------------------------------------------------------------------------------------------
PlayingCard::PlayingCard(PlayingCard&& p) noexcept : name(std::move(p.name)), picture(std::move(p.picture)) {
    
}
//------------------------------------------------------------------------------------------
PlayingCard& PlayingCard::operator=(PlayingCard&& p) noexcept {
    if (this == &p) {
        return *this;
    }
    
    name = std::move(p.name);
    picture = std::move(p.picture);
    
    return *this;
}
//-------------------------------------------------------------------------------------------
[[nodiscard]] const std::string PlayingCard::getColor() const noexcept {
    return name;
}
//-------------------------------------------------------------------------------------------
[[nodiscard]] const size_t PlayingCard::getCardNumber() const noexcept {
    
    return picture;
}
//-------------------------------------------------------------------------------------------
[[nodiscard]] std::ostream& PlayingCard::print(std::ostream& os) const noexcept {
    switch (picture) {
        case 1:
            os  << name << "-" << "As";
        case 11:
            os  << name << "-" << "Bube";
            break;
        case 12:
            os  << name << "-" << "Dame";
            break;
        case 13:
            os  << name << "-" << "König";
            break;
        default:
            os  << name << "-" << picture;
            break;
    }
    
    return os;
}
//-------------------------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const std::unique_ptr<PlayingCard>& card) noexcept {
    return card->print(os);
}
