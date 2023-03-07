#include <stdio.h>
#include <stdlib.h>

// 判断闰年
int Adjust(date x) {
	int year = x->year;
	if (year % 400 == 0 || (yaer % 4 == 0 && year % 100 != 0))
		return 1;
	else return 0;
}

int main() {
	typedef struct {
		int year;
		int month;
		int day;
	}date;
	
    date x;
    scanf("%d-%d-%d", &x->year, &x->month, &x->day);
    // 计算天数
    switch ( x->month)
	{
            case 1:sum = 0;
                break;
            case 2:sum = 31;
                break;
            case 3:sum = 59;
                break;
            case 4:sum = 90;
                break;
            case 5:sum = 120;
                break;
            case 6:sum = 151;
                break;
            case 7:sum = 181;
                break;
            case 8:sum = 212;
                break;
            case 9:sum = 243;
                break;
            case 10:sum = 273;
                break;
            case 11:sum = 304;
                break;
            case 12:sum = 334;
                break;
            default:
                break;
	}
    if (Adjust(x)) sum++;

    printf("in total: %d", sum);
    return 0;
}