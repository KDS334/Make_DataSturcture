// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

#include "MyStack.h"
#include "MyQueue.h"
#include "MyVector.h"

//_msize 함수를 이용하여 힙영역에 할당된 크기를 얻을 수 있다.

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    CMyVector<int> vecInt1;
    CMyVector<int> vecInt2;

    vecInt1.push_back(100);
    vecInt1.push_back(200);
    vecInt1.push_back(300);
    vecInt1.push_back(400);

    vecInt2.push_back(10);
    vecInt2.push_back(20);
    vecInt2.push_back(30);
    vecInt2.push_back(40);

    vecInt1.swap(vecInt2);

    for (int i = 0; i < vecInt1.size(); ++i)
        cout << vecInt1[i] << '\n';

    for (int i = 0; i < vecInt2.size(); ++i)
        cout << vecInt2[i] << '\n';
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
