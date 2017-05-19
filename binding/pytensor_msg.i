%module pytensor_msg

// %include "std_string.i"

%{
#define SWIG_FILE_WITH_INIT
#include "pytensor_msg.hpp"
%}

%include "numpy.i"
// %include "std_string.i"
// %include "std_map.i"

%init %{
    import_array();
%}


%apply int *OUTPUT { int *bufferlen };
 
%apply (int* IN_ARRAY2, int DIM1, int DIM2) {(int* int_array2d, int ix2d, int iy2d)}
%apply (float* IN_ARRAY2, int DIM1, int DIM2) {(float* float_array2d, int fx2d, int fy2d)}
%apply (double* IN_ARRAY2, int DIM1, int DIM2) {(double* double_array2d, int dx2d, int dy2d)}

%apply (int* IN_ARRAY3, int DIM1, int DIM2, int DIM3) {(int* int_array3d, int ix3d, int iy3d, int iz3d)}
%apply (float* IN_ARRAY3, int DIM1, int DIM2, int DIM3) {(float* float_array3d, int fx3d, int fy3d, int fz3d)}
%apply (double* IN_ARRAY3, int DIM1, int DIM2, int DIM3) {(double* double_array3d, int dx3d, int dy3d, int dz3d)}


%apply (int* IN_ARRAY4, int DIM1, int DIM2, int DIM3, int DIM4) {(int* int_array4d, int ix4d, int iy4d, int iz4d, int iw4d)}
%apply (float* IN_ARRAY4, int DIM1, int DIM2, int DIM3, int DIM4) {(float* float_array4d, int fx4d, int fy4d, int fz4d, int fw4d)}
%apply (double* IN_ARRAY4, int DIM1, int DIM2, int DIM3, int DIM4) {(double* double_array4d, int dx4d, int dy4d, int dz4d, int dw4d)}

%newobject pack_msg;
%include "pytensor_msg.hpp"



