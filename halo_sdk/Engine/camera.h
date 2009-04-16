#ifndef CAMERA_H
#define CAMERA_H

#include <windows.h>
#include <d3dx9math.h>
#include "types.h"

#define CAMERA_ADDRESS 0x006AC4DC;

#define FOV_XBOUND 0.024f
#define FOV_YBOUND 0.012f
#define OBJECT_CLIP 17

struct Camera
{
	WORD Unknown1;
	short wPerspective; // First Person( 0 ), Third Person( 1 ), Dead( 3 )
	DWORD Unknown2; 

	vect3 vWorld; // x,y,z ( game units )
	vect3 fShift; // x,y,z ( forward/back,side,vertical )( game units )
	float fDepth;
	float Fov;      // in radians ( default = 70 degrees )
	vect3 vLookAt;
	vect3 fUp;
	vect3 fVelocity;

	DWORD Unknown3[26];

	vect3 fWorld2;
	vect3 fShift2; // x,y,z ( forward/back,side,vertical )( game units )
	float fDepth2;
	float Fov2;      // in radians ( default = 70 degrees )
	vect3 fForward2;
	vect3 fUp2;
	vect3 fVelocity2;

	DWORD Unknown4[9];
	vect3 fWorld3;
	DWORD Unknown5[5];
	vect3 fForward3;
	vect3 fUp3;
	float fFov3;

	vect3 fWorld4;
	DWORD Unknown6[4];
	float fFov4;
	vect3 fForward4;
	vect3 fUp4;
};

class CCamera
{
public:
	CCamera();
	~CCamera();

	Camera* camera;
	
	D3DXVECTOR3 vEye;
	D3DXVECTOR3 vLookAt;
	D3DXVECTOR3 vUp;

	D3DXMATRIX matView;
	D3DXMATRIX matProj;
	D3DXMATRIX matWorld;

	D3DXVECTOR3 vScreen;
	D3DXVECTOR3 vWorld;

	float aspect_ratio;

	void CreateViewMatrix(vect3 fEye, vect3 vLookAt, vect3 fUp);
	void CreateProjectionMatrix(float fFov, float fAspect, float fNear, float fFar);
	void CreateWorldMatrix(vect3 fWorld);
	float GetAspectRatio();
	vect3 WorldToScreen(vect3 object_world);
};

#endif /* CAMERA_H */