/*
Polycarp loves ciphers. He has invented his own cipher called Right-Left.
Right-Left cipher is used for strings. To encrypt the string s=s1s2…sn
Polycarp uses the following algorithm:

1.He writes down s1
2.He appends the current word with s2(i.e. writes down s2 to the right of the current result)
3.he prepends the current word with s3(i.e. writes down s3 to the left of the current result)
4.He appends the current word with s4(i.e. writes down s4 to the right of the current result)
5.He prepends the current word with s5(i.e. writes down s5 to the left of the current result)
  and so on for each position until the end of s. 

For example, if s="techno" the process is: "t" → "te" → "cte" → "cteh" → "ncteh" → "ncteho". 
So the encrypted s="techno" is "ncteho".

Given string t— the result of encryption of some string s. 
Your task is to decrypt it, i.e. find the string s.

Input:
The only line of the input contains t— the result of encryption of some string s. 
It contains only lowercase Latin letters. The length of t is between 1 and 50, inclusive.

Output:
Print such string sthat after encryption it equals t.
*/


#include <bits/stdc++.h>
#include <stack>
using namespace std;

int main() {
    string t;
    cin >> t;
    int n = t.length();
    if(n < 3) {
        cout << t;
    }
    else {
        stack <char> s;
        int x = 0 , y = n-1;
        while(n > 0) {
            if((n-1) % 2 == 0) {
                s.push(t[x]);
                x++;
            }
            else {
                s.push(t[y]);
                y--;
            }
            n--;
        }
        while(!s.empty()) {
            cout << s.top();
            s.pop(); 
        }
    }
    return 0;
}