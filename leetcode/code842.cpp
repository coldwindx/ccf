/*
842. 将数组拆分成斐波那契序列

给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。
形式上，斐波那契式序列是一个非负整数列表 F，且满足：
0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。
返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

示例 1：
输入："123456579"
输出：[123,456,579]

示例 2：
输入: "11235813"
输出: [1,1,2,3,5,8,13]

示例 3：
输入: "112358130"
输出: []
解释: 这项任务无法完成。

示例 4：
输入："0123"
输出：[]
解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。

示例 5：
输入: "1101111"
输出: [110, 1, 111]
解释: 输出 [11,0,11,11] 也同样被接受。

提示：
1 <= S.length <= 200
字符串 S 中只含有数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include<string>
#include<vector>
using namespace std;
// 将输入的字符串拆分成数组，该数组为斐波那契数列
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;     // 存储斐波那契数列
        int cnt = 0;            // result的长度
        _cut = vector<int>(256, 1);
        _dfs(S, result, cnt);
        return result;
    }
private:
    vector<int> _cut;   // 记录当前递归是，每个数列值对应的截取长度，默认1
    /*
    s: 当前剩余字符串
    result: 当前已截取到的满足要求的数组
    cnt: result的长度
    */
    void _dfs(string s, vector<int> & result, int cnt){
        // 递归终止条件: s.size()==0
        if(0 == s.size()) return; 
        for(int i = _cut[cnt - 1], size = s.size(); i < size; ++i){     
            // 需要判断当前截取到的数字，首字符是否为'0'
            if('0' == s[0]){
                // 这里需要判断回溯条件
                continue;
            } 
            // i表示要截取的长度，从1开始，最长可以截取size个字符
            int val = stoi(s.substr(0, i));
            if(cnt < 2 || result[cnt - 1] + result[cnt - 2] == val){
                // 当已经截取的数组长度不足两个时，可以直接插入
                // 满足斐波那契数列时，可以直接插入
                result.push_back(val);
                _cut[cnt] = i;
                ++cnt;
                s = s.substr(i);
            }else{
                // 继续，当当前截取长度为size时，需要回溯
                continue;
            }
            // 递归
            return _dfs(s, result, cnt);
        }    
        // 需要回溯
        _cut[cnt] = 1;
        if(--cnt == -1) return;
        s = to_string(result.back()) + s;
        result.pop_back(); 
        // 需要记录上一次截取的长度 -> 全局变量cut
        return _dfs(s, result, cnt);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string S = stringToString(line);
        
        vector<int> ret = Solution().splitIntoFibonacci(S);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}