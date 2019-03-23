#ifndef _ELMA_VENDING_MACHINE_IDLE_H
#define _ELMA_VENDING_MACHINE_IDLE_H

#include "vendingmachine.h"

namespace vendingmachine {

    using namespace std::chrono;
    using namespace elma;

    class VendingMachine; // Declare containing class so it can be refered to here
                     // before it is defined in vendingmachine.h

    //! A State class to represent the state in which the vendingmachine is Idle means it is ready to serve new customer.
    class IdleState : public State {

        public:
        //! Construct a new Idle state
        IdleState() : State("idle") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from Idle to Ready
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        VendingMachine& vendingmachine();

    };

}

#endif