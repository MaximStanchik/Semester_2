#include "Varparm.h"
#include <stdarg.h>

using namespace std;

namespace Varparm {
    int ivarparm(int n, ...)
    {
        if (n == 0)
        {
            return 0;
        }
        int mul = 1;
        int* p = &n;
        for (int i = 1; i < n + 1; i++)
        {
            mul *= *(p + i);
        }
        return mul;
    }

    int svarparm(short n, ...) {
        int max = 0;

        int* p = (int*)(&n);
        for (int i = 1; i < n + 1; i++)
        {
            if (*(p + i) > max)
            {
                max = *(p + i);
            }
        }
        return max;
    }
    double fvarparm(float n, ...) {
        double sum = (double)n;
        double* ptr = (double*)(&n + 1);
        if (n == FLT_MAX) return 0;
        while (*ptr != (double)FLT_MAX) {
            sum += *ptr;
            ptr++;
        }
        return sum;
    }

    double dvarparm(double n, ...) {
        double sum = n;
        double* ptr = &n + 1;
        if (n == DBL_MAX) return 0;
        while (*ptr != DBL_MAX) {
            sum += *ptr;
            ptr++;
        }
        return sum;
    }
}













//int ivarparm(int n, ...) {
//    int result = 1;
//    va_list args;
//    va_start(args, n);
//    for (int i = 0; i < n; i++) {
//        result *= va_arg(args, int);
//    }
//    va_end(args);
//    return result;
//}