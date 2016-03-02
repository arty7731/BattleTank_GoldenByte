#pragma once

enum class Direction
{
	None,
	Right,
	Left,
	Up,
	Down,
	Fire
};

enum class BulletType
{
	Piercing,
	Sprlinter,
	Comulative
};

enum class ViewType
{
	MainMenu,
	GameView,
	AboutMenu,
	SelectGameMode,
	Exit = 16
};

