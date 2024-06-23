#pragma once

#include "SUGIPROJ/steps/step.h"

namespace sugi {
    
    class leveling : public sugi::step {
    public:
        leveling() = default;

        void go() override;

    private:
        
    };

}