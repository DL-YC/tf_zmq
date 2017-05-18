import tensor_msg_pack as tm
import numpy as np
import zmq

# ctx = zmq.Context()
# socket = ctx.socket(zmq.PUSH)
# socket.connect('ipc:///tmp/ipc-socket-0')

msg = tm.pack_tensor_2d(np.array([[1.], [2.]], dtype=np.float32))
print msg
    # socket.send(msg, copy=False)
