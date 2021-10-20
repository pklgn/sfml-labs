#include <cstdio>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int sum = 0;

    std::puts("Finding the sum of three numbers\nPlease, enter three numbers separated by a space: ");
    std::scanf("%d %d %d", &a, &b, &c);
    sum = a + b + c;
    std::printf("The sum is %d", sum);
}