//
//  TwentyOne.cpp
//  TwentyOne
//
//  Created by MacJay on 16.02.24.
//

#include "TwentyOne.hpp"

TwentyOne::TwentyOne() noexcept : boxComp(9), boxPlayer(9) {
//    Karten mischen
    deck.shuffle();
}

void TwentyOne::play() noexcept {
    std::cout << "Kartenspiel 21\n";
    std::cout << "Spielabbruch bei der S-Taste\n";
     
    
    std::string select;
    bool game = true;
    while (game) {
        playGame();
        std::cout << std::endl;
        
        std::cout << "Spielabbruch: S-Taste Weiter: W-Taste\n";
        std::cin >> select;
        if (select == "S") {
            game = false;
        } else {
            game = true;
        }
    }
//    playGame();
    
    
}

void TwentyOne::selct() {
    
}

void TwentyOne::playGame() {
    
    std::string continueGame;
    std::string name;
    
    /* 
        Variante abweichend von der Aufgabe, um das Spiel zu wiederholen
        Neue Objekte für Computerkarten
     */
    TwentyOneBox boxComp(9);
    TwentyOneBox boxPlayer(9);
    CardDeck deck;
    deck.shuffle();
    
    std::cout << "Spielnamen eingeben: ";
    /*
        alternativ: Bei Ersteingabe fehlt der erste Buchstabe
        Verwerfung des übriggebliebenen Zeilenumbruchs
        std::cin.ignore();
     */
    std::getline(std::cin >> std::ws, name);
    
//        Karten wird an die Spieler verteilt
    if (boxComp.insert(deck.getNextCard())) {
        std::cout << "Dealer: " << boxComp << " / " << boxComp.getBoxValue() << std::endl;
    }
    
    if (boxPlayer.insert(deck.getNextCard())) {
        std::cout << name << ": " << boxPlayer << " / " << boxPlayer.getBoxValue() << std::endl;
    }
    
    while (true) {
        std::cout << "Spielen? [J]a / [N]ein\n";
        std::cin >> continueGame;
        
        if (continueGame == "J" || continueGame == "N") {
            break;
        } else {
            std::cout << "Ungültige Eingabe. Bitte geben Sie 'J' für Ja oder 'N' für Nein ein.\n";
            // Wenn die Eingabe ungültig ist, wird die Schleife erneut durchlaufen
        }
    }
    
    
    bool play = 1;
    while (play != 0) {
        /*Spieler*/
        if (continueGame == "J") {
            if (boxPlayer.insert(deck.getNextCard())) {
                std::cout << name << ": " << boxPlayer << " / " << boxPlayer.getBoxValue() << std::endl;
            }
            
            if (boxPlayer.getBoxValue() > 21) {
                //            abbruch -> Verloren Textausgabe
                std::cout << "Gewinner: Computer\n";
                play = 0;
            }
            
            if (boxPlayer.getBoxValue() == 21) {
    //            abbruch -> Highscore. Zu Dealer wechseln Textausgabe
                continueGame = "N";
            }
                
            if (boxPlayer.getBoxValue() < 21) {
                if (21 - boxPlayer.getBoxValue() == 1) {
    //                Abbruch -> Zu Dealer wechseln Textausgabe
                    continueGame = "N";
                }
                else {
    //                Weiterspielen std::cout << "Spielen? [J]a / [N]ein\n";
                    while (true) {
                        std::cout << "Spielen? [J]a / [N]ein\n";
                        std::cin >> continueGame;
                        
                        if (continueGame == "J" || continueGame == "N") {
                            break;
                        } else {
                            std::cout << "Ungültige Eingabe. Bitte geben Sie 'J' für Ja oder 'N' für Nein ein.\n";
                            // Wenn die Eingabe ungültig ist, wird die Schleife erneut durchlaufen
                        }
                    }
                    
                }
            }
        }
        
        /*Computer*/
        if (continueGame == "N") {
            if (boxComp.insert(deck.getNextCard())) {
                std::cout << "Computer: " << boxComp << " / " << boxComp.getBoxValue() << std::endl;
            }
            
            if (boxComp.getBoxValue() > 21) {
                //            abbruch -> Verloren Textausgabe
                std::cout << "Gewinner: " << name << std::endl;
                play = 0;
            }
            
            if (boxComp.getBoxValue() < 17) {
                continueGame = "N";
            }
            
            if (boxComp.getBoxValue() >= 17 && boxComp.getBoxValue() <= 21) {
                if (boxComp.getBoxValue() == boxPlayer.getBoxValue()) {
                    std::cout << "Unentschieden\n" << std::endl;
                }
                if (boxComp.getBoxValue() < boxPlayer.getBoxValue()) {
                    std::cout << "Gewinner: " << name << std::endl;
                }
                if (boxComp.getBoxValue() > boxPlayer.getBoxValue()) {
                    std::cout << "Gewinner: Computer\n" << std::endl;
                }
                play = 0;
            }
        }
    }
    
}
