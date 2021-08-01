#ifndef CMDFACTORY_H
#define CMDFACTORY_H

#include "Cmd.h"
#include <memory>
#include <map>

class ICommand;

#define COMMAND_BEGIN void CommandFactory::addCommand() {
#define COMMAND_END }
// todo : have to define the macro?
// todo : why need factory? 
// todo : here need to shared_ptr?

// todo : use value_type !! why and how
// todo : cmdClass type is safe here ? 
#define COMMAND_ADD(cmdName, cmdClass) {                                \
        std::shared_ptr<ICommand> pCmd = std::make_shared<cmdClass>();  \   
        std::string name = cmdName;                                     \
        cmdMap_.insert({name, pCmd});                                   \
   }                                                                    \

namespace burgerkv {

class CmdFactory {
   public:
      CmdFactory();
      ~CmdFactory() = default;
      void addCommand();
      ICommand * getCommandProcesser(const char * pcmd);  // raw ptr here? 
   private:
      std::map<std::string, std::shared_ptr<ICommand> > cmdMap_;
};

} // namespace burgerkv




#endif // CMDFACTORY_H