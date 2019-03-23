#include <chrono>
#include <vector>

#include "vendingmachine.h"

using namespace std::chrono;
using namespace elma;
using namespace vendingmachine;

VendingMachine::VendingMachine() : StateMachine("vendingmachine") {

    // Define state machine initial states and transitions here
    set_initial(idle);
    set_propagate(false);
    add_transition("$0.25", idle, ready);
    add_transition("$0.50", idle, ready);
    add_transition("$1.0", idle, ready);
    add_transition("$0.25", ready, ready);
    add_transition("$0.50", ready, ready);
    add_transition("$1.0", ready, ready);
    add_transition("coin_return", ready, idle); 
    add_transition("snack", ready, vending); 
    add_transition("water", ready, vending); 
    add_transition("juice", ready, vending);  
    add_transition("vend_complete", vending, idle);
    add_transition("go to ready", vending, ready); 

    // Make sure we start in the right condition
    reset();
}

double VendingMachine::value() {
        return _value;
}

void VendingMachine::begin() { }

void VendingMachine::reset() { _value =0;}

void VendingMachine::stop() { }

void VendingMachine::add(double value) {
    _value = _value + value;
}

void VendingMachine::set_value(double value) {
    _value = value;
}