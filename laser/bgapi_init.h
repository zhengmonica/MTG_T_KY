#ifndef __BGAPI_INIT_H__
#define __BGAPI_INIT_H__

#ifdef __cplusplus
extern "C"
{
#endif


int init_systems(int* system_count, void* externppSystem);
int init_camera(int system_count, void* externppSystem,int* pCurrSystem, void* externppCamera);
int release_systems(int system_count, void* ppSystem );
int release_images(int image_count, void* ppImage);


#ifdef __cplusplus
}
#endif


#endif // __BGAPI_INIT_H__
