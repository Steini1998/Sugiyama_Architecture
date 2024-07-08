#include "SUGIPROJ/steps/step.h"

using namespace sugi;

void step::setSugiyama(sugiyama* sg) {
    m_sugiyama = sg;
} 

leda::graph& step::getGraph() {
    return m_graph;
}

void step::setGraph(leda::graph g) {
    m_graph = g;
    this->setPositions();
}

leda::node_array<leda::point>& step::getPositions() {
    return m_positions;
}

void step::setPositions() {
    m_positions = leda::node_array<leda::point>(m_graph);
    //m_sugiyama->getGraphWin().get_position(m_positions); // ISSUE !!!
}