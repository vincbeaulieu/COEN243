/*
Random Palindrome: Write a function that takes integer N as a parameter. This function then generates N random digits (numbers between 0 and 9) using the computer time as the seed of the random number generator.
The probability that a generated digit is even is 80% whereas the probability that a generated digit is odd is 20%.
The function the concatenates the N randomly created digits to form one number. This function then checks if this number is a palindrome or not. (Hint: find the reverse of that number)
Finally, the function prints out the number and says whether it is a palindrome or not.

Example 1:
Please enter the length of a number: 6
The concatenation of the 6 randomly generated numbers is: 258852
The number is a palindrome!

Example 2:
Please enter the length of a number: 5
The concatenation of the 5 randomly generated numbers is: 86824
The number is NOT a palindrome!
*/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

void limit(int,int,int);
bool Palindrome(int,int,int);
void Random_Palindrome(int);

int main() {
    int exit_key = 0;
    while(exit_key != -1){
		cout << "Try to generate a palindrome! \nPlease enter the length of a number (between 0 and 9): ";
		int N;
		cin >> N;
		Random_Palindrome(N);
		cout << "enter any number except -1 to try again, else to quit" << endl;
		cin >> exit_key;
    }
}

void limit(int input, int a, int b){
    if(input < a || input > b){
        if(input < a) input = a;
        if(input > b) input = b;
        cout << "Input out of boundary!" << endl;
        cout << "Input set to " << input << endl;
    }
}

bool Palindrome(int Array[], int m, int n){
    if(Array[m]!=Array[n]){
        return false;
    } else if (m>=n) {
        return true;
    } else {
        Palindrome(Array, m+1, n-1);
        return true;
    }
}

void Random_Palindrome(int N){
    limit(N,0,9);
    srand(static_cast<unsigned int>(time(0)));
    int numbers_holders[N-1];
    cout << "this is your number : ";
    for(int i=0; i<=(N-1); i++){
        int Gen = rand();
        if(Gen%100 < 80){
            numbers_holders[i] = 2*Gen % 10;
        } else {
            numbers_holders[i] = (2*Gen % 10)+1;
        }
        cout << numbers_holders[i];
    }
    cout << endl;
    
    if(Palindrome(numbers_holders,0,(N-1)) == true){
        cout << "The number is a palindrome!" << endl;
    } else {
        cout << "The number is NOT a palindrome!" << endl;
    }
}