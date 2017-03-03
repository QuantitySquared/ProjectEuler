#include <stdio.h>

int main(){
	typedef enum Month{
		January,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	} Month;

	typedef enum Days {
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday
	} Days;

	int i;
	int day = 0;
	int year = 1900;
	Month month = January;
	Days dayList[7] = {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};
	int daysInMonth;
	int firstSundays = 0;

	for(year=1900; year<2001; year++){
		for(month= January; month<=December; month++){
			if(month == January || month == March || month == May || month == July || month == August || month == October || month == December)
				daysInMonth = 31;
			else if(month == September || month == April || month == June || month == November)
				daysInMonth = 30;
			else{
				if(year%400==0 && year%100==0)
					daysInMonth = 29;
				else if(year%4==0)
					daysInMonth = 29;
				else
					daysInMonth = 28;
			}

			for(i=1; i<=daysInMonth; i++){
				if(i==1 && dayList[day] == Sunday && year>1900)
					firstSundays++;

				day++;
				if(day>6)
					day = 0;
			}
		}
		
	}

	printf("%d\n", firstSundays);

}
