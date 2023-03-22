#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;

   int from = 0, to = 0, candidate = 1, move = 0;

   for(int i = n + 1; i >= 1; --i)
   t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);

   if(n%2 == 1){
        to = 1;
   while (t[1].size() < n+1) { 
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

      t[to].push_back(t[from].back());
      t[from].pop_back();

      if (t[(to+1)%3].back() < t[(to+2)%3].back())
         from = (to+1)%3;
      else
         from = (to+2)%3;

      candidate = t[from].back();

      if (t[from].back() < t[(from+1)%3].back())
         to = (from+1)%3;
      else
         to = (from+2)%3;
   }
   }

   if(n%2 == 0){
        to = 2;
   while (t[1].size() < n+1) { 
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";

      t[to].push_back(t[from].back());
      t[from].pop_back();

      if (t[(to+2)%3].back() < t[(to+1)%3].back())
         from = (to+2)%3;
      else
         from = (to+1)%3;

      candidate = t[from].back();

      if (t[(from+2)%3].back() < t[from].back())
         to = (from+1)%3;
      else
         to = (from+2)%3;
   }
   }

   return 0;
}