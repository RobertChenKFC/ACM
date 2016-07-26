// Factorial Frequencies *AC*

#include <stdio.h>

const int BIG_NUM_SIZE = 800;

int main() {
	int num[BIG_NUM_SIZE];
	int frequencies[10];
	int input;
	while(true) {
		// get input
		scanf("%d", &input);
		if(input == 0)
			return 0;
		else {
			// big num setup
			for(int i = 0; i < BIG_NUM_SIZE; ++i) {
				num[i] = i == 0 ? 1 : 0;
				if(i < 10)
					frequencies[i] = 0;
			}

			// outer loop: multiplication, inner loop: big num operations
			for(int i = 2; i <= input; ++i) {
				int carry = 0;
				for(int j = 0; j < BIG_NUM_SIZE; ++j) {
					// multiplication
					num[j] *= i;
					num[j] += carry;
					
					// calculate carry
					carry = 0;
					while(num[j] > 10) {
						carry = num[j] / 10;
						num[j] %= 10;
					}
				}
			}

			// calculate frequencies
			bool changed = false;
			for(int i = BIG_NUM_SIZE - 1; i >= 0; --i) {
				if(num[i] != 0)
					changed = true;
				if(changed)
					frequencies[num[i]]++;
			}
			
			// output
			printf("%d! --\n", input);
			printf("    (0)  %3d    (1)  %3d    (2)  %3d    (3)  %3d   (4)  %3d\n", frequencies[0], frequencies[1], frequencies[2], frequencies[3], frequencies[4]);
			printf("    (5)  %3d    (6)  %3d    (7)  %3d    (8)  %3d   (9)  %3d\n", frequencies[5], frequencies[6], frequencies[7], frequencies[8], frequencies[9]);
		}	
	}
}
