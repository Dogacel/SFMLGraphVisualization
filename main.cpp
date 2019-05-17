#include <SFML/Graphics.hpp>
#include <iostream>
#include "Screen.h"
#include "NodeShape.h"
#include "EdgeShape.h"

int main() {

	Screen screen;

	NodeShape node(new NodeShape::GraphNode{"N", 10}, 100);
	NodeShape node2(new NodeShape::GraphNode{"M", 20}, 100);

	node.setPosition(150, 230);
	node2.setPosition(400, 350);
	
	EdgeShape edge(&node, &node2);

	screen.addDrawable(edge);
	screen.addDrawable(node);
	screen.addDrawable(node2);

	screen.run();

	return 0;
}