#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"
#include "NodeShape.h"

int main() {

	Screen screen;

	NodeShape node(new GraphNode{"N", 10}, 100);
	NodeShape node2(new GraphNode{"M", 20}, 100);

	node.setPosition(150, 230);
	node2.setPosition(400, 350);

	VertexArray va;
	va.append(sf::Vertex(node.getPosition()));
	va.append(sf::Vertex(node2.getPosition()));
	va.setPrimitiveType(Lines);

	screen.addDrawable(va);
	screen.addDrawable(node);
	screen.addDrawable(node2);

	screen.run();

	return 0;
}