#ifndef __EDGE_SHAPE_H
#define __EDGE_SHAPE_H

#include <SFML/Graphics.hpp>
#include "NodeShape.h"

class EdgeShape : public sf::Sprite {
	public:
		EdgeShape(NodeShape* from, NodeShape* to);
		void Update();
	private:
		NodeShape *from, *to;
		sf::RenderTexture rtx;
		sf::VertexArray line;
};

#endif