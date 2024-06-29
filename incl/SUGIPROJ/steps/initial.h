#pragma once

#include "SUGIPROJ/steps/step.h"

namespace sugi {
    
    class initial : public sugi::step {
    public:
        initial() = default;

        void run() override;

    private:
        
    };

}