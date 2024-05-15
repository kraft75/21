//
//  TwentyOneBox.cpp
//  TwentyOne
//
//  Created by MacJay on 16.02.24.
//

#include "TwentyOneBox.hpp"

TwentyOneBox::TwentyOneBox(const size_t m) noexcept : max(m) {
    box.resize(max);
}
//------------------------------------------------------------------------------------
const bool TwentyOneBox::insert(std::unique_ptr<PlayingCard>&& card) noexcept {
    for (size_t i = 0; i < box.size(); ++i) {
        if (box[i] == nullptr) {
            box[i] = std::move(card);
            return true;
        }
    }
    return false;
}
//------------------------------------------------------------------------------------
void TwentyOneBox::clear() {
    box.clear();
}
//------------------------------------------------------------------------------------

[[nodiscard]] const size_t TwentyOneBox::getBoxValue() const noexcept {
    size_t sum = 0;
    
    for (size_t i = 0; i < box.size(); ++i) {
        if (box[i] == nullptr) {
            break;
        }
        
        size_t cardNumber = box[i]->getCardNumber();
        switch (cardNumber) {
            case 1:
                cardNumber = 11;
                sum += cardNumber;
                break;
            case 11:
            case 12:
            case 13:
                cardNumber = 10;
                sum += cardNumber;
                break;
            default:
                sum += cardNumber;
                break;
        }
    }
    
    return sum;
}
//------------------------------------------------------------------------------------

[[nodiscard]] std::ostream& TwentyOneBox::print(std::ostream& os) const noexcept {
    for (size_t i = 0; i < box.size(); ++i) {
        if (box[i] == nullptr) {
            break;
        }
        os << " " << box[i];
    }
//    os << std::endl;
    
    return os;
}

std::ostream& operator<<(std::ostream& os, const TwentyOneBox& box) noexcept {
    return box.print(os);
}
