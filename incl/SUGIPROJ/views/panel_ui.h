#pragma once

#include "LEDA/graphics/graphwin.h"
#include "LEDA/graphics/panel.h"

#include "SUGIPROJ/views/ui.h"

namespace sugi {
    
    class panel_ui : public ui {
    public:
        panel_ui(leda::GraphWin&);

        int get() override;

    private:
        void configurePanel();

    private:
        leda::GraphWin& m_graphwin;
        leda::panel m_panel;
        
    };

}