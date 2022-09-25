Problem
===
Edison, a robot, does not have a right hand or eyes. As a brave robot, **he always puts his left hand on the wall no matter he walks or turns around**. Because he thinks it is too dangerous, Edison does not walk backward.

Assume that Edison has found himself in a square-shaped maze of **NxN** square cells which is surrounded by walls from the outside. In the maze, some of the cells are also walls. Edison can only move between two empty cells in four directions, north, south, west and east. In order to get out of the maze, he drafts a plan. He uses his left hand to lean on the wall and goes by following the wall.

Here is the question, is Edison able to get out of the maze in at most 10,000 steps? If he can make it, output the path. By getting out of the maze, he only needs to be in the exit cell. If the starting cell is the same as the exit, Edison won't need to move and can directly get out of the maze.

Input
===
The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case starts with an integer **N**. **N** is the size of the maze. The following **N** lines, each line contains **N** characters which may be '.' or '#'. '.' is an empty cell, '#' is a wall. Followed by a line which contains four integers: **sx, sy, ex, ey. (sx, sy)** means that Edison is standing on row **sx** and column **sy** as his starting cell, **(ex, ey)** is the exit of the maze. **(sx, sy)** is guaranteed to be at one of the 4 corners of the maze, and Edison can only touch the wall on 4 adjacent cells(not 8) initially. **(ex, ey)** can be anywhere in the maze. Note that the top-left corner is at position (1,1).

Output
===
For each test case, output a line containing "Case #x: y", where x is the case number (starting from 1) and y is "Edison ran out of energy." (without the quotes) if Edison can't reach the exit of the maze in at most 10,000 steps, otherwise y should be the number of steps followed by another line which contains y characters to describe the path (each character should be E for east, S for south, W for west or N for north). There is no character to represent the turning around. We don't care about the turning around steps, please only output the path of how Edison will cross the maze.

Limits
===
Time limit: 30 seconds per test set.<br />
Memory limit: 1 GB.<br />
1 ≤ **T** ≤ 30.<br />
1 ≤ **sx, sy, ex, ey** ≤ **N**.<br />
The starting cell and the exit of the maze will always be an empty cell. And the starting cell and the exit of the maze won't be the same.

Test set 1 - Visible
===
2 ≤ **N** ≤ 10.

Test set 2 - Hidden
===
2 ≤ **N** ≤ 100.

Sample
===
Sample Input
---
```
3
2
.#
#.
1 1 2 2
5
.##.#
.....
...#.
.###.
...#.
1 1 5 3
3
...
.#.
...
1 1 3 3
```
Sample Output
---
```
Case #1: Edison ran out of energy.
Case #2: 22
SEEENSESSSNNNWWSWWSSEE
Case #3: 4
EESS
```

Note:
In the 2nd test case after moving 1 cell down from his starting cell, Edison will still be able to lean on the wall at the cell (1,2) by his left hand.
In the third test case, due to Edison can't touch the wall at cell (2,2) initially, so he has to go east in his first step.