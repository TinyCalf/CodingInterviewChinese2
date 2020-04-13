/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����?
// ���ߣ��κ���
//==================================================================

// ������39�������г��ִ�������һ�������?
// ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���?
// ������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
// ������5�Σ��������鳤�ȵ�һ�룬������2��

#include <cstdio>
#include "..\Utilities\Array.h"
#include <iostream>

using namespace std;

bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if(numbers == nullptr && length <= 0)
        g_bInputInvalid = true;

    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
    int times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] == number)
            times++;
    }
 
    bool isMoreThanHalf = true;
    if(times * 2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}

// ====================����1====================
int Part(int* numbers, int length, int start, int end) {
	cout << start << ' ' << end << endl;
    if(start == end)
        return numbers[start];
	if (start > end)
		return 0;

    int chosenIndex = start;

    for(int i = start + 1; i <= end; i++) {
        if(numbers[i] < numbers[chosenIndex]) {
            int tmp = numbers[i];
            for(int j = i - 1; j>=chosenIndex; j --) {
                numbers[j + 1] = numbers[j];
            }
            numbers[chosenIndex] = tmp;
            chosenIndex ++;
        }
    }

    if(chosenIndex == length >> 1) 
        return numbers[chosenIndex];
	else if(chosenIndex >  length >> 1)
        return Part(numbers, length, start, chosenIndex - 1);
    else 
        return Part(numbers, length, chosenIndex + 1, end);
}


int MoreThanHalfNum_Solution1(int* numbers, int length) {
    return Part(numbers, length, 0 , length -1);
}


























// int MoreThanHalfNum_Solution1(int* numbers, int length)
// {
//     if(CheckInvalidArray(numbers, length))
//         return 0;
 
//     int middle = length >> 1;
//     int start = 0;
//     int end = length - 1;
//     int index = Partition(numbers, length, start, end);
//     while(index != middle)
//     {
//         if(index > middle)
//         {
//             end = index - 1;
//             index = Partition(numbers, length, start, end);
//         }
//         else
//         {
//             start = index + 1;
//             index = Partition(numbers, length, start, end);
//         }
//     }
 
//     int result = numbers[middle];
//     if(!CheckMoreThanHalf(numbers, length, result))
//         result = 0;

//     return result;
// }

// ====================����2====================
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
    if(CheckInvalidArray(numbers, length))
        return 0;
 
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
 
    if(!CheckMoreThanHalf(numbers, length, result))
        result = 0;
 
    return result;
}

// ====================���Դ���====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result = MoreThanHalfNum_Solution1(numbers, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = MoreThanHalfNum_Solution2(copy, length);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    delete[] copy;
}

// ���ڳ��ִ����������鳤��һ�������?
void Test1()
{
    int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// �����ڳ��ִ����������鳤��һ�������?
void Test2()
{
    int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// ���ִ����������鳤��һ������ֶ������������ǰ�벿��
void Test3()
{
    int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// ���ִ����������鳤��һ������ֶ�����������ĺ�벿��?
void Test4()
{
    int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// �����ָ��?
void Test5()
{
   int numbers[] = {1};
   Test("Test5", numbers, 1, 1, false);
}

// �����ָ��?
void Test6()
{
    Test("Test6", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

