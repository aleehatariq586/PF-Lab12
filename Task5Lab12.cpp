#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getCategory(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return 1; 
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        return 2; 
    }
    else if (ch >= '0' && ch <= '9')
    {
        return 3;  
    }
    else
    {
        return 4;
    }
}

int main()
{
    int n, i, j;
    int match, maxIndex = 0;
    float similarity, maxSimilarity = -1;

    char *pattern;

    printf("Enter number of participants: ");
    scanf("%d", &n);
    pattern = (char *)malloc(100 * sizeof(char));

    if (pattern == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    printf("Enter password pattern: ");
    scanf("%99s", pattern);
    char **password = (char **)malloc(n * sizeof(char *));

    if (password == NULL)
    {
        free(pattern);
        printf("Memory allocation failed!");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        password[i] = (char *)malloc(100 * sizeof(char));

        if (password[i] == NULL)
        {
            printf("Memory allocation failed!");
            return 1;
        }

        printf("Enter password for participant %d: ", i + 1);
        scanf("%99s", password[i]);
    }
    printf("\nPassword Similarity Results:\n");

    for (i = 0; i < n; i++)
    {
        match = 0;

        int patternLength = strlen(pattern);
        int passwordLength = strlen(password[i]);

        int length = patternLength;

        if (passwordLength < length)
        {
            length = passwordLength;
        }

        for (j = 0; j < length; j++)
        {
            if (getCategory(pattern[j]) == getCategory(password[i][j]))
            {
                match++;
            }
        }

        similarity = (float)match / patternLength * 100;

        printf("\nPassword: %s", password[i]);
        printf("\nSimilarity: %.2f%%\n", similarity);

        if (similarity > maxSimilarity)
        {
            maxSimilarity = similarity;
            maxIndex = i;
        }
    }
    printf("\nPassword with Highest Similarity: %s", password[maxIndex]);
    printf("\nHighest Similarity: %.2f%%", maxSimilarity);
    for (i = 0; i < n; i++)
    {
        free(password[i]);
    }
    free(password);
    free(pattern);

    return 0;
}

