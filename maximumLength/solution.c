#include <stdio.h>
#include <string.h>

int helper(const char* s, int n, int x) {
    int cnt[26] = {0};
    int p = 0;

    for (int i = 0; i < n; i++) {
        while (s[p] != s[i]) p++;
        if (i - p + 1 >= x) cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] > 2) return 1;  // Return true if more than 2 occurrences of a character
    }

    return 0;  // Return false if no character appears more than twice
}

int maximumLength(char* s) {
    int n = strlen(s);
    int l = 1, r = n;

    if (!helper(s, n, l)) return -1;

    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (helper(s, n, mid)) l = mid;
        else r = mid;
    }

    return l;
}
