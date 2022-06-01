#include<stdio.h>

#define IFDEF_TEST_H
#include "ifdef-test.h"
#undef IFDEF_TEST_H

int main(){
    ok();
    return 0;
}