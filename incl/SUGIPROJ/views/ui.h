#pragma once

namespace sugi {

    class ui {
    public:
        /* Returns 0, if view should stop.
         * Returns 1, if view should go 1 step backward.
         * Returns 2, if view should go 1 step forward. */
        virtual int get() = 0;  
    };

}