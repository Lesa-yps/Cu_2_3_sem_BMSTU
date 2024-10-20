EMPTY = -2
OK = 0
ERROR = 1

def arr_to_str(arr, n):
    stika = ""
    for i in range(n):
        if (stika != ""):
            stika += " "
        stika += str(arr[i])
    return stika

def check_num(stika):
    rc = OK
    i = 0
    if (len(stika) == 0):
        rc = EMPTY
    elif (len(stika) == 1 and (not (stika[0]).isdigit())):
        rc = ERROR
    else:
        if (stika[0] in "+-"):
            i += 1
        while (i < len(stika) and rc == OK):
            if (not (stika[i]).isdigit()):
                rc = ERROR
            i += 1
    return rc
    

def str_to_arr(stika):
    arr = stika.split(" ")
    arr_res = list()
    rc = OK
    i = 0
    while (i < len(arr) and rc == OK):
        if ((rc := check_num(arr[i])) == OK):
            arr_res += [int(arr[i])]
        elif (rc == EMPTY):
            rc = OK
        i += 1
    if len(arr_res) == 0:
        rc = ERROR
    return rc, arr_res, len(arr_res)

def str_to_int(k):
    k_res = 0
    if ((rc := check_num(k)) == OK):
        k_res = int(k)
    elif (rc == EMPTY):
        rc = ERROR
    return rc, k_res
