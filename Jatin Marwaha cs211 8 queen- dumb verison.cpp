
#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[][8]) {
    for (int c = 7; c>0; c--){
		int r = 0;
		while (q[r][c] != 1) {
			r++;				
		}
		
		int i;
   for (int i = 0; i < c; i++){                    
      if (q[r][i] == 1)
				return false;
			}
		
   for (int i = 1; r - i >= 0 and c - i >= 0; i++)
      if (q[r-i][c-i] == 1) {
				return false;
			}
		
   for (int i = 1; r + i < 8 && c - i >= 0; i++)  
      if (q[r+i][c-i] == 1) {
				return false;
			}
		
	}
		return true; 
}


void print(int q[][8]){
   static int numSolutions = 1;
cout << "Solution #" << numSolutions++ << ":\n";
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j){
			cout << q[i][j];
            }
            cout<<endl;
        }
cout <<endl;
       
   }


int main() {
	int q[8][8] = {};
	
	for (int i0 = 0; i0 < 8; ++i0)
		for (int i1 = 0; i1 < 8; ++i1)
			for (int i2 = 0; i2 < 8; ++i2)
				for (int i3 = 0; i3 < 8; ++i3)
					for (int i4 = 0; i4 < 8; ++i4)
						for (int i5 = 0; i5 < 8; ++i5)
							for (int i6 = 0; i6 < 8; ++i6)
								for (int i7 = 0; i7 < 8; ++i7) {
								
									q[i0][0] = 1; 
									q[i1][1] = 1;			 
									q[i2][2] = 1;			 
									q[i3][3] = 1;
									q[i4][4] = 1;
									q[i5][5] = 1;
									q[i6][6] = 1;
									q[i7][7] = 1;

									if (ok(q)) {
										print(q);	
									}
									q[i0][0] = 0;
									q[i1][1] = 0;
									q[i2][2] = 0;
									q[i3][3] = 0;
									q[i4][4] = 0;
									q[i5][5] = 0;
									q[i6][6] = 0;
									q[i7][7] = 0;
									
								}
	return 0;}
