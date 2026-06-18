# Project #1: Take away game
The goal of this project is to create a two player game called `take away`.
The game consists of one or more piles.
Typically, each pile contains stones or sticks.
In your program, you may refer to them how you like.
I will use stones.

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

The key to the strategy is to try to make a move that results in the 
`exclusive or` of the stones in all piles is equal to zero.
For example, given a game with 3 piles with 2, 3, and 4 stones in the piles.
In binary, the game looks like:

```
    0 1 0        // binary 2
    0 1 1        // binary 3
  ^ 1 0 0        // binary 4
    -----
    1 0 1        // exclusive or of all values = binary 5
```

This result is called the *nim sum*, because this strategy was first completely described in 1901
by a mathematician, Charles Bouton, who named the game 'nim'.
The origins of this game are much more ancient, but the exact history has been lost.

Since the nim sum is greater than 0, a winning move is possible.
That is, a move that changes the nim sum of all heaps to 0 is possible.
If 3 stones are removed from the pile containing 4:

```
    0 1 0 
    0 1 1
  ^ 0 0 1
    -----
    0 0 0
```

That leaves `1 ^ 2 ^ 3`, which = 0.

This is a "winning position", because there is no move the next player can make
which will leave the piles in a state where the nim sum of all piles is zero.

When it is your turn and the nim sum is already zero, 
then there is no move you can make to guarantee a win.
The only winning strategy is to drag the game out
and hope your opponent makes a mistake.

This is a rational strategy for a computer,
because the longer a game lasts,
the more likely a human opponent will make a mistake the computer
can take advantage of.

## Example output

### Show help

```
./take-away -h
Usage: ./take-away [-h] [-c] [-p # piles] [-s # stones] 

Options:
  -h   Show this text.
  -c   Make player two the computer.  Default = false.
  -p   Manually set the starting number of piles in the game.
  -s   Manually set the starting number of stones in each pile.

       Max values for piles and stones: 99
       Min values for piles and stones: 1
```

After the help text is displayed, the program should exit.

### Default behavior
Play a random two player game.

```plain
  ./take-away
  First player name: Alice
  Second player name: Bob's Your Uncle
  Player 1: Alice
  Player 2: Bob's Your Uncle
  Heap 1 [ 5]: *****
  Heap 2 [14]: **************
  Heap 3 [ 8]: ********

  Alice's turn
  Which heap? 1
  How many stones? 5
  Player 1: Alice
  Player 2: Bob
  Heap 1 [14]: **************
  Heap 2 [ 8]: ********

  Bob's Your Uncle's turn
  Which heap? 2
  How many stones? 9
     There aren't that many stones in this heap.
  How many stones? 7
  Player 1: Alice
  Player 2: Bob
  Heap 1 [14]: **************
  Heap 2 [ 1]: *

  Alice's turn
  Which heap? 1
  How many stones? 13
  Player 1: Alice
  Player 2: Bob
  Heap 1 [ 1]: *
  Heap 2 [ 1]: *

  Bob's Your Uncle's turn
  Which heap? 1
  How many stones? 1
  Player 1: Alice
  Player 2: Bob
  Heap 1 [ 1]: *

  Alice's turn
  How many stones? 1
  Alice wins!!
  Play another game? [Y/n] n

```


### Play against the computer
Play a random game - human vs. computer.

```plain
  ./take-away -c 
  Human player name: Darla

  Heap 0 [15]: ***************
  Heap 1 [13]: *************
  Heap 2 [ 7]: *******
  Heap 3 [12]: ************
  Heap 4 [11]: ***********
  Heap 5 [ 9]: *********
  Darla's turn
  Which heap? 1
  How many stones? 13

  Heap 0 [15]: ***************
  Heap 1 [ 7]: *******
  Heap 2 [12]: ************
  Heap 3 [11]: ***********
  Heap 4 [ 9]: *********
  HAL 9000's turn
  HAL 9000 removed 6 stones from heap 0.

  Heap 0 [ 9]: *********
  Heap 1 [ 7]: *******
  Heap 2 [12]: ************
  Heap 3 [11]: ***********
  Heap 4 [ 9]: *********
  Darla's turn
  Which heap? 

  (rest of the game omitted)
```

### Play with a fixed number of piles
This example uses the computer, but could apply to a 2 player game.

```plain
  ./take-away -c -p 5
  Human player name: Ed

  Heap 0 [13]: *************
  Heap 1 [ 1]: *
  Heap 2 [ 5]: *****
  Heap 3 [14]: **************
  Heap 4 [ 9]: *********
  Ed's turn
  Which heap? 

  (rest of the game omitted)
```

### Play with a fixed number of piles and stones
This example sets both, but setting only the stones in each pile
and allowing the piles to be random is a valid option.

```plain
  ./take-away -c -p 3 -s 5
  Human player name: Fern

  Heap 0 [ 5]: *****
  Heap 1 [ 5]: *****
  Heap 2 [ 5]: *****
  Fern's turn
  Which heap? 

  (rest of the game omitted)
```

