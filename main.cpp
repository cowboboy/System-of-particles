#include <iostream>
#include <SFML/Graphics.hpp>
#include <list>
#include "Particle.h"
#include "Particles.h"
#include "Config.h"

int main() {
	srand(time(0));
	rand();
	sf::RenderWindow window(sf::VideoMode(W, H), "Particles");
	Particles system;

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

		window.clear(sf::Color::White);
		float sleepMilliseconds = elapsedMillisecondsExpected - elapsedMilliseconds;
		int frames = int(elapsedMilliseconds / elapsedMillisecondsExpected) + 1;
		for (int i = 0; i < frames; ++i) system.UpdateState(elapsedMillisecondsExpected); 
		system.Render(window);
		window.display();
	}
	return 0;
}