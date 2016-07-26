// Request for Proposal *AC*

#include <iostream>
#include <cstdio>
#include <string>
#include <climits>

using namespace std;

struct Prop {
	string name;
	double price;
	int reqsMet;
	double comp;
};

int main() {
	string buf;
	int numReq, numProp;
	bool first = true;
	for(int numRPF = 1; true; numRPF++) {
		cin >> numReq >> numProp;
		getchar();
		if(numReq == 0 && numProp == 0)
			return 0;

		for(int i = 0; i < numReq; i++)
			getline(cin, buf);

		Prop curProp, maxProp;
		maxProp.price = INT_MAX, maxProp.comp = -1;
		for(int i = 0; i < numProp; i++) {
			getline(cin, curProp.name);
			cin >> curProp.price >> curProp.reqsMet;
			getchar();
			curProp.comp = (double)curProp.reqsMet / numReq;

			for(int j = 0; j < curProp.reqsMet; j++)
				getline(cin, buf);

			if(curProp.comp > maxProp.comp)
				maxProp = curProp;
			else if((curProp.comp == maxProp.comp) && (curProp.price < maxProp.price))
				maxProp = curProp;
		}

		if(!first)
			cout << endl;
		else
			first = false;
		cout << "RFP #" << numRPF << endl
			 << maxProp.name << endl;
	}
}
