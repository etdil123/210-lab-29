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

void simulateGame(map<string, array<list<int>, 3>> &, const string &);

// Definition for function to simulate a game for a team 
    // parameters: map of team and list to update stats
    // creates a variable to randomly assign how the team is going to play
    // randomly create stats for points, rebounds, assists - add to the lists
void simulateGame(map<string, array<list<int>, 3>> & teamStats, const string & teamName) {
    // Add random numbers to the team's lists in the map
    teamStats[teamName][0].push_back(rand() % 40 + 1);
    teamStats[teamName][1].push_back(rand() % 20 + 1);
    teamStats[teamName][2].push_back(rand() % 10 + 1);

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
    string teamName;
    int points, rebounds, assists;
    file >> teamName >> rebounds >> points >> assists;

    // insert team name
    teamStats[teamName] = array<list<int>, 3>();
    
    // for initial get the data into the map
    teamStats[teamName][0].push_back(points);
    teamStats[teamName][1].push_back(rebounds);
    teamStats[teamName][2].push_back(assists);

    // close file
    file.close();

    // Time based simulation of the 25 game season
        // For a loop of 25 times
        for (int i = 0; i < 1; i++){

            cout << "Game " << i << "has been played" << endl;
            // Go through each team on map 
            for (auto & pair : teamStats) {
                // call the function to input stats for one game for the team
                simulateGame(teamStats, pair.first);
            }
                // call the function to input stats for one game for the team
        }

    // rank and display the teams at the end of the season to show season performance
    cout << "Season Rankings: " << endl;

    // end the main function
    // Iterate through each team in teamStats
    



}