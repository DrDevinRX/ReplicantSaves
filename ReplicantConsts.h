#pragma once

// TODO: Find out what is in the large header
#define HEADER_SIZE 0x8160UL//0x8154

#define DIFFICULTY 0x28UL
#define TEXT_LANG 0x74UL
#define VOICEOVER 0x78UL

#define SAVE_SIZE 0x9250UL//0x925C
#define SAVE1_LOCATION 0x8160UL//0x8154U
#define SAVE2_LOCATION 0x113B0UL
#define SAVE3_LOCATION 0x1A610UL
// TODO: Find out what is in the large footer

typedef enum
{
	DEasy = 0,
	DNormal,
	DHard
}Difficulty;

typedef enum VO_Language
{
	VOJapanese = 0,
	VOEnglish
}VO_Language;

typedef enum TextLanguage
{
	TLJapanese = 0,
	TLEnglish,
	TLFrench,
	TLGerman,
	TLItalian,
	TLSpanish,
	TLSimpChinese,
	TLTradChinese,
	TLKorean
}TextLanguage;

static const char* GAMESAVE_NAME = "GAMEDATA";

static const char* SLOTFILE_NAMES[3] = {
	"slot_1.bin",
	"slot_2.bin",
	"slot_3.bin"
};

static const unsigned long SAVE_LOC[3] = {
	SAVE1_LOCATION,
	SAVE2_LOCATION,
	SAVE3_LOCATION
};

#define SLOTFILE(slotNum) SLOTFILE_NAMES[slotNum - 1]
#define SAVELOC(x) SAVE_LOC[x - 1]
