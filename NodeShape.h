#ifndef __NODE_SHAPE_H
#define __NODE_SHAPE_H

#include <SFML/Graphics.hpp>

class NodeShape : public sf::Sprite {
	public:
		struct GraphNode {
			std::string label;
			int			weight;
		};
		NodeShape(GraphNode *node, int size = 200, sf::Color color = sf::Color::White);
		void Update();
	private:
		GraphNode *node;
		sf::Font font;
		sf::Text text;
		sf::CircleShape circle;
		sf::RenderTexture rtx;		
};

#endif