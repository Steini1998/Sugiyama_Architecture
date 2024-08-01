#include "SUGIPROJ/sugiyama.h"

using namespace sugi;

void step::setSugiyama(sugiyama* sg) {
    m_sugiyama = sg;
} 

void step::make() {
    run();
    saveResult();
}

void step::saveResult() {
    m_position_graph = positionable_graph{};
    m_position_graph.takeSnapshot(m_sugiyama->getGraph(), m_sugiyama->getPositions());
}

void step::showResult() {
    m_position_graph.show(m_sugiyama->getGraphWin());
}