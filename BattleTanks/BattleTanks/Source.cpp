#include"Header.h"
#include "AllegroCore.h"

void main()
{

	try
	{
		AllegroCore battleTanks;
		battleTanks.Initialize(1280, 720, 0, 0, 0);
		battleTanks.Main();
	}
	catch (char* messenge)
	{
		cout << messenge << endl;
	}


}