// What's Cryptanalysis? *AC*

#include <stdio.h>
#include <string.h>

struct Alphabet {
	int frequency;
	char alphabet;
};

const int SIZE = 1000;
int main() {
	int numOfSentences;
	scanf("%d\n", &numOfSentences);

	Alphabet alphabets[26];
	for(char i = 'A'; i <= 'Z'; ++i)
		alphabets[i - 'A'].alphabet = i, alphabets[i - 'A'].frequency = 0;

	for(int i = 0; i < numOfSentences; ++i) {
		char sentence[SIZE] = {'0'};

		fgets(sentence, SIZE, stdin);

		int size = strlen(sentence) - 1;

		for(int j = 0; j < size; ++j) {
			if(sentence[j] >= 'A' && sentence[j] <= 'Z')
				alphabets[sentence[j] - 'A'].frequency++;
			else if(sentence[j] >= 'a' && sentence[j] <= 'z')
				alphabets[sentence[j] - 'a'].frequency++;
		}
	}

	for(int i = 0; i < 26; ++i) {
		int maxPos = i;
		for(int j = i; j < 26; ++j) {
			if(alphabets[j].frequency > alphabets[maxPos].frequency)
				maxPos = j;
			else if((alphabets[j].frequency == alphabets[maxPos].frequency) &&
					(alphabets[j].alphabet < alphabets[maxPos].alphabet))
				maxPos = j;
		}
		Alphabet t = alphabets[i];
		alphabets[i] = alphabets[maxPos], alphabets[maxPos] = t;
	}

	for(int i = 0; i < 26; ++i) {
		if(alphabets[i].frequency != 0)
			printf("%c %d\n", alphabets[i].alphabet, alphabets[i].frequency);
	}
}
