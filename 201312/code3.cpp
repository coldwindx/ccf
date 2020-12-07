/**
Question:
    在横轴上放了n个相邻的矩形，每个矩形的宽度是1，而第i（1 ≤ i ≤ n）个矩形的高度是hi。这n个矩形构成了一个直方图。例如，下图中六个矩形的高度就分别是3, 1, 6, 5, 2, 3。
    请找出能放在给定直方图里面积最大的矩形，它的边要与坐标轴平行。对于上面给出的例子，最大矩形如下图所示的阴影部分，面积是10。
Input:
    第一行包含一个整数n，即矩形的数量(1 ≤ n ≤ 1000)。
    第二行包含n 个整数h1, h2, … , hn，相邻的数之间由空格分隔。(1 ≤ hi ≤ 10000)。hi是第i个矩形的高度。
Output:
    输出一行，包含一个整数，即给定直方图内的最大矩形的面积。
Input Example:
6
3 1 6 5 2 3
Output Example:
10
*/
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    // vector<int> nums(n + 1);
    // dp[i][j]表示横轴i~j之间的最小高度
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, INT_MAX));
    int area = 0;
    for(int j = 1; j < n + 1; ++j){
        // cin >> nums[j];
        cin >> dp[j][j];
        for(int i = 1; i < j; ++i){
            dp[i][j] = min(dp[i][j - 1], dp[j][j]);
            area = max(area, dp[i][j] * (j - i + 1));
        }
    }
    cout << area << endl;
    system("pause");
    return 0;
}