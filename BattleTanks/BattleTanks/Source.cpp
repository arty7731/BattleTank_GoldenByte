#include"Header.h"
#include "AllegroCore.h"

void main()
{

	try
	{
	AllegroCore bTanks;
	bTanks.Initialize(1280, 720, 0, 0, 0);
	bTanks.Main();
	}
	catch (char* messenge)
	{
		cout << messenge << endl;
	}


}