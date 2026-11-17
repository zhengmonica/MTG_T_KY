#ifndef __LIBELE_H__
#define __LIBELE_H__

#ifdef WIN32
#ifdef LIBELE_MAKINGDLL
#define LIBELE_API __declspec(dllexport)
#else
#define LIBELE_API __declspec(dllimport)
#endif
#else
#define LIBELE_API
#endif

#ifdef __cplusplus
extern "C" {
#endif


#ifdef _WIN32
#pragma pack(push, 1)
#endif

/* command group definition */
#define CMD_GET_TIME 0x01
#define CMD_SET_MACHINE_ID 0x02
#define CMD_GET_MACHINE_ID 0x03

#define IO_PACKAGE_HEADER_SIZE 	2    //IO package header length:tag+len
#define MAX_IO_DATA_SIZE	0xf5 // maximum IO data size

/* IO package */
typedef struct _IO_PACKAGE
{
	unsigned char tag;
	unsigned char len;
	unsigned char buff[MAX_IO_DATA_SIZE];
} IO_PACKAGE;

#ifdef _WIN32
#pragma pack(pop)
#endif


LIBELE_API int DoSense(const char* vendor,const char* model,IO_PACKAGE* pIn,IO_PACKAGE* pOut);
LIBELE_API int GetMacAddress(char addr[][13],int num);


#ifdef __cplusplus
}
#endif

#endif //__LIBELE_H__
