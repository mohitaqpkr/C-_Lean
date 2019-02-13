#pragma once

#include "Game.h"
#include <random>
#include <vector>
#include <iostream>
#include "ECS/Rect.h"


class Map {

public:
	Map();
	~Map();
	void LoadMap(int arr[20][25]);
	void DrawMap();

	//Dungeon
	enum Tile
	{
		Unused = '0',
		Floor = '2',
		Corridor = '2',
		Wall = '1',
		ClosedDoor = '2',
		OpenDoor = '2',
		UpStairs = '2',
		DownStairs = '2'
	};

	enum Direction
	{
		North,
		South,
		West,
		East,
		DirectionCount
	};

	Map(int width, int height);
	void generate(int maxFeatures);
	void print();
	void LoadDungeonMap(int features);

	//Dungeon End


private:

	SDL_Rect src, dest;
	SDL_Texture *dirt;
	SDL_Texture *grass;
	SDL_Texture *water;

	int map[20][25];

	//Dungeon private members

	int _width, _height;
	std::vector<char> _tiles;
	std::vector<Rect> _rooms; // rooms for place stairs or monsters
	std::vector<Rect> _exits; // 4 sides of rooms or corridors

	char getTile(int x, int y) const;
	void setTile(int x, int y, char tile);
	bool createFeature();
	bool createFeature(int x, int y, Direction dir);
	bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
	bool makeCorridor(int x, int y, Direction dir);
	bool placeRect(const Rect& rect, char tile);
	bool placeObject(char tile);

	//Dungeon End
};

//struct Rect
//{
//	int x, y;
//	int width, height;
//};

namespace
{
	std::random_device rd;
	std::mt19937 mt(rd());

	int randomInt(int exclusiveMax)
	{
		std::uniform_int_distribution<> dist(0, exclusiveMax - 1);
		return dist(mt);
	}

	int randomInt(int min, int max) // inclusive min/max
	{
		std::uniform_int_distribution<> dist(0, max - min);
		return dist(mt) + min;
	}

	bool randomBool(double probability = 0.5)
	{
		std::bernoulli_distribution dist(probability);
		return dist(mt);
	}
}