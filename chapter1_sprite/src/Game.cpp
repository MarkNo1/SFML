/*
 * Game.cpp
 *
 *  Created on: Jun 4, 2018
 *      Author: mark
 */

#include <Game.hpp>
#include <iostream>

Game::Game(): mWindow(sf::VideoMode(640,480), "SFML Application"), mTexture(), mPlayer(),
	moveUp(false), moveDown(false),moveRight(false),moveLeft(false){

	if (!mTexture.loadFromFile("resource/ufo.png"))
		//Error
		std::cout << "Error Loadinf File!" << std::endl;

	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.f,100.f);
	mWindow.setVerticalSyncEnabled(true);
}

void Game::run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while(mWindow.isOpen()){

		processEvents();
		timeSinceLastUpdate += clock.restart();

		while ( timeSinceLastUpdate > TimePerFrame){
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key,bool isPressed){
	switch (key) {

	case sf::Keyboard::W:
			moveUp=isPressed;
			break;
	case sf::Keyboard::S:
			moveDown=isPressed;
			break;
	case sf::Keyboard::A:
			moveLeft=isPressed;
			break;
	case sf::Keyboard::D:
			moveRight=isPressed;
			break;
	}
}

void Game::processEvents(){

	sf::Event event;
	while (mWindow.pollEvent(event)){

		switch (event.type){

		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time deltaTime){
	sf::Vector2f movement(0.f, 0.f);

	if (moveUp)
		movement.y -= 100.f;
	if (moveDown)
		movement.y += 100.f;
	if (moveRight)
		movement.x += 100.f;
	if (moveLeft)
		movement.x -= 100.f;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render(){
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}
