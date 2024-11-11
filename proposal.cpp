// Ethan Dilk | COMSC 210 | Lab 29 Proposal
// include necessary headers related to data structures
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <cstdlib>  
#include <ctime>
using namespace std;

// Definition for function to simulate a game for a team 
    // parameters: map of team and list to update stats
    // creates a variable to randomly assign how the team is going to play
    // randomly create stats for points, rebounds, assists - add to the lists
void simulateGame(map<string, array<list<int>, 3> > &teamStats, const string &teamName) {
    // Add random numbers to the team's lists in the map
    teamStats[teamName][0].push_back(rand() % 40 + 1);
    teamStats[teamName][1].push_back(rand() % 20 + 1);
    teamStats[teamName][2].push_back(rand() % 10 + 1);

}

void check_stats(map<string, array<list<int>, 3> > &teamStats, const string &teamName) {
    for (auto & pair : teamStats) {
        // call the function to input stats for one game for the team
        simulateGame(teamStats, pair.first);
        // Access the last element of each list for points, rebounds, and assists
        int lastPoints = teamStats.at(teamName)[0].back();
        int lastRebounds = teamStats.at(teamName)[1].back();
        int lastAssists = teamStats.at(teamName)[2].back();

        cout << "Team Added: " << teamName << endl;
        cout << "Points: " << lastPoints << endl;
        cout << "Rebounds: " << lastRebounds << endl;
        cout << "Assists: " << lastAssists << endl;
    }
}

// Define main function
int main() {
    // Initialize a map used to store team information - each team will have array of lists for points, rebounds, assists
    map<string, array<list<int>, 3>> teamStats;
    // Open external file to read data on first 5 games of the season 
    ifstream file("team_data.txt");
        // print error and exit if file doesn't open
    if (!file) {
        cout << "Error opening!" << endl;
        return 1;
    }

    
    // read data from external file and use to populate the map
        // Store the initial team names into the map
        // for each line - get the stats from the file
            // put the stats into the proper list for the team
    
    while (file) {

        string teamName;
        int points, rebounds, assists;

        file >> teamName >> points >> rebounds >> assists;

        bool found = false;

        if (teamStats.find(teamName) != teamStats.end()) {

        }
        else {
            // insert team name
            teamStats[teamName] = array<list<int>, 3>();
        
            // for initial get the data into the map
            teamStats[teamName][0].push_back(points);
            teamStats[teamName][1].push_back(rebounds);
            teamStats[teamName][2].push_back(assists);
        }
    }
    // close file
    file.close();

    // Time based simulation of the 25 game season
        // For a loop of 25 times
        for (int i = 0; i < 1; i++){

            cout << "Game " << i + 1 << " has been played" << endl;
            // Go through each team on map 
            for (auto & pair : teamStats) {
                // call the function to input stats for one game for the team
                simulateGame(teamStats, pair.first);
            }
                // call the function to input stats for one game for the team
        }

    check_stats(teamStats, "Lakers");

    // rank and display the teams at the end of the season to show season performance
    cout << "Season Rankings: " << endl;

    // end the main function
    // Iterate through each team in teamStats
    // Iterate through each team in teamStats
    for (const auto& [teamName, statsArray] : teamStats) {
        cout << "Team: " << teamName << endl;

        // Display points for each game
        cout << "Points per game: ";
        for (const int points : statsArray[0]) {
            cout << points << " ";
        }
        cout << endl;

        // Display rebounds for each game
        cout << "Rebounds per game: ";
        for (const int rebounds : statsArray[1]) {
            cout << rebounds << " ";
        }
        cout << endl;

        // Display assists for each game
        cout << "Assists per game: ";
        for (const int assists : statsArray[2]) {
            cout << assists << " ";
        }
        cout << endl;
    }
}

