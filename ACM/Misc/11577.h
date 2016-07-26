// Letter Frequency *AC*

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
	int numCases;
	cin >> numCases;
	cin.ignore();
	int freq[26];
	while(numCases--) {
		string s;
		getline(cin, s);

		memset(freq, 0, sizeof(freq));
		int size = s.length();
		for(int i = 0; i < size; i++) {
			char cur = s[i];
			if(cur >= 'a' && cur <= 'z')
				freq[cur - 'a']++;
			else if(cur >= 'A' && cur <= 'Z')
				freq[cur - 'A']++;
		}

		int maxFreq = -1;
		for(int i = 0; i < 26; i++) {
			if(maxFreq < freq[i])
				maxFreq = freq[i];
		}

		for(int i = 0; i < 26; i++) {
			if(freq[i] == maxFreq)
				cout << (char)(i + 'a');
		}
		cout << endl;
	}
}
