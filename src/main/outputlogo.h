
#ifndef OUTPUT_LOGO_H_
#define OUTPUT_LOGO_H_

#include <string>

class OutputLogo
{
public:
  explicit OutputLogo() = default;
  virtual ~OutputLogo() = default;

  virtual int render() = 0;

protected:
  void displayStr(int y, int x, const std::string& str);
};

#endif // OUTPUT_LOGO_H_
