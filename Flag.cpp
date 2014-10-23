#include "Flag.h"

Flag::Flag(std::string flag, char shortcut) : name_(flag), shortcut_(shortcut)
{}

bool Flag::operator==(const char to_compare)
{
  if(shortcut_ == to_compare)
  {
    return true;
  }

  return false;
}

bool Flag::operator==(const std::string to_compare)
{
  if(name_ == to_compare)
  {
    return true;
  }
  
  return false;
}