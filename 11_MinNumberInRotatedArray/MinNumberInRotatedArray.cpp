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

// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

#include <cstdio>
#include <iostream>
using namespace std;

//int MinInOrder(int* numbers, int index1, int index2);

//int Min(int* numbers, int length)
//{
//    if(numbers == nullptr || length <= 0)
//        return 0;
//
//    int index1 = 0;
//    int index2 = length - 1;
//    int indexMid = index1;
//    while(numbers[index1] >= numbers[index2])
//    {
//        // ���index1��index2ָ�����ڵ���������
//        // ��index1ָ���һ����������������һ�����֣�
//        // index2ָ��ڶ���������ĵ�һ�����֣�Ҳ���������е���С����
//        if(index2 - index1 == 1)
//        {
//            indexMid = index2;
//            break;
//        }
//
//        // ����±�Ϊindex1��index2��indexMidָ�������������ȣ�
//        // ��ֻ��˳�����
//        indexMid = (index1 + index2) / 2;
//        if(numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
//            return MinInOrder(numbers, index1, index2);
//
//        // ��С���ҷ�Χ
//        if(numbers[indexMid] >= numbers[index1])
//            index1 = indexMid;
//        else if(numbers[indexMid] <= numbers[index2])
//            index2 = indexMid;
//    }
//
//    return numbers[indexMid];
//}
//
//int MinInOrder(int* numbers, int index1, int index2)
//{
//    int result = numbers[index1];
//    for(int i = index1 + 1; i <= index2; ++i)
//    {
//        if(result > numbers[i])
//            result = numbers[i];
//    }
//
//    return result;
//}
//

/**
 * ������
 */
int findMin(int* numbers, int length, int leftIndex, int rightIndex) {
    int minNum;
    if(leftIndex == rightIndex)  {
        minNum = numbers[leftIndex];
        return minNum;
    }

    int middleIndex = leftIndex + (rightIndex - leftIndex) >> 1;

    if(numbers[leftIndex] == numbers[rightIndex]) {
        minNum = findMin(numbers, length, leftIndex + 1, middleIndex);
    }
    else if(numbers[leftIndex] > numbers[rightIndex]) {
        int num1 = findMin(numbers, length, leftIndex, middleIndex);
        int num2 = findMin(numbers, length, middleIndex + 1, rightIndex);
        if(num1 > num2) {
            minNum = num2;
        }else {
            minNum = num1;
        }
    }
    else {
        minNum = numbers[leftIndex];
    }

    return minNum;
}

int Min(int* numbers, int length) {
    if(numbers == nullptr || length < 0) {
        return 0;
    }
    int leftIndex = 0;
    int rightIndex = length - 1;
    int res = findMin(numbers, length, leftIndex, rightIndex);
    cout << res << endl;
    return res;
}

// ====================���Դ���====================
void Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char* argv[])
{
    // �������룬��������������һ����ת
    int array1[] = { 3, 4, 5, 1, 2 };
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = { 1, 0, 1, 1, 1 };
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = { 1, 2, 3, 4, 5 };
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // ������ֻ��һ������
    int array6[] = { 2 };
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // ����nullptr
    Test(nullptr, 0, 0);

    return 0;
}

