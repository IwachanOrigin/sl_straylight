
#include "outputlogofactory.h"
#include "outputdefaultlogo.h"
#include "outputcolorlogo.h"

OutputLogo* OutputLogoFactory::create(const LogoMode mode)
{
  switch(mode)
  {
    case LogoMode::COLOR:
    {
      return new OutputColorLogo();
    }
    break;

    case LogoMode::DEFAULT:
    default:
    {
      return new OutputDefaultLogo();
    }
  }
}
