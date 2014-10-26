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

#include <string>
#include <iostream>

int main(int argc, char **argv)
{
  int errorcode = 0;
  try
  {
     Postfixer postfixer;

     errorcode = postfixer.run(argv, argc);
  }
 
  catch(errorcode)
  {
    std::cout << "Error: errorcode " << errorcode << std::endl;

    // switch through errors
  }

  return 0;
}