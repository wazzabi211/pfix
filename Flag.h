#include <string>

class Flag
{
  private:
  std::string name_;
  char shortcut_;

  public:
  // Constructor
  Flag(std::string flag, char shortcut);

  // Operator
  bool operator==(const char to_compare);
  bool operator==(const std::string to_compare);
};