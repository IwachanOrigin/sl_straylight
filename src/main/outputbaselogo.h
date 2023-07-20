
#ifndef OUTPUT_BASE_LOGO_H_
#define OUTPUT_BASE_LOGO_H_

#include <string>

class OutputBaseLogo
{
public:
  explicit OutputBaseLogo() = default;
  ~OutputBaseLogo() = default;

  int render();

private:
  void displayStr(int y, int x, const std::string& str);
};

#endif // OUTPUT_BASE_LOGO_H_
