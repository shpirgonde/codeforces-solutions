// Author: Shivshankar Pirgonde
// Adapted from online resources and rewritten for learning.

#include <stdio.h>
#include <string.h>

#define MAXN 105 // Max no. of input strings.
#define MAXM 55  // Max length of each input string.

// Function Prototypes
void reverseString(char str[], int len);
void checkReverse(const char s1[], const char s2[], int m);
void solve(int n, int m, char inputString[MAXN][MAXM]);

int main()
{

    // n = No. of strings entered.
    // m = Exact length of each entered string .

    int n, m;

    scanf("%d %d", &n, &m);

    char inputString[MAXN][MAXM];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", inputString[i]);
    }

    solve(n, m, inputString);

    return 0;
}

// Helper Funtion to reverse a string (Pass by Reference)
void reverseString(char str[], int len)
{
    for (int l = 0, r = len - 1; l < r; l++, r--)
    {
        char temp = str[l];
        str[l] = str[r];
        str[r] = temp;
    }
}

// check if two strings are reverse of each other
int isReverse(const char s1[], const char s2[], int m)
{
    for (int i = 0; i < m; i++)
    {
        if (s1[i] != s2[m - 1 - i])
            return 0;
    }
    return 1;
}

// check if string is a pallindrome
int isPallindrome(const char s[], int m)
{
    for (int l = 0, r = m - 1; l < r; l++, r--)
    {
        if (s[l] != s[r])
            return 0;
    }
    return 1;
}

// Function to solve the problem
void solve(int n, int m, char inputString[MAXN][MAXM])
{
    int used[MAXN] = {0};
    int leftIndices[MAXN], leftCount = 0;
    int middleIndex = -1;

    // 1.Identify reverse pairs and middle pallindrome
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        // Try to find matching reverse pair for the left side
        int foundPair = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (!used[j] && isReverse(inputString[i], inputString[j], m))
            {
                leftIndices[leftCount++] = i;
                used[i] = used[j] = 1;
                foundPair = 1;
                break;
            }
        }

        // If no reverse pair, check if it's a candidate for the middle
        if (!foundPair && middleIndex == -1 && isPallindrome(inputString[i], m))
        {
            middleIndex = i;
            used[i] = 1;
        }
    }

    // 2.Output the result directly

    int totalLen = (leftCount * 2 * m) + (middleIndex != -1 ? m : 0);
    printf("%d\n", totalLen);

    for (int i = 0; i < leftCount; i++)
        printf("%s", inputString[leftIndices[i]]);

    if (middleIndex != -1)
        printf("%s", inputString[middleIndex]);

    for (int i = leftCount - 1; i >= 0; i--)
    {
        char temp[MAXM];
        strcpy(temp, inputString[leftIndices[i]]);
        reverseString(temp, m);
        printf("%s", temp);
    }

    printf("\n");
}