#ifndef _ELMA_VENDING_MACHINE_H
#define _ELMA_VENDING_MACHINE_H

#include "elma/elma.h" // Note installation directory for elma

#include "idle.h"
#include "ready.h"
#include "vending.h"
#include "user_interface.h"

namespace vendingmachine {

    using namespace std::chrono;
    using namespace elma;    

    //! A VendingMachine class, that inherits from StateMachine
    class VendingMachine : public StateMachine {

        public:
        //! Make a new VendingMachine
        VendingMachine();

        //! Start the VendingMachine
        void begin();

        //! Reset the VendingMachine and amount to zero
        void reset();

        //! Stop the vending machine
        void stop();

        //! Get the amount input to vending machine
        double value();

        //! Add amount in dollars 
        void add (double value);

        //! Set amount in dollars 
        void set_value (double value);

        private:

        // When overriding the StateMachine class, put state declarations here.
        ReadyState ready;
        IdleState idle;
        VendingState vending;

        //Amount in dollars
        double _value;
    };

}

#endif