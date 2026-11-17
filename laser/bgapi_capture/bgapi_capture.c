/******************************************************************/
/*                                                                */
/*  This is a basic BGAPI example for C                           */
/*  It will show you how to use systems and cameras               */
/*  and everything you need to know for basic initialization.     */
/*                                                                */  
/******************************************************************/


#include "bgapi.h"
#include "bgapi_init.h"

#include <stdlib.h>
#include <stdio.h>

BGAPI_RESULT BGAPI_CALLBACK imageCallback( void * callBackOwner, BGAPI_Image* pImage  )
{
	BGAPI_RESULT res = BGAPI_RESULT_OK;
	unsigned char* imagebuffer = NULL;
	int swc = 0;
	int hwc = 0;

	BGAPI_Image_get( pImage, &imagebuffer );
	//Now you have the Imagebuffer and can do everything with it you want

	BGAPI_Image_getNumber( pImage, &swc, &hwc );
	printf("Image number %d.\r", swc );
	fflush( stdout );

	//after ou are ready with this image, return it to the camera for the next image
	BGAPI_Camera_setImage( (BGAPI_Camera*) callBackOwner, pImage );

	return res;
}

int main()
{
	int system_count = 0;
	int image_count = 0;
	BGAPI_System **ppSystem = NULL;
	BGAPI_Camera *pCamera = NULL;
	BGAPI_Image **ppImage = NULL; 
	int currSystem = 0;
	BGAPIX_TypeListINT listint;
	BGAPI_FeatureState state;
	BGAPIX_TypeINT intNumberofbuffer;
	BGAPIX_TypeRangeINT dataLen;
	int i = 0;
	int inputVal = -1;
	
	BGAPI_RESULT res = BGAPI_RESULT_FAIL;

	printf("*******************************************************************************\n");
	printf("*                                                                             *\n");
	printf("*            Welcome to BGAPI_CAPTURE Example for Version 1.6.X.X             *\n");
	printf("*                                                                             *\n");
	printf("*******************************************************************************\n");
	printf("\n");
	printf("This example will show you how to capture frames with BGAPI in C.\n");
	printf("\n");
	printf("The first step is to initialize the systems and cameras.\n");
	printf("How to do this is explained in BGAPI_INIT example.\n");
	printf("\n");

	//init the system like shown in bgapi_init example
	res = init_systems( &system_count, (void*)&ppSystem );
	if( res != BGAPI_RESULT_OK )
	{
		printf("init_systems Errorcode: %d\n", res);
	}

	//select a camera to use
	res = init_camera( system_count, (void*)ppSystem, &currSystem, (void*)&pCamera );
	if( res != BGAPI_RESULT_OK )
	{
		printf("init_camera Errorcode: %d\n", res);
	}
	
	listint.cbSize = sizeof( BGAPIX_TypeListINT );
	state.cbSize = sizeof( BGAPI_FeatureState );
	intNumberofbuffer.cbSize = sizeof( BGAPIX_TypeINT );
	dataLen.cbSize = sizeof ( BGAPIX_TypeRangeINT );

	res = BGAPI_Camera_getDataAccessMode( pCamera, &state, &listint, &intNumberofbuffer );
	if( res != BGAPI_RESULT_OK )
	{
		printf("getDataAccessMode returned with errorcode %d\n", res );
	}
	
	for( i = 0; i < listint.length; i++ )
	{
		printf("%d select DataAccessMode %s\n", i, (listint.array[i] == BGAPI_DATAACCESSMODE_NORMALINTERN)? "NORMALINTERN" : (listint.array[i] == BGAPI_DATAACCESSMODE_NORMALEXTERN)? "NORMALEXTERN" : (listint.array[i] == BGAPI_DATAACCESSMODE_QUEUEDINTERN)? "QUEUEDINTERN"  : (listint.array[i] == BGAPI_DATAACCESSMODE_QUEUEDEXTERN)? "QUEUEDEXTERN" : "UNKNOWN");
	}

	do
	{
		fflush( stdin );fflush( stdout );
		scanf( "%d", &inputVal );
	}
	while( inputVal < 0 || inputVal > listint.length );
	
	
	res = BGAPI_Camera_setDataAccessMode( pCamera, (BGAPI_DataAccessMode)listint.array[inputVal], intNumberofbuffer.current);
	if (res != BGAPI_RESULT_OK)
	{
		printf("getDataAccessMode returned with errorcode %d\n", res);
	}

	res = BGAPI_Camera_getDataAccessMode( pCamera, &state, &listint, &intNumberofbuffer );
	if( res != BGAPI_RESULT_OK )
	{
		printf("BGAPI::Camera::getDataAccessMode returned with errorcode %d\n", res );
	}
	

	if( listint.array[listint.current] == BGAPI_DATAACCESSMODE_NORMALINTERN || listint.array[listint.current] == BGAPI_DATAACCESSMODE_NORMALEXTERN )
	{
		ppImage = (BGAPI_Image**)malloc( sizeof( BGAPI_Image* )  );

		//create image object
		res = BGAPI_createImage( &ppImage[0] ); 
		if( res != BGAPI_RESULT_OK )
		{
			printf("BGAPI_createImage for Image 0 returned with errorcode %d\n", res );
		}
		image_count++;
		
		if((BGAPI_DataAccessMode)listint.array[listint.current] == BGAPI_DATAACCESSMODE_NORMALEXTERN)
		{
			//allocate memory
			res = BGAPI_Camera_getDataLength( pCamera, &state, &dataLen );
			if( res != BGAPI_RESULT_OK )
			{
				printf("BGAPI::Camera::getDataLength for Image 0 returned with errorcode %d\n", res );
			}
			res = BGAPI_Image_setBuffer( ppImage[0], (unsigned char*) malloc( dataLen.current ), dataLen.current );
			if( res != BGAPI_RESULT_OK )
			{
				printf("BGAPI::Image::setBuffer for Image 0 returned with errorcode %d\n", res );
			}
		}

		res = BGAPI_Camera_setImage( pCamera, ppImage[0] );
		if( res != BGAPI_RESULT_OK )
		{
			printf("BGAPI_Camera_setImage for Image 0 returned with errorcode %d\n", res );
		}
		
	}
	else if( listint.array[listint.current] == BGAPI_DATAACCESSMODE_QUEUEDINTERN || listint.array[listint.current] == BGAPI_DATAACCESSMODE_QUEUEDEXTERN )
	{
		ppImage = (BGAPI_Image**)malloc( sizeof( BGAPI_Image* ) * intNumberofbuffer.current );

		//create image objects
		for(i = 0; i < intNumberofbuffer.current; i++)
		{
			res = BGAPI_createImage( &ppImage[i] ); 
			if( res != BGAPI_RESULT_OK )
			{
				printf("BGAPI_createImage for Image %d returned with errorcode %d\n", i, res );
				break;
			}
			image_count++;

			if((BGAPI_DataAccessMode)listint.array[listint.current] == BGAPI_DATAACCESSMODE_QUEUEDEXTERN)
			{
				//allocate memory
				res = BGAPI_Camera_getDataLength( pCamera, &state, &dataLen );
				if( res != BGAPI_RESULT_OK )
				{
					printf("BGAPI::Camera::getDataLength for Image %d returned with errorcode %d\n", i, res );
				}
				res = BGAPI_Image_setBuffer( ppImage[i], (unsigned char*) malloc( dataLen.current ), dataLen.current );
				if( res != BGAPI_RESULT_OK )
				{
					printf("BGAPI::Image::setBuffer for Image %d returned with errorcode %d\n", i, res );
				}
			}
			
			res = BGAPI_Camera_setImage( pCamera, ppImage[i] );
			if( res != BGAPI_RESULT_OK )
			{
				printf("BGAPI_Camera_setImage for Image %d returned with errorcode %d\n", i, res );
				break;
			}
		}
	} 

	res = BGAPI_Camera_registerNotifyCallback( pCamera, pCamera, (BGAPI_NOTIFY_CALLBACK_C)&imageCallback );
	if( res != BGAPI_RESULT_OK )
	{
		printf( "Error %d while register NotifyCallback.\n", res );
	}

	res = BGAPI_Camera_setStart( pCamera, BGAPI_true );
	if( res != BGAPI_RESULT_OK )
	{
		printf("BGAPI_Camera_setStart for Image %d returned with errorcode %d\n", i, res );
	}


	printf(" Press 's' + [ENTER] to stop.\n");
	//add a check for input here if needed
	scanf( "%d", &i );

	//stop the camera when you are done with the capture
	res = BGAPI_Camera_setStart( pCamera, BGAPI_false );
	if( res != BGAPI_RESULT_OK )
	{
		printf("BGAPI_Camera_setStart Errorcode: %d\n", res);
	}

	printf("\n"); 
	printf("At the end of this example (like in every programm )we release the resources.\n"); 
	//release the system like shown in bgapi_init example
	res = release_systems( system_count, (void*)ppSystem );
	if( res != BGAPI_RESULT_OK )
	{
		printf("release_systems Errorcode: %d\n", res);
	}
	res = release_images( image_count, (void*)ppImage );
	if( res != BGAPI_RESULT_OK )
	{
		printf("release_images Errorcode: %d\n", res);
	}

	return 0;

}
