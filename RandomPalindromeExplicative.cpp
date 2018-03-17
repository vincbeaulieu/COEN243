# COEN243
Random Palindrome

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

//This is how I have solve this assignment problem.

//First, I always include manually a bunch of library before my code.
//Also, this is a ways to learn them easly so you don't freak out at the midterm because you forgot their names.

#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;


//Here is the prototypes of the functions I have created for this problem.

void limit(int,int,int);
bool Palindrome(int,int,int);
void Random_Palindrome(int);


int main() {
    int exit_key = 0;
    while(exit_key != -1){                                                                              		//I have create a loop to facilitate debugging.
		cout << "Try to generate a palindrome! \nPlease enter the length of a number (between 0 and 9): ";  	//I have accommodate the sentence of the problem example to make it more user-friendly.
		int N;                                                                                              	//Initializing the amount of digits should contain the number.
		cin >> N;
		Random_Palindrome(N);
		cout << "enter any number except -1 to try again, else to quit" << endl;                            	//Request to close the debugging loop.
		cin >> exit_key;
    }
}

//I always separate my function by section to keep a good organization and ease debugging.

//The limit function here is to put a boundary when you "generates N random digits (numbers between 0 and 9)".

void limit(int input, int a, int b){
    if(input < a || input > b){
        if(input < a) input = a;
        if(input > b) input = b;
        cout << "Input out of boundary!" << endl;
        cout << "Input set to " << input << endl;
    }
}


//this is the Palindrome function. I've found it easier to use a recursive structure rather then a iterative structure.

bool Palindrome(int Array[], int m, int n){       //this Palindrome function will use the array (numbers_holders) from the function Random_Palindrome below.
    if(Array[m]!=Array[n]){                       //We check the two ends of the array.
        return false;                             //If they don't contain the same value, it return false and the function end here (base case 1).
    } else if (m>=n) {                            //If the two ends reaches in the middle, or they pass by (in case of a even amount of digits),
        return true;                              //well the function is a palindrome and it return true (base case 2).
    } else {                                      //Recursion utile a base case is achieve.
        Palindrome(Array, m+1, n-1);              //First, Array[m] and Array[n] is check. Then Array[m+1] and Array[n-1] is check. Then Array[m+2] and Array[n-2] is check. And so on...
        return true;                              //Utile a base case is achieve, it's return true.
    }
}


//This is the "main" problem function that call the two functions above. 

void Random_Palindrome(int N){
    limit(N,0,9);                                                               //Setting the limit of the function. limit(input of the amount N of digits of the random number, minimal end, maximal end).
    srand(static_cast<unsigned int>(time(0)));                                  //Generate a seed "using the computer time as the seed of the random number generator".
    int numbers_holders[N-1];                                                   //Initializing the array that will hold each randoms numbers digits generated.
    cout << "The concatenation of the 6 randomly generated numbers is: ";       //Like in the example.
    for(int i=0; i<=(N-1); i++){                                                //Arrays include 0, so N-1 is the last cell of the array.
        
        int Gen = rand();                                                       /*I have initialize "Gen" to a rand() generator in the "for loop", so it generated ever time the loop is looping. 
                                                                                  The following is a hypothesis:
                                                                                  And, by doing this, you avoid generating a other random number during the loop every time you need to use a rand(),
                                                                                  in other word, it reduce the variation of probability and make the probability more accurate.*/

        if(Gen%100 < 80){                                                       /*This make "The probability that a generated digit is even is 80% 
                                                                                  whereas the probability that a generated digit is odd is 20%".*/
            numbers_holders[i] = 2*Gen % 10;                                    //By definition, 2n is the equation of evens numbers.
        } else {
            numbers_holders[i] = (2*Gen % 10)+1;                                //By definition, 2n+1 is the equation of odds numbers.
        }
        cout << numbers_holders[i];                                             //"The concatenation of the "N" randomly generated numbers is: "(The Number Of N Digits Generated)""
    }
    cout << endl;
    
    if(Palindrome(numbers_holders,0,(N-1)) == true){                            //If the Palindrome function return true, then the random number generated is a palindrome, else, its not.
        cout << "The number is a palindrome!" << endl;
    } else {
        cout << "The number is NOT a palindrome!" << endl;
    }
}
