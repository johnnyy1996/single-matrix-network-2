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
	/*
		Network xor(2, 2, 1, "xor.txt"); // creates your desired network and prints it to a file
		Network xor("xor.txt"); // uses your created network

		double Xor_input[2];

		Xor_input[0] = Xor_input[1] = 0.0;
		xor.setNetworkInput(Xor_input);

		xor.cycleNetwork();
		xor.printNetworkOutputState();
		xor.writeNetworkOutputStateToFile("xor_out.txt");
	*/


	//Network wOscillator(1,2,2,"oscillator.txt");
	Network wOscillator("oscillator.txt");
	Network wOscillator2("oscillator2.txt");
	
	int i = 0;
	int currentCycle = 0;
	double Oscillator_input[1];
	while (i < maxCycles) {

		currentCycle += i;
	//	if (currentCycle % 2 == 0) {

			Oscillator_input[0] = 1.0;
			wOscillator.setNetworkInput(Oscillator_input);
			wOscillator2.setNetworkInput(Oscillator_input);
	//	}
		/*else {
			Oscillator_input[0] = 0.0;
			wOscillator.setNetworkInput(Oscillator_input);
			wOscillator2.setNetworkInput(Oscillator_input);
		}*/

		//squashingFunction(1, 1, -2, 0); 
		/*	
			cycleNetwork also squashes the output by calling the new squashNeuronOutputs() function in network.cpp. 
			To Change the paprameters of the squashing function, edit the squashNeuronOutputs() parameters in the 
			cycleNetwork function definition in Network.cpp	
		*/

		wOscillator.cycleNetwork();
		wOscillator.printNetworkOutputState();
		//std::cout << "Current Cycle: " << currentCycle << std::endl;
		wOscillator.writeNetworkOutputStateToFile("Oscillator_out3.txt", currentCycle);

		wOscillator2.cycleNetwork();
		//wOscillator2.printNetworkOutputState();
		wOscillator2.writeNetworkOutputStateToFile("Oscillator_out4.txt", currentCycle);

		i++;
	}
	
	return 0;

}
