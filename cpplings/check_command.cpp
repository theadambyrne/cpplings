#include "check_command.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void CheckCommand::describe() {
  cout << "check your progress";
}


void CheckCommand::getProgress(const map<string, vector<pair<string, bool>>>& exercises) {
    cout << left << setw(5) << "#" 
         << setw(25) << "~" 
         << setw(25) << "Exercise" 
         << setw(25) << endl;
    cout << setfill('-') << setw(80) << "" << endl;

    int counter = 1;
    for (const auto& pair : exercises) {
        cout << left << setw(5) << counter 
             << setw(25) << pair.first 
             << setw(25) << "" 
             << setw(25) << "" 
             << endl;
        
        for (const auto& exercise : pair.second) {
            cout << left << setw(5) << "" 
                 << setw(25) << "" 
                 << setw(25) << exercise.first 
                 << setw(25) << (exercise.second? "✅" : "🚫") 
                 << endl;
        }

        counter++;
    }
}

void CheckCommand::execute() {
  filesystem::path exercisesDir = "../exercises/";
  map<string, vector<pair<string,bool>>> exercises; // subdirs

  for (const auto& dirEntry : filesystem::directory_iterator(exercisesDir)) {
    if (!dirEntry.is_directory()) continue; // skip non-dirs

    vector<pair<string, bool>> filenames;

    for (const auto& fileEntry: filesystem::directory_iterator(dirEntry.path())) {
      if(!fileEntry.is_regular_file()) continue; // skip non-files
      
      ifstream file(fileEntry.path());
      string line;
      bool markedDone = false;

      while(getline(file, line)) {
        if (!line.find("// NOT DONE")) {
          markedDone = true;
          break;
        }
      }
      file.close();

      filenames.push_back(make_pair(fileEntry.path().filename().string(), markedDone));
    }

    exercises[dirEntry.path().filename().string()] = filenames;
  }
  
 getProgress(exercises);
}
