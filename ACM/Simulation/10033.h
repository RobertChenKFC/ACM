#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

const int NUM_REG = 10, NUM_RAM = 1000;

int main() {
	int numCases;
	string buf;
	stringstream ss;
	getline(cin, buf);
	ss << buf;
	ss >> numCases;
	ss.clear();
	buf.clear();

	// clear blank line
	getline(cin, buf);
	buf.clear();

	int reg[NUM_REG], ram[NUM_RAM];
	for(int caseNum = 0; caseNum < numCases; caseNum++) {
		memset(reg, 0, sizeof(int) * NUM_REG);
		memset(ram, 0, sizeof(int) * NUM_RAM);

		int numIns = 0;
		for(int i = 0; true; i++) {
			if(!getline(cin, buf)) {
				goto NEXT;
			}
			if(buf[0] == '\n')
				break;
			ss << buf;
			ss >> ram[i];
			buf.clear();
			ss.clear();
		}

		for(int i = 0; i < NUM_RAM; i++) {
			int a = ram[i] / 10 % 10, b = ram[i] % 10;
			numIns++;
			switch(ram[i] / 100) {
			case 1:
				goto DONE;
			case 2:
				reg[a] = b;
				break;
			case 3:
				reg[a] += b;
				break;
			case 4:
				reg[a] *= b;
				break;
			case 5:
				reg[a] = reg[b];
				break;
			case 6:
				reg[a] += reg[b];
				break;
			case 7:
				reg[a] *= reg[b];
				break;
			case 8:
				reg[a] = ram[reg[b]];
				break;
			case 9:
				ram[reg[b]] = reg[a];
				break;
			case 0:
				if(reg[b] != 0)
					i = reg[a];
				break;
			}
		}


	DONE:
		if(caseNum != 0)
			cout << endl;
		cout << numIns << endl;

	NEXT:
		continue;
	}
}
