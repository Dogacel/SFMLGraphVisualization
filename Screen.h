#ifndef __SCREEN_H
#define __SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace::sf;
using namespace::std;

class Screen : public RenderWindow {
	public:
		Screen();
		void addDrawable(Drawable &d);
		void run();
	private:
		void drawObjects();
		vector<Drawable*> objects;
		ContextSettings	settings;
		RenderWindow window;
		View view;
		Event event;
		bool mousemove, drag;
		float zoom;
};

#endif