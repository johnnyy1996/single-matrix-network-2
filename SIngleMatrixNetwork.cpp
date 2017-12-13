// SIngleMatrixNetwork.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Network.h"
#include <math.h>
#include <stdio.h>

const int NUMBER_OF_INPUTS = 10; //number of inputs in network
const int MAX_TIME_STEP = 1000; //number of time steps
const int INPUT_SIZE = NUMBER_OF_INPUTS * MAX_TIME_STEP; //number of total inputs in simulation

int main(int argc, char* argv[])
{
	Network obstacle_avoidance("AvoidanceNet.txt"); //create network with parameters from file

	int time_step = 0; //time step starts at 0
	double *environment;	//declare variable to hold pointer of simulation input array
	double input[NUMBER_OF_INPUTS]; //initializes input array
	environment = new double[INPUT_SIZE]; //initializes file input array
	
	obstacle_avoidance.readInputFromFile("Avoidance_Input.txt", environment, INPUT_SIZE); //reads input from file

	while (time_step < MAX_TIME_STEP) {
		//obstacle_avoidance.cycleNetworkNormalizeHebbianLearning(); //apply plastic weights and learning rates to neurons
		obstacle_avoidance.cycleNetwork(); //perform calculations 
		obstacle_avoidance.printNetworkOutputState(); //print output to console
		obstacle_avoidance.writeNetworkOutputStateToFile("Avoidance_Net_Output.txt"); //write output to file

		for (int i = 0; i < NUMBER_OF_INPUTS; ++i)
			input[i] = environment[NUMBER_OF_INPUTS * time_step + i]; //set input weights for time step
		obstacle_avoidance.setNetworkInput(input); //set network inputs for that time step

		++time_step; //increment time step
	}
	return 0;
}

