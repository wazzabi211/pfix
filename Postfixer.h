#include <string>

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

  public:
  // Constructors and Destructors
  Postfixer();
  ~Postfixer();

  // Other
  void validate_flags();
  void read();
  void read_file(); 
};