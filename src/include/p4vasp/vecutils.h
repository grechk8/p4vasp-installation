/*
 *  p4vasp is a GUI-program and library for processing outputs of the
 *  Vienna Ab-inition Simulation Package (VASP)
 *  (see http://cms.mpi.univie.ac.at/vasp/Welcome.html)
 *  
 *  Copyright (C) 2003  Orest Dubay <odubay@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef vecutils_h
#define vecutils_h
#ifndef _MATH_H
#include <math.h>
#endif
#include <stdio.h>
#include <string.h>

double *cross(double *dest,double *a,double *b);
double *add(double *dest,double *a,int dim=3);
double *add(double *dest,double *a,double *b,int dim=3);
double *add(double *dest,double c,double *a,int dim=3);
double *sub(double *dest,double *a,int dim=3);
double *mul(double *dest,double a,int dim=3);
double *mul(double *dest,double *a,int dim=3);
double *div(double *dest,double a,int dim=3);
double *div(double *dest,double *a,int dim=3);
double *copy(double *dest,double *a,int dim=3);
double sum(double *dest,int dim=3);
double veclength(double *dest,int dim=3);
double scalmul(double *a,double *b,int dim=3);
double *normalizevec(double *v,int dim=3);

double *mulmatvec(double *dest,double *a,double *v,int n=3,int m=-1);
double *mulmatvec(double *a,double *v,int n=3,int m=-1);
double *addmulmatvec(double *dest,double *a,double *v,int n=3,int m=-1);
double *mulmatmat(double *dest,double *a,double *b,int n=3,int m=-1,int o=-1);
double *addmulmatmat(double *dest,double *a,double *b,int n=3,int m=-1,int o=-1);
double *identitymat(double *dest,int n=3);
void fprintmat(FILE *f,double *dest,int n=3,int m=-1);
void printmat(double *dest,int n=3,int m=-1);


inline double *add3(double *dest,double *a){
  dest[0]+=a[0];
  dest[1]+=a[1];
  dest[2]+=a[2];
  return dest;
}

inline double *add3(double *dest,double c,double *a){
  dest[0]+=c*a[0];
  dest[1]+=c*a[1];
  dest[2]+=c*a[2];
  return dest;
}

inline double *add3(double *dest,double *a,double *b){
  dest[0]=a[0]+b[0];
  dest[1]=a[1]+b[1];
  dest[2]=a[2]+b[2];
  return dest;
}


inline double *sub3(double *dest,double *a){
  dest[0]-=a[0];
  dest[1]-=a[1];
  dest[2]-=a[2];
  return dest;
}

inline double *mul3(double *dest,double a){
  dest[0]*=a;
  dest[1]*=a;
  dest[2]*=a;
  return dest;
}

inline double *mul3(double *dest,double *a){
  dest[0]*=a[0];
  dest[1]*=a[1];
  dest[2]*=a[2];
  return dest;
}

inline double *div3(double *dest,double a){
  dest[0]/=a;
  dest[1]/=a;
  dest[2]/=a;
  return dest;
}

inline double *div3(double *dest,double *a){
  dest[0]/=a[0];
  dest[1]/=a[1];
  dest[2]/=a[2];
  return dest;
}

inline double *copy3(double *dest,double *a){
  dest[0]=a[0];
  dest[1]=a[1];
  dest[2]=a[2];
  return dest;
}

inline double sum3(double *dest){
  return dest[0]+dest[1]+dest[2];
}

inline double veclength3(double *dest){
  return sqrt(dest[0]*dest[0]+dest[1]*dest[1]+dest[2]*dest[2]);
}

inline double scalmul3(double *a,double *b){
  return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
}

inline double *mulmatvec3(double *dest,double *a,double *v){
  dest[0]=a[0]*v[0]+a[1]*v[1]+a[2]*v[2];
  dest[1]=a[3]*v[0]+a[4]*v[1]+a[5]*v[2];
  dest[2]=a[6]*v[0]+a[7]*v[1]+a[8]*v[2];
  return dest;
}
inline double *mulmatvec3(double *a,double *v){
  double dest[3];
  dest[0]=a[0]*v[0]+a[1]*v[1]+a[2]*v[2];
  dest[1]=a[3]*v[0]+a[4]*v[1]+a[5]*v[2];
  dest[2]=a[6]*v[0]+a[7]*v[1]+a[8]*v[2];
  v[0]=dest[0];
  v[1]=dest[1];
  v[2]=dest[2];
  return v;
}
inline double *addmulmatvec3(double *dest,double *a,double *v){
  dest[0]+=a[0]*v[0]+a[1]*v[1]+a[2]*v[2];
  dest[1]+=a[3]*v[0]+a[4]*v[1]+a[5]*v[2];
  dest[2]+=a[6]*v[0]+a[7]*v[1]+a[8]*v[2];
  return dest;
}

inline double *mulmatvec4(double *dest,double *a,double *v){
  dest[0]=a[ 0]*v[0]+a[ 1]*v[1]+a[ 2]*v[2]+a[ 3]*v[3];
  dest[1]=a[ 4]*v[0]+a[ 5]*v[1]+a[ 6]*v[2]+a[ 7]*v[3];
  dest[2]=a[ 8]*v[0]+a[ 9]*v[1]+a[10]*v[2]+a[11]*v[3];
  dest[3]=a[12]*v[0]+a[13]*v[1]+a[14]*v[2]+a[15]*v[3];
  return dest;
}
inline double *mulmatvec4(double *a,double *v){
  double dest[4];
  dest[0]=a[ 0]*v[0]+a[ 1]*v[1]+a[ 2]*v[2]+a[ 3]*v[3];
  dest[1]=a[ 4]*v[0]+a[ 5]*v[1]+a[ 6]*v[2]+a[ 7]*v[3];
  dest[2]=a[ 8]*v[0]+a[ 9]*v[1]+a[10]*v[2]+a[11]*v[3];
  dest[3]=a[12]*v[0]+a[13]*v[1]+a[14]*v[2]+a[15]*v[3];
  v[0]=dest[0];
  v[1]=dest[1];
  v[2]=dest[2];
  v[3]=dest[3];
  return v;
}
inline double *addmulmatvec4(double *dest,double *a,double *v){
  dest[0]+=a[ 0]*v[0]+a[ 1]*v[1]+a[ 2]*v[2]+a[ 3]*v[3];
  dest[1]+=a[ 4]*v[0]+a[ 5]*v[1]+a[ 6]*v[2]+a[ 7]*v[3];
  dest[2]+=a[ 8]*v[0]+a[ 9]*v[1]+a[10]*v[2]+a[11]*v[3];
  dest[3]+=a[12]*v[0]+a[13]*v[1]+a[14]*v[2]+a[15]*v[3];
  return dest;
}

inline double *mulmatmat3(double *dest,double *a,double *b){
  dest[0]=a[0]*b[0]+a[1]*b[3]+a[2]*b[6];
  dest[1]=a[0]*b[1]+a[1]*b[4]+a[2]*b[7];
  dest[2]=a[0]*b[2]+a[1]*b[5]+a[2]*b[8];
  dest[3]=a[3]*b[0]+a[4]*b[3]+a[5]*b[6];
  dest[4]=a[3]*b[1]+a[4]*b[4]+a[5]*b[7];
  dest[5]=a[3]*b[2]+a[4]*b[5]+a[5]*b[8];
  dest[6]=a[6]*b[0]+a[7]*b[3]+a[8]*b[6];
  dest[7]=a[6]*b[1]+a[7]*b[4]+a[8]*b[7];
  dest[8]=a[6]*b[2]+a[7]*b[5]+a[8]*b[8];
  return dest;
}

inline double *addmulmatmat3(double *dest,double *a,double *b){
  dest[0]+=a[0]*b[0]+a[1]*b[3]+a[2]*b[6];
  dest[1]+=a[0]*b[1]+a[1]*b[4]+a[2]*b[7];
  dest[2]+=a[0]*b[2]+a[1]*b[5]+a[2]*b[8];
  dest[3]+=a[3]*b[0]+a[4]*b[3]+a[5]*b[6];
  dest[4]+=a[3]*b[1]+a[4]*b[4]+a[5]*b[7];
  dest[5]+=a[3]*b[2]+a[4]*b[5]+a[5]*b[8];
  dest[6]+=a[6]*b[0]+a[7]*b[3]+a[8]*b[6];
  dest[7]+=a[6]*b[1]+a[7]*b[4]+a[8]*b[7];
  dest[8]+=a[6]*b[2]+a[7]*b[5]+a[8]*b[8];
  return dest;
}

inline double *mulmatmat3(double *a,double *b){
  double dest[9];
  dest[0]=a[0]*b[0]+a[1]*b[3]+a[2]*b[6];
  dest[1]=a[0]*b[1]+a[1]*b[4]+a[2]*b[7];
  dest[2]=a[0]*b[2]+a[1]*b[5]+a[2]*b[8];
  dest[3]=a[3]*b[0]+a[4]*b[3]+a[5]*b[6];
  dest[4]=a[3]*b[1]+a[4]*b[4]+a[5]*b[7];
  dest[5]=a[3]*b[2]+a[4]*b[5]+a[5]*b[8];
  dest[6]=a[6]*b[0]+a[7]*b[3]+a[8]*b[6];
  dest[7]=a[6]*b[1]+a[7]*b[4]+a[8]*b[7];
  dest[8]=a[6]*b[2]+a[7]*b[5]+a[8]*b[8];
  memcpy(b,dest,9*sizeof(double));
  return b;
}

inline double *mulmatmat4(double *dest,double *a,double *b){
  dest[ 0]=a[ 0]*b[ 0]+a[ 1]*b[ 4]+a[ 2]*b[ 8]+a[ 3]*b[12];
  dest[ 1]=a[ 0]*b[ 1]+a[ 1]*b[ 5]+a[ 2]*b[ 9]+a[ 3]*b[13];
  dest[ 2]=a[ 0]*b[ 2]+a[ 1]*b[ 6]+a[ 2]*b[10]+a[ 3]*b[14];
  dest[ 3]=a[ 0]*b[ 3]+a[ 1]*b[ 7]+a[ 2]*b[11]+a[ 3]*b[15];

  dest[ 4]=a[ 4]*b[ 0]+a[ 5]*b[ 4]+a[ 6]*b[ 8]+a[ 7]*b[12];
  dest[ 5]=a[ 4]*b[ 1]+a[ 5]*b[ 5]+a[ 6]*b[ 9]+a[ 7]*b[13];
  dest[ 6]=a[ 4]*b[ 2]+a[ 5]*b[ 6]+a[ 6]*b[10]+a[ 7]*b[14];
  dest[ 7]=a[ 4]*b[ 3]+a[ 5]*b[ 7]+a[ 6]*b[11]+a[ 7]*b[15];

  dest[ 8]=a[ 8]*b[ 0]+a[ 9]*b[ 4]+a[10]*b[ 8]+a[11]*b[12];
  dest[ 9]=a[ 8]*b[ 1]+a[ 9]*b[ 5]+a[10]*b[ 9]+a[11]*b[13];
  dest[10]=a[ 8]*b[ 2]+a[ 9]*b[ 6]+a[10]*b[10]+a[11]*b[14];
  dest[11]=a[ 8]*b[ 3]+a[ 9]*b[ 7]+a[10]*b[11]+a[11]*b[15];

  dest[12]=a[12]*b[ 0]+a[13]*b[ 4]+a[14]*b[ 8]+a[15]*b[12];
  dest[13]=a[12]*b[ 1]+a[13]*b[ 5]+a[14]*b[ 9]+a[15]*b[13];
  dest[14]=a[12]*b[ 2]+a[13]*b[ 6]+a[14]*b[10]+a[15]*b[14];
  dest[15]=a[12]*b[ 3]+a[13]*b[ 7]+a[14]*b[11]+a[15]*b[15];
  return dest;
}

inline double *addmulmatmat4(double *dest,double *a,double *b){
  dest[ 0]+=a[ 0]*b[ 0]+a[ 1]*b[ 4]+a[ 2]*b[ 8]+a[ 3]*b[12];
  dest[ 1]+=a[ 0]*b[ 1]+a[ 1]*b[ 5]+a[ 2]*b[ 9]+a[ 3]*b[13];
  dest[ 2]+=a[ 0]*b[ 2]+a[ 1]*b[ 6]+a[ 2]*b[10]+a[ 3]*b[14];
  dest[ 3]+=a[ 0]*b[ 3]+a[ 1]*b[ 7]+a[ 2]*b[11]+a[ 3]*b[15];

  dest[ 4]+=a[ 4]*b[ 0]+a[ 5]*b[ 4]+a[ 6]*b[ 8]+a[ 7]*b[12];
  dest[ 5]+=a[ 4]*b[ 1]+a[ 5]*b[ 5]+a[ 6]*b[ 9]+a[ 7]*b[13];
  dest[ 6]+=a[ 4]*b[ 2]+a[ 5]*b[ 6]+a[ 6]*b[10]+a[ 7]*b[14];
  dest[ 7]+=a[ 4]*b[ 3]+a[ 5]*b[ 7]+a[ 6]*b[11]+a[ 7]*b[15];

  dest[ 8]+=a[ 8]*b[ 0]+a[ 9]*b[ 4]+a[10]*b[ 8]+a[11]*b[12];
  dest[ 9]+=a[ 8]*b[ 1]+a[ 9]*b[ 5]+a[10]*b[ 9]+a[11]*b[13];
  dest[10]+=a[ 8]*b[ 2]+a[ 9]*b[ 6]+a[10]*b[10]+a[11]*b[14];
  dest[11]+=a[ 8]*b[ 3]+a[ 9]*b[ 7]+a[10]*b[11]+a[11]*b[15];

  dest[12]+=a[12]*b[ 0]+a[13]*b[ 4]+a[14]*b[ 8]+a[15]*b[12];
  dest[13]+=a[12]*b[ 1]+a[13]*b[ 5]+a[14]*b[ 9]+a[15]*b[13];
  dest[14]+=a[12]*b[ 2]+a[13]*b[ 6]+a[14]*b[10]+a[15]*b[14];
  dest[15]+=a[12]*b[ 3]+a[13]*b[ 7]+a[14]*b[11]+a[15]*b[15];
  return dest;
}

inline double *mulmatmat4(double *a,double *b){
  double dest[16];
  dest[ 0]=a[ 0]*b[ 0]+a[ 1]*b[ 4]+a[ 2]*b[ 8]+a[ 3]*b[12];
  dest[ 1]=a[ 0]*b[ 1]+a[ 1]*b[ 5]+a[ 2]*b[ 9]+a[ 3]*b[13];
  dest[ 2]=a[ 0]*b[ 2]+a[ 1]*b[ 6]+a[ 2]*b[10]+a[ 3]*b[14];
  dest[ 3]=a[ 0]*b[ 3]+a[ 1]*b[ 7]+a[ 2]*b[11]+a[ 3]*b[15];

  dest[ 4]=a[ 4]*b[ 0]+a[ 5]*b[ 4]+a[ 6]*b[ 8]+a[ 7]*b[12];
  dest[ 5]=a[ 4]*b[ 1]+a[ 5]*b[ 5]+a[ 6]*b[ 9]+a[ 7]*b[13];
  dest[ 6]=a[ 4]*b[ 2]+a[ 5]*b[ 6]+a[ 6]*b[10]+a[ 7]*b[14];
  dest[ 7]=a[ 4]*b[ 3]+a[ 5]*b[ 7]+a[ 6]*b[11]+a[ 7]*b[15];

  dest[ 8]=a[ 8]*b[ 0]+a[ 9]*b[ 4]+a[10]*b[ 8]+a[11]*b[12];
  dest[ 9]=a[ 8]*b[ 1]+a[ 9]*b[ 5]+a[10]*b[ 9]+a[11]*b[13];
  dest[10]=a[ 8]*b[ 2]+a[ 9]*b[ 6]+a[10]*b[10]+a[11]*b[14];
  dest[11]=a[ 8]*b[ 3]+a[ 9]*b[ 7]+a[10]*b[11]+a[11]*b[15];

  dest[12]=a[12]*b[ 0]+a[13]*b[ 4]+a[14]*b[ 8]+a[15]*b[12];
  dest[13]=a[12]*b[ 1]+a[13]*b[ 5]+a[14]*b[ 9]+a[15]*b[13];
  dest[14]=a[12]*b[ 2]+a[13]*b[ 6]+a[14]*b[10]+a[15]*b[14];
  dest[15]=a[12]*b[ 3]+a[13]*b[ 7]+a[14]*b[11]+a[15]*b[15];
  memcpy(b,dest,16*sizeof(double));
  return b;
}

inline double *makerotmat3(double *dest,double x,double y,double z){
  double cx=cos(x);
  double cy=cos(y);
  double cz=cos(z);
  double sx=sin(x);
  double sy=sin(y);
  double sz=sin(z);
  dest[0]=  cy*cz;
  dest[1]= -sz*cy;
  dest[2]=  sy;

  dest[3]=  sx*sy*cz+cx*sz;
  dest[4]=  cx*cz-sx*sy*sz;
  dest[5]=  -sx*cy;

  dest[6]= sx*sz - cx*sy*cz;
  dest[7]= cx*sy*sz+sx*cz;
  dest[8]= cx*cy;
  return dest;
}

inline double *makerotmat3(double *dest,double x,double y,double z,double a){
  double S=a/sqrt(x*x+y*y+z*z);
  x*=S;
  y*=S;
  z*=S;
  double cx=cos(x);
  double cy=cos(y);
  double cz=cos(z);
  double sx=sin(x);
  double sy=sin(y);
  double sz=sin(z);
  dest[0]=  cy*cz;
  dest[1]= -sz*cy;
  dest[2]=  sy;

  dest[3]=  sx*sy*cz+cx*sz;
  dest[4]=  cx*cz-sx*sy*sz;
  dest[5]=  -sx*cy;

  dest[6]= sx*sz - cx*sy*cz;
  dest[7]= cx*sy*sz+sx*cz;
  dest[8]= cx*cy;
  return dest;
}

inline double *makerotmat4(double *dest,double x,double y,double z){
  double cx=cos(x);
  double cy=cos(y);
  double cz=cos(z);
  double sx=sin(x);
  double sy=sin(y);
  double sz=sin(z);
  dest[ 0]=  cy*cz;
  dest[ 1]= -sz*cy;
  dest[ 2]=  sy;
  dest[ 3]=  0.0;

  dest[ 4]=  sx*sy*cz+cx*sz;
  dest[ 5]=  cx*cz-sx*sy*sz;
  dest[ 6]=  -sx*cy;
  dest[ 7]=  0.0;

  dest[ 8]= sx*sz - cx*sy*cz;
  dest[ 9]= cx*sy*sz+sx*cz;
  dest[10]= cx*cy;
  dest[11]= 0.0;

  dest[12]= 0.0;
  dest[13]= 0.0;
  dest[14]= 0.0;
  dest[15]= 1.0;

  return dest;
}

inline double *makerotmat4(double *dest,double x,double y,double z,double a){
  double S=a/sqrt(x*x+y*y+z*z);
  x*=S;
  y*=S;
  z*=S;
  double cx=cos(x);
  double cy=cos(y);
  double cz=cos(z);
  double sx=sin(x);
  double sy=sin(y);
  double sz=sin(z);
  dest[ 0]=  cy*cz;
  dest[ 1]= -sz*cy;
  dest[ 2]=  sy;
  dest[ 3]=  0.0;

  dest[ 4]=  sx*sy*cz+cx*sz;
  dest[ 5]=  cx*cz-sx*sy*sz;
  dest[ 6]=  -sx*cy;
  dest[ 7]=  0.0;

  dest[ 8]= sx*sz - cx*sy*cz;
  dest[ 9]= cx*sy*sz+sx*cz;
  dest[10]= cx*cy;
  dest[11]= 0.0;

  dest[12]= 0.0;
  dest[13]= 0.0;
  dest[14]= 0.0;
  dest[15]= 1.0;

  return dest;
}

inline double *identitymat3(double *dest){
  dest[0]=1.0;
  dest[1]=0.0;
  dest[2]=0.0;
  dest[3]=0.0;
  dest[4]=1.0;
  dest[5]=0.0;
  dest[6]=0.0;
  dest[7]=0.0;
  dest[8]=1.0;
  return dest;
}

inline double *identitymat4(double *dest){
  dest[ 0]=1.0;
  dest[ 1]=0.0;
  dest[ 2]=0.0;
  dest[ 3]=0.0;

  dest[ 4]=0.0;
  dest[ 5]=1.0;
  dest[ 6]=0.0;
  dest[ 7]=0.0;

  dest[ 8]=0.0;
  dest[ 9]=0.0;
  dest[10]=1.0;
  dest[11]=0.0;

  dest[12]=0.0;
  dest[13]=0.0;
  dest[14]=0.0;
  dest[15]=1.0;
  return dest;
}
#endif
