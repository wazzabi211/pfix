#include "Postfixer.h"
#include "Data.h"

#include <string>

using std::string;

Postfixer::Postfixer()
{

}

Postfixer::~Postfixer()
{

}

void Postfixer::help_info()
{
  // display help information
}

int Postfixer::run(char **argv, int argc)
{
  bool file = false;
  bool save = false;
  bool operator_display = false;
  bool operator_file = false;

  for(int actual_flag = 1; actual_flag < argc; actual_flag++)
  {
    string actual_argument = argv[actual_flag];

    if(actual_argument ==  SHORT_FILE_FLAG ||
       actual_argument ==  FULL_FILE_FLAG)
    {
      file = true;
    }
    else if (actual_argument ==  SHORT_SAVE_FLAG ||
       actual_argument ==  FULL_SAVE_FLAG)
    {
      save = true;
    }
    else if (actual_argument ==  SHORT_OPERATOR_FLAG ||
       actual_argument ==  FULL_OPERATOR_FLAG)
    {
      operator_display = true;
    }
    else if (actual_argument ==  SHORT_OPFILE_FLAG ||
       actual_argument ==  FULL_OPFILE_FLAG)
    {
      operator_file = true;
    }
    else if (actual_argument ==  SHORT_HELP_FLAG ||
       actual_argument ==  FULL_HELP_FLAG)
    {
      help_info();
      return 0;
    }
  }

  // if file is true load the term from file!
  // if save is true save the result to file!
    // also save the used operators to file if operator display was set !
  // if operator_display is true then display the operators used and their priorities
    // also if save is true then save the used operator info to file
  // if operator_file is true then load the operators to use from a file
  // if help is true, the help text will be displayed and the programm will stop.

  return 0;
}