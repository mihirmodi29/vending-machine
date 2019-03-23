#ifndef _ELMA_VENDING_MACHINE_VENDING_H
#define _ELMA_VENDING_MACHINE_VENDING_H

#include "vendingmachine.h"

namespace vendingmachine {

    using namespace std::chrono;
    using namespace elma;

    class VendingMachine; // Declare containing class so it can be refered to here
                     // before it is defined in vendingmachine.h

    //! A State class to represent the state in which the vendingmachine is vending
    class VendingState : public State {

        public:
        //! Construct a new vending state
        VendingState() : State("vending") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from vending to Idle or vending to ready
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        VendingMachine& vendingmachine();

    };

}

#endif