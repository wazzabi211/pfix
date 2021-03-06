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
      cout << endl << SO_INTRO;
      cout << plus_ << SEPERATOR;
      cout << minus_ << SEPERATOR;
      cout << times_ << SEPERATOR;
      cout << per_ << endl;
}

void Postfixer::saveStandardOperators(fstream &to_save)
{
      to_save << endl << SO_INTRO;
      to_save << plus_ << SEPERATOR;
      to_save << minus_ << SEPERATOR;
      to_save << times_ << SEPERATOR;
      to_save << per_ << endl;
}

void Postfixer::convertToPostfix(std::string)
{
  // the unbelieveable convertion algorithmus of DOOM
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

  // the input where the unprocessed term will be
  string input;
  // the result where the ..errh .. the result will be
  string result;

  if(operator_file)
  {
    // load additional operators from a file and put it into the map 
    if(operator_display && !save)
    {
      // Show standard operators and then the loaded ones
      showStandardOperators();
      cout << endl << ADDITIONAL_OP << endl;
      //
    }
  }
  else if(operator_display && !save)
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

            // get the input of file from here
            to_load >> input;

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
    cout << "Please enter your term: " << endl;
    cin >> input;

    // debug
    cout << input << endl;
  }

  // check if the input is given
  if(input.length() == 0)
  {
    cout << "Error: no input given." << endl;
    return 3;
  }


  // ALGORITHM TIME !
  






  // if the save flag is given we save the result into a file
  if(save)
  {
    // check argv 
    // search for the file flag
    for (int actual_argument = 1; actual_argument < argc; actual_argument++)
    {
      string argv_string = argv[actual_argument];

      if((argv_string == SHORT_SAVE_FLAG) || (argv_string == FULL_SAVE_FLAG) )
      {
        // check if its not the last argument
        if(actual_argument < (argc - 1) )
        {
          // check if the next argument isn't another flag
          if(argv[actual_argument + 1][0] == '-')
          {
            cout << endl << "Error: no file given after save flag." << endl;
            return 4;  // MAKE ERRORCODE
          }

          // if ok then try to open file
          fstream to_save;
          to_save.open(argv[actual_argument + 1], fstream::out);

          if(to_save.is_open())
          {
            cout << "Saving to file: " << argv[actual_argument + 1] << endl;

            // get the result into the file here !
            if(operator_display)
            {
              // save the standard operators
              saveStandardOperators(to_save);

              if(operator_file)
              {
                // save additional operators
              }
            }

            // DEBUG
            result = input;
            to_save << "Result:" << endl;
            to_save << result << endl;

            to_save.close();
          }
          else
          {
            cout << "Error: could not save to \"" << argv[actual_argument + 1] <<
            "\"" << endl;  // MAKE ERRORCODE
            return 2;
          }

        }
        else
        {
          cout << endl << "Error: no file given after save flag." << endl;
          return 4; // MAKE ERRORCODE
        }
      }
    }

  }
  else
  {
    // display result

    // DEBUG
    result = input;
    cout << "Result: " << endl;
    cout << result << endl;
  }



  return 0;
}