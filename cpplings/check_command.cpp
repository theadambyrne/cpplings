#include "check_command.h"
#include <iostream>


void CheckCommand::describe() {
  std::cout << "check your progress";
}

void CheckCommand::execute() {
  // TODO:
  // - Discover exercises per category in `exercises/`
  // - Classify Done/Not done via comments
  // - Output metrics
  
  std::cout << "CHECK COMMAND EXECUTED";
}
