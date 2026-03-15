#include "header.h"

int main(int argc, char** argv)
{
  srand(time(0));

  gameInfo settings;

  if(readCommands(argc, argv, settings)) // read commands and return if necessary
  {
    return 0;
  }

  readNames(settings);  //get player name
  game(settings);  //start game

  return 0;
}
