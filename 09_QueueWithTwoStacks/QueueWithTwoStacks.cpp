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

// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
// ��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�

#include "Queue.h"

// ====================���Դ���====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');

    return 0;
}

