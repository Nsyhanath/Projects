#include "header.h"

void makePiles(vector<int>& pilesTest, gameInfo& settings)
{
  //initialize number of piles
  if (settings.piles <= 0)
  {
    settings.piles = (rand() % (MAXIMUMPILES - MINIUMVALUE)) + MINIMUMVALUE;
  }
  pilesTest.resize(settings.piles);
  //initialize number of stones
  if(settings.stones <= 0)
  {
    settings.stones = (rand() % MAXIMUMVALUE - MINIMUMVALUE) + MINIMUMVALUE;
  }
  //set number of stones per pile
  for(int i = 0; i < pilesTest.size(); i++)
  {
    pilesTest[i] = settings.stones;
  }
}

void printPiles(vector<int>& pile, int numOfPiles)
{
  //print piles and stone amount
  for (int i = 0; i < pile.size(); i++)
  {
    if(piles[i] > 0)
    {
      std::cout << "Heap " << i << " [" << piles[i] << "]: ";

      for(int j = 0; j < pile[j]; j++)
      {
        std::cout << "* ";
      }
      std::cout << '\n';
    }
  }
}

int readCommands(int argc, char** argv, gameInfo& settings)
{
  //read args
  for(int i = 0; i < argc; i++)
  {
    //-h help
    if(strcmp(argv[i], "-h") == 0)
    {
      std::cout << "Options:" << "\nt-help text" << "\nt-c play against computer" << "\n\t-p set number of piles" << "\n\t-s set number of stones" << "\n\t| Maximum Piles: " << MAXIMUMPILES << "\n\t| Maximum Stones: " << MAXIMUMVALUE;
      return 1;
    }
    //-c computer
    else if(strcmp(argv[i], "-c") == 0)
    {
      settings.computer = true;
    }
    //-p number of piles
    else if(strcmp(argv[i], "-p") == 0)
    {
      //read number of piles
      if( i+1 < argc)
      {
        //check that argument is a number
        if(is_num(argv[i+1]))
        {
          int value = std::stoi(argv[i+1]);
          //check that number is within range
          if(value> MINIMUMVALUE && value <= MAXIMUMPILES)
          {
            settings.piles = value;
          }
        }
        //ignores the next element in the vector 
        i++;
      }
    }
    //-s number of stones in pile
    else if(strcmp(argv[i], "-s") == 0)
    {
      //read number of stones
      if(i+1 < argc)
      {
        //check that argument is a number
        if(isNum(argv[i+1]))
        {
          int value = std::stoi(argv[i+1]);
          //check number is within ragne
          if(value > MINIMUMVALUE && value <= MAXIMUMVALUE)
          {
            settings.stones = value;
          }
        }
        i++;
      }
    }
  }
  return 0;
}

void readNames(gameInfo& info)
{
  //Read player 1 name
  std::cout << "Player  1 Name: ";
  cin >> info.player1;

  //Read player 2 name if there no computer
  if(!info.computer)
  {
    std::cout << "Player 2 Name: ";
    std::cin >> info.player2;
  }
  else
  {
    info.player2 = "Computer";
  }
}

bool isNum(char* str)
{
  int stringLength = static_cast<int>(strlen(str));

  for(int i = 0; i < stringLength; i++)
  {
    if(str[i] < '0' || str[i] > '9')
    {
      return 0;
    }
  }
  return stringLength;
}

std::pairs<int, int> computer_move(vector<int>& piles)
{
    for(int i = 0; i < piles.size(); i++)
    {
      //try every bitshift
      if(piles[i] > 0)
      {
        int stones = piles[i] >> 1;

        bool includeZero = false;

        while(!includeZero)
        {
          int sum = 0;

          for(int j = 0; j < i; j++)
          {
            sum ^= piles[j];
          }
          sum ^= stones;
          for(int j = i+1; j < piles.size(); j++)
          {
            sum ^= piles[j];
          }
          // found value
          if(sum == 0)
          {
            return std::pairs<int, int>{i, piles[i] - stones};
          }
          if(stones == 0)
          {
            includeZero = true;
          }
          stones >>= 1;
        }
      }
    }
    //no move
    for(int i = 0; i < piles.size(); i++)
    {
        if(piles[i] > 0)
        {
          return std::pairs<int, int>{i,1};
        }
    }
}

void game(gameInfo& settings)
{
    //initialize piles
    vector<int> piles;

    //game reset loop
    while(1)
    {
      //start game with player 1 turn
      bool turn = 1;

      //number of piles that stones
      int numOfPiles = settings.piles;

      //set piles
      makePiles(piles, settings);

      //loop while there are piles with stones
      while(numOfPiles)
      {
        //Prompts player turn
        std::cout << (turn?settings.player1 : settings.player2) << "'s Turn: \n";
        std::cout << numOfPiles << " piles left:\n";
        printPiles(piles, numOfPiles);

        int pileNumber;
        int stoneAmount;

        //Computer
        if(turn == 0 && settings.computer)
        {
          std::pairs<int, int> ret = computerMove(piles);

          std::cout << "Computer chose pile " << ret.first << " and removed " << ret.second << " stones.\n";
          pileNumber = ret.first;
          piles[pileNumber] -= ret.second;
        }
        //Player Turn
        else
        {
          //Read pile and stone
          std::cout << "Type the pile number and the amount of stones you want to take.\n";
          cin >> pileNumber >> stoneAmount;

          //Check if valid input
          if(pileNumber < piles.size() && piles[pileNumber] >= stoneAmount && piles[pilesNumber] > 0)
          {
            piles[pileNumber] -= stoneAmount;
          }
          else
          {
            continue;
          }
        }
        //remove pile
        if(piles[pileNumber] == 0)
        {
          numOfPiles--;
        }
        //change turn
        turn = !turn;
      }
    }
    //Prompts which player wins
    std::cout << (!turn ? settings.player1 : settings.player2) << " Wins.\n";

    //Prompt new game
    char answer;
    std::cout << "Play again? [y/n]: ";
    std::cin >> answer;
    if(answer != 'y')
    {
      break;
    }
}
*/

