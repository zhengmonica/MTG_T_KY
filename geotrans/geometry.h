#ifndef GEOMETRY_H_INCLUDED
#define GEOMETRY_H_INCLUDED

#ifdef WIN32
#ifdef GEOTRANS_MAKINGDLL
#define GEOTRANS_API __declspec(dllexport)
#else
#define GEOTRANS_API __declspec(dllimport)
#endif
#else
#define GEOTRANS_API extern
#endif

#ifdef __cplusplus
extern    "C" {
#endif


typedef struct point2d_t
{
    double x,y;
}point2d_t;

typedef struct point2d_t vector2d_t;


typedef struct transform2d_t
{
    double alf;   
    double scale; 
    double dx,dy;  
}transform2d_t;

typedef struct affine_t{
   double a1,a2,a3;
   double b1,b2,b3;
   double c1,c2,c3;
}affine_t;

typedef struct point3d_t
{
    double x,y,z;
}point3d_t;

typedef struct point3d_t vector3d_t;


typedef struct transform3d_t
{
    double epx,epy,epz; //(x-y-z)
    double dx,dy,dz;      
    double scale;        
    double a1,a2,a3;     
    double b1,b2,b3;
    double c1,c2,c3;
}transform3d_t;


typedef struct segment2d_t
{
    point2d_t node1;
    point2d_t node2;
}segment2d_t;


typedef struct polygon2d_t
{
    int num;
    point2d_t* nodes;
}polygon2d_t;

///ax+by+c=0;
typedef struct line2d_t
{
    double a,b,c;
}line2d_t;


typedef struct circle2d_t
{
    double x,y;
    double r;
}circle2d_t;

typedef struct circle3d_t
{
    double x,y,z;
    double r;
}circle3d_t;


//    a1x+b1y+c1z+d1=0;
//    a2x+b2y+c2z+d2=0
//    (x-x)/m=(y-y0)/n=(z-z0)/p;

typedef struct line3d_t
{
    double m,n,p;     ///
    double x0,y0,z0;  ///
}line3d_t;

//
//ax+by+cz+d=0
//
typedef struct plane_t
{
    double a,b,c,d;
}plane_t;



GEOTRANS_API void point2d_init(point2d_t* pt,double x,double y);
GEOTRANS_API double point2d_dist(const point2d_t* pt1,const point2d_t* pt2);
GEOTRANS_API void vector2d_init(vector2d_t* v,double dx,double dy);
GEOTRANS_API double vector2d_dir(const vector2d_t* v);
GEOTRANS_API void vector2d_add(const vector2d_t* v1,const vector2d_t* v2,vector2d_t* v3);
GEOTRANS_API void vector2d_sub(const vector2d_t* v1,const vector2d_t* v2,vector2d_t* v3);
GEOTRANS_API void vector2d_scale(vector2d_t* v,double s);
GEOTRANS_API double vector2d_plot(const vector2d_t* v1,const vector2d_t* v2);
GEOTRANS_API double vector2d_cross(const vector2d_t* v1,const vector2d_t* v2);
GEOTRANS_API double vector2d_length(const vector2d_t* v);


GEOTRANS_API void line2d_init(line2d_t* line,double a,double b,double c);
GEOTRANS_API int line2d_init_points(line2d_t* line,int n,const point2d_t* pts);
GEOTRANS_API void line2d_init_mid_perpend(line2d_t* line,const point2d_t* pt1,const point2d_t* pt2 );
GEOTRANS_API int line2d_intersect(const line2d_t* line1,const line2d_t* line2,point2d_t* pt);


GEOTRANS_API void segment2d_init(segment2d_t* seg,const point2d_t* pt1,const point2d_t* pt2);
GEOTRANS_API int segment2d_intersect(const segment2d_t* seg1,const segment2d_t* seg2,point2d_t* cross);
GEOTRANS_API int point2d_on_segment(const point2d_t* pt,const segment2d_t* seg);


GEOTRANS_API void circle2d_init(circle2d_t* cir,double x,double y,double r);
GEOTRANS_API int circle2d_init_points(circle2d_t* cir,int n,const point2d_t* pts);


GEOTRANS_API void circle3d_init(circle3d_t* cir,double x,double y,double z,double r);
GEOTRANS_API    int circle3d_init_points(circle3d_t* cir,int n,const point3d_t* pts,double *pout);


GEOTRANS_API void point3d_init(point3d_t* pt,double x,double y,double z);
GEOTRANS_API double point3d_dist(const point3d_t* pt1,const point3d_t* pt2);


GEOTRANS_API void vector3d_init(vector3d_t* v,double x,double y,double z);
GEOTRANS_API double vector3d_plot(const vector3d_t* v1,const vector3d_t* v2);
GEOTRANS_API void vector3d_cross(const vector3d_t* v1,const vector3d_t* v2,vector3d_t* v3);
GEOTRANS_API void vector3d_add(const vector3d_t* v1,const vector3d_t* v2,vector3d_t* v3);
GEOTRANS_API void vector3d_sub(const vector3d_t* v1,const vector3d_t* v2,vector3d_t* v3);
GEOTRANS_API void vector3d_scale(vector3d_t* v,double s);
GEOTRANS_API double vector3d_length(const vector3d_t* v);
GEOTRANS_API void vector3d_normal(vector3d_t* v);


GEOTRANS_API void line3d_init(line3d_t* line,const vector3d_t* v,const point3d_t* pt);
GEOTRANS_API int line3d_init_points(line3d_t* line,int n,const point3d_t* pts);
GEOTRANS_API void transform3d_init(transform3d_t* t,double epx,double epy,double epz,double dx,double dy,double dz,double s);
GEOTRANS_API    int transform3d_init_points(transform3d_t* t,int n,const point3d_t* pts1,const point3d_t* pts2,const int* flags);
GEOTRANS_API void transform3d_trans(const transform3d_t* t,const point3d_t* p1,point3d_t* p2);
GEOTRANS_API void transform3d_revtrans(const transform3d_t* t,const point3d_t* p1,point3d_t* p2);
GEOTRANS_API    void transform3d_trans_vector(const transform3d_t* t,const vector3d_t* v1,vector3d_t* v2);
GEOTRANS_API    void transform3d_revtrans_vector(const transform3d_t* t,const vector3d_t* v1,vector3d_t* v2);
GEOTRANS_API void transform3d_reverse(transform3d_t* forward,transform3d_t* back);

GEOTRANS_API void transform2d_init(transform2d_t* t,double alf,double scale,double dx,double dy);
GEOTRANS_API    int transform2d_init_points(transform2d_t* t,int n,const point2d_t* pts1,const point2d_t* pts2);
GEOTRANS_API void transform2d_trans(const transform2d_t* t,const point2d_t* p1,point2d_t* p2);
GEOTRANS_API void transform2d_revtrans(const transform2d_t* t,const point2d_t* p1,point2d_t* p2);
GEOTRANS_API    void transform2d_trans_vector(const transform2d_t* t,const vector2d_t* v1,vector2d_t* v2);
GEOTRANS_API    void transform2d_revtrans_vector(const transform2d_t* t,const vector2d_t* v1,vector2d_t* v2);

GEOTRANS_API void affine_init(affine_t* t,double m[9]);
GEOTRANS_API void affine_trans(affine_t* t,const point2d_t* p1,point2d_t *p2);
GEOTRANS_API void affine_revtrans(affine_t* t,const point2d_t* p1,point2d_t* p2);
GEOTRANS_API int affine_init_points(affine_t* t,int n,const point2d_t* pts1,const point2d_t* pts2);


GEOTRANS_API   plane_t* plane_create();
GEOTRANS_API   void plane_free(plane_t* p);
GEOTRANS_API   void plane_init(plane_t* p,double a,double b,double c,double d);
GEOTRANS_API   int plane_init_points(plane_t* p,int n,const point3d_t* pts);


GEOTRANS_API    void point_proj_on_line3d(const point3d_t *pt,const line3d_t *line,point3d_t* proj);
GEOTRANS_API    void point_proj_on_line2d(const point2d_t* pt,const line2d_t *line,point2d_t* proj);
GEOTRANS_API    double point_to_line3d(const point3d_t *pt,const line3d_t* line);
GEOTRANS_API    double point_to_line2d(const point2d_t* pt,const line2d_t* line);
GEOTRANS_API    double point_to_plane(const point3d_t* pt,const plane_t *plane);

GEOTRANS_API   void polygon2d_init(polygon2d_t* p,int n,double* xm,double* ym);
GEOTRANS_API   int polygon_crash_polygon2d(const polygon2d_t* p1,const polygon2d_t* p2);
GEOTRANS_API   int polygon_contain_polygon2d(const polygon2d_t* p1,const polygon2d_t* p2);
GEOTRANS_API   int point_in_polygon2d(const point2d_t* pt,const polygon2d_t* pl);

#ifdef __cplusplus
}
#endif

#endif // GEOMETRY_H_INCLUDED
