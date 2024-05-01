//
//  High_Score_page.cpp
//  CG_project
//
//  Created by Swajan Baruah on 30/4/24.
//

#include <stdio.h>
#include "High_Score_page.h"
using namespace std;
vector<long long>highScore;
void read_from_file(){
    ifstream file("/Users/swajanbaruah/Documents/Class/CG/CG_project/CG_project/highscores.txt");
    if (!file.is_open()) {
           cout<< "Failed to open the file." << endl;
        }
    string line;
      while (getline(file, line)) {
          cout << line <<endl;
      }
      
      // Close the file
      file.close();
    
}
void write_score(long long score){
    ofstream outputFile("/Users/swajanbaruah/Documents/Class/CG/CG_project/CG_project/highscores.txt");
    if (!outputFile.is_open()) {
        cout<< "Failed to open the file for writing." <<endl;
    }
    
    ifstream file("/Users/swajanbaruah/Documents/Class/CG/CG_project/CG_project/highscores.txt");
    
    // convert string to int
    string line;
    while (getline(file, line)) {
        highScore.push_back(stoi(line));
    }
    file.close();
    //
    highScore.push_back(score);
    sort(highScore.begin(),highScore.end());
    reverse(highScore.begin(),highScore.end());
    for(int i =0 ;i<5;i++){
       // cout<<highScore[i]<<" ";
    }
    for(int i =0 ;i<5;i++){
        outputFile << to_string(highScore[i])<< std::endl;
    }
}
