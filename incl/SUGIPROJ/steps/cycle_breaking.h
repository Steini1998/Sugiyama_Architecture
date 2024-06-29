#pragma once

#include "SUGIPROJ/steps/step.h"

namespace sugi {
    
    class cycle_breaking : public sugi::step {
    public:
        cycle_breaking() = default;

        void run() override;

    private:
        
    };

}