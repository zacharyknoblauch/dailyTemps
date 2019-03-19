/*
*
*  Program: dailyTemps.cc
*  Name: Zachary Knoblauch
*  Date: 19/March/2019
*  Description: Program opens data file and reads all numbers into an array.
*               The calculation function checks for a higher/lower number than the previous
*               The calculation function finds lowest low and highest high as well as adding all numbers to get an average
*               The main then finishes the average calculation and outputs the results to the monitor
*
*/

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void getNumbers(int &highest, int &lowest, double &average, int dailyLow[]);

int main(){//main function

  int dailyLow[30];

  ifstream read;
  read.open("athens_low_temps.txt");//opens file
  if(read.fail()){//checks to make sure file opened successfully
    exit(1);//if it didn't open, exit the program before bad things happen
  }
  for(int i = 0; i < 30; i++){//fills array with data from file
    read >> dailyLow[i];
  }
  read.close();//closes file

  int highest = -10000000;//guarantees that a realistic temperature will replace this number immediately for highest low
  int lowest = 10000000;//guarantee that a realistic temperature will replace this number immediately for lowest lowest
  double average = 0.0;//average of all temperatures

  getNumbers(highest, lowest, average, dailyLow);//calls the calculation function

  average = average / 30.0;//completes the average calculation

  cout << "The highest low for the first 30 days of 2019 is " << highest << endl;//output results
  cout << "The lowest low for the first 30 days of 2019 is " << lowest << endl;//output results
  cout << "The average low for the first 30 days of 2019 is " << average << endl;//output results

  return 0;//end of the program
}

void getNumbers(int &highest, int &lowest, double &average, int dailyLow[]){//calculation function
  for(int i = 0; i < 30; i++){
    if(dailyLow[i] > highest){//checks if the number in the ith place in the array is bigger than the previous
      highest = dailyLow[i];//if so, replace that number with the current number
    }
    if(dailyLow[i] < lowest){//checks if the number in the ith place in the array is smaller than the previous
      lowest = dailyLow[i];//if so, replace that number with the current number
    }
    average += dailyLow[i];//adds all numbers in the array together
  }
}
