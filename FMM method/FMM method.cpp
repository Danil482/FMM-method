#include"testPoint.h"
#include <iostream>

int main()
{   
    bool pointLengthTest = testPoint_length();
    std::cout <<"Результат теста метода length(): "<< pointLengthTest << '\n';

    bool pointMinusTest = testPoint_minus_operator();
    std::cout << "Результат теста оператора минус: " << pointMinusTest << '\n';

    return 0;
}
