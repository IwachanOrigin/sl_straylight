
#ifndef OUTPUT_COLOR_LOGO_H_
#define OUTPUT_COLOR_LOGO_H_

#include <string>

class OutputColorLogo
{
public:
  explicit OutputColorLogo() = default;
  ~OutputColorLogo() = default;

  int render();

private:
  void displayStr(int y, int x, const std::string& str);
};

#endif // OUTPUT_COLOR_LOGO_H_
