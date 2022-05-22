#include <iostream>
using namespace std;

int sortBubble(int *arr, int len)
{
    _asm
    {
        mov ebx, arr
        mov ecx, len
        for_i: dec ecx
        xor edx, edx
        for_j: cmp ebx, ecx
        jae exit_for_j
        jbe no_swap
        mov eax, 
    }
    return;
}

int main()
{
    const int size = 10;
    int numbers[size];// { 0 };
    for (int i = 0; i < size; i++)
    {
        numbers[i] = 9 - i;
    }

    for (size_t i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    cout << sortBubble(numbers, 7);

    for (size_t i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }
}
