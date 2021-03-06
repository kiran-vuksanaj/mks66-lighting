#ifndef GMATH_H
#define GMATH_H

#include "matrix.h"
#include "ml6.h"

// constants for lighting
#define AMBIENT 0
#define DIFFUSE 1
#define SPECULAR 2
#define LOCATION 0
#define COLOR 1
#define RED 0
#define GREEN 1
#define BLUE 2
#define SPECULAR_EXP 8

// lighting functions
color get_lighting( double *normal, double *view, color alight, double light[2][3], double *areflect, double *dreflect, double *sreflect);
double calculate_ambient(unsigned short alight, double areflect);
double calculate_diffuse(double *light_vector, double light_value, double dreflect, double *normal );
double calculate_specular(double* light_vector, double light_value,double sreflect, double *view, double *normal );
void limit_color( color * c );

// vector functions
void normalize( double *vector );
double dot_product( double *a, double *b );
double *calculate_normal(struct matrix *polygons, int i);

#endif
