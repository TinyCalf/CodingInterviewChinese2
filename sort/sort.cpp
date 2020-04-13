#include <iostream>
#include <string.h>

using namespace std;

void BubbleSort(int* numbers, int length) {
    if(numbers == nullptr || length < 0)
        return;
    int notFinish = true;
    while(notFinish) {
        notFinish = false;
        for(int i = 0; i < length - 1; i++) {
            if(numbers[i] > numbers[i+1]) {
                int tmp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i+ 1] = tmp;
                notFinish = true;
            }
        }
    }
}

//==============================================================

void QuickSortCore(int* numbers, int length, int start , int end) {
    if(start >= end)
        return;
    int cIndex = start;
    for(int i = start + 1; i <= end; i++) {
        if(numbers[i] < numbers[cIndex]) {
            int tmp = numbers[i];
            for(int j = i - 1; j >= cIndex; j --) {
                numbers[j+ 1] = numbers[j];
            }
            numbers[cIndex] = tmp;
            cIndex ++;
        }
    }
    QuickSortCore(numbers, length, start, cIndex - 1);
    QuickSortCore(numbers, length, cIndex + 1, end);
}

void QuickSort(int* numbers, int length) {
    if(numbers == nullptr || length < 0)
        return;
    QuickSortCore(numbers, length, 0, length -1);
}

//==============================================================

void InsertSort(int* numbers, int length) {
    if(numbers == nullptr || length < 0)
        return;

    for(int i = 1; i < length ;i++) {
        cout << "i " << i  << ' ' << numbers[i] << endl;
        int tmp = numbers[i];
        int j = i;
        while(j > 0 && numbers[j - 1] > tmp) {
            cout << "j " << j << ' ' << numbers[j] << endl;
            j--;
            numbers[j + 1] = numbers[j];
        }
        numbers[j] = tmp;
    }
}

// ================================test==========================
//
void printArray(int* numbers, int length) {
    for(int i = 0; i < length; i++)
        cout << numbers[i] << ' ';
    cout << endl;
}

int* cpNumbers(int* numbers, int length) {
    int* b = new int[length];
    memcpy(b,numbers,sizeof(b));
    return b;
}

void test(int* numbers, int length) {
    cout << "The origin array is: ";
    printArray(numbers, length);

    //BubbleSort(numbers, length);
    //QuickSort(numbers, length);
    InsertSort(numbers, length);

    cout << "The result is:";
    printArray(numbers, length);

    cout << endl;
}

void test1() {
    int numbers[] = {2,1,3,1,4};
    test(numbers, sizeof(numbers)/sizeof(numbers[0]));
}

void test2() {
    int numbers[] = {0,0,1,0,0};
    test(numbers, sizeof(numbers)/sizeof(numbers[0]));
}

void test3() {
    int numbers[] = {1,5,4,3,6,8,7,2,2,9,12,11,10};
    test(numbers, sizeof(numbers)/sizeof(numbers[0]));
}

int main() {
    test1();
    test2();
    test3();
}
