#include "objects.h"
#include "Map/tags.h"
#include "../Debug/debug.h"

CObjects::CObjects()
{
	ObjectData = (AObjectData*)OBJECT_ADDRESS;
}
CObjects::~CObjects()
{
}

ident CObjects::GetObjectIdent(unsigned char object_index)
{
	ident default_ident = {0,0};
	if(!ObjectData->ObjectHeader[object_index].Object)
		return default_ident;
	else
		return ObjectData->ObjectHeader[object_index].Object->ModelTag;
}

void CObjects::PrintObjectInfo()
{
	CTags tags;
	/*
	for(unsigned short i = 0; i < ObjectData->ObjectsHeader.Max; i++)
	{
		if(!ObjectData->ObjectHeader[i].Object)
			continue;

		DEBUG("Path: %s", tags.GetTagPath(ObjectData->ObjectHeader[i].Object->ModelTag.Index));
		DEBUG("ID: %X",	ObjectData->ObjectHeader[i].ID);
		DEBUG("Flags: %X", ObjectData->ObjectHeader[i].Flags);
		DEBUG("Type: %X", ObjectData->ObjectHeader[i].Type);
		DEBUG("Cluster: %i", ObjectData->ObjectHeader[i].CluserIndex);
		DEBUG("Size: %i\n", ObjectData->ObjectHeader[i].Size);


	}
	*/
	for(unsigned long i = 0; i < tags.TagIndex->TagCount; i++)
	{
		ATagInstance* TagInstance = tags.GetTagInstance(i);
		if(TagInstance->TagParent != 'ÿÿÿÿ')
		{
			DEBUG("Parent: %X", TagInstance->TagParent);
		}
		if(TagInstance->TagChild != 'ÿÿÿÿ')
		{
			DEBUG("Child: %X", TagInstance->TagChild);
		}
	}

}