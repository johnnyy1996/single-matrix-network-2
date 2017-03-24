// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>
#include <iostream>

const int maxCycles = 50;

int main(int argc, char* argv[])
{
	//Network wOscillator(1,2,2,"oscillator.txt");
	Network wOscillator("oscillator.txt");
	Network wOscillator2("oscillator2.txt");
	
	int i = 0;
	int currentCycle = 0;
	double Oscillator_input[1];
	while (i < maxCycles) {

		currentCycle += i;
		if (currentCycle % 2 == 0) {

			Oscillator_input[0] = 1.0;
			wOscillator.setNetworkInput(Oscillator_input);
			wOscillator2.setNetworkInput(Oscillator_input);
		}
		else {
			Oscillator_input[0] = 1.0;
			wOscillator.setNetworkInput(Oscillator_input);
			wOscillator2.setNetworkInput(Oscillator_input);
		}

		//squashingFunction(1, 1, -2, 0); 
		/*	
			cycleNetwork also squashes the output by calling the new squashNeuronOutputs() function in network.cpp. 
			To Change the paprameters of the squashing function, edit the squashNeuronOutputs() parameters in the 
			cycleNetwork function definition in Network.cpp	
		*/

		wOscillator.cycleNetwork();
		wOscillator.printNetworkOutputState();
		wOscillator.writeNetworkOutputStateToFile("NEWOscillator_out_9_cont1.txt");

		wOscillator2.cycleNetwork();
		wOscillator2.writeNetworkOutputStateToFile("NEWOscillator_out10_cont1.txt");

		i++;
	}
	
	return 0;

}
