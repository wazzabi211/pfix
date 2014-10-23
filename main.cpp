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

#include <string>
#include <iostream>

int main(int argc, char **argv)
{
  Data database;
  Postfixer postfixer;

  // specify by argv
  postfixer.validate_flags();


  return 0;
}