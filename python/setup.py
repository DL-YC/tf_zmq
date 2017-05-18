from distutils.core import setup, Extension
import numpy
import os
import re
import requests

# get NUMPY.I
np_version = re.compile(r'(?P<MAJOR>[0-9]+)\.'
                        '(?P<MINOR>[0-9]+)').search(numpy.__version__)
np_version_string = np_version.group()
np_version_info = {key: int(value)
                   for key, value in np_version.groupdict().items()}
np_file_name = 'numpy.i'
np_file_url = 'https://raw.githubusercontent.com/numpy/numpy/maintenance/' + \
              np_version_string + '.x/tools/swig/' + np_file_name
if(np_version_info['MAJOR'] == 1 and np_version_info['MINOR'] < 9):
    np_file_url = np_file_url.replace('tools', 'doc')
chunk_size = 8196
with open(np_file_name, 'wb') as file:
    for chunk in requests.get(np_file_url, stream=True).iter_content(chunk_size):
        file.write(chunk)

a = '-DZMQ_BUILD_DRAFT_API=1 -I/graphics/projects/opt_Ubuntu16.04/msgpack-c/dist/include -I/graphics/projects/opt_Ubuntu16.04/libzmq/dist/include'
b = '-L/graphics/projects/opt_Ubuntu16.04/msgpack-c/dist/lib -L/graphics/projects/opt_Ubuntu16.04/libzmq/dist/lib -lzmq -lmsgpackc'

# build
os.environ['CC'] = 'g++'
setup(name='TensorMsg', version='1.0',
      ext_modules=[Extension('tensor_msg_pack',
                   ['tensor_msg_pack.cpp', 'tensor_msg_pack.i'],
                   extra_compile_args=["-Wno-deprecated", "-O3", "-std=c++11", a, b],
                   include_dirs=[numpy.get_include(), '.'])])
