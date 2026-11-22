#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i,total=0;
	int lowestIndex=0;
	float average;
	printf("Enter number of book categories: ");
	scanf("%d",&n);
	int *stock=(int *)malloc(n* sizeof(int));
	if(stock==NULL){
		printf("Memory Allocation Failed!");
		return 1;
	}
	for(i=0;i<n;i++){
		printf("Enter stock for category %d: ",i);
		scanf("%d",&stock[i]);
	}
	for(i=0;i<n;i++){
		total=total+stock[i];
	}
	for(i=1;i<n;i++){
		if(stock[i]<stock[lowestIndex]){
			lowestIndex=i;
		}
	}
	average=(float)total/n;
	printf("\nTotal stock=%d\n",total);
	printf("Average Stock=%.2f\n",average);
	printf("Category of Lowest stock=%d\n",lowestIndex);
	int category,newStock;
	printf("Enter category to update: ");
	scanf("%d",&category);
	if(category>=0 && category<n){
		printf("Enter new stock quantity: ");
        scanf("%d",&newStock);
        stock[category]=newStock;
        printf("\nUpdated Stock\n");
        for(i=0;i<n;i++)
        {
            printf("Category %d=%d\n",i,stock[i]);
        }
    }
    else
    {
        printf("Invalid category index!");
    }
    free(stock);
	}
