/*****************************************
?matrix.h
?
??
?20101215
******************************************/
#ifndef MATRIX_H_INCLUDE
#define MATRIX_H_INCLUDE

#ifdef __cplusplus
 extern "C"{
#endif

/*?*////result=m1*m2
  void  matmul(const double *m1,const double *m2,double *result,int i_1,int j_12,int j_2);
/*?*/
  int  matinv(double *m1,int n);
/*??*/
  void  mattrans(const double *m1,double *m2,int m,int n);
/*?*/
  void  matinv_pos(double *a,int n);
/* solve linear equation -------------------------------------------------------
* solve linear equation (X=A\Y or X=A'\Y)
* args   : double *A        I   input matrix A (n x n)
*          double *Y        I   input matrix Y (n x m)
*          int    n,m       I   size of matrix A,Y
*          double *X        O   X=A\Y or X=A'\Y (n x m)
* return : status (0:ok,0>:error)
* notes  : matirix stored by column-major order (fortran convention)
*          X can be same as Y
*-----------------------------------------------------------------------------*/
  int solve(const double *A, const double *y, int n,int m, double *x);
/*§³?*/
/* least square estimation -----------------------------------------------------
* least square estimation by solving normal equation (x=(A*A')^-1*A*y)
* args   : double *A        I   design matrix (m x n)
*          double *y        I   (weighted) measurements (m x 1)
*          int    n,m       I   number of parameters and measurements (n<=m)
*          double *x        O   estmated parameters (n x 1)
*          double *Q        O   esimated parameters covariance matrix (n x n)
* return : status (0:ok,0>:error)
* notes  : for weighted least square, replace A and y by A*w and w*y (w=W^(1/2))
*          matirix stored by column-major order (fortran convention)
*-----------------------------------------------------------------------------*/
  int  lsq (const double *A, const double *y, int n, int m, double *x,double *Q);


#ifdef __cplusplus
}
#endif

#endif
