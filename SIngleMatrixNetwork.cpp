// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	Network khepera("Ian_Test_Network_Changing_Inputs.txt"); //Ian_Test_Network_Equal_Vary_Inputs.txt

	int i = 0;
	double input[7];
	while (i < 710) {

		khepera.cycleNetwork();
		khepera.printNetworkOutputState();

		khepera.writeNetworkOutputStateToFile("Ian_Changing_Inputs_Output_v7.txt");

		/*
		if (i >= 201) {
			input[0] = input[1] = input[2] = i - 200;
			input[3] = input[4] = input[5] = 455 - input[0];
			input[6] = 1;
			khepera.setNetworkInput(input);
		}
		if (i >= 456) {
			input[0] = input[1] = input[2] = 455 - input[0];
			input[3] = input[4] = input[5] = i - 200;
			input[6] = 1;
			khepera.setNetworkInput(input);
		}
		*/
		
		
		if (i >= 200) {
			input[0] = input[1] = input[2] = 1.0;
			input[3] = input[4] = input[5] = 0.5;
			khepera.setNetworkInput(input);
		}

		if (i >= 400) {
			input[0] = input[1] = input[2] = 0.5;
			input[3] = input[4] = input[5] = 1.0;
			khepera.setNetworkInput(input);
		}
		++i;
	}	

	return 0;

}
