/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#include <cstdio>
#include <memory>
#include <iostream>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
//void Print1ToMaxOfNDigits_1(int n)
//{
//    if (n <= 0)
//        return;
//
//    char *number = new char[n + 1];
//    memset(number, '0', n);
//    number[n] = '\0';
//
//    while (!Increment(number))
//    {
//        PrintNumber(number);
//    }
//
//    delete[]number;
//}
//
//// �ַ���number��ʾһ�����֣��� number������1
//// ������ӷ�������򷵻�true������Ϊfalse
//bool Increment(char* number)
//{
//    bool isOverflow = false;
//    int nTakeOver = 0;
//    int nLength = strlen(number);
//
//    for (int i = nLength - 1; i >= 0; i--)
//    {
//        int nSum = number[i] - '0' + nTakeOver;
//        if (i == nLength - 1)
//            nSum++;
//
//        if (nSum >= 10)
//        {
//            if (i == 0)
//                isOverflow = true;
//            else
//            {
//                nSum -= 10;
//                nTakeOver = 1;
//                number[i] = '0' + nSum;
//            }
//        }
//        else
//        {
//            number[i] = '0' + nSum;
//            break;
//        }
//    }
//
//    return isOverflow;
//}
//
//// ====================������====================
//void Print1ToMaxOfNDigits_2(int n)
//{
//    if (n <= 0)
//        return;
//
//    char* number = new char[n + 1];
//    number[n] = '\0';
//
//    for (int i = 0; i < 10; ++i)
//    {
//        number[0] = i + '0';
//        Print1ToMaxOfNDigitsRecursively(number, n, 0);
//    }
//
//    delete[] number;
//}
//
//void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
//{
//    if (index == length - 1)
//    {
//        PrintNumber(number);
//        return;
//    }
//
//    for (int i = 0; i < 10; ++i)
//    {
//        number[index + 1] = i + '0';
//        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
//    }
//}
//
//// ====================��������====================
//// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
//// ��ӡ��������֣������Կ�ͷ��0
//void PrintNumber(char* number)
//{
//    bool isBeginning0 = true;
//    int nLength = strlen(number);
//
//    for (int i = 0; i < nLength; ++i)
//    {
//        if (isBeginning0 && number[i] != '0')
//            isBeginning0 = false;
//
//        if (!isBeginning0)
//        {
//            printf("%c", number[i]);
//        }
//    }
//
//    printf("\t");
//}

void PrintNumberInArray(int * number, int length);
void PrintNumberCore(int* number, int length, int index);

void Print1ToMaxOfNDigits_2(int n) {
    if(n <= 0) {
        return;
    }

    int* number = new int[n];
    PrintNumberCore(number, n, 0);
}

void PrintNumberCore(int* number, int length, int index) {
    for(int i = 0; i <= 9; i ++) {
        number[index] = i;
        if(index == length - 1) {
            PrintNumberInArray(number, length);
        }else {
            PrintNumberCore(number, length, index + 1);
        } 
    }
}

void PrintNumberInArray(int * number, int length) {
    bool foundStartIndex = false; 
    for(int i = 0; i < length; i ++) {
       if (!foundStartIndex && number[i] > 0 || length - 1 == i) {
           foundStartIndex = true; 
       }
       if(number[i] == 0 && foundStartIndex == true || number[i] > 0) {
            std::cout << number[i];
       }
    }
    std::cout <<std::endl; 
}

void Print1ToMaxOfNDigits_1(int n) {
    if(n <= 0) {
        return;
    }
    int *number = new int[n + 1];
    for(int i= 0; i < n + 1; i++) {
        number[i] = 0;
    }
    while(number[0] == 0) {
        PrintNumberInArray(number, n + 1);
        int incr = true;
        int index = n;
        while(incr == true && index >= 0) {
           if(number[index] == 9) {
               incr = true;  
               number[index] = 0;
           }else {
               incr = false;
               number[index] ++;
           }
           index --;
        }
    }
}

// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    //Print1ToMaxOfNDigits_2(n);

    printf("\nTest for %d ends.\n", n);
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}

