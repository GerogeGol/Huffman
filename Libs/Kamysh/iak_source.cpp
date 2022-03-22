#include <iostream>
#include "iak_header.h"

int main(int, char**) {
    char data[10];
    strcpy(data, "abcdefg");
    code_symbol Lib[sizeof(data)];
    int k = 100;
    for (int i = 0; i < sizeof(data); i++) {
        Lib[i].code = k;
        k++;
        Lib[i].symbol = data[i];
    }
}
