#pragma once

#include "SUGIPROJ/step.h"

namespace sugi {
    
    class leveling : public sugi::step {
    private:

    public:
        leveling() = default;
        void go() override;
        
    };

}