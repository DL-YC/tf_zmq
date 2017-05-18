// Patrick Wieschollek, 2016
#include <iostream>
#include <array>
#include <vector>
#include <malloc.h>
#include <cstdlib>

#include <msgpack.hpp>
#include "../includes/tensor_msg.hpp"


void pack_tensor_2d(float *data, int m, int n, char **buffer, int *bufferlen){

  // std::vector<tensor_msg > tensors;
  // tensors.push_back(tensor_msg({m, n}, data));

  // // encode
  // msgpack::sbuffer sbuf;
  // msgpack::pack(sbuf, tensors);

  // char* src = sbuf.data();
  char* src = new char[3]{'H', 'I', '\0'};

  // memcpy(src, trg, sbuf.size());
  memcpy(src, buffer, 3);
  // *bufferlen = sbuf.size();
  *bufferlen = 3;

}

