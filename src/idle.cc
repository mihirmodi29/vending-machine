#include <iostream>
#include <chrono>
#include <vector>

#include "vendingmachine.h"

using namespace std::chrono;
using namespace elma;
using namespace vendingmachine;

VendingMachine& IdleState:: vendingmachine() { return (VendingMachine&) state_machine(); }

void IdleState::exit(const Event& e) {
    if ( e.name() == "$0.25" ){
        vendingmachine().add(0.25);
    }else if ( e.name() == "$0.50" ){
        vendingmachine().add(0.50);
    }else if ( e.name() == "$1.0" ){
        vendingmachine().add(1.0);
    }
}
