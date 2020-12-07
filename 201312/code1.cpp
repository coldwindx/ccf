/*
Question：
    给定n个正整数，找出它们中出现次数最多的数。如果这样的数有多个，请输出其中最小的一个。
Input：
    输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
    输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。
Output：
    输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。
Input Example:
6
10 1 10 20 30 20
Output Example:
10
*/
#include<iostream>
#include<stdlib.h>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    int size, n, _min = INT_MAX, _cnt = 0;
    cin >> size;
    map<int, int> countMap;
    // input
    for(int i = 0; i < size; ++i){
        cin >> n;
        countMap[n]++;
        if(_cnt < countMap[n]){
            _cnt = countMap[n];
            _min = min(_min, n);
        }
    }
    // output
    cout << _min << endl;
    system("pause");
    return 0;
}