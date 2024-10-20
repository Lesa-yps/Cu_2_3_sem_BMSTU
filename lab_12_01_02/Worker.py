import tkinter as tk
from ctypes_func import ctypes_go, ctypes_filtr
from help import *

# Функция, в зависимости от выбранного действия, вызывает нужные функции
# простейшие действия выполняет сама
def fork(doing, stika_go, stika_filtr, arr_str, k_str):
    if doing == "Сдвинуть":
        rc, arr, n = str_to_arr(arr_str.get())
        if (rc == OK):
            rc, k = str_to_int(k_str.get())
            if (rc == OK):
                strk = ctypes_go(arr, n, k)
            else:
                strk = "Error k!"
        else:
            strk = "Error arr!"
        stika_go.delete(0, tk.END)
        stika_go.insert(0, strk)
    elif doing == "Фильтровать":
        rc, arr, n = str_to_arr(arr_str.get())
        if (rc == OK):
            strk = ctypes_filtr(arr, n)
        else:
            strk = "Error arr!"
        stika_filtr.delete(0, tk.END)
        stika_filtr.insert(0, strk)
    elif doing == "Очистить ввод массива":
        arr_str.delete(0, tk.END)
    elif doing == "Очистить ввод k":
        k_str.delete(0, tk.END)


            






        
