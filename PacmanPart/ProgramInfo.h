#pragma once
#include "Map.h"
#include "Player.h"
#include "TimeManager.h"
class ProgramInfo
{
public:
	Map pacman_map = Map();
	std::vector<Enemy> enemigos;
	Player player = Player(pacman_map.spawn_player);
	USER_INPUTS input = USER_INPUTS::NONE;
	bool run = true;
	bool win = false;
	bool loose = false;
};

