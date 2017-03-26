#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	
   // TODO add Markov vector - Matrix multiplication

	std::vector<double> probvec; //Prob. of finishing on the nth roll. MODAL****
	double lastprob = 0; //Pr of the game finishing on the previous roll.
	for (int j = 0; j < ROLLS; j++) //Loops the #o f ROLLS
	{
		v.setZero(); //reset the vec 
		v(0) = 1.0; //reset the vec
		for (int i = 0; i < j; i++) //a loop for calcuating the pr of landing on a square after J rolls
			v = v.transpose() * TransitionMatrix; // ""
		probvec.push_back(v[size - 1] - lastprob); //Pass: the pr of end game(size-1) - the pr of the game being over on the previous roll(lastprob)
		lastprob = v[size - 1]; //is the game over on this roll?. (fruit)Loops.
	}

	std::cout <<  v << std::endl;


	for (int j = 0; j < ROLLS; j++)
	{
		myfile << probvec[j] << std::endl;
	}

	int x; std::cin >> x;
	//myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats
	
	myfile.close();


  return 1;
}