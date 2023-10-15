Analysis
--------
Scans the board, the floodfills from an unreached 0 cell until it reaches 1-8, recursively. At last, we can get a number of disconnect components of 0, and add the rest number of unreached 1-8 to the result. initial board: 02* 2*3 *3* after one floodfill, //* /*3 *3* There are two 3s left, so the result is 3