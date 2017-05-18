%module tensor_msg_pack

%{
    #define SWIG_FILE_WITH_INIT
    #define SWIG_PYTHON_STRICT_BYTE_CHAR
    #include "tensor_msg_pack.h"
%}

%include "numpy.i"

%init %{
    import_array();
%}

%cstring_output_withsize(char *bugger, int *bufferlen);
%apply (float* INPLACE_ARRAY2, int DIM1, int DIM2) {(float *data, int m, int n)}
%include "tensor_msg_pack.h"