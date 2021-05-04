#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <io.h>
#include "ReplicantConsts.h"
#include "ReplicantSaveFuncs.h"

bool FileExists(const char* filename)
{
	return _access(filename, 0) == 0;
}

bool GetSetHeader(FILE* fp, GetSetFlag getset)
{
	bool res = true;
	if (getset == get)
	{

	}
	return res;
}

bool GetSetSlot(int slotNum, GetSetFlag getset)
{
	FILE* gamedatafp = NULL;
	if (getset == get)
	{
		gamedatafp = fopen(GAMESAVE_NAME, "rb+");
		FILE* fp = fopen(SLOTFILE(slotNum), "wb+");
		if (!fp && !gamedatafp)
		{
			return false;
		}
		char* saveBuf = malloc(SAVE_SIZE);
		int seek = fseek(gamedatafp, SAVELOC(slotNum), SEEK_SET);
		size_t read = fread(saveBuf, 1, SAVE_SIZE, gamedatafp);

		if (!seek && read != SAVE_SIZE)
		{
			free(saveBuf);
			return false;
		}

		size_t write = fwrite(saveBuf, 1, SAVE_SIZE, fp);
		fclose(fp);
		fclose(gamedatafp);
		free(saveBuf);
		return write == SAVE_SIZE;
	}

	gamedatafp = fopen(GAMESAVE_NAME, "rb+");
	FILE* fp = fopen(SLOTFILE(slotNum), "rb");
	if (!fp && !gamedatafp)
	{
		return false;
	}
	char* saveBuf = malloc(SAVE_SIZE);
	size_t read = fread(saveBuf, 1, SAVE_SIZE, fp);

	if (read != SAVE_SIZE)
	{
		free(saveBuf);
		return false;
	}

	fseek(gamedatafp, SAVELOC(slotNum), SEEK_SET);
	size_t write = fwrite(saveBuf, 1, SAVE_SIZE, gamedatafp);
	free(saveBuf);
	fclose(fp);
	fclose(gamedatafp);
	return write == SAVE_SIZE;
}