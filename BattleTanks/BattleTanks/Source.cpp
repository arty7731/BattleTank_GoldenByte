#include"Header.h"
#include "AllegroCore.h"

void main()
{
	AllegroCore bTanks;
	bTanks.Initialize(1280, 720, 0, 0, 0);

	bTanks.Main();
}