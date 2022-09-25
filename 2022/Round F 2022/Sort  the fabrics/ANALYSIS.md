Analysis
---
Let us denote the fabric array sorted by Ada as **Ad**, and the one sorted by Charles as **_Ch_**.

Test Set 1
---
The maximum number of fabrics here is 2.

**One fabric**

When there's only one fabric, the answer is always 1.

**Two fabrics**

When there are two fabrics, the answer is either 0 or 2.

If the two fabrics have the same color and the same durability, the sort will be done by the unique identifier, leading to the same ordering of the fabrics in both _Ad_ and _Ch_; hence the answer is 2.

If the two fabrics have the same color, then _Ad_ would be sorted in the ascending order of the unique identifier. We need to check, if the smaller unique index has the smaller durability of the two fabrics or not. If yes, then the fabrics in _Ch_ will be in the same order as _Ad_, and the answer is 2; otherwise the answer is 0.

If the two fabrics have the same durability, then _Ch_ would be sorted in the ascending order of the unique identifier. We need to check, if the smaller unique index has the lexicographically smaller color of the two fabrics, or not. If yes, then the fabrics in _Ad_ will be in the same order as _Ch_, and the answer is 2; otherwise the answer is 0.

If the two fabrics have different colors and durabilities and if the less durable fabric also has the lexicographically smaller color, then in both _Ad_ and _Ch_, the sorted array will have the same order of fabrics, and the answer will be 2. If that is not the case, the answer is 0.

In all of the approaches discussed above, the time complexity is _O(1)_, which is sufficient for Test Set 1.

Test Set 2
---
We can create two instances of the fabric array, and sort one of them to create _Ad_, and another one to create _Ch_. Now, we can compare the two arrays, and the number of fabrics that have the same index in both of them is the required answer.

Here, the time complexity of sorting by ascending durability is _O_(**N** log **N**), and the time complexity of sorting by ascending color is _O_(**N** log **N** × max|**Ci**|). Running a loop over _Ad_ and _Ch_ is _O_(**N**). So, the total time complexity is _O_(**N** log **N** × max|**Ci**|), which is sufficient for Test Set 2.