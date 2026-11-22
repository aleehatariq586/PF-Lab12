#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i;
    int total=0;
    int highestIndex=0;
    float average;
	printf("Enter number of movie categories: ");
    scanf("%d",&n);
    int *ratings=(int *)malloc(n*sizeof(int));
	if(ratings==NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        printf("Enter ratings for category %d: ",i);
        scanf("%d",&ratings[i]);
    }
    for(i=0;i<n;i++)
    {
        total=total+ratings[i];
    }
    for(i=1;i<n;i++)
    {
        if(ratings[i]>ratings[highestIndex])
        {
            highestIndex=i;
        }
    }
	average=(float)total/n;
    printf("\nTotal Ratings=%d",total);
    printf("\nAverage Ratings=%.2f",average);
    printf("\nCategory with Highest Ratings=%d",highestIndex);
    int category, newRating;

    printf("\n\nEnter category index to update: ");
    scanf("%d",&category);

    if(category>=0 && category<n)
    {
        printf("Enter new rating count: ");
        scanf("%d",&newRating);

        ratings[category]=newRating;
        printf("\nUpdated Ratings:\n");
		total=0;
        highestIndex=0;

        for(i=0;i<n;i++)
        {
            printf("Category %d=%d\n",i,ratings[i]);
			total=total+ratings[i];
			if (ratings[i] > ratings[highestIndex])
            {
                highestIndex=i;
            }
        }
		average=(float)total/n;
		printf("\nUpdated Total Ratings=%d",total);
        printf("\nUpdated Average Ratings=%.2f",average);
        printf("\nUpdated Highest Category=%d",highestIndex);
    }
    else
    {
        printf("Invalid category index!");
    }
    free(ratings);

    return 0;
}

