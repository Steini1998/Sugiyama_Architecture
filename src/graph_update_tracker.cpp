#include "SUGIPROJ/graph_update_tracker.h"


using namespace leda;


list<node> sugi::graph_update_tracker::getAddedNodes() {
    return m_added_nodes;
}

void sugi::graph_update_tracker::addAddedNode(node n) {
    m_added_nodes.append(n);
}

void sugi::graph_update_tracker::removeAddedNode(node n) {
    m_added_nodes.remove(n);
}

list<node> sugi::graph_update_tracker::getRemovedNodes() {
    return m_removed_nodes;
}

void sugi::graph_update_tracker::addRemovedNode(node n) {
    m_removed_nodes.append(n);
}

void sugi::graph_update_tracker::removeRemovedNode(node n) {
    m_removed_nodes.remove(n);
}

list<edge> sugi::graph_update_tracker::getAddedEdges() {
    return m_added_edges;
}

void sugi::graph_update_tracker::addAddedEdge(edge e) {
    m_added_edges.append(e);
}

void sugi::graph_update_tracker::removeAddedEdge(edge e) {
    m_added_edges.remove(e);
}

list<edge> sugi::graph_update_tracker::getRemovedEdges() {
    return m_removed_edges;
}

void sugi::graph_update_tracker::addRemovedEdge(edge e) {
    m_removed_edges.append(e);
}

void sugi::graph_update_tracker::removeRemovedEdge(edge e) {
    m_removed_edges.remove(e);
}

list<edge> sugi::graph_update_tracker::getReveresedEdges() {
    return m_reversed_edges;
}

void sugi::graph_update_tracker::addReversedEdge(edge e) {
    m_reversed_edges.append(e);
}

void sugi::graph_update_tracker::removeReversedEdge(edge e) {
    m_reversed_edges.remove(e);
}