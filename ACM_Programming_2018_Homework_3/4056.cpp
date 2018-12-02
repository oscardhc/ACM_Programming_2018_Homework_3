//
//  4056.cpp
//  ACM_Programming_2018_Homework_3
//
//  Created by Haichen Dong on 11/28/18.
//  Copyright © 2018 Haichen Dong. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <vector>

const int mx = 4e5 + 233;
int n, m, f[mx];
long long sz[mx], sm[mx], val[mx], tmp[mx], pr[mx];
std::pair< int, std::pair<int,int> > e[mx];
std::vector< int > v[mx];

int gtf(int x) {
    if (f[x] == x) return x;
    else return f[x] = gtf(f[x]);
}

void dfs1(int cur, int fat) {
    sz[cur] = cur <= n;
    for (int i = 0, tp = v[cur].size(); i < tp; i++) {
        dfs1(v[cur][i], cur);
        sz[cur] += sz[v[cur][i]];
    }
}

void dfs2(int cur, int fat) {
    tmp[cur] = sz[cur] * val[cur];
    sm[cur] = tmp[fat] - sz[cur] * val[fat];
    pr[cur] = sm[cur] + pr[fat];
    for (int i = 0, tp = v[cur].size(); i < tp; i++) {
        dfs2(v[cur][i], cur);
    }
}

inline void work() {
    scanf("%d", &n);
    m = n - 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &e[i].second.first, &e[i].second.second, &e[i].first);
    }
    std::sort(e + 1, e + 1 + m);
    reverse(e + 1, e + 1 + m);
    for (int i = 1; i <= n + m; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int f1 = gtf(e[i].second.first), f2 = gtf(e[i].second.second);
        f[f1] = f[f2] = i + n;
        val[i + n] = e[i].first;
        v[i + n].push_back(f1);
        v[i + n].push_back(f2);
    }
    int root = gtf(1);
    dfs1(root, 0);
    dfs2(root, 0);
	long long ans = 0;
	for (int i = 1; i <= n + m; i++) {
		ans = std::max(ans, pr[i]);
		v[i].clear();
	}
	printf("%lld\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        work();
    }
    return 0;
}
