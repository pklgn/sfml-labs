#include <cstdio>

int main()
{
    //1. ввод
    std::puts("please enter a and b for equation `ax + b = 0`");
    float a = 0;
    float b = 0;
    std::scanf("%f %f", &a, &b);
    //2. решение уравнения
    float x = -b / a;
    //3. вывод решения
    std::printf("solution %f\n", x);
}


