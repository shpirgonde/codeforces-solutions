// Author: Shivshankar Pirgonde
// Adapted from online resources (Google, ChatGPT) and rewritten for learning.

#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        char s[200005];
        scanf("%s", s);

        int zeros = 0, ones = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '0')
                zeros++;
            else
                ones++;
        }

        int ans = (zeros < ones) ? zeros : ones;

        if (zeros == ones)
            ans--;

        printf("%d\n", ans);
    }
}