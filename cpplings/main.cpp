#include "command.h"
#include "check_command.h"
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

void help(const unordered_map<string, shared_ptr<Command>>& commands) {
  cout << "🚀 Welcome to cpplings!" << endl;
  cout << "run ./cpplings to open this help message" << endl;
  cout << endl << "Commands:" << endl;

  for (const auto& pair: commands) {
    cout << pair.first << "\t";
    pair.second->describe();
    cout << endl << endl;
  }
}

int main(int argc, char**argv) {
  unordered_map<string, shared_ptr<Command>> commands; // shared: auto deallocation, single heap allocation
  commands["check"] = make_shared<CheckCommand>();

  if (argc != 2) { // one command only 
    help(commands);  
    cerr << "Usage: " << argv[0] << " <command>" << endl;
    return 1;
  }

  string commandName = argv[1];
  auto command = commands.find(commandName);

  if (command != commands.end()) {
    command->second->execute();
  } else {
    help(commands);
    cerr << "Command \"" << commandName << "\" not recognised" << endl;
    return 1;
  }

  return 0;
}
