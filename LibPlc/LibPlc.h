// LibPlc.h : main header file for the LIBPLC DLL
//

#if !defined(AFX_LIBPLC_H__25DF2A80_8F8A_40DF_B69F_DE7F1A105B09__INCLUDED_)
#define AFX_LIBPLC_H__25DF2A80_8F8A_40DF_B69F_DE7F1A105B09__INCLUDED_

//#include "libmtg.h"

#ifdef WIN32
#ifdef LIBPLC_MAKINGDLL
#define LIBPLC_API __declspec(dllexport)
#else
#define LIBPLC_API __declspec(dllimport)
#endif
#else
#define LIBPLC_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct plc_unit_t
{
	int type;      ///0-null,2-int,5-double,11-bool,3-long
	int readorwrite;    ///0-read,1-write
	int val_int;
	double val_double;
	long val_long;
	LPWSTR szItemID;       ///address
	DWORD vtDataTypeItem;  ///value
	double val_add,val_mul;   ///add means additive,mul means multiplying
	double val_result;
	int status;     ///地址状态,1表示获取成功，0表示该地址不可用
}plc_unit_t;

typedef struct mtg_tp
{
    int nunit;
    plc_unit_t units[300];
    LPWSTR ProgID;
    char IDname[1024];
	LPWSTR GroupName;
	int read_plc_complete;
	int write_plc_complete;
	int type;       ///0表示西门子PLC 1表示三菱PLC

}mtg_tp;

extern LIBPLC_API mtg_tp testP;

///PLC数据读写
extern LIBPLC_API int init_plc(char* path);    ///结构体已声明，把指针传进来
extern LIBPLC_API void read_plc();
extern LIBPLC_API void write_plc();
extern LIBPLC_API void uninit_plc();
extern LIBPLC_API void OnCheckActivategroup();
extern LIBPLC_API void free_plc();

//extern LIBPLC_API int read_plc_complete;
/////读取PLC内容
//
//extern LIBPLC_API int read_plc_start_val;
//extern LIBPLC_API double read_plc_uaj_val;            // 推进油缸行程A组
//
/////写入PLC内容
//extern LIBPLC_API double write_plc_roll1_val;         // 俯仰角1(盾体轴线与第一节盾体水平线之间的夹角)
//
//extern LIBPLC_API int write_plc_numb1_val;            // 掘进编号（除管环编号外）


extern LIBPLC_API int plc_data;


#ifdef __cplusplus
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBPLC_H__25DF2A80_8F8A_40DF_B69F_DE7F1A105B09__INCLUDED_)
