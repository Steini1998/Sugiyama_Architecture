#include <iostream>

#include "SUGIPROJ/leveling.h"

using namespace sugi;


void leveling::go() {
    m_processed_graph = m_received_graph;
    std::cout << m_processed_graph.number_of_nodes();
}