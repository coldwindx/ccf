/*
问题描述
　　我们把一个数称为有趣的，当且仅当：
　　1. 它的数字只包含0, 1, 2, 3，且这四个数字都出现过至少一次。
　　2. 所有的0都出现在所有的1之前，而所有的2都出现在所有的3之前。
　　3. 最高位数字不为0。
　　因此，符合我们定义的最小的有趣的数是2013。除此以外，4位的有趣的数还有两个：2031和2301。
　　请计算恰好有n位的有趣的数的个数。由于答案可能非常大，只需要输出答案除以1000000007的余数。
输入格式
　　输入只有一行，包括恰好一个正整数n (4 ≤ n ≤ 1000)。
输出格式
　　输出只有一行，包括恰好n 位的整数中有趣的数的个数除以1000000007的余数。
样例输入
4
样例输出
3
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

int main(){
    // 0 当前数字之前不包含任何数字，当前数字：1，2，3
    // 1 当前数字之前包含[0]，当前数字[0,1,2,3]
    // 2 当前数字之前包含[1],当前数字[1,2,3]
    // 3 当前数字之前包含[2],当前数字[0,1,2,3]
    // 4 当前数字之前包含[3],当前数字[0,1,3]

    // 0 - 0000 - 1,2,3 - 0
    // 0001 - 0 - error - 1
    // 0010 - 1 - 1,2,3 - 2
    // 0011 - 0,1 - 1,2,3 - 3
    // 0100 - 2 - 0,1,2,3 - 4
    // 0101 - 0,2 - 0,1,2,3 - 5
    // 0110 - 1,2 - 1,2,3 - 6
    // 0111 - 0,1,2 - 1,2,3 - 7
    // 1000 - 3 - 0,1,3 - 8
    // 1001 - 0,3 - 0,1,3 - 9
    // 1010 - 1,3 - 1,3 - 10
    // 1011 - 0,1,3 - 1,3 - 11
    // 1100 - 2,3 - 0,1,3 -12
    // 1101 - 0,2,3 - 0,1,3 - 13
    // 1110 - 1,2,3 - 1,3 - 14
    // 1111 - 0,1,2,3 - 1,3 - 15
    int n;
    cin >> n;
    vector<vector<long long> > vc(16, vector<long long>(n, 0));
    vc[2][0] = vc[4][0] = vc[8][0] = 1;
    for(int i = 1; i < n; ++i){
        vc[4][i] = vc[4][i - 1];
        vc[5][i] = vc[4][i - 1] + 2l * vc[5][i - 1];
        vc[7][i] = vc[3][i - 1] + vc[5][i - 1] + 2l * vc[7][i - 1];
        vc[12][i] = vc[4][i - 1] + vc[12][i - 1];
        vc[13][i] = vc[5][i - 1] + vc[12][i - 1] + 2l * vc[13][i - 1];
        vc[15][i] = vc[7][i - 1] + vc[13][i - 1] + 2l * vc[15][i - 1];
    }
    cout << vc[15][n - 1] % 1000000007 << endl;
    system("pause");
    return 0;
}
