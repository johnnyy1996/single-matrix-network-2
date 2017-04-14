// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
using namespace std;



/*  Added By Roberto Coyotl. 
 *  Creates the specified number of files names and returns them in a vector
 *  Many file are needed to print out data of various different trials.
 *  This function does not fully work

std::vector<char*> CreateVectOfFileName(int i) {
	const int NumOfFile = i;
	std::vector<char*> FileNameVect(NumOfFile);
	for (int j = 0; j < NumOfFile - 1; j++) {
		FileNameVect[j] = "NetOutput.text";
		char fileNumber = j;
		FileNameVect[j].insert(9 ,1 ,fileNumber);
	}
	return FileNameVect;
}
*/
int main(int argc, char* argv[])
{
	double Oscillator_input[1];
	const int maxCycles = 35;
	int currentTrial = 1;
	//Network wOscillator2("oscillator2test.txt");
	
	Parameters parameterSet;// this struct gives us the alpha through delta values

	double alpha = parameterSet.alpha;
	double beta = parameterSet.beta;
	double gamma = parameterSet.gamma;
	double delta = parameterSet.delta;
	double epsilon = parameterSet.epsilon;
	double eta = parameterSet.eta;

	for ( parameterSet.alpha = 0.1000; parameterSet.alpha <= 1.0; parameterSet.alpha += .1000) {
		for (parameterSet.beta = 0.1000; parameterSet.beta <= 1.0; parameterSet.beta += .1000) {
			for (parameterSet.gamma = 0.1000; parameterSet.gamma <= 1.0; parameterSet.gamma += .1000) {
					for (parameterSet.delta = 0.1000; parameterSet.delta <= 1.0; parameterSet.delta += .1000) {
						for (parameterSet.epsilon = -0.1000; parameterSet.epsilon >= -1.0; parameterSet.epsilon -= .1000) {
							parameterSet.eta = parameterSet.epsilon; // I believe that eta must be equal to epslion to oscilate properly
							
							Network wOscillator2("myNewnetwork.txt");
							alpha = parameterSet.alpha;
							beta = parameterSet.beta;
							gamma = parameterSet.gamma;
							delta = parameterSet.delta;
							epsilon = parameterSet.epsilon;
							eta = parameterSet.eta;
							wOscillator2.writeTrialInfo("Network_out.txt", currentTrial);
							parameterSet.writeParametersToFile("Network_out.txt");
							wOscillator2.writeNetworkToFile("myNewnetwork.txt", alpha, beta, gamma, delta, epsilon, eta);
							currentTrial++;

							for (int i = 1; i <= maxCycles; i++) {

								Oscillator_input[0] = 1.00;
								wOscillator2.setNetworkInput(Oscillator_input);
								wOscillator2.cycleNetwork();
								//wOscillator2.printNetworkOutputState();
								//wOscillator2.writeNetworkOuputToFile("Net_out2.xlsx");
								wOscillator2.writeNetworkOutputStateToFile("Network_out.txt");
								//wOscillator2.writeNetworkOuputToFile("Network_out.xlsx");
							}
					}
				}
			}
		}
	}
}
					
/*
This following maxtrix will oscillate		This should be the general format for matrix generates a wilson oscillater
0	 0	 0	 .5	 .5							0	0		0		alpha		alpha
0	.5	 0	-.8	  0							0	beta	0		-epsilon	0
0	 0	.5	  0	-.8							0	0		beta	0			-epsilon
0	.3	 0	 .5	-.8							0	delta	0		gamma		-eta
0	 0	.3	-.8	 .5							0	0		delta	-eta		gamma
**** The first the network activation of the first input(alpha) nueron
should be set a tiny bit higher than the second alpha. Otherwise,
with the same input, the two motor neurons will level out and not
oscillate


int currentCycle = 0;
while (currentCycle <= maxCycles) {

if (currentCycle == 1) {

Oscillator_input[0] = 1;
wOscillator2.setNetworkInput(Oscillator_input);
}
else {
Oscillator_input[0] = 1;
wOscillator2.setNetworkInput(Oscillator_input);
}
wOscillator2.cycleNetwork();
wOscillator2.printNetworkOutputState();
wOscillator2.writeNetworkOutputStateToFile("Net_out.xlsx");
wOscillator2.writeNetworkOutputStateToFile("Net_out.txt");
currentCycle++;

}



/*  This process is meant to cycle through all possible paramter combinations.
*	It produces a massive ammount fd data, even though it only outputs the output neurons of your net.
*  It would be best to output every trial into a seperate file. This would produce a LOT of files.
*  *Currently does not change the network values for every trial. I need to figure out how to get into the file and alter the mtrix for each trial.
*/

	