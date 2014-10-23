/*
################################################################################
Pfix by Florian Schneider

Possible flags:
nothing: load standard operators and read from stdin and display in stdout
-file,     -f  -> read from file
-save,     -s  -> save to file
-operators, -op -> show loaded operators and their priorities
-opfile,   -of -> load operators and their priorities from file
-help,     -h  -> display help information (do not process)
################################################################################
*/
#include "Postfixer.h"
#include "Data.h"
#include "Flag.h"

#include <map>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
  Data database;

  std::map<std::string, Flag*> full_flags;
  std::map<std::string, Flag*> short_flags;
  database.load_flags(short_flags, full_flags);

  // specify by argv

  // search maps
  // loop through flags
  for(int actual_flag_index = 1; actual_flag_index < argc; actual_flag_index++)
  {
    // convert actual flag to string
    std::string actual_flag = argv[actual_flag_index];

    // check if one of the maps finds it
    if(full_flags.find(actual_flag) != full_flags.end())
    {
      std::cout << "found!" << std::endl;
    }
    else
    {
      std::cout << "not found!" << std::endl;
    }
  }


  // delete all heap objects: flags, 
  return 0;
}