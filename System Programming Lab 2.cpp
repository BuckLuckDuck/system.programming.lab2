#include <iostream>
using namespace std;

static int* sortBubble(int* arr, int len);

int main()
{
    int siz = 10;
    int* numbers = new int[siz];

    for (int i = 0; i < siz; i++)
    {
        numbers[i] = rand() % 31;
    }

    for (int i = 0; i < siz; i++)
    {
        std::cout << numbers[i] << " ";
    }

	cout << endl;

	_asm 
	{
		push siz
		push numbers
		call sortBubble
		mov numbers, eax
		add esp, 8
	}

    for (int i = 0; i < siz; i++)
    {
        std::cout << numbers[i] << " ";
    }
}

static int* sortBubble(int* arr, int len)
{
	_asm
	{
		mov ecx, len
		dec ecx
		mov eax, arr
	J3 : mov edx, 0
	J2 : mov ebx, edx
		inc ebx
		mov ebx, [eax + 4 * ebx]
		cmp[eax + 4 * edx], ebx
		jle J1
		mov esi, edx
		inc esi
		mov edi, [eax + 4 * edx]
		mov[eax + 4 * esi], edi
		mov[eax + 4 * edx], ebx
	J1 : inc edx
		cmp edx, ecx
		jl J2
		dec ecx
		cmp ecx, 0
		jg J3
	}
}