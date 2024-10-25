#pragma once

#include "LEDA/graph/graph.h"
#include "LEDA/geo/point.h"

#include "SUGIPROJ/positionable_graph.h"


namespace sugi {

	class sugiyama; // Forward declaration
	
	class step {		
	public:

		void setSugiyama(sugiyama*);

		void make(); // Template method

		void showResult();

	protected:
		sugiyama* m_sugiyama;

		positionable_graph m_position_graph;
		
	private:
		virtual void run() = 0;

		void saveResult();
		
	};
	
}