import ctypes
from help import arr_to_str

lib = ctypes.CDLL("./libarr.so")

# void arr_go(int *arr, int n, int *arr_new, int k)
_arr_go = lib.arr_go
_arr_go.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_arr_go.restype = None

# int arr_filtr(int *arr, int n, int *arr_new)
_arr_filtr = lib.arr_filtr
_arr_filtr.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_arr_filtr.restype = ctypes.c_int

def ctypes_go(arr, n, k):
    arr_c = (ctypes.c_int * n)(*arr)
    arr_new_c = (ctypes.c_int * n)(0)
    _arr_go(arr_c, n, arr_new_c, k)
    return arr_to_str(list(arr_new_c), n)
    

def ctypes_filtr(arr, n):
    arr_c = (ctypes.c_int * n)(*arr)
    arr_new_c = (ctypes.c_int * n)(0)
    n_new = _arr_filtr(arr_c, n, arr_new_c)
    if n_new == 0:
        stika = "Empty!"
    else:
        stika = arr_to_str(list(arr_new_c), n_new)
    return stika
