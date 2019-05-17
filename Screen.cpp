#include "Screen.h"
#include "NodeShape.h"

Screen::Screen() : 	window(sf::VideoMode(640, 480), "SFML Test", sf::Style::Default, settings) {

	settings.antialiasingLevel = 8;

	mousemove = false, drag = false;
	zoom = 1.0f;
	view = window.getDefaultView();

}

void Screen::addDrawable(Drawable &d) {
	objects.push_back(&d);
}

void Screen::drawObjects() {
	window.clear();
	for (Drawable *dw : objects) {
		window.draw(*dw);
	}
	window.display();
}

void Screen::run() {
	sf::Vector2f lastpos;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					mousemove = true;
					drag = false;
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					mousemove = false;
				}
				break;
			case sf::Event::MouseMoved:
				if (mousemove) {
					if (!drag) {
						lastpos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
						drag = true;
					}

					sf::Vector2f newpos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
					sf::Vector2f deltapos = lastpos - newpos;
					
					view.move(deltapos);
					window.setView(view);

					lastpos = window.mapPixelToCoords(sf::Vector2i(event.mouseMove.x, event.mouseMove.y));
				}
				break;
			case sf::Event::MouseWheelScrolled:
                    if (!mousemove) {
						if (event.mouseWheelScroll.delta <= -1) {
							zoom = std::min(5.f, zoom + .1f);
						} else if (event.mouseWheelScroll.delta >= 1) {
							zoom = std::max(.2f, zoom - .1f);
						}
					}
                    view.setSize(window.getDefaultView().getSize()); // Reset the size
                    view.zoom(zoom); // Apply the zoom level (this transforms the view)
                    window.setView(view);
                    break;
			default:
				break;
			}
		}
		drawObjects();
	}
}