// Author: Shivshankar Pirgonde

#include <stdio.h>

void solve(char s[])
{
    int zeros = 0, ones = 0;

    for (char *p = s; *p != '\0'; p++)
    {
        if (*p == '0')
            zeros++;
        else
            ones++;
    }

    int ans = (zeros < ones) ? zeros : ones;

    if (zeros == ones)
        ans--;

    printf("%d\n", ans);
}

int main()
{
    char s[200005]; 
    int t;

    scanf("%d", &t);

    while (t--)
    {

        scanf("%s", s);
        solve(s);
    }
    return 0;
}