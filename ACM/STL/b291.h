// *AC*

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n;
	string animal, place;
	int num;
	map< string, map<string, int> > places;
	vector<string> placeOrder;
	set<string> hasAnimal;
	vector<string> animalOrder;

	cin >> n;
	while(n--) {
		cin >> animal >> num >> place;
		if(places.find(place) == places.end()) {
			places[place] = map<string, int>();
			placeOrder.push_back(place);
		}
		if(places[place].find(animal) == places[place].end()) {
			places[place][animal] = num;
			if(hasAnimal.find(animal) == hasAnimal.end()) {
				hasAnimal.insert(animal);
				animalOrder.push_back(animal);
			}
		}
		else places[place][animal] += num;
	}

	for(const auto &curPlaceName : placeOrder) {
		cout << curPlaceName << " : ";
		auto &curPlace = places[curPlaceName];
		bool first = true;
		for(const auto &curAnimalName : animalOrder) {
			if(curPlace.find(curAnimalName) != curPlace.end()) {
				if(first) first = false;
				else cout << ", ";
				cout << curAnimalName;
				cout << " " << curPlace[curAnimalName];
			}
		}
		cout << endl;
	}
}
