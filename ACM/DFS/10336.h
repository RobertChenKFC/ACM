// Rank the Languages *AC*

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

class Lang {
public:
	Lang(char lang, int num) :
	lang(lang), num(num) {}

	bool operator> (Lang rhs) {
		if(num > rhs.num)
			return true;
		if(num == rhs.num && lang < rhs.lang)
			return true;
		return false;
	}

	bool operator== (Lang rhs) {
		return (lang == rhs.lang) && (num == rhs.num);
	}

	bool operator>= (Lang rhs) {
		return (*this == rhs) || (*this > rhs);
	}

	bool operator< (Lang rhs) {
		return !(*this >= rhs);
	}

	bool operator<= (Lang rhs) {
		return !(*this > rhs);
	}

	char lang;
	int num;
};

void LanguageSearchBase(const vector< vector<char> >& world, vector< vector<bool> >& marked,
						int h, int w, int curI, int curJ) {
	char curLang = world[curI][curJ];
	// up
	if(curI > 0) {
		int newI = curI - 1, newJ = curJ;
		if(!marked[newI][newJ] && world[newI][newJ] == curLang) {
			marked[newI][newJ] = true;
			LanguageSearchBase(world, marked, h, w, newI, newJ);
		}
	}
	// down
	if(curI < h - 1) {
		int newI = curI + 1, newJ = curJ;
		if(!marked[newI][newJ] && world[newI][newJ] == curLang) {
			marked[newI][newJ] = true;
			LanguageSearchBase(world, marked, h, w, newI, newJ);
		}
	}
	// left
	if(curJ > 0) {
		int newI = curI, newJ = curJ - 1;
		if(!marked[newI][newJ] && world[newI][newJ] == curLang) {
			marked[newI][newJ] = true;
			LanguageSearchBase(world, marked, h, w, newI, newJ);
		}
	}
	// right
	if(curJ < w - 1) {
		int newI = curI, newJ = curJ + 1;
		if(!marked[newI][newJ] && world[newI][newJ] == curLang) {
			marked[newI][newJ] = true;
			LanguageSearchBase(world, marked, h, w, newI, newJ);
		}
	}
}

void LanguageSearch(const vector< vector<char> >& world, int h, int w) {
	vector< vector<bool> > marked(h, vector<bool>(w, false));
	vector<Lang> langs(26, Lang(0, 0));
	for(int i = 0; i < 26; i++)
		langs[i] = Lang(i + 'a', 0);
	vector<bool> calced(26, false);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(!marked[i][j]) {
				marked[i][j] = true;
				char curLang = world[i][j];
				int curLangIndex = curLang - 'a';
				langs[curLangIndex].num++;
				LanguageSearchBase(world, marked, h, w, i, j);
				calced[curLangIndex] = true;
			}
		}
	}

	int numLangs = langs.size();
	for(int i = 0; i < numLangs; i++) {
		for(int j = 0; j + i + 1 < numLangs; j++) {
			if(langs[j] < langs[j + 1]) {
				Lang t = langs[j];
				langs[j] = langs[j + 1], langs[j + 1] = t;
			}
		}
	}

	for(int i = 0; i < numLangs; i++) {
		if(langs[i].num == 0)
			break;
		cout << langs[i].lang << ": " << langs[i].num << endl;
	}
}

int main() {
	int numWorlds;
	cin >> numWorlds;
	for(int curWorld = 1; curWorld <= numWorlds; curWorld++) {
		int h, w;
		cin >> h >> w;

		vector< vector<char> > world(h, vector<char>(w, 0));
		for(int i = 0; i < h; i++) {
			for(int j = 0; j < w; j++)
				cin >> world[i][j];
		}

		cout << "World #" << curWorld << endl;
		LanguageSearch(world, h, w);
	}
}
