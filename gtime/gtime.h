#ifndef GTIME_H
#define GTIME_H

#include <stdio.h>
#include <time.h>

#ifdef WIN32
#ifdef GTIME_MAKINGDLL
#define GTIME_API __declspec(dllexport)
#else
#define GTIME_API __declspec(dllimport)
#endif
#else
#define GTIME_API extern
#endif

#ifdef WIN32
#define FILEPATHSEP '\\'
#include <windows.h>
#else
#include <sys/time.h>
#include <dirent.h>
#define FILEPATHSEP '/'
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {        /* time struct */
    time_t time;        /* time (s) expressed by standard time_t */
    double sec;         /* fraction of second under 1 s */
} gtime_t;

/* time and string functions -------------------------------------------------*/
GTIME_API double  str2num(const char *s, int i, int n);
GTIME_API int     str2time(const char *s, int i, int n, gtime_t *t);
GTIME_API void    time2str(gtime_t t, char *str, int n);
GTIME_API gtime_t epoch2time(const double *ep);
GTIME_API void    time2epoch(gtime_t t, double *ep);
GTIME_API gtime_t gpst2time(int week, double sec);
GTIME_API double  time2gpst(gtime_t t, int *week);
GTIME_API gtime_t gst2time(int week, double sec);
GTIME_API double  time2gst(gtime_t t, int *week);
GTIME_API char    *time_str(gtime_t t, int n);

GTIME_API gtime_t timeadd  (gtime_t t, double sec);
GTIME_API double  timediff (gtime_t t1, gtime_t t2);
GTIME_API gtime_t gpst2utc (gtime_t t);
GTIME_API gtime_t utc2gpst (gtime_t t);
GTIME_API gtime_t timeget  (void);
GTIME_API void    timeset  (gtime_t t);
GTIME_API double  time2doy (gtime_t t);

GTIME_API int adjgpsweek(int week);
GTIME_API unsigned int tickget(void);
GTIME_API void sleepms(int ms);

GTIME_API int reppath(const char *path, char *rpath, gtime_t time, const char *rov,
                   const char *base);
GTIME_API int reppaths(const char *path, char *rpaths[], int nmax, gtime_t ts,
                    gtime_t te, const char *rov, const char *base);
GTIME_API int uncompress(const char *file, char *uncfile);

 /* platform dependent functions ----------------------------------------------*/
GTIME_API int execcmd(const char *cmd);
GTIME_API int expath (const char *path, char *paths[], int nmax);
GTIME_API void createdir(const char *path);

#ifdef __cplusplus
}
#endif

#endif
