#ifndef CHECK_COMMAND_H
#define CHECK_COMMAND_H

#include "command.h"

class CheckCommand : public Command {
  public:
    void execute() override;
    void describe() override;
};

#endif
