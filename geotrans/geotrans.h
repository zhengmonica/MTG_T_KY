#ifndef GEOTRANS_H_INCLUDED
#define GEOTRANS_H_INCLUDED

#ifdef WIN32
#ifdef GEOTRANS_MAKINGDLL
#define GEOTRANS_API __declspec(dllexport)
#else
#define GEOTRANS_API __declspec(dllimport)
#endif
#else
#define GEOTRANS_API extern
#endif

/**/
#define COORD_TYPE_GEOCENTRIC 0
#define COORD_TYPE_GEODETIC   1
#define COORD_TYPE_CARTESION  2


typedef struct Ellipsoid Ellipsoid;
typedef struct Datum Datum;
typedef struct GeoPoint GeoPoint;
typedef struct Param7 Param7;
typedef struct Param4 Param4;
typedef struct Proj Proj;

struct Param7    ///?
{
    double Delta_X;
    double Delta_Y;
    double Delta_Z;
    double Rotation_X;
    double Rotation_Y;
    double Rotation_Z;
    double Scale;
};

struct Param4
{
    double Delta_Easting;
    double Delta_Northing;
    double Rotaion_Horizon;
    double Scale_Horizon;
};

struct Proj
{
    double Central_Meridian;       //?
    double Origin_Latitude;        //?¶√
    double False_Northing;         //?
    double False_Easting;          //?
    double Scale_Factor;           //?
};

struct Datum  ///?
{
    char Name[64];
    ///
    char Ellipsoid_Name[64];
    double a;
    double f;
    ///?(WGS84)
    double Delta_X;
    double Delta_Y;
    double Delta_Z;
    double Rotation_X;
    double Rotation_Y;
    double Rotation_Z;
    double Scale;
    ///??
    double Central_Meridian;       //?
    double Origin_Latitude;        //?¶√
    double False_Northing;         //?
    double False_Easting;          //?
    double Scale_Factor;           //?
    ///???
    double Delta_Easting;
    double Delta_Northing;
    double Rotaion_Horizon;
    double Scale_Horizon;
    ///??
    /*char Geoid_File_Name[260];
    int Geoid_Cols;
    int Geoid_Rows;
    double* Geoid_Grid;*/
};

struct GeoPoint
{
    ///
    char Name[64];
	///?
	char CoordinateSystem[64];
    ///
    int Type;
    ///
    union
    {
        struct///
        {
            double x;
            double y;
            double z;
        };
        struct///
        {
            double Longitude;          //
            double Latitude;           //¶√
            double Height;             //?
        };
        struct///???
        {
            double Northing;           //
            double Easting;            //
            double Elevation;             //?
        };
    }Coordinate;
};

//
struct Ellipsoid
{
    char Name[64];         //
    double a;                  //
    double f;                //
} ;


#ifdef __cplusplus
GEOTRANS_API "C"{
#endif

GEOTRANS_API int ImportDatum(const char* file);
GEOTRANS_API int ExportDatum(const char* file);

GEOTRANS_API int CountEllipsoid();
GEOTRANS_API int DefineEllipsoid(const char* code,double a,double f);
GEOTRANS_API Ellipsoid* EllipsoidName(const char* code);
GEOTRANS_API Ellipsoid* EllipsoidIndex(int index);
GEOTRANS_API int RemoveElliosoid(int index);

/*
*???
*/
GEOTRANS_API int CountDatum();
/**
*??
*code,?
**/
GEOTRANS_API Datum* DatumName(const char* code);
GEOTRANS_API Datum* DatumIndex(int index);
GEOTRANS_API int RemoveDatum(int index);
/**
*?
*Name,?
*EllipseName,
*p7,?
*prj,??
*p4????
*GeoidFile???
**/
GEOTRANS_API int DefineDatum(const char* Name,
                        const char* eName,
                        const Param7* p7,
                        const Proj* prj,
                        const Param4* p4);
/*?
 *t?
 *nn?
 *src??
 *dest??
 */
GEOTRANS_API  int CalParam7(Param7 *p7,
                      int n,
                      const GeoPoint* src,
                      const GeoPoint* dest);

/*?»Œ
*forward: ??
*back:    ??
*/
GEOTRANS_API  void RevParam7(Param7* forword,Param7* back);


/*
 *?
 *Coordinate_In  ?
 *Coordinate_Out ?
 */
GEOTRANS_API  int TranslateCoordinate(const GeoPoint* Coordinate_In,GeoPoint* Coordinate_Out);


#ifdef __cplusplus
}
#endif
#endif // GEOTRANS_H_INCLUDED
