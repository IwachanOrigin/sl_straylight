
#ifndef OUTPUT_DEFAULT_LOGO_H_
#define OUTPUT_DEFAULT_LOGO_H_

#include <string>

class OutputDefaultLogo
{
public:
  explicit OutputDefaultLogo() = default;
  ~OutputDefaultLogo() = default;

  int render();

private:
  void displayStr(int y, int x, const std::string& str);
};

#endif // OUTPUT_DEFAULT_LOGO_H_
