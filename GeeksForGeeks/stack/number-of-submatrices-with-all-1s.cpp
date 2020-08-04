/*
Algorithm:

1. Initialize a stack ‘q’ to store the value of the elements getting pushed along with the count(Cij) of the number of elements that were pushed in this 
stack with a value strictly greater than the value of the current element. We will use a pair to tie up the two data together.
Initialize a variable ‘to_sum’ with 0. At each step, this variable is updated to store the number of submatrices with all 1s starting 
from the element being pushed at that step. Thus, using ‘to_sum’, we update the count of number of submatrices with all 1s at each step.

2. For a column ‘j’, at any step ‘i’, we will prepare to push p_arr[i][j] in the stack. Let Qt represent the topmost element of the 
stack and Ct represent the number of elements previously pushed in the stack with a value greater than the top-most element of the stack. 
Before pushing an element ‘p_arr[i][j]’ in the stack, while the stack is not empty or topmost element is greater than the number to be pushed, 
keep popping the topmost element of the stack and at the same time update to_sum as to_sum += (Ct + 1) * (Qt – p_arr[i][j]). Let Ci, jrepresent the 
number of elements greater than the current element that were pushed in this stack previously. We also need to keep a track of Ci, j. 
Thus, before popping an element, we update Ci, j as Ci, j += Ct along with to_sum.

3. We update the answer as ans += to_sum.

4. Finally, we push that element in the stack after pairing it with Ci, j.
*/

// C++ program to count number of 
// sub-matrices with all 1s 

#include <iostream> 
#include <stack> 

using namespace std; 

#define n 3 

// Function to find required prefix-count for 
// each row from right to left 
void findPrefixCount(int p_arr[][n], bool arr[][n]) 
{ 
	for (int i = 0; i < n; i++) { 
		for (int j = n - 1; j >= 0; j--) { 

			if (!arr[i][j]) 
				continue; 

			if (j != n - 1) 
				p_arr[i][j] += p_arr[i][j + 1]; 

			p_arr[i][j] += (int)arr[i][j]; 
		} 
	} 
} 

// Function to count the number of 
// sub-matrices with all 1s 
int matrixAllOne(bool arr[][n]) 
{ 
	// Array to store required prefix count of 
	// 1s from right to left for boolean array 
	int p_arr[n][n] = { 0 }; 

	findPrefixCount(p_arr, arr); 

	// variable to store the final answer 
	int ans = 0; 

	/* Loop to evaluate each column of 
		the prefix matrix uniquely. 
		For each index of a column we will try to 
		determine the number of sub-matrices 
		starting from that index 
		and has all 1s */
	for (int j = 0; j < n; j++) { 

		int i = n - 1; 

		/* Stack to store elements and the count 
			of the numbers they popped 
			
			First part of pair will be the 
			value of inserted element. 
			Second part will be the count 
			of the number of elements pushed 
			before with a greater value */
		stack<pair<int, int> > q; 

		// variable to store the number of 
		// submatrices with all 1s 
		int to_sum = 0; 

		while (i >= 0) { 

			int c = 0; 

			while (q.size() != 0 and q.top().first > p_arr[i][j]) { 

				to_sum -= (q.top().second + 1) * 
							(q.top().first - p_arr[i][j]); 

				c += q.top().second + 1; 
				q.pop(); 
			} 

			to_sum += p_arr[i][j]; 

			ans += to_sum; 

			q.push({ p_arr[i][j], c }); 

			i--; 
		} 
	} 

	return ans; 
} 

// Driver Code 
int main() 
{ 
	bool arr[][n] = { { 1, 1, 0 }, 
					{ 1, 0, 1 }, 
					{ 0, 1, 1 } }; 

	cout << matrixAllOne(arr); 

	return 0; 
} 
