/*
 * Game.hpp
 *
 *  Created on: June 4, 2018
 *      Author: mark
 */

#ifndef SRC_GAME_HPP_
#define SRC_GAME_HPP_

#include <SFML/Graphics.hpp>
#include <Resource/ResourceHolder.hpp>
#include <Resource/ResourceIdentifiers.hpp>



class Game {
public:
	Game();
	void run();
	sf::Time TimePerFrame = sf::seconds(1.f / 120.f);

private:
	void 	processEvents();
	void 	update(sf::Time deltaTime);
	void 	render();

	void handlePlayerInput(sf::Keyboard::Key key,
			bool isPressed);

private:
	sf::RenderWindow mWindow;
	sf::Sprite mPlayer;
	TextureHolder mTextureHolder;
	bool moveUp, moveDown, moveRight, moveLeft;

};

#endif /* SRC_GAME_HPP_ */
