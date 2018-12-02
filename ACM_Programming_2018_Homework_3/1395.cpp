//
//  1395.cpp
//  ACM_Programming_2018_Homework_3
//
//  Created by Haichen Dong on 12/1/18.
//  Copyright © 2018 Haichen Dong. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <assert.h>

const int mx = 1e5 + 233;
int n, m, id[mx], tot;
double base;

struct N {
    double possm, negsm, sz, asn;
    int tag, lson, rson;
    // tag = 1:asn 2:abs
    void assign (double k);
    void absolute ();
    void pushdown ();
}t[mx<<1];

void N::assign (double k) {
    assert(sz);
    tag = 1;
    asn = k;
    if (asn > 0) {
        possm = asn * sz;
        negsm = 0;
    } else {
        possm = 0;
        negsm = asn * sz;
    }
}
void N::absolute () {
    if (tag == 2) {
        return;
    } else if (tag == 1) {
        if (asn < 0) {
            possm = -negsm;
            negsm = 0;
            asn = -asn;
        }
    } else {
        possm -= negsm;
        negsm = 0;
        tag = 2;
    }
}
void N::pushdown () {
    if (lson) {
        if (tag == 1) {
            t[lson].assign(asn);
            t[rson].assign(asn);
        } else {
            t[lson].absolute();
            t[rson].absolute();
        }
    }
    asn = 0;
    tag = 0;
}
void asn (int cur, int l, int r, int ql, int qr, double k) {
    if (l == ql && r == qr) {
        t[cur].assign(k);
        return;
    }
    if (t[cur].tag) {
        t[cur].pushdown();
    }
    int m = (l + r) >> 1;
    if (ql <= m) {
        asn(t[cur].lson, l, m, ql, std::min(m, qr), k);
    }
    if (qr > m) {
        asn(t[cur].rson, m + 1, r, std::max(ql, m + 1), qr, k);
    }
    t[cur].possm = t[t[cur].lson].possm + t[t[cur].rson].possm;
    t[cur].negsm = t[t[cur].lson].negsm + t[t[cur].rson].negsm;
}
void abs (int cur, int l, int r, int ql, int qr) {
    if (l == ql && r == qr) {
        t[cur].absolute();
        return;
    }
    if (t[cur].tag) {
        t[cur].pushdown();
    }
    int m = (l + r) >> 1;
    if (ql <= m) {
        abs(t[cur].lson, l, m, ql, std::min(m, qr));
    }
    if (qr > m) {
        abs(t[cur].rson, m + 1, r, std::max(ql, m + 1), qr);
    }
    t[cur].possm = t[t[cur].lson].possm + t[t[cur].rson].possm;
    t[cur].negsm = t[t[cur].lson].negsm + t[t[cur].rson].negsm;
}

int build (int l, int r) {
    int cur = ++tot;
    if (l == r) {
        id[l] = cur;
        return cur;
    }
    int m = (l + r) >> 1;
    t[cur].lson = build(l, m);
    t[cur].rson = build(m + 1, r);
    return cur;
}
void init (int cur) {
    if (t[cur].lson) {
        init(t[cur].lson);
        init(t[cur].rson);
        t[cur].sz = t[t[cur].lson].sz + t[t[cur].rson].sz;
        t[cur].possm = t[t[cur].lson].possm + t[t[cur].rson].possm;
        t[cur].negsm = t[t[cur].lson].negsm + t[t[cur].rson].negsm;
    } else {
        t[cur].possm *= t[cur].sz;
        t[cur].negsm *= t[cur].sz;
    }
}

int main () {
    scanf("%d", &n);
    build(1, n);
    base = 0.5 * n * (n + 1);
    for (int i = 1; i <= n; i++) {
        double tmp;
        scanf("%lf", &tmp);
        if (tmp > 0) t[id[i]].possm = tmp;
        else t[id[i]].negsm = tmp;
    }
    for (int i = 1; i <= n; i++) {
        t[id[(n + 1) / 2]].sz += std::min(i, n + 1 - i);
        t[id[(n + 2) / 2]].sz += std::min(i, n + 1 - i);
    }
    if ((n + 1) / 2 == (n + 2) / 2) {
        t[id[(n + 1)/2]].sz /= 2;
    }
    for (int i = (n + 1) / 2 - 1, j = (n + 2) / 2 + 1, k = n % 2 == 1 ? 1 : 2; i >= 1; i--, j++, k += 2) {
        t[id[i]].sz = t[id[i + 1]].sz - k;
        t[id[j]].sz = t[id[j - 1]].sz - k;

    }
    for (int i = 1; i <= n; i++) {
        printf(">%lf\n", t[id[i]].sz);
    }
    init(1);
    scanf("%d", &m);
    while (m--) {
        int op;
        scanf("%d", &op);
        if (op == 3) {
            double ret = (t[1].possm + t[1].negsm) / base;
            while (ret <= -10000.0 || ret >= 10000.0) {
                ret /= 10.0;
            }
            printf("%.0lf\n", ret);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            if (op == 1) {
                double k;
                scanf("%lf", &k);
                asn(1, 1, n, l, r, k);
            } else if (op == 2) {
                abs(1, 1, n, l, r);
            }
        }
    }
    return 0;
}
