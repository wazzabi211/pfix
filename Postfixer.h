#include <string>
#include <map>
#include <fstream>

class Postfixer
{
  private:
  // Flag Constants
  const std::string SHORT_FILE_FLAG = "-f";
  const std::string FULL_FILE_FLAG = "-file";

  const std::string SHORT_SAVE_FLAG = "-s";
  const std::string FULL_SAVE_FLAG = "-save";

  const std::string SHORT_OPERATOR_FLAG = "-op";
  const std::string FULL_OPERATOR_FLAG = "-operators";

  const std::string SHORT_OPFILE_FLAG = "-of";
  const std::string FULL_OPFILE_FLAG = "-opfile";

  const std::string SHORT_HELP_FLAG = "-h";
  const std::string FULL_HELP_FLAG = "-help";

  const std::string plus_ = "+";
  const unsigned int plus_p_ = 1;

  const std::string minus_ = "-";
  const unsigned int minus_p_ = 1;

  const std::string times_ = "*";
  const unsigned int times_p_ = 2;

  const std::string per_ = "/";
  const unsigned int per_p_ = 2;

  public:
  // Constructors and Destructors
  Postfixer();
  ~Postfixer();

  // Other
  int run(char **argv, int argc);
  void read();
  void help_info();
  std::map<std::string, unsigned int> loadStandardOperators();
  void showStandardOperators();
  void saveStandardOperators(std::fstream &to_save);
  void convertToPostfix(std::string);
};