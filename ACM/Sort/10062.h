// Tell me the frequencies! *AC*

#include <stdio.h>
#include <string.h>

struct Character {
	char character;
	int frequency;
};

#define SIZE 1000
#define NUM_OF_ASCII 32 + 128
int main() {
	char string[SIZE] = {0};
	Character frequencies[NUM_OF_ASCII];
	bool first = true;
	while(gets(string) != NULL) {
		if(!first)
			printf("\n");

		for(int i = 0; i < NUM_OF_ASCII; ++i)
			frequencies[i].character = i, frequencies[i].frequency = 0;

		int size = strlen(string);
		for(int i = 0; i < size; ++i)
			frequencies[(int)string[i]].frequency++;

		for(int i = 0; i < NUM_OF_ASCII - 1; ++i) {
			for(int j = 0; j + i < NUM_OF_ASCII - 1; ++j) {
				if(frequencies[j].character < frequencies[j + 1].character) {
					Character t = frequencies[j];
					frequencies[j] = frequencies[j + 1], frequencies[j + 1] = t;
				}
				if(frequencies[j].frequency > frequencies[j + 1].frequency) {
					Character t = frequencies[j];
					frequencies[j] = frequencies[j + 1], frequencies[j + 1] = t;
				}
			}
		}

		for(int i = 0; i < NUM_OF_ASCII; ++i) {
			if(frequencies[i].frequency != 0 && frequencies[i].character >= 32 && frequencies[i].character <= 128 )
				printf("%d %d\n", frequencies[i].character, frequencies[i].frequency);
		}

		first = false;
	}
}
