/*
 * Game.hpp
 *
 *  Created on: Jun 4, 2018
 *      Author: mark
 */

#ifndef SRC_GAME_HPP_
#define SRC_GAME_HPP_

#include <SFML/Graphics.hpp>



class Game {
public:
	Game();
	void run();

private:
	void 	processEvents();
	void 	update(sf::Time deltaTime);
	void 	render();

	void handlePlayerInput(sf::Keyboard::Key key,
			bool isPressed);

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	bool moveUp, moveDown, moveRight, moveLeft;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
};

#endif /* SRC_GAME_HPP_ */
