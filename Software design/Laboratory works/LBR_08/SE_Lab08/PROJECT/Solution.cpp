#include <iostream>

int defaultparm(int a, int b, int c, int d, int e, int f = 1, int g = 2) //два последних внизу стека, остальные по очереди как указаны. 
{
    return (a + b + c + d + e + f + g) / 7;
}

int main()
{
    std::cout << defaultparm(1,2,3,4,5,6,7) << std::endl; 
    std::cout << defaultparm(1, 2, 3, 4, 5) << std::endl; 
    return 0;
}


