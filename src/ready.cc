#include <iostream>
#include <chrono>
#include <vector>

#include "vendingmachine.h"

using namespace std::chrono;
using namespace elma;
using namespace vendingmachine;

VendingMachine& ReadyState:: vendingmachine() { return (VendingMachine&) state_machine(); }

void ReadyState::exit(const Event& e) {
    if ( e.name() == "$0.25" ){
        vendingmachine().add(0.25);
    }else if ( e.name() == "$0.50" ){
        vendingmachine().add(0.50);
    }else if ( e.name() == "$1.0" ){
        vendingmachine().add(1.0);
    }else if ( e.name() == "coin_return" ){
        clear();
        mvprintw(5,1,"Return Change: $%lf", vendingmachine().value());
        vendingmachine().set_value(0);
    } else if ( e.name() == "snack" ){
            clear();
            double value = vendingmachine().value() - 2.0;
            vendingmachine().set_value(value);
            mvprintw(5,1,"Your product is Ready for pick up!");
            mvprintw(6,1,"Do you want anything else? Press 'y' for YES and 'n' for NO" );
    }else if ( e.name() == "juice" ){
            clear();
            double value = vendingmachine().value() - 1.5;  
            vendingmachine().set_value(value);  
            mvprintw(5,1,"Your product is Ready for pick up!");
            mvprintw(6,1,"Do you want anything else? Press 'y' for YES and 'n' for NO" );
    }else if ( e.name() == "water" ){
            clear();
            double value = vendingmachine().value() - 1.0;    
            vendingmachine().set_value(value);  
            mvprintw(5,1,"Your product is Ready for pick up!");
            mvprintw(6,1,"Do you want anything else? Press 'y' for YES and 'n' for NO" );
    }
}
