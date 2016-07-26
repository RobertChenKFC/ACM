// Leap Year or Not Leap Year and... *AC*

#include <stdio.h>
#include <string.h>

const int SIZE = 1000;
#define CtoN(x) (int)(x - '0')
#define ABS(x) x > 0 ? x : -x

int main() {
	char year[SIZE];

	bool first = true;
	while(scanf("%s", year) != EOF) {
		if(!first)
			printf("\n");
		else
			first = false;


		int actualSize = strlen(year);
		bool isLeapYear = false;
		bool dB4 = (CtoN(year[actualSize - 2]) * 10 + CtoN(year[actualSize - 1])) % 4 == 0,
			dB100 = CtoN(year[actualSize - 2]) == 0 && CtoN(year[actualSize - 1]) == 0,
			dB400 = ((CtoN(year[actualSize - 4]) * 10 + CtoN(year[actualSize - 3])) % 4 == 0) && dB100;

		int sum = 0, oddSum = 0, evenSum = 0;
		for (int i = 0; i < actualSize; ++i) {
			sum += CtoN(year[i]);
			if(i % 2 == 0)
				evenSum += CtoN(year[i]);
			else
				oddSum += CtoN(year[i]);
		}

		bool dB3 = (sum % 3) == 0,
			dB5 = (CtoN(year[actualSize - 1]) == 5) || (CtoN(year[actualSize - 1]) == 0),
			dB11 = (oddSum - evenSum) % 11 == 0;
		bool dB15 = dB3 && dB5, dB55 = dB5 && dB11;

		bool ordinary = true;
		if((dB4 && !dB100) || dB400) {
			printf("This is leap year.\n");
			isLeapYear = true;
			ordinary = false;
		}
		if(dB15) {
			printf("This is huluculu festival year.\n");
			ordinary = false;
		}
		if(dB55 && isLeapYear) {
			printf("This is bulukulu festival year.\n");
			ordinary = false;
		}
		if(ordinary)
			printf("This is an ordinary year.\n");
	}
 }
