/*!
 * @file  cmathTest.cpp
 * @brief test cmath
 * @date 2017/01/24
 * @author YoonSeong Yong 
 * 
 */

#include <cmath>
#include <stdio.h>
#define _USE_MATH_DEFINES

int main(){
    printf("PI = %lf\n", M_PI);
    printf("cos(PI) = %f\n", cos(M_PI));
    printf("acos(-1) = %f\n", acos(-1));
}
