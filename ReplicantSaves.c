// ReplicantSaves.c : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ReplicantConsts.h"
#include "ReplicantSaveFuncs.h"

int main(int argc, char** argv)
{
	GetSetFlag flag = get;
	int slotNum = 0;
	bool DoAllSlots = true;
	if (argc < 2)
	{
		// Prettify argv[0] to get last index of
		size_t len = strlen(argv[0]);
		char* lastIdxOf = NULL;
		for (size_t i = len; i > 0; i--)
		{
			if (argv[0][i] == '\\')
			{
				lastIdxOf = &(argv[0][i + 1]);
				break;
			}
		}

		printf("Example usage: %s [import/export] <slot [1-3]>\n"
			   "If slotNum is not specified, all slots will be imported/exported.\n"
			   "Slot files will be named \"slot_x.bin\"\n", lastIdxOf == NULL ? argv[0] : lastIdxOf);
		return 255;
	}

	if (strcmp(argv[1], "import") != 0 && strcmp(argv[1], "export") != 0)
	{
		printf("Need to specify import or export\n");
		return 1;
	}

	if (!FileExists(GAMESAVE_NAME))
	{
		printf("%s does not exist in the current directory.\n", GAMESAVE_NAME);
		return 2;
	}

	flag = (!strcmp(argv[1], "import") ? set : get);

	if (argv[2] != NULL)
	{
		int val = sscanf(argv[2], "%d", &slotNum);
		if (val != 1)
		{
			printf("Bad scan\n");
			return 3;
		}

		if (slotNum < 1 || slotNum > 3)
		{
			printf("Slot number must be between 1 and 3 inclusive.\n");
			return 4;
		}
		DoAllSlots = false;
	}

	for (int i = (DoAllSlots ? 1 : slotNum); i <= (DoAllSlots ? 3 : slotNum); i++)
	{
		if (!FileExists(SLOTFILE(i)) && flag == set)
		{
			printf("File: %s not found, continuing...\n", SLOTFILE(i));
			continue;
		}

		if (!GetSetSlot(i, flag))
		{
			printf("Read/Write failed.\n");
			return 5;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
