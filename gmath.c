
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


/*============================================
  IMPORANT NOTE

  Ambient light is represeneted by a color value

  Point light sources are 2D arrays of doubles.
       - The fist index (LOCATION) represents the vector to the light.
       - The second index (COLOR) represents the color.

  Reflection constants (ka, kd, ks) are represened as arrays of
  doubles (red, green, blue)
  ============================================*/


//lighting functions
color get_lighting( double *normal, double *view, color alight, double light[2][3], double *areflect, double *dreflect, double *sreflect) {
  normalize(normal);
  normalize(light[LOCATION]);
  color i;
  i.red =
	calculate_ambient(alight.red,areflect[RED]) +
	calculate_diffuse (light[LOCATION],light[COLOR][RED],dreflect[RED],normal) +
	calculate_specular(light[LOCATION],light[COLOR][RED],sreflect[RED],view,normal);
  i.green =
  	calculate_ambient(alight.green,areflect[GREEN]) +
  	calculate_diffuse (light[LOCATION],light[COLOR][GREEN],dreflect[GREEN],normal) +
  	calculate_specular(light[LOCATION],light[COLOR][GREEN],sreflect[GREEN],view,normal);
  i.blue =
  	calculate_ambient(alight.blue,areflect[BLUE]) +
  	calculate_diffuse (light[LOCATION],light[COLOR][BLUE],dreflect[BLUE],normal) +
  	calculate_specular(light[LOCATION],light[COLOR][BLUE],sreflect[BLUE],view,normal);
  return i;
}
/*=========================
  hi! i modified headers; i think its cleaner to have functions that just calculate each value, and merge them into the colors later. i hope this doesnt backfire :p 
  -kiran
  =========================*/
double calculate_ambient(unsigned short alight, double areflect) {
  return alight * areflect;
}

double calculate_diffuse(double *light_vector,double light_value, double dreflect, double *normal ) {
  return light_value * dreflect * dot_product( normal , light_vector );
  // P * k_d * ( N_hat . L_hat )
  // normalized in get_lighting()
}

double calculate_specular(double* light_vector, double light_value, double sreflect, double *view, double *normal ) {
  double R[3];
  double cos_theta = dot_product(normal,light_vector);
  R[0] = 2 * cos_theta * normal[0] - light_vector[0];
  R[1] = 2 * cos_theta * normal[1] - light_vector[1];
  R[2] = 2 * cos_theta * normal[2] - light_vector[2];
  return light_value * sreflect * pow( dot_product(R,view), SPECULAR_EXP );
					
}

//limit each component of c to a max of 255
void limit_color( color * c ) {
}

//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
  double magnitude;
  magnitude = sqrt( vector[0] * vector[0] +
                    vector[1] * vector[1] +
                    vector[2] * vector[2] );
  int i;
  for (i=0; i<3; i++) {
    vector[i] = vector[i] / magnitude;
  }
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  double dp = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
  return dp < 0 ? 0 : dp;
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {

  double A[3];
  double B[3];
  double *N = (double *)malloc(3 * sizeof(double));

  A[0] = polygons->m[0][i+1] - polygons->m[0][i];
  A[1] = polygons->m[1][i+1] - polygons->m[1][i];
  A[2] = polygons->m[2][i+1] - polygons->m[2][i];

  B[0] = polygons->m[0][i+2] - polygons->m[0][i];
  B[1] = polygons->m[1][i+2] - polygons->m[1][i];
  B[2] = polygons->m[2][i+2] - polygons->m[2][i];

  N[0] = A[1] * B[2] - A[2] * B[1];
  N[1] = A[2] * B[0] - A[0] * B[2];
  N[2] = A[0] * B[1] - A[1] * B[0];

  return N;
}
