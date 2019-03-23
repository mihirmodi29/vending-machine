#include <unistd.h>
#include "vendingmachine.h"

using namespace vendingmachine;

UserInterface::UserInterface(VendingMachine& vm) : Process("user input"), _vendingmachine(vm) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};

void UserInterface::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 'a':
            clear();
            emit(Event("$0.25"));
            break;
        case 'b':
            clear();
            emit(Event("$0.50"));
            break;
        case 'c':
            clear();        
            emit(Event("$1.0"));
            break;
        case 'r':
            clear();
            emit(Event("coin_return"));
            break;
        case '1':
             if(_vendingmachine.value() >= 2.0)
            {
                clear();
                emit(Event("snack"));
                break;
            }
            else
            { 
                clear();
                mvprintw(5,1,"Add more $%lf",2-_vendingmachine.value());
                break;
            }
        case '2':
            if(_vendingmachine.value() >= 1.0)
            {
                clear();
                emit(Event("water"));
                break;
            }
            else
            { 
                clear();
                mvprintw(5,1,"Add more $%lf",1-_vendingmachine.value());
                break;
            }
        case '3':
            if(_vendingmachine.value() >= 1.5)
            {
                clear();            
                emit(Event("juice"));
                break;
            }
            else
            { 
                clear();
                mvprintw(5,1,"Add more $%lf",1.5-_vendingmachine.value());
                break;
            }            
        case 'y':
            clear();        
            emit(Event("go to ready"));
            break;    
        case 'n':
            clear();        
            emit(Event("vend_complete"));
            break;
        case 'q':
            clear();        
            std::cout << "halting\n";
            halt();
            break;
    }
    
    // OUTPUT
    mvprintw(1,1,"Your Balance: $%lf",_vendingmachine.value());
    mvprintw(3,1,"$0.25(a), $0.50(b), $1.0(c), coin_return(r), snack $2.0 (1), water $1.0 (2), juice $1.5 (3), Yes(y), No(n), quit(q)");
    usleep(9999);

}