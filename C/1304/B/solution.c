// Author: Shivshankar Pirgonde
// Adapted from online resources and rewritten for learning.

#include <stdio.h>
#include <string.h>

#define MAXN 105 // Max no. of strings
#define MAXM 55  // Max length of each string

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char inputString[MAXN][MAXM];
    int used[MAXN] = {0};

    for (int i = 0; i < n; i++)
    {
        scanf("%s", inputString[i]);
    }

    char left[MAXN][MAXM];
    int leftCount = 0;

    char middle[MAXM] = "";
    int hasMiddle = 0;

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        char rev[MAXM];
        strcpy(rev, inputString[i]);

        // reverse a string
        for (int l = 0, r = m - 1; l < r; l++, r--)
        {
            char temp = rev[l];
            rev[l] = rev[r];
            rev[r] = temp;
        }

        if (strcmp(inputString[i], rev) == 0)
        {
            // self Palindrom for Middle
            if (!hasMiddle)
            {
                strcpy(middle, inputString[i]);
                hasMiddle = 1;
                used[i] = 1;
            }
        }

        // find reverse pair from remaining strings
        else
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!used[j] && strcmp(inputString[j], rev) == 0)
                {
                    strcpy(left[leftCount++], inputString[i]);
                    used[i] = used[j] = 1;
                    break;
                }
            }
        }
    }

    // Build result
    char result[10000] = "";

    // left part
    for (int i = 0; i < leftCount; i++)
    {
        strcat(result, left[i]);
    }

    // middle
    if (hasMiddle)
    {
        strcat(result, middle);
    }

    // right part (start from last string of left + reverse the string)
    for (int i = leftCount - 1; i >= 0; i--)
    {
        char rev[MAXM];
        strcpy(rev, left[i]);

        for (int l = 0, r = m - 1; l < r; l++, r--)
        {
            char temp = rev[l];
            rev[l] = rev[r];
            rev[r] = temp;
        }
        strcat(result, rev);
    }

    printf("%d\n", (int)strlen(result));
    printf("%s\n", result);

    return 0;
}