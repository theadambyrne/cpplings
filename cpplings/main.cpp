#include "command.h"
#include "check_command.h"
#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

int main(int argc, char**argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <command>" << std::endl;
    return 1;
  }

  std::string commandName = argv[1];
  std::unordered_map<std::string, std::shared_ptr<Command>> commands; // shared: auto deallocation, single heap allocation
  commands["check"] = std::make_shared<CheckCommand>();

  auto command = commands.find(commandName);
  if (command != commands.end()) {
    command->second->execute();
  } else {
    std::cerr << "Command \"" << commandName << "\" not recognised" << std::endl;
    return 1;
  }

  return 0;
}
