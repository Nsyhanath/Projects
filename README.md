# Project Take-Away
The goal of this project is to create a two player game called `take away`.
The game consists of one or more piles.

A player may remove any number of stones from **a single pile**
when it is their turn.
The player who removes the last stone(s) wins.

## Basic Gameplay
Ask each player for their name.
The game should initialize the game with a random number of piles and 
a random number of stones in each pile.
The first player starts.
When the game is over the program should display the name of the winning player
and prompt to play another game.

The game must only allow legal moves:
- When it is a players turn they must remove at least 1 stone
- A player cannot remove more stones than are in a single pile
- A player may remove stones only from 1 pile per turn

After each player turn the game should redraw the current state of
all remaining piles.
Do not display piles with 0 stones.

