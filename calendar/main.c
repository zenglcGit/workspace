#include <stdio.h>
#include <time.h>
struct tm * getCurrentTime()
{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    return timeinfo;
}

int getCurrentYear()
{
    struct tm * timeinfo = getCurrentTime();
    return timeinfo->tm_year + 1900;
}

int getCurrentMonth()
{
    struct tm * timeinfo = getCurrentTime();
    return timeinfo->tm_mon+1;
}

int getYearDays(int y)
{
	if ((y%4==0) && (y%100!=0) || y%400==0)
		return 366;
	else
		return 365;
}

int getWeekOfCurrentMonthFirstDay(int year, int month)
{
    int monDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(getYearDays(year) == 366)
		monDays[1] = 29;

    int days = 1;
    int i;
	for(i=0; i<(month-1); i++)
        days += monDays[i];

    int week = (year-1+(year-1)/4-(year-1)/100+(year-1)/400+days)%7;

    return week;
}

int getCurrentMonthDays(int year, int month)
{
    int monDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(getYearDays(year) == 366)
		monDays[1] = 29;

	return monDays[month-1];
}

int main()
{
        int currentYear = getCurrentYear();
        int currentMonth = getCurrentMonth();
        printf("\n%d年%d月日历如下：\n\n", currentYear, currentMonth);

        printf("       %d月          \n",currentMonth);
        printf("  7  1  2  3  4  5  6\n");
        printf("=====================\n");
        int j, begin=1;
        int week = getWeekOfCurrentMonthFirstDay(currentYear, currentMonth);
        for(j=0; j < week; j++)
            printf("   ");
        while(begin <= getCurrentMonthDays(currentYear, currentMonth))
        {
            printf("%3d", begin);
            begin++;
            week=(week+1)%7;
            if(week%7==0)
                printf("\n");
        }
        printf("\n\n");
}


