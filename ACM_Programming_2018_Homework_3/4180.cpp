//
//  4180.cpp
//  ACM_Programming_2018_Homework_3
//
//  Created by Haichen Dong on 11/29/18.
//  Copyright © 2018 Haichen Dong. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

const int mx = 1e5 + 233;
int n, a, b, fir[mx], tot, cnt, in[mx], rk[mx];
struct E{
    int t, nx;
}e[mx];
std::queue<int> q;

inline void addEdge(int _s,int _t) {
    in[_t]++;
    e[++tot] = E{_t, fir[_s]} , fir[_s] = tot;
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= a; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        addEdge(s, t);
    }
    memset(rk, -1, sizeof rk);
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (cnt < n) {
        int cur = q.front();
        q.pop();
        rk[cur] = ++cnt;
        for (int i = fir[cur]; i; i = e[i].nx) {
            in[e[i].t]--;
            if (in[e[i].t] == 0) {
                q.push(e[i].t);
            }
        }
    }
    for (int i = 1;i <= b; i++) {
        int s, t;
        scanf("%d%d", &s, &t);
        if (rk[s] > rk[t]) std::swap(s,t);
        printf("%d %d\n", s, t);
    }
    return 0;
}
