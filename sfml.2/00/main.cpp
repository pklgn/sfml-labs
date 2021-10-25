#include <iostream>

int main()
{
    //цикл выводит числа от 1 до 100
    for (int num = 1; num <= 100; num += 1)
    {
        //если число кратно и 3, и 5, вывести FizzBuzz
        if ((num % 3 == 0) && (num % 5 == 0))
        {
            std::cout << "FizzBuzz" << std::endl;
        }
        //иначе если число кратно 3, вывести Fizz
        else if (num % 3 == 0)
        {
            //Fizz
            std::cout << "Fizz" << std::endl;
        }
        else if (num % 5 == 0)
        {
            //Buzz
            //иначе если число кратно 5, вывести Buzz
            std::cout << "Buzz" << std::endl;
        }
        else
        {
            //num
            //иначе вывести число
            std::cout << num << std::endl;
        }
        //добавляем к числу 1
        //оператор += это сокращение от `num = num + 1`
    }
}