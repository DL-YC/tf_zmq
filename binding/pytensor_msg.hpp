#ifndef PYTENSOR_MSG_HPP
#define PYTENSOR_MSG_HPP

#include <string>


char* pack_msg(int *bufferlen);
// 2d
void int32_2D(int* int_array2d, int ix2d, int iy2d);
void float32_2D(float* float_array2d, int fx2d, int fy2d);
void float64_2D(double* double_array2d, int dx2d, int dy2d);

// 3d
void int32_3D(int* int_array3d, int ix3d, int iy3d, int iz3d);
void float32_3D(float* float_array3d, int fx3d, int fy3d, int fz3d);
void float64_3D(double* double_array3d, int dx3d, int dy3d, int dz3d);

// 4d
void int32_4D(int* int_array4d, int ix4d, int iy4d, int iz4d, int iw4d);
void float32_4D(float* float_array4d, int fx4d, int fy4d, int fz4d, int fw4d);
void float64_4D(double* double_array4d, int dx4d, int dy4d, int dz4d, int dw4d);

void debug();

// void connect(const std::string &address);

#endif