Problem
-------
Minesweeper is a computer game that became popular in the 1980s, and is still included in some versions of the Microsoft Windows operating system. This problem has a similar idea, but it does not assume you have played Minesweeper.

In this problem, you are playing a game on a grid of identical cells. The content of each cell is initially hidden. There are M mines hidden in M different cells of the grid. No other cells contain mines. You may click on any cell to reveal it. If the revealed cell contains a mine, then the game is over, and you lose. Otherwise, the revealed cell will contain a digit between 0 and 8, inclusive, which corresponds to the number of neighboring cells that contain mines. Two cells are neighbors if they share a corner or an edge. Additionally, if the revealed cell contains a 0, then all of the neighbors of the revealed cell are automatically revealed as well, recursively. When all the cells that don't contain mines have been revealed, the game ends, and you win.

For example, an initial configuration of the board may look like this ('*' denotes a mine, and 'c' is the first clicked cell):

```*..*...**.
....*.....
..c..*....
........*.
..........```
There are no mines adjacent to the clicked cell, so when it is revealed, it becomes a 0, and its 8 adjacent cells are revealed as well. This process continues, resulting in the following board:

```*..*...**.
1112*.....
00012*....
00001111*.
00000001..```
At this point, there are still un-revealed cells that do not contain mines (denoted by '.' characters), so the player has to click again in order to continue the game.

You want to win the game as quickly as possible. You want to find the minimum number of clicks to win the game. Given the size of the board (N x N), output such minimum number of clicks.

Input
-----
The first line of the input gives the number of test cases, **T**. **T** test cases follow. First line of each test case contains one integer N. N lines strings with length N follows containing '*' and '.', denotes the Minesweeper initial board.

Output
------
For each test case, output one line containing "`Case #x: y`", where x is the test case number (starting from 1) and y is the minimum number of clicks to win.

Limits
------
Time limit: 30 seconds per test set.<br/>
Memory limit: 1 GB.<br/>
1 ≤ **T** ≤ 100.

Small dataset (Test Set 1 - Visible)
------------------------------------
1 ≤ **N** ≤ 50.

Large dataset (Test Set 2 - Hidden)
-----------------------------------
1 ≤ **N** ≤ 300.

Sample
------
Sample Input
============
```
2
3
..*
..*
**.
5
..*..
..*..
.*..*
.*...
.*...
```
Sample Output
-------------
```
Case #1: 2
Case #2: 8
```