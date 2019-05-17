#include "NodeShape.h"

NodeShape::NodeShape(GraphNode *node, int size, sf::Color color) : sf::Sprite::Sprite() {
	this->node = node;
	this->setOrigin(size/2, size/2);
	
	circle = sf::CircleShape(size / 2, size);
	circle.setFillColor(color);
	
	text = sf::Text();

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(size/4);
	text.setOutlineColor(sf::Color::Transparent);

	rtx.create(size, size);
	rtx.setSmooth(true);
	
	this->setTexture(rtx.getTexture());

	rtx.clear(sf::Color::Transparent);
	rtx.display();
	this->Update();
};

void NodeShape::Update() {
	text.setFillColor(sf::Color::Black);
	text.setString(sf::String(node->label + ":" + std::to_string(node->weight)));
	text.setPosition(rtx.getSize().x/2 - text.getLocalBounds().width/2, rtx.getSize().y/2 - text.getLocalBounds().height/2);
	rtx.clear(sf::Color::Transparent);
	rtx.draw(circle);
	rtx.draw(text);
	rtx.display();
};