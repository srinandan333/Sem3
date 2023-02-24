#include<stdio.h>
#include"header.h"
void read(ipl s[],int n)
{
for(int i=0;i<n;i++)
{
	printf("\nEnter the name of player %d: ",i+1);
	scanf("%s",s[i].name);
	printf("\nEnter the team name of player %d: ",i+1);
	scanf("%s",s[i].team);
	printf("\nEnter the number of matches played by player %d :",i+1);
	scanf("%d",&s[i].matches);
	for(int k=0;k<20;k++)
		s[i].runs[k]=0;
	for(int j=0;j<s[i].matches;j++)
	{
		printf("\nEnter runs scored by player %d in match %d: ",i+1,j+1);
		scanf("%d",&s[i].runs[j]);
	}
} 
}
void display(ipl s[],int n)
{
for(int i=0;i<n;i++)
{
	printf("\nthe name of player %d: %s ",i+1,s[i].name);
	printf("\nthe team name of player %d:  %s",i+1,s[i].team);
	printf("\nthe number of matches played by player %d : %d",i+1,s[i].matches);
	for(int j=0;j<s[i].matches+1;j++)
	{
		printf("\nruns scored by player %d in match %d: %d",i+1,j+1,s[i].runs[j]);
	}
} 
}
void max_runs(ipl s[],int n)
{
int m,max=0;
printf("\nEnter the match number to find player with maximum runs: ");
fflush(stdin);
scanf("%d",&m);
for(int i=0;i<n;i++)
{
	if(s[i].matches>=m)
	{
		if(s[i].runs[s[i].matches-1]>s[max].runs[s[max].matches]-1)
			max=i;
	}
}
printf("\nthe name of player who scored max runs in match  %d: %s ",m,s[max].name);
printf("\nthe team to which the player belongs is :  %s",s[max].team);
printf("\nthe number of matches played by player: %d",s[max].matches);
printf("\nruns scored by player in match %d: %d",m,s[max].runs[s[max].matches-1]);
}
void matches(ipl s[],int n)
{
for(int i=0;i<n;i++)
	printf("\nMatches played by player %d : %d",i+1,s[i].matches);
}
