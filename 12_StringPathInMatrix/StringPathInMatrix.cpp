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

// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
// A B T G
// C F C S
// J D E H

#include <cstdio>
#include <string>
#include <stack>

using namespace std;

//bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);
//
//bool hasPath(const char* matrix, int rows, int cols, const char* str)
//{
//    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
//        return false;
//
//    bool *visited = new bool[rows * cols];
//    memset(visited, 0, rows * cols);
//
//    int pathLength = 0;
//    for(int row = 0; row < rows; ++row)
//    {
//        for(int col = 0; col < cols; ++col)
//        {
//            if(hasPathCore(matrix, rows, cols, row, col, str,
//                pathLength, visited))
//            {
//                return true;
//            }
//        }
//    }
//
//    delete[] visited;
//
//    return false;
//}
//
//bool hasPathCore(const char* matrix, int rows, int cols, int row,
//    int col, const char* str, int& pathLength, bool* visited)
//{
//    if(str[pathLength] == '\0')
//        return true;
//
//    bool hasPath = false;
//    if(row >= 0 && row < rows && col >= 0 && col < cols
//        && matrix[row * cols + col] == str[pathLength]
//        && !visited[row * cols + col])
//    {
//        ++pathLength;
//        visited[row * cols + col] = true;
//
//        hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
//            str, pathLength, visited)
//            || hasPathCore(matrix, rows, cols, row - 1, col,
//                str, pathLength, visited)
//            || hasPathCore(matrix, rows, cols, row, col + 1,
//                str, pathLength, visited)
//            || hasPathCore(matrix, rows, cols, row + 1, col,
//                str, pathLength, visited);
//
//        if(!hasPath)
//        {
//            --pathLength;
//            visited[row * cols + col] = false;
//        }
//    }
//
//    return hasPath;
//}

/**
*/

/** version 1**/
bool hasPathCore(const char* matrix, int rows, int cols, int r,
        int c, const char* str, int& pathLength, bool* visited)
{
    if(visited[r * cols + c]) {
        return false;
    }

    if(str[pathLength] != matrix[r * cols + c]) {
        return false;
    }else if(str[pathLength + 1] == '\0') {
        return true;
    }

    visited[r * cols + c] = true;
    pathLength ++;

    //upper
    if(r > 0) {
        int upperR = r - 1;
        int upperC = c;
        bool hasPath = hasPathCore(matrix, rows, cols, upperR, upperC, str, pathLength, visited);
        if(hasPath) {
            return true;
        }
    }
    //lower
    if(r < rows - 1) {
        int lowerR = r + 1;
        int lowerC = c;
        bool hasPath = hasPathCore(matrix, rows, cols, lowerR, lowerC, str, pathLength, visited);
        if(hasPath) {
            return true;
        }
    }
    //left
    if(c > 0) {
        int leftR = r;
        int leftC = c - 1;
        bool hasPath = hasPathCore(matrix, rows, cols, leftR, leftC, str, pathLength, visited);
        if(hasPath) {
            return true;
        }
    }
    //right
    if(c < cols - 1) {
        int rightR = r;
        int rightC = c +1;
        bool hasPath = hasPathCore(matrix, rows, cols, rightR, rightC, str, pathLength, visited);
        if(hasPath) {
            return true;
        }
    }
    pathLength --;
    visited[r * cols + c] = false;
    return false;
}

bool hasPath(const char* matrix, int rows, int cols, const char* str) {
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr) {
        return false;
    }

    bool* visited = new bool[rows * cols];
    for(int i = 0; i < rows * cols; i++ ) {
        visited[i] = false;
    }

    int pathLength = 0;

    for(int c = 0; c < cols; c ++) {
        for(int r = 0; r < rows; r ++) {
            if(hasPathCore(matrix, rows, cols, r, c, str, pathLength, visited))    {
                return true;
            }
        }
    }
    return false;
}


// ====================���Դ���====================
void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    Test("Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    Test("Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    Test("Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    Test("Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    Test("Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    Test("Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    Test("Test11", (const char*) matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();
    Test12();

    return 0;
}
