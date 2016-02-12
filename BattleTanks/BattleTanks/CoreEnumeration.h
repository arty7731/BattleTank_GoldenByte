#pragma once

enum class DirectionTank
{
	None,
	Right,
	Left
};

enum class Direction
{
	None,
	Right,
	Left,
	Up,
	Down
};

enum class DirectionMuzzle
{
	None,
	Up,
	Down
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

