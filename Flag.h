#include <string>

class Flag
{
  private:
  std::string name_;
  std::string shortcut_;

  public:
  // Constructor
  Flag(std::string flag, std::string shortcut);

  // Operator
  bool operator==(const std::string to_compare);
};