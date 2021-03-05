#pragma once
#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include "globals.h"

class Graphics;
struct SDL_Texture;

class Level {
public:
	Level();
	Level(std::string mapName, Vector2 spawnpoint, Graphics& graphics);
	~Level();
	void update(int elapsedTime);
	void draw(Graphics& graphics);

private:
	std::string _mapName;
	Vector2 _spawnPoint;
	Vector2 _size;
	SDL_Texture* _backgroundTexture;

		//loads a map. its private because it will only be called by itself
	void loadMap(std::string mapName, Graphics& graphics);




};


#endif