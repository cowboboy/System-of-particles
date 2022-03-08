#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Particle.h"
#include "Emitter.h"
#include "Config.h"
#include "Point.h"
#include "GravityPoint.h"
#include "AntiGravityPoint.h"
#include "TopEmitter.h"

int main() {
	srand(time(0));
	rand();
	sf::RenderWindow window(sf::VideoMode(W, H), "Particles");
	TopEmitter system(W);

	system.impactPoints.push_back(new GravityPoint(W / 4, H / 2));
	system.impactPoints.push_back(new AntiGravityPoint(W / 2, H / 2));
	system.impactPoints.push_back(new GravityPoint(W * 0.75, H / 2)); 

	int framerate = 100;
	float elapsedMillisecondsExpected = 1000.f / framerate;

	while (window.isOpen())
	{
		sf::Clock clock;
		float elapsedMilliseconds = clock.restart().asMicroseconds();

		system.MouseControl(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		for (int i = 0; i < frames; ++i) system.UpdateState(elapsedMillisecondsExpected); 
		system.Render(window);
		window.display();
	}
	return 0;
}