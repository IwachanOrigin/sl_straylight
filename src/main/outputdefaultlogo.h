
#ifndef OUTPUT_DEFAULT_LOGO_H_
#define OUTPUT_DEFAULT_LOGO_H_

#include <string>
#include "outputlogo.h"

class OutputDefaultLogo : public OutputLogo
{
public:
  explicit OutputDefaultLogo() = default;
  virtual ~OutputDefaultLogo() = default;

  int render() override;
};

#endif // OUTPUT_DEFAULT_LOGO_H_
