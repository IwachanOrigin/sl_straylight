
#ifndef OUTPUT_LOGO_H_
#define OUTPUT_LOGO_H_

#include <string>

class OutputLogo
{
public:
  explicit OutputLogo() = default;
  virtual ~OutputLogo() = default;

  virtual int render() = 0;
  void setFlushON() { m_flushON = true; }

protected:
  void displayStr(int y, int x, const std::string& str);
  bool m_flushON = false;
};

#endif // OUTPUT_LOGO_H_
