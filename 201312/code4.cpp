/*
Question:
    我们把一个数称为有趣的，当且仅当：
　　1. 它的数字只包含0, 1, 2, 3，且这四个数字都出现过至少一次。
　　2. 所有的0都出现在所有的1之前，而所有的2都出现在所有的3之前。
　　3. 最高位数字不为0。
　　因此，符合我们定义的最小的有趣的数是2013。除此以外，4位的有趣的数还有两个：2031和2301。
　　请计算恰好有n位的有趣的数的个数。由于答案可能非常大，只需要输出答案除以1000000007的余数。
Input:
    输入只有一行，包括恰好一个正整数n (4 ≤ n ≤ 1000)。
Output:
    输出只有一行，包括恰好n 位的整数中有趣的数的个数除以1000000007的余数。
Input Example:
    4
Output Example:
    3
*/
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<vector<int> > dp(4, vector<int>(n, -1));
    // init
    system("pause");
    return 0;
}