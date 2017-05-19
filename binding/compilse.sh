
NP_INC=$(python -c 'import numpy; print(numpy.get_include())')
CFLAGS=`pkg-config --cflags libzmq msgpack`
LFLAGS=`pkg-config --libs libzmq msgpack`
PFLAGS=`python-config --cflags --ldflags`

swig -c++ -python pytensor_msg.i
g++ -fpic -c pytensor_msg.cc  pytensor_msg_wrap.cxx ${PFLAGS} ${CFLAGS} -std=c++11
g++ -shared pytensor_msg.o pytensor_msg_wrap.o -o _pytensor_msg.so ${LFLAGS} -std=c++11