#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int main()
{
    vector<string> vec;
    constexpr int N = 100'000;
    auto start = chrono::high_resolution_clock::now();
    // 실행 시간이 걸리는 코드
    auto end = chrono::high_resolution_clock::now();
    cout << "이동시간 : " << chrono::duration<double>(end - start).count() << "초" << endl;

    return 0;
}