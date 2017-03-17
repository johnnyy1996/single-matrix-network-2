// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.
//
#include<iostream>
#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>

using namespace std;

const int maxCycles = 10;

int main(int argc, char* argv[])
{
	Network Khepera(2, 0, 2, "Kruzel.txt");

	int i = 0;
	double input[2];

	while (i < maxCycles) {
		
		input[0] = 0; //left input
		input[1] = .5; //right input
		
		Khepera.setNetworkInput(input);
		Khepera.cycleNetwork();
		Khepera.writeNetworkSquashedOutputStateToFile("KheperaOUTPUTSquashed.txt");
		Khepera.printNetworkOutputState();
		Khepera.writeNetworkOutputStateToFile("Khepera_out.txt");
		i++;
	}
	
	return 0;

}