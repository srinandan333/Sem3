typedef struct ipl_players
{
	char name[20];
	char team[10];
	int matches;
	int runs[20];
}ipl;
void read(ipl s[],int n);
void max_runs(ipl s[],int n);
void matches(ipl s[],int n);

