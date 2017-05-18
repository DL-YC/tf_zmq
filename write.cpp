#include "includes/zmq.hpp"
#include "includes/tensor_msg.hpp"
#include <msgpack.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int main () {

    // create a tensor of 4x4 floats
    float *image_data = new float[4*4]{0.f, 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 
                                       8.f, 9.f, 10.f, 11.f, 12.f, 13.f, 14.f, 15.f};
    int *label_data = new int[1]{42};
    
    std::vector<tensor_msg > tensors;
    tensors.push_back(tensor_msg({4, 4}, image_data));
    tensors.push_back(tensor_msg({1}, label_data));

    // encode
    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, tensors);

    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_PUSH);
    socket.connect ("ipc:///tmp/ipc-socket-0");

    while (true) {
        zmq::message_t *msg = new zmq::message_t(sbuf.size());
        memcpy (msg->data (), sbuf.data(), sbuf.size());
        socket.send(*msg);
        delete msg;
    }
    return 0;
}