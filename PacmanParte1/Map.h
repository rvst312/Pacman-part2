#pragma once

#include "ConsoleUtils.h"
#include <map>

class Map
{
public:
	/// <summary>
	/// The map tiles and it's symbols
	/// </summary>
	enum MAP_TILES { MAP_EMPTY = ' ', MAP_WALL = '#', MAP_POINT = '.'};
	/// <summary>
	/// The background color given a map tile
	/// </summary>
	std::map<MAP_TILES, ConsoleUtils::CONSOLE_COLOR> backgrounds;
	/// <summary>
	/// The character color given a map tile
	/// </summary>
	std::map<MAP_TILES, ConsoleUtils::CONSOLE_COLOR> foregrounds;
	/// <summary>
	/// The width of the map
	/// </summary>
	const int Width = 44;
	/// <summary>
	/// The height of the map
	/// </summary>
	const int Height = 19;
	/// <summary>
	/// The amount of tiles in the map
	/// </summary>
	const int Size = Width * Height;
	/// <summary>
	/// The remaining points in the map
	/// </summary>
	int points;
	/// <summary>
	/// The spawn point of the player
	/// </summary>
	COORD spawn_player;
	/// <summary>
	/// The spawn point of the enemy
	/// </summary>
	COORD spawn_enemy;
private:
	MAP_TILES* storedmap;
	int inline GetPos(int _x, int _y);
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	Map();
	/// <summary>
	/// Default destructor
	/// </summary>
	~Map();

	/// <summary>
	/// Draws the map
	/// </summary>
	void Draw();
	/// <summary>
	/// Returns the tile given the coordinates
	/// </summary>
	/// <param name="_x">Horizontal coordinate</param>
	/// <param name="_y">Vertical coordinate</param>
	/// <returns>The tile in the given coordinate</returns>
	MAP_TILES GetTile(int _x, int _y);
	/// <summary>
	/// Sets the tile given the coordinates and the tile
	/// </summary>
	/// <param name="_x">Horizontal coordinate</param>
	/// <param name="_y">Vertical coordinate</param>
	/// <param name="_tile">The tile to replace</param>
	void SetTile(int _x, int _y, MAP_TILES _tile);
};

