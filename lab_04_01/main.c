#include <stdio.h>
#include <stddef.h>

#include "strpbrk.h"
#include "strspn.h"
#include "strcspn.h"
#include "strchr.h"
#include "strrchr.h"
#include "const.h"

//main function
int main(void)
{
    int count = 0;
    char arr_str[][MAX_LEN] = { "ijefffiosfje ewf",
        "awi owejf   ewf",
        " 8327  4hr73rh7w8d8d w37ey3a",
        "7382eh87r hefauehf  _   ueifh",
        "3 3 4a 5r 5 a43uh da frr",
        "d___+++===!!!???dfgr",
        " ui54o     a3        oiubt ",
        "udhe83e 3uhrfuew4yrf8wefhies8pw9euw39fhc",
        "feger rtf ewtf  tedg  abc eriure f13",
        "abc8uehf384hf",
        "7yer7hete7ht7tht1",
        "abc123bca312b2",
        "aiugttigthuight tiughtrghr g958t ()57g",
        "",
        "a",
        "i",
        " ",
        " d ",
        "00",
        "0 1",
        "                ",
        "\0",
        "IDGJUGNfbeyftd d fh",
        " ke dei  deifh e w9o ao sqiwed wioda[opskakzmx 893wyruhwefuhe8ry0",
        "              \n",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaad",
        "daaaaaaaaaaaaaaaaaaaaaaaaa",
        "aaaaaaaaaaaaaadaaaaaaaaaadaaaaaaaa",
        "aaaaaaaaaaaaaaaaaaaaaaaddaaaaaaaaa",
        "uritgh58mgu8u,g985h,,trj" };
    for (size_t i = 0; i < (sizeof(arr_str) / sizeof(arr_str[0])); i++)
    {
        count = all_strpbrk(count, arr_str[i]);

        count = all_strspn(count, arr_str[i]);

        count = all_strcspn(count, arr_str[i]);

        count = all_strchr(count, arr_str[i]);

        count = all_strrchr(count, arr_str[i]);
    }
    printf("Result: %d\n", count);
    return OK;
}
