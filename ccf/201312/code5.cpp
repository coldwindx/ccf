/*
问题描述
　　给定一个R行C列的地图，地图的每一个方格可能是'#', '+', '-', '|', '.', 'S', 'T'七个字符中的一个，分别表示如下意思：
　　'#': 任何时候玩家都不能移动到此方格；
　　'+': 当玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
　　'-': 当玩家到达这一方格后，下一步可以向左右两个方向相邻的一个非'#'方格移动一格；
　　'|': 当玩家到达这一方格后，下一步可以向上下两个方向相邻的一个非'#'方格移动一格；
　　'.': 当玩家到达这一方格后，下一步只能向下移动一格。如果下面相邻的方格为'#'，则玩家不能再移动；
　　'S': 玩家的初始位置，地图中只会有一个初始位置。玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
　　'T': 玩家的目标位置，地图中只会有一个目标位置。玩家到达这一方格后，可以选择完成任务，也可以选择不完成任务继续移动。如果继续移动下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格。
　　此外，玩家不能移动出地图。
　　请找出满足下面两个性质的方格个数：
　　1. 玩家可以从初始位置移动到此方格；
　　2. 玩家不可以从此方格移动到目标位置。
输入格式
　　输入的第一行包括两个整数R 和C，分别表示地图的行和列数。(1 ≤ R, C ≤ 50)。
　　接下来的R行每行都包含C个字符。它们表示地图的格子。地图上恰好有一个'S'和一个'T'。
输出格式
　　如果玩家在初始位置就已经不能到达终点了，就输出“I'm stuck!”（不含双引号）。否则的话，输出满足性质的方格的个数。
样例输入
5 5
--+-+
..|#.
..|##
S-+-T
####.
样例输出
2
样例说明
　　如果把满足性质的方格在地图上用'X'标记出来的话，地图如下所示：
　　--+-+
　　..|#X
　　..|##
　　S-+-T
　　####X
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Node{
    bool sstatus = false;
    bool tstatus = false;
    char ch;
    Node(char c) : ch(c) {}
};
int si, sj, ti, tj, n, m, cnt = 0;
bool in(char ch, string s){
    for(char & c : s)
        if(ch == c)
            return true;
    return false;
}
void dfss(vector<vector<Node*>> & graph, int i, int j){
    if(graph[i][j]->sstatus) return;
    switch(graph[i][j]->ch){
        case '#': return ;
        case 'T':
        case 'S':
        case '+': 
            graph[i][j]->sstatus = true;
            if(i + 1 < n) dfss(graph, i + 1, j);
            if(0 < i) dfss(graph, i - 1, j);
            if(j + 1 < m) dfss(graph, i, j + 1);
            if(0 < j) dfss(graph, i, j - 1);
            break;
        case '-':
            graph[i][j]->sstatus = true;
            if(j + 1 < m) dfss(graph, i, j + 1);
            if(0 < j) dfss(graph, i, j - 1);
            break;
        case '|':
            graph[i][j]->sstatus = true;
            if(i + 1 < n) dfss(graph, i + 1, j);
            if(0 < i) dfss(graph, i - 1, j);
            break;
        case '.':
            graph[i][j]->sstatus = true;
            if(i + 1 < n) dfss(graph, i + 1, j);
            break;
    }
}
void dfst(vector<vector<Node*>> & graph, int i, int j){
    if(graph[i][j]->tstatus) return;
    if(graph[i][j]->ch == '#') return;
    graph[i][j]->tstatus = true;
    // up
    if(0 < i && in(graph[i - 1][j]->ch, "+|.ST")) dfst(graph, i - 1, j);
    // down
    if(i + 1 < n && in(graph[i + 1][j]->ch, "+|ST")) dfst(graph, i + 1, j);
    // left
    if(0 < j && in(graph[i][j - 1]->ch, "+-ST")) dfst(graph, i, j - 1);
    // right
    if(j + 1 < m && in(graph[i][j + 1]->ch, "+-ST")) dfst(graph, i, j + 1);
}
int main(){
    cin >> n >> m;
    vector<vector<Node*>> graph(n, vector<Node*>(m));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            graph[i][j] = new Node(getchar());
            if('S' == graph[i][j]->ch) { si = i; sj = j; }
            if('T' == graph[i][j]->ch) { ti = i; tj = j; }
        }   
    }
    dfss(graph, si, sj);
    dfst(graph, ti, tj);
    if(!graph[ti][tj]->tstatus) {
        cout << "I'm stuck!" << endl;
        return 0;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(graph[i][j]->sstatus && !graph[i][j]->tstatus)
                ++cnt;
    cout << cnt << endl;
    return 0;
}