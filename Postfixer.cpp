#include "Postfixer.h"
#include "Data.h"

#include <string>
#include <map>
#include <iostream>
#include <fstream>

using std::string;
using std::map;
using std::cout;
using std::endl;
using std::fstream;
using std::cin;

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

map<string, unsigned int> Postfixer::loadStandardOperators()
{
  map<string, unsigned int> standard_operators;

  standard_operators[plus_] = plus_p_;
  standard_operators[minus_] = minus_p_;
  standard_operators[times_] = times_p_;
  standard_operators[per_] = per_p_;

  return standard_operators;
}

void Postfixer::showStandardOperators()
{
      cout << endl << "Standard operators: ";
      cout << plus_ << ", ";
      cout << minus_ << ", ";
      cout << times_ << ", ";
      cout << per_ << endl;
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

  // Load Standard-Operators
  map<string, unsigned int> standard_operators = loadStandardOperators();

  if(operator_file)
  {
    // load additional operators from a file and put it into the map 
    if(operator_display)
    {
      // Show standard operators and then the loaded ones
      showStandardOperators();
      cout << endl << "Additional operators loaded: " << endl;
      //
    }
  }
  else if(operator_display)
  {
    // if only operator_display and not operator_file is given just display
    // the standard operators
    showStandardOperators();
  }

  // Get the input

  if(file)
  {
    // load from given file after

    // check argv 
    // search for the file flag
    for (int actual_argument = 1; actual_argument < argc; actual_argument++)
    {
      string argv_string = argv[actual_argument];

      if((argv_string == SHORT_FILE_FLAG) || (argv_string == FULL_FILE_FLAG) )
      {
        // check if its not the last argument
        if(actual_argument < (argc - 1) )
        {
          // check if the next argument isn't another flag
          if(argv[actual_argument + 1][0] == '-')
          {
            cout << endl << "Error: no file given after file flag." << endl;
            return 1;  // MAKE ERRORCODE
          }

          // if ok then try to open file
          fstream to_load(argv[actual_argument + 1]);

          if(to_load.is_open())
          {
            cout << "Loading from file: " << argv[actual_argument + 1] << endl;

            // get the input of file from here !!! // TODO

          }
          else
          {
            cout << "Error: could not open \"" << argv[actual_argument + 1] <<
            "\"" << endl;  // MAKE ERRORCODE
            return 2;
          }

        }
        else
        {
          cout << endl << "Error: no file given after file flag." << endl;
          return 1; // MAKE ERRORCODE
        }
      }
    }
  }
  else
  {
    // if file flag was not given ask for the input
    string input;

    cout << "Please enter your term: " << endl;
    cin >> input;

  }

  return 0;
}