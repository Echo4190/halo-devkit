#ifndef BSP_H
#define BSP_H

//#include "map.h"

struct BSPInfoPrimary
{
	unsigned long	BspMapOffset;
	unsigned long	BspSize;
	void*			BSPInfoSec;
	unsigned long	Unknown;
	TagReference	BSPRef;
};

struct BSPInfoSecondary
{
	void*			BSPHeader;
	long			Unknown[4];
	unsigned long	Name;	//'psbs'
};

struct BSPHeader
{
  TagReference		LightmapsTag;
  unsigned long		Unknown[37];
  TagBlock			Shaders;
  TagBlock			CollBspHeader;
  TagBlock			Nodes;
  unsigned long		Unknown1[6];
  TagBlock			Leaves;
  TagBlock			LeafSurfaces;
  TagBlock			SubmeshTriIndices;
  TagBlock			SubmeshHeader;
  TagBlock			Chunk10;
  TagBlock			Chunk11;
  TagBlock			Chunk12;
  TagBlock			Clusters;
  unsigned long		ClusterDataSize;
  unsigned long		Unknown2;
  TagBlock			Chunk14;
  TagBlock			ClusterPortals;
  TagBlock			Chunk16a;
  TagBlock			BreakableSurfaces;
  TagBlock			FogPlanes;
  TagBlock			FogRegions;
  TagBlock			FogOrWeatherPallette;
  TagBlock			Chunk16f;
  TagBlock			Chunk16g;
  TagBlock			Weather;
  TagBlock			WeatherPolyhedra;
  TagBlock			Chunk19;
  TagBlock			Chunk20;
  TagBlock			PathfindingSurface;
  TagBlock			Chunk24;
  TagBlock			BackgroundSound;
  TagBlock			SoundEnvironment;
  unsigned long		SoundPASDataSize;
  unsigned long		Unknown3;
  TagBlock			Chunk25;
  TagBlock			Chunk26;
  TagBlock			Chunk27;
  TagBlock			Markers;
  TagBlock			DetailObjects;
  TagBlock			RuntimeDecals;
  unsigned long		Unknown4[9];
}; // Size = 0x0288 ( 648 )

// **** BSP COLLISION LUMPS START ****

struct CollisionHeader
{
	TagBlock		Nodes;      //12 bytes
	TagBlock		Planes;     //16 bytes
	TagBlock		Leaves;     //8 bytes
	TagBlock		Bsp2dRef;   //8 bytes
	TagBlock		Bsp2dNodes;	//20 bytes
	TagBlock		Surfaces;   //12 bytes
	TagBlock		Edges;      //24 bytes
	TagBlock		Vertices;   //16 bytes
};

struct CollisionNode
{
	unsigned long	PlaneIndex;
	unsigned long	Back;
	unsigned long	Front;
};

struct CollisionPlane
{
	float			x;
	float			y;
	float			z;
	float			d;
};

struct CollisionLeaf
{
	unsigned long	Unknown[2];
};

struct CollisionBSP2dRef
{
	unsigned long	Unknown[2];
};

struct CollisionBSP2dNodes
{
	float			Unknown[3];
	unsigned long	Unknown2;
	unsigned long	LeafIndex;
};

struct CollisionSurfaces
{
	unsigned long	Unknown[2];
	short			Unknown1;
	short			Unknown2;
};

struct CollisionEdges
{
	unsigned long	Unknown[6];
};

struct CollisionVertex
{
	float			Unknown[4];
};

// **** BSP COLLISION LUMPS END ****

// **** BSP LUMPS START ****

struct Shader
{
	TagReference	ShaderRef;
	unsigned short	Unknown[2];
};

struct Nodes
{
  short				Unknown[3];
};

struct Leaves
{
  unsigned long		Unknown[4];
};

struct LeafSurface
{
  unsigned long		Unknown[2];
};

struct SubmeshTriIndices
{
  unsigned short	TriIndices[3];
};

struct SubmeshHeader
{
	short			LightmapIndex;
	short			Unknown;
	unsigned long	Unknown1[4];
	TagBlock		Material;
};

struct Cluster
{
	short			SkyIndex;
	short			FogIndex;
	short			BackgroundSoundIndex;
	short			SoundEnvIndex;
	short			WeatherIndex;
	short			TransitionBsp;
	unsigned long	Unknown1[10];
	TagBlock		SubCluster;
	unsigned long	Unknown2[7];
	TagBlock		Portals;
};

struct Weather
{
	char			Name[32];
	char			TagGroup[4];
	unsigned long	NamePtr;
	unsigned long	Zero;
	unsigned long	TagId;
	unsigned long	Reserved[20];
	char			TagGroup2[4];
	unsigned long	NamePtr2;
	unsigned long	Zero2;
	unsigned long	Signature2;
	unsigned long	Unknown[24];
};

struct MaterialSubmeshHeader
{
  TagReference		ShaderTag;
  unsigned long		UnkZero2;
  unsigned long		VertIndexOffset;
  unsigned long		VertIndexCount;
  float				Centroid[3];
  float				AmbientColor[3];
  unsigned long		DistLightCount;
  float				DistLight1[6];
  float				DistLight2[6];
  float				unkFloat2[3];
  float				ReflectTint[4];
  float				ShadowVector[3];
  float				ShadowColor[3];
  float				Plane[4];
  unsigned long		UnkFlag2;
  unsigned long		UnkCount1;
  unsigned long		VertexCount1;
  unsigned long		UnkZero4;
  unsigned long		VertexOffset;
  unsigned long		Vert_Reflexive;
  unsigned long		UnkAlways3;
  unsigned long		VertexCount2;
  unsigned long		UnkZero9;
  unsigned long		UnkLightmapOffset;
  unsigned long		CompVert_Reflexive;
  unsigned long		UnkZero5[2];
  unsigned long		SomeOffset1;
  unsigned long		PcVertexDataOffset;
  unsigned long		UnkZero6;
  unsigned long		CompVertBufferSize;
  unsigned long		UnkZero7;
  unsigned long		SomeOffset2;
  unsigned long		VertexDataOffset;
  unsigned long		UnkZero8;
};

// **** BSP LUMPS END ****

#endif /* BSP_H */