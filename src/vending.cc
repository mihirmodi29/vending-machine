#include <iostream>
#include <chrono>
#include <vector>

#include "vendingmachine.h"

using namespace std::chrono;
using namespace elma;
using namespace vendingmachine;

VendingMachine& VendingState:: vendingmachine() { return (VendingMachine&) state_machine(); }

void VendingState::exit(const Event& e) {
    if ( e.name() == "go to ready" ) {
        clear();
        mvprintw(5,1,"Please select your product!");
    } else if ( e.name() == "vend_complete" ) {
        clear();
        mvprintw(5,1,"Return Change: $%lf", vendingmachine().value());
        vendingmachine().set_value(0);
        mvprintw(6,1,"Have a good day!");
    }
}
