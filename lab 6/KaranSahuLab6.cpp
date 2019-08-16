// Author:  Karan Sahu
// Assignment Number: Lab 6
// File Name: KaranSahuLab6.cpp
// Course/Section: COSC 1337 Section 003
// Due Date:  7/20/2018
// Instructor: Bernard Ku
//

/*------------------------------
* Program Lab6
* This program sort score values(array in the dynamic memory)
* using STL Sort and finds the average.
* 04/13/2018
*/
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Function prototypes
double getAverage (const double*, int);
void show(const double*, int);

int main()
{
   int numScores;   // Number of scores
   double *scores = nullptr; // Holds the dynamically allocate scores
   double average = 0.0; // Holds the average of scores 
   
   // Get number of scores
   cout << "Enter number of Scores: ";
   cin >> numScores;    
   
   //Dynamically allocate an array large enough
   // to hold that score values
   scores = new double[numScores];  // Allocate memory
   double *p = scores;

	// Get the score value
	cout << "Enter the "<< numScores << " scores separated by spaces:" << endl;
	int day =0;
	int negative =0;
	do {
			if(day == 0){
				negative =0;
				cin.clear();
				cin.ignore(10,'\n');
			}
			cin >> *p;
			
			// Negative score not allowed
			while(*p < 0)
			{
			cout << "Error! Negative numbers for test scores are not accepted. " << endl;
			cout << "Enter the scores " << endl;
			day=0;
			p=nullptr;
			delete [] scores;
			scores = nullptr;
			scores = new double[numScores];
			p = scores;
			negative = 1;
			}
			if(*p > 0 && negative != 1){
			day++;
			p++;
			}
			
	}while(day < numScores);

	p=scores;
	
	//Print the scores entered by user
	cout << "Scores entered:\n";
	for (int count = 0; count < numScores; count++)
   	{
       cout << *(p+count) << "  ";
   	}
	
	//Get average of scores using pointer
	average = getAverage(p, numScores);
	
	//STL sort function to sort the scores
	sort(p,p+numScores);
	
	 //STL sort display
    show(p,numScores);

	// Display results
    cout << fixed << showpoint << setprecision(1);
   
   // Print lowest of all sales
   cout << "\nThe average is: " << setw(3) << average  << endl;
	
	// Free dynamically allocated memory
   delete [] scores;
   scores = nullptr;
   
   return 0;
}

//
/*************************************************************
 *                        getAverage                       
 * This function is called to find the lowest of all sales 
 * using pointer instead of array
 *************************************************************/

double getAverage(const double *p, int numScores)
{
	double average =0.0;
	double sum =0.0;

	for (int count = 0; count < numScores; count++)
	{		
			sum += *p;
			p++;
	}
	average = sum/numScores;
	return average;
}

//
/*************************************************************
 *                        show                       
 * This function is called display the values in the array
 *************************************************************/

void show(const double *p, int numScores){
	cout << "\nThe list of sorted scores is: \n" ;
	for (int count = 0; count < numScores; count++)
	{		
		cout << *(p+count) << "  ";
	}
}


/* SAMPLE OUTPUT
Enter number of Scores: 5
Enter the 5 scores separated by spaces:
30 40 20 70 100
Scores entered:
30  40  20  70  100
The list of sorted scores is:
20  30  40  70  100
The average is: 52.0


*/
