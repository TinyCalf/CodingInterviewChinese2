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

#pragma once
#include <stack>
#include <exception>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    
    // �ڶ���ĩβ����һ�����
    void appendTail(const T& node);

    // ɾ�����е�ͷ���
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
} 

// template<typename T> T CQueue<T>::deleteHead()
// {
//     if(stack2.size()<= 0)
//     {
//         while(stack1.size()>0)
//         {
//             T& data = stack1.top();
//             stack1.pop();
//             stack2.push(data);
//         }
//     }

//     if(stack2.size() == 0)
//         throw new exception("queue is empty");

//     T head = stack2.top();
//     stack2.pop();

//     return head;
// }

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size() <= 0) {
        while(stack1.size() >0) {
            T& data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }

    if(stack2.size() <= 0) {
        throw new exception("queue is empty");
    }

    T head = stack2.top();
    stack2.pop();

    return head;
}
