#include <SFML/Graphics.hpp>

struct GraphNode {
	std::string label;
	int			weight;
};

class NodeShape : public sf::Sprite {
	public:
		NodeShape(GraphNode *node, int size = 200, sf::Color color = sf::Color::White);
		void Update();
	private:
		GraphNode *node;
		sf::Font font;
		sf::Text text;
		sf::CircleShape circle;
		sf::RenderTexture rtx;
		
};