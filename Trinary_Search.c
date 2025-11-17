#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int low=0,m1,m2,temp,num,flag=1;
	printf("Choose the number to search: ");
	scanf("%d",&num);
	printf("Choose the arrey size: ");
	scanf("%d",&n);
	int hig=n-1;
	printf("Choose arrey elements(%d): ",n);
	int *ptr;
	ptr=(int *)calloc(n,sizeof(int));

	//arrey
	for(int i=0; i<n; i++)
		scanf("%d",&ptr[i]);

	//sorting
	for(int i=0; i<n-1; i++)
	{
		for(int j=0; j<n-1-i; j++)
		{
			if(ptr[i]>ptr[i+1])
			{
				temp=ptr[i];
				ptr[i]=ptr[i+1];
				ptr[i+1]=temp;
			}
		}
	}

	while(low<hig)
	{
		m1=((hig-low)/3)+low;
		m2=hig-((hig-low)/3);
		if(ptr[m1]==num || ptr[m2]==num)
		{
			printf("number found");
			flag=0;
			break;
		}
		else
		{
			if(num < ptr[m1])
				hig=m1-1;

			else if(num > ptr[m2])
				low=m1;

			else
				low=m1+1;
			hig=m2-1;
		}

	}
	if(flag==1)
		printf("no number found");
	return 0;
}
