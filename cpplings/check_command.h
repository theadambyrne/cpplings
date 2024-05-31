#ifndef CHECK_COMMAND_H
#define CHECK_COMMAND_H

#include "command.h"
#include <string>
#include <map>

class CheckCommand : public Command {
  public:
    void execute() override;
    void describe() override;
  private:
    void getProgress(const std::map<std::string, std::vector<std::pair<std::string,bool>>>& exercises);
};

#endif
