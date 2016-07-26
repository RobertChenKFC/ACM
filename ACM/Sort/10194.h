// Football (aka Soccer) *RE*

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Team {
	Team() :
		name(),
		ptsEarned(0),
		gamesPlayed(0),
		wins(0), ties(0), losses(0),
		goalDiff(0),
		goalsScored(0), goalsAgainst(0)
	{}

	void calc() {
		ptsEarned = 3 * wins + ties;
		goalDiff = goalsScored - goalsAgainst;
	}

	string name;
	int ptsEarned;
	int gamesPlayed;
	int wins, ties, losses;
	int goalDiff;
	int goalsScored, goalsAgainst;
};

#define TO_TEAM(X) (*((Team*)X))
int teamCmp(const void* a, const void* b) {
	// 1. Most points earned
	if(TO_TEAM(a).ptsEarned < TO_TEAM(b).ptsEarned)
		return 1;
	if(TO_TEAM(a).ptsEarned > TO_TEAM(b).ptsEarned)
		return -1;

	// 2. Most wins
	if(TO_TEAM(a).wins < TO_TEAM(b).wins)
		return 1;
	if(TO_TEAM(a).wins > TO_TEAM(b).wins)
		return -1;

	// 3. Most goal difference
	if(TO_TEAM(a).goalDiff < TO_TEAM(b).goalDiff)
		return 1;
	if(TO_TEAM(a).goalDiff > TO_TEAM(b).goalDiff)
		return -1;

	// 4. Most goals scored
	if(TO_TEAM(a).goalsScored < TO_TEAM(b).goalsScored)
		return 1;
	if(TO_TEAM(a).goalsScored > TO_TEAM(b).goalsScored)
		return -1;

	// 5. Less games played
	if(TO_TEAM(a).gamesPlayed > TO_TEAM(b).gamesPlayed)
		return 1;
	if(TO_TEAM(a).gamesPlayed < TO_TEAM(b).gamesPlayed)
		return -1;

	// 6. Lexicographic order
	return TO_TEAM(a).name.compare(TO_TEAM(b).name);
}

int main() {
	// see if new line is needed
	bool first = true;

	// get number of cases
	int numCases;
	cin >> numCases;
	cin.ignore();
	while(numCases--) {
		// gets the name of the tournament
		string name;
		getline(cin, name);

		// get the team names and set index table
		int numTeams;
		cin >> numTeams;
		cin.ignore();
		Team* teams = new Team[numTeams];
		unordered_map<string, int> table;
		for(int i = 0; i < numTeams; i++) {
			getline(cin, teams[i].name);
			table[teams[i].name] = i;
		}

		// get game informations
		int numGames;
		cin >> numGames;
		cin.ignore();
		while(numGames--) {
			// get game into string
			string game;
			getline(cin, game);

			// calculate where the score team names start and end
			int firstTeamEnd = 0, versus, secondTeamStart;
			while(game[firstTeamEnd] != '#') firstTeamEnd++;
			versus = (firstTeamEnd--) + 1;
			while(game[versus] != '@') versus++;
			secondTeamStart = versus + 1;
			while(game[secondTeamStart] != '#') secondTeamStart++;
			secondTeamStart++;

			// get the team scores
			int teamAScore, teamBScore;
			string score = game.substr(firstTeamEnd + 2, versus - (firstTeamEnd + 2));
			stringstream ss;
			ss << score;
			ss >> teamAScore;
			ss.clear();
			score = game.substr(versus + 1, (secondTeamStart - 1) - versus);
			ss << score;
			ss >> teamBScore;

			// set team A parameters
			string teamName = game.substr(0, firstTeamEnd + 1);
			int teamIndex = table[teamName];
			teams[teamIndex].gamesPlayed++;
			if(teamAScore > teamBScore)
				teams[teamIndex].wins++;
			else if(teamAScore < teamBScore)
				teams[teamIndex].losses++;
			else
				teams[teamIndex].ties++;
			teams[teamIndex].goalsScored += teamAScore;
			teams[teamIndex].goalsAgainst += teamBScore;

			// set team B parameters
			teamName = game.substr(secondTeamStart, game.length() - secondTeamStart);
			teamIndex = table[teamName];
			teams[teamIndex].gamesPlayed++;
			if(teamAScore < teamBScore)
				teams[teamIndex].wins++;
			else if(teamAScore > teamBScore)
				teams[teamIndex].losses++;
			else
				teams[teamIndex].ties++;
			teams[teamIndex].goalsScored += teamBScore;
			teams[teamIndex].goalsAgainst += teamAScore;
		}

		// calculate other parameters
		for(int i = 0; i < numTeams; i++)
			teams[i].calc();

		// sort
		qsort(teams, numTeams, sizeof(Team), teamCmp);

		// output teams
		if(!first)
			cout << endl;
		else
			first = false;
		cout << name << endl;
		for(int i = 0; i < numTeams; i++) {
			cout << i + 1 << ") " << teams[i].name << " " << teams[i].ptsEarned << "p, "
				 << teams[i].gamesPlayed << "g (" << teams[i].wins << "-" << teams[i].ties << "-" << teams[i].losses
				 << "), " << teams[i].goalDiff << "gd (" << teams[i].goalsScored << "-" << teams[i].goalsAgainst << ")" << endl;
		}

		delete[] teams;


	}
}
