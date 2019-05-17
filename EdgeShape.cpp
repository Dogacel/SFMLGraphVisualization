#include "EdgeShape.h"

EdgeShape::EdgeShape(NodeShape* from, NodeShape *to) {
	this->from = from;
	this->to = to;

	line.append(sf::Vertex(sf::Vector2f(0,0)));
	line.append(sf::Vertex(to->getPosition() - from->getPosition()));
	line[0].color = sf::Color::White;
	line[1].color = sf::Color::White;
	line.setPrimitiveType(sf::Lines);

	rtx.create(line.getBounds().width, line.getBounds().height);
	rtx.display();

	rtx.clear(sf::Color::Transparent);
	rtx.draw(line);
	rtx.display();

	this->setTexture(rtx.getTexture());
	this->setPosition(from->getPosition());
}