#include <bits/stdc++.h>
using namespace std; 
#include <string.h>

int lcs(string s1, string s2)
{		
        int m = s1.length();
        int n = s2.length();
        int c[m + 1][n + 1];
		int stm[m+1][n+1];						//for getting initial string
		
		for (int i = 0; i <= m; i++) 
		{
                c[i][0] = 0;					//Initializing the first row and the first column of the matrix LCS to 0
        }
        for (int j = 0; j <= n; j++) 
		{
                c[0][j] = 0;
        }
		for (int i = 1; i <= m; i++) {		
			for (int j = 1; j <= n; j++) {
				if (s1[i-1] == s2[j-1]){ 				//if Xi == Yi
					c[i][j] = c[i - 1][j - 1] + 1; 	
					stm[i][j] = 999;					// for decoding the string while printing
				}
  
				else if(c[i - 1][j] >= c[i][j - 1]){		// MAX of [(i-1),j] & [i,(j-1)]
					c[i][j] = c[i - 1][j];
					stm[i][j] = 222;					// for decoding the string while printing
				}
				else{
					c[i][j] = c[i][j - 1];
					stm[i][j] = 666;					// for decoding the string while printing
					}
			}
		}
		int l = 0;
		char lcs[l];				//intializing array lcs to store string that matches
		int i = m, j = n; 
	while (i > 0 && j > 0) 
	{ 
       if (stm[i][j] == 999) 			//Checking if the string matched and puts in array lcs
      { 
		  lcs[l] = s1[i-1];  
          i--; j--;
		   l++; 
      } 
  
    
      else if (stm[i][j] == 222) 
         i--; 
      else if(stm[i][j] == 666)
         j--; 
   } 
	
	cout <<"Matching String is: ";		
	for(i=l-1;i>=0;--i)
	{
		cout <<lcs[i];					// Prints string that matches from array lcs
	}
	
	
	return c[m][n]; 
} 


int main(int argc, char** argv) 
{ 
    string X = argv[1]; 			// input 1
    string Y = argv[2]; 			// input 2
	int j = lcs(X, Y);				// get value of length of LCS
	cout << " and its length is: " << j << endl;   //prints lenght
  
    return 0; 
} 