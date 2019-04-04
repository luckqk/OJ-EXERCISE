#include "stdc++.h"
using namespace std;

// n, m：意义如题
// matrix：一个字符串数组，用来记录所给矩形，matrix[i][j]表示所给矩形第i行第j列的字符（下标均从0开始）
// 返回值：题目所求答案，即最大矩形面积
int getAnswer(int n, int m, string *matrix) {
    /* 请在这里设计你的算法，并将答案返回 */
}

int main() {
    ios::sync_with_stdio(false);  // 读入优化
    
    int n, m;
    cin >> n >> m;
    
    string *matrix = new string[n]();
    
    for (int i = 0; i < n; ++i)
        cin >> matrix[i];
    
    cout << getAnswer(n, m, matrix) << endl;
    
    delete[] matrix;
    return 0;
}