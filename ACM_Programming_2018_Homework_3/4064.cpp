//
//  4064.cpp
//  ACM_Programming_2018_Homework_3
//
//  Created by Haichen Dong on 12/2/18.
//  Copyright © 2018 Haichen Dong. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

const int mx = 1e5 + 233;
int n;
long long L, a[mx], b[mx], ans;

long long cal (int k) {
    long long ret = 0;
    for (int i = 1; i <= n; i++) {
        ret += std::min(std::abs(a[i] - b[(i + k - 1) % n + 1]), L - std::abs(a[i] - b[(i + k - 1) % n + 1]));
    }
    ans = std::min(ans, ret);
    return ret;
}

void work () {
    scanf("%d%lld", &n, &L);
	ans = (long long)1e16;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
    }
    std::sort(a + 1, a + 1 + n);
    std::sort(b + 1, b + 1 + n);
    for (int l = 0, r = n - 1 ; l < r; ) {
        int m1 = l + (r - l) / 3;
        int m2 = l + (r - l) * 2 / 3;
        if (cal(m1) < cal(m2)) {
            r = m2 - 1;
        } else {
            l = m1 + 1;
        }
    }
    printf("%lld\n", ans);
}

int main () {
	int T;
	scanf("%d", &T);
	while (T--) {
		work();
	}
	return 0;
}
