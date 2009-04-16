#ifndef HALO_TYPES_H
#define HALO_TYPES_H
#include <windows.h>
#include <d3dx9math.h>
////////////////////////////////////////
// Generic Halo Types
////////////////////////////////////////
#define INVALID -1
#define vect2 D3DXVECTOR2
#define vect3 D3DXVECTOR3

struct bone
{
	float	Scale;
	vect3	Transform[3];
	vect3	World;
};

struct ident
{
	short	Index;
	short	ID;
};

struct pinfo
{
	char	MachineIndex;
	char	Unknown;
	char	Team;
	char	PlayerIndex;
};

struct DataHeader
{
	char				Name[32];
	unsigned short		Max;		// Max number of <things> possible
	unsigned short		Size;		// Size of each <thing> class instance
	bool				IsValid;
	bool				IdentifierZeroInvalid;
	short				Padding;
	unsigned long		Signature;	// d@t@
	short				NextIndex;
	short				LastIndex;
	ident				Next;		// the next <thing> to be initialized
	void*				First;		// Pointer to the first <thing> class instance
};

#endif /* HALO_TYPES_H */