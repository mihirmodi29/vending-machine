#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "vendingmachine.h"

using namespace std::chrono;
using namespace elma;
using namespace vendingmachine;

int main() {

    Manager m;
    VendingMachine vendingmachine;
    UserInterface ui(vendingmachine);

    m.schedule(ui, 10_ms)
     .schedule(vendingmachine, 10_ms)     
     .init()
     .run();

    endwin();     
     
}