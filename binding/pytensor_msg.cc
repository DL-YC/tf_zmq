#include "pytensor_msg.hpp"
#include <memory>
#include "../includes/tensor_msg.hpp"
#include <vector>
#include <iostream>

static std::vector<tensor_msg> tensors;


 char* pack_msg(int *bufferlen)
{
    // encode
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, tensors);
    *bufferlen = sbuf.size();
    char* buffer = new  char[sbuf.size()];
    memcpy(buffer, sbuf.data(), sbuf.size());
    return buffer;
}

void int32_2D(int* int_array2d, int ix2d, int iy2d){
  tensors.push_back(tensor_msg({ix2d, iy2d}, int_array2d));
}
void float32_2D(float* float_array2d, int fx2d, int fy2d){
  tensors.push_back(tensor_msg({fx2d, fy2d}, float_array2d));
}
void float64_2D(double* double_array2d, int dx2d, int dy2d){
  tensors.push_back(tensor_msg({dx2d, dy2d}, double_array2d));
}

void int32_3D(int* int_array3d, int ix, int iy3d, int iz3d){
  tensors.push_back(tensor_msg({ix, iy3d, iz3d}, int_array3d));
}
void float32_3D(float* float_array3d, int fx3d, int fy3d, int fz3d){
  tensors.push_back(tensor_msg({fx3d, fy3d, fz3d}, float_array3d));
}
void float64_3D(double* double_array3d, int dx3d, int dy3d, int dz3d){
  tensors.push_back(tensor_msg({dx3d, dy3d, dz3d}, double_array3d));
}

void int32_4D(int* int_array4d, int ix, int iy4d, int iz4d, int iw4d){
  tensors.push_back(tensor_msg({ix, iy4d, iz4d, iw4d}, int_array4d));
}
void float32_4D(float* float_array4d, int fx4d, int fy4d, int fz4d, int fw4d){
  tensors.push_back(tensor_msg({fx4d, fy4d, fz4d, fw4d}, float_array4d));
}
void float64_4D(double* double_array4d, int dx4d, int dy4d, int dz4d, int dw4d){
  tensors.push_back(tensor_msg({dx4d, dy4d, dz4d, dw4d}, double_array4d));
}

void debug(){
  std::cout << "has "<<tensors.size() << " tensors" << std::endl;
    
  for(auto &el : tensors){
    std::cout << "tensor has shape " << el.shape_.size()<< std::endl;
    std::cout << "tensor has type " << el.type_<< std::endl;
    std::cout << "tensor has data ";
    if (el.type_ == 0){
      for (int i = 0; i < el.size(); ++i)
        std::cout << (int) ((int*)el.data_.ptr)[i] << " ";
    }
    if (el.type_ == 1){
      for (int i = 0; i < el.size(); ++i)
        std::cout << (float) ((float*)el.data_.ptr)[i] << " ";
    }
    if (el.type_ == 2){
      for (int i = 0; i < el.size(); ++i)
        std::cout << (double) ((double*)el.data_.ptr)[i] << " ";
    }
    std::cout << std::endl;
  }
}