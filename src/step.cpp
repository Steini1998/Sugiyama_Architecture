#include "SUGIPROJ/sugiyama.h"

using namespace sugi;

void step::setSugiyama(sugiyama* sg) {
    m_sugiyama = sg;
} 

leda::graph step::getGraph() {
    return m_graph;
}

void step::setGraph(leda::graph g) {
    m_graph = g;
}

leda::node_map<leda::point> step::getPositions() {
    return m_positions;
}

void step::setPositions(leda::node_map<leda::point> positions) {
    m_positions = positions;
}