#include <iostream>
#include <chrono>
#include <vector>
#include <ncurses.h>

#include "vendingmachine.h"

namespace vendingmachine {

    using namespace std::chrono;
    using namespace elma;
    using namespace vendingmachine;

    //! A user interface for the a VendingMachine object
    class UserInterface : public Process {

        public:

        //! Create a new vendingmachine user interface using curses
        //! \param sw A reference to a VendingMachine object
        UserInterface(VendingMachine& vm);

        void init() {}
        void start() {}

        //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
        void update();
        void stop() {}

        private:
        VendingMachine& _vendingmachine;

    };

}