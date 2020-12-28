/*
问题描述
　　给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
输入格式
　　输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
　　输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。
输出格式
　　输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
样例输入
6
10 1 10 20 30 20
样例输出
10
*/
#include<iostream>
#include<stdlib.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, m, _min = INT_MAX, _cnt = 0;
    map<int, int> mp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> m;
        mp[m]++;
        if(mp[m] == _cnt){
            _min = min(_min, m);
            continue;
        }
        if(_cnt < mp[m]){
            _min = m;
            _cnt = mp[m];
        }
    }
    cout << _min << endl;
    system("pause");
    return 0;
}