#ifndef _ELMA_VENDING_MACHINE_READY_H
#define _ELMA_VENDING_MACHINE_READY_H

#include "vendingmachine.h"

namespace vendingmachine {

    using namespace std::chrono;
    using namespace elma;

    class VendingMachine; // Declare containing class so it can be refered to here
                     // before it is defined in stopwatch.h

    //! A State class to represent the state in which the vendingmachine is Ready means it is in process to serve the existing customer.
    class ReadyState : public State {

        public:
        //! Construct a new Ready state
        ReadyState() : State("ready") {}
        void entry(const Event& e) {}
        void during() {}

        //! Perform actions required when switching from Ready to Vending
        //! \param e The event that triggered the transition
        void exit(const Event& e);

        //! \return A reference to the containing finite state machine object
        VendingMachine& vendingmachine();

    };

}

#endif