#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef enum
{
	get,
	set
} GetSetFlag;

bool FileExists(const char* filename);

bool GetSetHeader(FILE* fp, GetSetFlag getset);

bool GetSetSlot(int slotNum, GetSetFlag getset);