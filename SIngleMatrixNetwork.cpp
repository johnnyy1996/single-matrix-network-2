// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

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
	const int maxCycles = 50;
	Network wOscillator2("oscillator2.txt");

	/*
	This following maxtrix will oscillate		This should be the general format for matrix generates a wilson oscillater
	0	 0	 0	 .5	 .5							0	0		0		alpha		alpha
	0	.5	 0	-.8	  0							0	beta	0		-epsilon	0	
	0	 0	.5	  0	-.8							0	0		beta	0			-epsilon
	0	.3	 0	 .5	-.8							0	-delta	0		gamma		eta
	0	 0	.3	-.8	 .5							0	0		-delta	eta			gamma
												**** The first the network activation of the first input(alpha) nueron
													 should be set a tiny bit higher than the second alpha. Otherwise,
													 with the same input, the two motor neurons will level out and not
													 oscillate
	*/

	int currentCycle = 0;
	while (currentCycle <= maxCycles) {
	
		if (currentCycle == 1) {

			Oscillator_input[0] = 1;
			wOscillator2.setNetworkInput(Oscillator_input);
		}
		else {
			Oscillator_input[0] = 0;
			wOscillator2.setNetworkInput(Oscillator_input);
		}
		wOscillator2.cycleNetwork();
		wOscillator2.printNetworkOutputState();
		wOscillator2.writeNetworkOuputToFile("Net_out.xlsx");
		wOscillator2.writeNetworkOutputStateToFile("Net_out.txt");

	}



	/*  This process is meant to cycle through all possible paramter combinations.
	 *	It produces a massive ammount fd data, even though it only outputs the output neurons of your net.
	 *  It would be best to output every trial into a seperate file. This would produce a LOT of files.
	 *  *Currently does not change the network values for every trial. I need to figure out how to get into the file and alter the mtrix for each trial.
 	double Oscillator_input[1];
	const int maxCycles = 50;
	//for (float alpha = 0.1; alpha <= 1.0; alpha += .10) {
		for (float beta = 0.0; beta <= 1.0; beta += .50) {
			for (float gamma = 0.0; gamma <= 1.0; gamma += .50) {
				for (float zeta = 0.0; zeta <= 1.0; zeta += .50) {
					for (float delta = -0.0; delta >= -1.0; delta -= .50) {
						for (float epsilon = -0.0; epsilon >= -1.0; epsilon -= .50) {

							Network wOscillator2("oscillator2.txt");
							for (int i = 1; i <= maxCycles; i++) {

								Oscillator_input[0] = 1;
								wOscillator2.setNetworkInput(Oscillator_input);
								wOscillator2.cycleNetwork();
								//wOscillator2.printNetworkOutputState();
								wOscillator2.writeNetworkOuputToFile("Net_out2.xlsx");
								//wOscillator2.writeNetworkOutputStateToFile("Net_out2.xlsx");
								//wOscillator2.writeNetworkOutputStateToFile("Net_out.txt");
							}
						}
					}
				}
			}
		}
	}
	*/
}


					
	
	