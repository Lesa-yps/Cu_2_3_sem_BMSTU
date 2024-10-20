import sys
from help import *
from ctypes_func import ctypes_go, ctypes_filtr

# проверка напрямую (без tkinter)
rc = OK
doing = input()
if doing == "1":
    arr_str = input()
    rc, arr, n = str_to_arr(arr_str)
    if (rc == OK):
        k_str = input().strip()
        rc, k = str_to_int(k_str)
        if (rc == OK):
            strk = ctypes_go(arr, n, k)
        else:
            strk = "Error k!"
    else:
        strk = "Error arr!"
    print(strk, end = "")
elif doing == "2":
    arr_str = input()
    rc, arr, n = str_to_arr(arr_str)
    if (rc == OK):
        strk = ctypes_filtr(arr, n)
    else:
        strk = "Error arr!"
    print(strk, end = "")
else:
    print("Not check.", end = "")
    rc = ERROR

sys.exit(rc)