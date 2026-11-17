#include "bgapi.h"
#include "bgapi_init.h"
#include <stdio.h>
#include <stdlib.h>

int init_systems(int* system_count, void* externppSystem)
{
	BGAPI_RESULT res = BGAPI_RESULT_FAIL;
	int i = 0;
    //FILE* fp=fopen("F:init_systems.log","w");
	//this is the base call to find the bgapi_system modules which are necessary to perform any further action
	//every BGPAPI_Function returns a BGAPI_RESULT
	res = BGAPI_countSystems( system_count );
    //fprintf(fp,"system_count:%d\n",*system_count);
	//You should always check the result to make sure everything works fine
	if( res != BGAPI_RESULT_OK )
	{
		//in case of error you will get a result different from BGAPI_RESULT_OK
		//all resultcodes are defined in bgapiresult.h and are returned for special reasons
		trace(0, "BGAPI_CountSystems Errorcode: %d system_count %d\n", res, *system_count );
		//fprintf(fp, "BGAPI_CountSystems Errorcode: %d system_count %d\n", res, *system_count );
		return res;
	}

	//this is an example how to store pointers for all available systems
	*((BGAPI_System***)externppSystem) = (BGAPI_System**) malloc( sizeof (BGAPI_System*) * *system_count );

	for( i = 0; i < *system_count; i++ )
	{
		res = BGAPI_createSystem( i, &(*((BGAPI_System***)externppSystem))[i] );
		if( res != BGAPI_RESULT_OK )
		{
			trace(0,"BGAPI_CreateSystem Errorcode: %d Systemnumber %d SysPointer 0x%p\n", res, i, (void*) (*((BGAPI_System***)externppSystem))[i] );
			free( (*((BGAPI_System***)externppSystem)) );
			(*((BGAPI_System***)externppSystem)) = NULL;
			return res;
		}
		res = BGAPI_System_open( (*((BGAPI_System***)externppSystem))[i] );
		if( res != BGAPI_RESULT_OK )
		{
			trace(0, "BGAPI_System_open Systemnumber %d Errorcode: %d\n", i, res );
			free( (*((BGAPI_System***)externppSystem)) );
			(*((BGAPI_System***)externppSystem)) = NULL;
			return res;
		}
	}
    //fclose(fp);
	return res;
}

int init_camera(int system_count, void* externppSystem, int* pCurrSystem, void* externppCamera)
{
	BGAPI_RESULT res = BGAPI_RESULT_FAIL;
	int i = 0;
	int cam = 0;
	int* cameras = NULL;
	int camera_count = 0;
	BGAPI_FeatureState state;
	BGAPIX_CameraInfo cameradeviceinfo;
	int inputVal = 0;

	cameras = (int*)malloc( sizeof( int ) * system_count );

	for( i = 0; i < system_count; i++ )
	{
		//this is an example how to count available cameras for all available systems
		res = BGAPI_System_countCameras( ((BGAPI_System**)externppSystem)[i], &(cameras[i]) );
		if( res != BGAPI_RESULT_OK )
		{
			trace(0, "BGAPI_System_countCameras Systemnumber %d Errorcode: %d\n", i, res );
			return res;
		}

		for( cam = 0; cam < cameras[i]; cam++ )
		{
			camera_count++;

			//this is an example how to create a camera
			res = BGAPI_System_createCamera( ((BGAPI_System**)externppSystem)[i], cam, (BGAPI_Camera**)externppCamera );
			if( res != BGAPI_RESULT_OK )
			{
				trace(0,"\n");
				trace(0, "BGAPI_System_createCamera Systemnumber %d Errorcode: %d\n", i, res );
				return res;
			}

			//this is an example how to get the device information for a camera
			state.cbSize = sizeof( BGAPI_FeatureState );
			cameradeviceinfo.cbSize = sizeof( BGAPIX_CameraInfo );
			res = BGAPI_Camera_getDeviceInformation( *((BGAPI_Camera**)externppCamera), &state, &cameradeviceinfo );
			if( res != BGAPI_RESULT_OK )
			{
				trace(0,"\n");
				trace(0, "BGAPI_Camera_getDeviceInformation Errorcode: %d\n", res );
				return res;
			}
			trace(0,"%d select Camera %d of system %d - %s SN: %s\n", camera_count, cam, i, cameradeviceinfo.modelName, cameradeviceinfo.serialNumber );
			BGAPI_System_releaseCamera( ((BGAPI_System**)externppSystem)[i], *((BGAPI_Camera**)externppCamera) );
		}
	}

	do
	{
		fflush( stdin );fflush( stdout );
		scanf( "%d", &inputVal );
	}
	while( inputVal < 0 || inputVal > camera_count );

	camera_count = 0;
	for( i = 0; i < system_count; i++ )
	{
		for( cam = 0; cam < cameras[i]; cam++ )
		{
			camera_count++;

			if( camera_count == inputVal )
			{
				*pCurrSystem = i;

				//this is an example how to create a camera
				res = BGAPI_System_createCamera( ((BGAPI_System**)externppSystem)[*pCurrSystem], cam, (BGAPI_Camera**)externppCamera );
				if( res != BGAPI_RESULT_OK )
				{
					trace(0,"\n");
					trace(0, "BGAPI_System_createCamera Systemnumber %d Errorcode: %d\n", i, res );
					return res;
				}

				//this is an example how to open a camera
				res = BGAPI_Camera_open( *(BGAPI_Camera**)externppCamera );
				if( res != BGAPI_RESULT_OK )
				{
					trace(0,"\n");
					trace(0, "BGAPI_Camera_open Systemnumber %d Errorcode: %d\n", i, res );
					return res;
				}
				break;
			}
		}
	}
	return res;
}

int release_systems(int system_count, void* ppSystem )
{
	BGAPI_RESULT res = BGAPI_RESULT_FAIL;
	int i = 0;

	for( i = 0; i < system_count; i++ )
	{
		res = BGAPI_System_release( ((BGAPI_System**)ppSystem)[i] );
		if( res != BGAPI_RESULT_OK )
		{
			trace(0, "BGAPI_System_release %d Errorcode: %d\n", i, (int)res );
		}
		((BGAPI_System**)ppSystem)[i] = NULL;
	}

	return res;
}

int release_images(int image_count, void* ppImage )
{
	BGAPI_RESULT res = BGAPI_RESULT_FAIL;
	int i = 0;
	BGAPI_bool tmpExtern = BGAPI_false;
	unsigned char* tmpBuffer = NULL;

	for( i = 0; i < image_count; i++ )
	{
		res = BGAPI_Image_isExternBuffer( ((BGAPI_Image**)ppImage)[i], &tmpExtern );
		if( res != BGAPI_RESULT_OK )
		{
			trace(0, "BGAPI::Image::isExternBuffer %d Errorcode: %d\n", i, (int)res );
		}

		if( tmpExtern == BGAPI_true )
		{
			res = BGAPI_Image_getBuffer( ((BGAPI_Image**)ppImage)[i], &tmpBuffer );
			if( res != BGAPI_RESULT_OK )
			{
				trace(0, "BGAPI::Image::getBuffer %d Errorcode: %d\n", i, (int)res );
			}
			else
			{
				free( tmpBuffer );
			}
		}
		res = BGAPI_releaseImage( ((BGAPI_Image**)ppImage)[i] );
		if( res != BGAPI_RESULT_OK )
		{
			trace(0, "BGAPI_Image_release %d Errorcode: %d\n", i, (int)res );
		}
		((BGAPI_Image**)ppImage)[i] = NULL;
	}

	return res;
}
