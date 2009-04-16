#ifndef MAP_H
#define MAP_H

#include <windows.h>
//#include "tags.h"
//#include "scenario.h"
//#include "bsp.h"

// 2 Map Headers are loaded into static memory. 2 differences - 
// few bytes before and after the header ( Index Header pointer and bps pointer? )
// Either of these should work though
#define MAP_HEADER_ADDRESS 0x006A807C
#define MapHeaderAltAddy	0x006AAB80

struct MapHeader
{
	unsigned long	HeadSignature;		// 'deah' translates as head
	unsigned long	Version;			// 5 = Xbox, 6 = Trial, 7 = PC, 609 = CE
	unsigned long	DecompressedLength;	// Actual len of decompressed data. Halo sticks garbage on the end so that the file is one of several fixed sizes (35, etc).
	unsigned long	Unknown;
	unsigned long	TagIndexOffset;
	unsigned long	TagIndexMetaLength;
	unsigned long	Zeros[2];			// both always 0x0
	char			MapName[32];
	char			BuildDate[32];		// Year.Month.Day.Build - I guess they use this to make sure that a certain build will only open that build's map files, because this string is in the app too
	unsigned long	MapType;			// 0 = singleplayer, 1 = multiplayer, 2 = ui - this also determines the size of the cache file. UI = 35MB, multiplayer = 47MB, and singleplayer = 270MB
	unsigned long	Unknown1;
	unsigned long	Padding[485];
	unsigned long	FootSignature;		// 'toof' translates to foot
};

#endif /* MAP_H */