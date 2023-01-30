
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

int main(int argc, char *argv[])
{
  /*
    ######## ##     ##    ###     ######   ######
    ##       ###   ###   ## ##   ##    ## ##    ##
    ##       #### ####  ##   ##  ##       ##
    ######   ## ### ## ##     ## ##        ######
    ##       ##     ## ######### ##             ##
    ##       ##     ## ##     ## ##    ## ##    ##
    ######## ##     ## ##     ##  ######   ######
   */

  // init
  std::vector<std::string> vecStr;
  vecStr.push_back(" ######## ##     ##    ###     ######   ######  ");
  vecStr.push_back(" ##       ###   ###   ## ##   ##    ## ##    ## ");
  vecStr.push_back(" ##       #### ####  ##   ##  ##       ##       ");
  vecStr.push_back(" ######   ## ### ## ##     ## ##        ######  ");
  vecStr.push_back(" ##       ##     ## ######### ##             ## ");
  vecStr.push_back(" ##       ##     ## ##     ## ##    ## ##    ## ");
  vecStr.push_back(" ######## ##     ## ##     ##  ######   ######  ");

  // output
  for (int i = 0; i < vecStr.size(); i++)
  {
    std::cout << vecStr[i] << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  return 0;
}
