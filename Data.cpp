#include "Data.h"
#include "Flag.h"

using std::map;
using std::string;

Data::Data()
{

}

void Data::load_flags(map<string, Flag*> &short_flags, 
                                      map<string, Flag*> &full_flags)
{
  // Create the flags
  Flag* file_flag = new Flag(FULL_FILE_FLAG, SHORT_FILE_FLAG);
  Flag* save_flag = new Flag(FULL_SAVE_FLAG, SHORT_SAVE_FLAG);
  Flag* operator_flag = new Flag(FULL_OPERATOR_FLAG, SHORT_OPERATOR_FLAG);
  Flag* opfile_flag = new Flag(FULL_OPFILE_FLAG, SHORT_OPFILE_FLAG);
  Flag* help_flag = new Flag(FULL_HELP_FLAG, SHORT_HELP_FLAG);

  // put into shortcut map

  short_flags[SHORT_FILE_FLAG] = file_flag;
  short_flags[SHORT_SAVE_FLAG] = save_flag;
  short_flags[SHORT_OPERATOR_FLAG] = operator_flag;
  short_flags[SHORT_OPFILE_FLAG] = opfile_flag;
  short_flags[SHORT_HELP_FLAG] = help_flag;

  // put into full map

  full_flags[FULL_FILE_FLAG] = file_flag;
  full_flags[FULL_SAVE_FLAG] = save_flag;
  full_flags[FULL_OPERATOR_FLAG] = operator_flag;
  full_flags[FULL_OPFILE_FLAG] = opfile_flag;
  full_flags[FULL_HELP_FLAG] = help_flag;
}