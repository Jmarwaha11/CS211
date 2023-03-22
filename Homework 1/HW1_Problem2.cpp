#include <iostream>
using namespace std;

bool checkPrime(int n) {
    // Flag to store if number is prime or not
    // True for prime, else False
    bool flag = true;
    int i;
    
    if(n >= 1) {
       
        // Check for factors
          for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }
    }
    // If number less than 1, it's not prime
    else {
        flag = false;
    }
    return flag;
}

int main() {
    int n;
    cin >> n;
    cout <<"below are the prime numbers from 1 to the number you entered"<<endl;
    // check for numbers from 1 to n
    for(int i=1; i<=n; i++) {
        if(checkPrime(i)) {
            cout<<i<<" ";
        }
    }
    cout <<endl;
    return 0;
}
