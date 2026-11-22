#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n, i;
    int totalCharacters=0;
    int longestIndex=0;

    char **feedback=NULL;

    printf("Enter number of feedback entries: ");
    scanf("%d",&n);
    feedback=(char **)malloc(n * sizeof(char *));

    if(feedback==NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        feedback=(char **)realloc(feedback,(i+1)* sizeof(char *));
		if(feedback==NULL)
        {
            printf("Memory allocation failed!");
            return 1;
        }
		feedback[i] = (char *)malloc(200 * sizeof(char));
		if(feedback[i]==NULL)
        {
            printf("Memory allocation failed!");
            return 1;
        }
		printf("Enter feedback %d: ", i + 1);
        getchar();
        fgets(feedback[i], 200, stdin);
		feedback[i][strcspn(feedback[i],"\n")] = '\0';

        totalCharacters+=strlen(feedback[i]);
    }
    for(i=1;i<n;i++)
    {
        if(strlen(feedback[i])>strlen(feedback[longestIndex]))
        {
            longestIndex = i;
        }
    }
    printf("\nAll Feedback Entries:\n");

    for(i=0;i<n;i++)
    {
        printf("%s\n",feedback[i]);
    }
	printf("\nTotal Characters = %d", totalCharacters);
	printf("\nLongest Feedback = %s", feedback[longestIndex]);
    for (i=0;i<n;i++)
    {
        free(feedback[i]);
    }
    free(feedback);
}
