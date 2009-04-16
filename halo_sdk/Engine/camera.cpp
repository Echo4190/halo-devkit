#include "camera.h"

CCamera::CCamera()
{
	camera = (Camera*)CAMERA_ADDRESS;
	aspect_ratio = 4.0f/3.0f;
}

CCamera::~CCamera()
{
}

void CCamera::CreateViewMatrix(vect3 Eye, vect3 LookAt, vect3 Up)
{
	vEye = Eye;
	vLookAt = LookAt;
	vUp = Up;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp);
}

void CCamera::CreateProjectionMatrix(float Fov, float Aspect, float Near, float Far)
{
	D3DXMatrixPerspectiveFovLH(&matProj, Fov, Aspect, Near, Far);
}

void CCamera::CreateWorldMatrix(vect3 World)
{
	D3DXMatrixTranslation(&matWorld, World.x, World.y, World.z);
}

vect3 CCamera::WorldToScreen(vect3 coord)
{
	float Y_fov = camera->Fov / aspect_ratio;
	vect3 cam_to_obj(coord.x - camera->vWorld.x, coord.y - camera->vWorld.y, coord.z - camera->vWorld.z);
	float dist_to_obj = sqrt(cam_to_obj.x*cam_to_obj.x + cam_to_obj.y*cam_to_obj.y + cam_to_obj.z*cam_to_obj.z);
	D3DXVec3Normalize(&cam_to_obj, &cam_to_obj);

	// All angles are in radians, -PI<angle<PI, and no i dont know which could be equal to. but who cares - it's a float so it's impossible.
	float cam_yaw = atan2f(camera->vLookAt.y, camera->vLookAt.x);
	float obj_yaw = atan2f(cam_to_obj.y, cam_to_obj.x);

	// Relative(to cam) yaw ends up from -2 PI < yaw < 2 PI, but we want it from -PI<yaw<PI
	float relative_yaw = obj_yaw - cam_yaw;
	if(relative_yaw > D3DX_PI) // yaw>180 degrees. convert to negative, smaller.
		relative_yaw -= 2*D3DX_PI;
	if(relative_yaw < -D3DX_PI)
		relative_yaw += 2*D3DX_PI;
	// [/Difference]

	float obj_pitch = asin(cam_to_obj.z);
	float cam_pitch = asin(camera->vLookAt.z);

	float relative_pitch = cam_pitch - obj_pitch;
	float x_pos = -relative_yaw * 2 / camera->Fov; // radian angle measurement cancels here.
	float y_pos = relative_pitch * 2 / Y_fov; // and that's the (relative pitch) / (fov / 2)

	x_pos = (x_pos + 1) / 2; // Lastly, change from range (-1,1) to (0,1)  Also, it CAN be outside of that range - if it's outside of the FOV.
	y_pos = (y_pos + 1) / 2;

	vect3 onscreen(x_pos, y_pos, dist_to_obj);
	return onscreen;
}