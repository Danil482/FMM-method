#include"testPoint.h"
#include <iostream>

int main()
{   
    bool pointLengthTest = testPoint_length();
    std::cout <<"��������� ����� ������ length(): "<< pointLengthTest << '\n';

    bool pointMinusTest = testPoint_minus_operator();
    std::cout << "��������� ����� ��������� �����: " << pointMinusTest << '\n';

    return 0;
}
