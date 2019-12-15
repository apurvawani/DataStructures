/*Given a binary number, write a program that prints 1 if given binary number is a multiple of 3. Else prints 0. 
The given number can be big upto 2^100. It is recommended to finish the task using one traversal of input binary string.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string containing 0's and 1's.

Output:
For each test case, output a 1 if string is multiple of 3, else 0.

Constraints:
1<=T<=100
1<=Length of Input String<=100

Example:
Input:
2
011
100

Output:
1
0
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
        string s;
        cin >> s;
        int len = s.length() , sum = 0;
        for(int i = 0 ; i < len ; i++) {
            if(s[len-i-1] == '1') {
                if(i % 2 == 0)
                    sum += 1;
                else
                    sum += 2;
            }
            sum = sum % 3;
        }
        if(sum % 3 == 0)
            cout << "1" << endl;
	    else 
	        cout << "0" << endl;
	}
	return 0;
}
