//
//  4182.cpp
//  ACM_Programming_2018_Homework_3
//
//  Created by Haichen Dong on 12/2/18.
//  Copyright © 2018 Haichen Dong. All rights reserved.
//

#include <stdio.h>
#include <string.h>

const int mx = 3e6 + 233;
int n, ok = 26, c1[30], c2[30];
char s1[mx], s2[mx];

int main() {
    scanf("%s%s",s1 + 1, s2 + 1);
    n = strlen(s1 + 1);
    for (int i = 1; i <= n; i++) {
        c1[s1[i] - 'a']++;
        if (c1[s1[i] - 'a'] == c2[s1[i] - 'a']) {
            ok++;
        } else if (c1[s1[i] - 'a'] == c2[s1[i] - 'a'] + 1) {
            ok--;
        }
        c2[s2[i] - 'a']++;
        if (c2[s2[i] - 'a'] == c1[s2[i] - 'a']) {
            ok++;
        } else if (c2[s2[i] - 'a'] == c1[s2[i] - 'a'] + 1) {
            ok--;
        }
    }
    for (int i = n; i >= 1; i--) {
        
        if (ok == 26) {
            for (int j = 0; j < i; j++) {
                int flag = 1;
                for (int k = 1; k <= i; k++) {
                    if(s1[k] != s2[(j + k) % i + 1]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    printf("%d\n", i);
                    return 0;
                }
            }
        }
        
        c1[s1[i] - 'a']--;
        if (c1[s1[i] - 'a'] == c2[s1[i] - 'a']) {
            ok++;
        } else if (c1[s1[i] - 'a'] == c2[s1[i] - 'a'] - 1) {
            ok--;
        }
        c2[s2[i] - 'a']--;
        if (c2[s2[i] - 'a'] == c1[s2[i] - 'a']) {
            ok++;
        } else if (c2[s2[i] - 'a'] == c1[s2[i] - 'a'] - 1) {
            ok--;
        }
    }
    printf("0\n");
    return 0;
}
