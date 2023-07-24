
#ifndef OUTPUT_COLOR_LOGO_H_
#define OUTPUT_COLOR_LOGO_H_

#include <string>
#include "outputlogo.h"

class OutputColorLogo : public OutputLogo
{
public:
  explicit OutputColorLogo() = default;
  virtual ~OutputColorLogo() = default;

  int render() override;
};

#endif // OUTPUT_COLOR_LOGO_H_
