#include <iostream>
#include <iomanip> //this library is needed for setw
using namespace std;

int main () {
  cout << setw (60); //Modify the number to align it to the center
  cout << "Hello"<< endl;  //This outputs Hello towards the middle 
  return 0;
}
