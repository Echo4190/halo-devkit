#include "tags.h"

CTags::CTags()
{
	TagIndex = (ATagIndex*)	TAG_INDEX_ADDRESS;
}
CTags::~CTags()
{
}

char* CTags::GetTagPath(unsigned short tag_index)
{
	ATagInstance* TagInstance;
	TagInstance = (ATagInstance*)((unsigned long)TagIndex->FirstTagAddress + (tag_index * 32));
	return TagInstance->Name;
}

ATagInstance* CTags::GetTagInstance(unsigned long tag_index)
{
	ATagInstance* TagInstance;
	TagInstance = (ATagInstance*)((unsigned long)TagIndex->FirstTagAddress + (tag_index * 32));
	return TagInstance;
}