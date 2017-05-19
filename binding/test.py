import pytensor_msg
import numpy as np

# data, lenn = pytensor_msg.out()
# print len(data)
# print np.asarray(bytearray(data)[:lenn], dtype=np.uint8)

# tensor = np.random.randn(4, 2).astype(np.float32)
# pytensor_msg.float32_2D(tensor)
# tensor = np.random.randn(4, 1, 2).astype(np.float32)
# pytensor_msg.float32_3D(tensor)
# pytensor_msg.debug()
# tensor = np.random.randn(4, 2).astype(np.int32)
# pytensor_msg.int32_2D(tensor)
# tensor = np.random.randn(4, 2, 4, 5).astype(np.int32)
# pytensor_msg.int32_4D(tensor)
# pytensor_msg.debug()


# tensor = np.ones((4, 2), np.float32)
# print tensor
# pytensor_msg.float32_2D(tensor)

# pytensor_msg.debug()


import zmq
try:
    ctx = zmq.Context()
    socket = ctx.socket(zmq.PUSH)
    socket.connect('ipc:///tmp/ipc-socket-0')

    tensor = np.ones((4, 2), np.float32).astype(np.float32)
    pytensor_msg.float32_2D(tensor)
    pytensor_msg.debug()

    data, size = pytensor_msg.pack_msg()
    print data, size
    byts = data
    print byts, len(byts)

    while True:
        socket.send(byts, copy=False)

finally:
    ctx.destroy(linger=0)
# # pytensor_msg.connect("ipc:///tmp/ipc-socket-0")

# # tensor = np.ones((4, 2), np.float32)
# # pytensor_msg.float32_2D(tensor)