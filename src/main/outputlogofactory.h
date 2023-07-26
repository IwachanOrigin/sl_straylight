
#ifndef OUTPUT_LOGO_FACTORY_H_
#define OUTPUT_LOGO_FACTORY_H_

#include "outputlogo.h"

enum class LogoMode
{
  DEFAULT = 0
  , COLOR = 1
  , HELP  = 99
};

class OutputLogoFactory
{
public:
  explicit OutputLogoFactory() = default;
  ~OutputLogoFactory() = default;

  OutputLogo* create(const LogoMode mode);
};

#endif // OUTPUT_LOGO_FACTORY_H_
