#include "Flag.h"

Flag::Flag(std::string flag, std::string shortcut) : name_(flag), shortcut_(shortcut)
{}

bool Flag::operator==(const std::string to_compare)
{
  if( (name_ == to_compare) || (shortcut_== to_compare) )
  {
    return true;
  }

  return false;
}