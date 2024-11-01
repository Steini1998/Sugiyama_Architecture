#include "SUGIPROJ/sugiyama.h"

using namespace sugi;


void step::execute() {
    run();
    saveResult();
}

void step::showResult() {
    m_positionable_graph.show(m_sugiyama->getGraphWin());
}

void step::setSugiyama(sugiyama* sg) {
    m_sugiyama = sg;
} 

void step::saveResult() {
    m_positionable_graph = positionable_graph{};
    m_positionable_graph.takeSnapshot(m_sugiyama->getGraph(), m_sugiyama->getPositions());
}