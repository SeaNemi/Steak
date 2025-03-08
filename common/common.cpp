#include "common.h"

//ceiling rounds up numbers
int ceiling(double x){
    return (x >(int)x) ? (int)x + 1: (int)x;
}

int logbasetwoceil(int x){
    int j = 1;
    int k = 0;
    while(j < x){
        j *= 2;
        k++;
    }
    return k;
}

double power(double x, int y){
    double j = 1.0;
    for(int i = 0; i < y; i++){
        j *= x;
    }
    return j;
}