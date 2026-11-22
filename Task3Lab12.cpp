#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int containsDigit(char *str){
	int i=0;
	while(str[i]!='\0'){
		if(str[i]>='0' && str[i]<='9'){
			return 1;
		}
		i++;
	}	
}
int main(){
	int n,i;
	printf("Enter number of usernames: ");
	scanf("%d",&n);
	char **username=(char **)malloc(n*sizeof(char *));
	if(username==NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    for(i=0;i<n;i++)
    {
        username[i]=(char *)malloc(100*sizeof(char));

        if(username[i]==NULL)
        {
            printf("Memory allocation failed!");
            return 1;
        }
		printf("Enter username %d: ",i+1);
        scanf("%99s",username[i]);
    }
    printf("\nValid Usernames:\n");

    for(i=0;i<n;i++)
    {
        if (containsDigit(username[i])==0)
        {
            printf("%s\n", username[i]);
        }
    }
    for(i=0;i<n;i++)
    {
        free(username[i]);
    }
	free(username);
	return 0;
}
