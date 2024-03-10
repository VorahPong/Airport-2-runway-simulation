/****************************************************

Your name:					VorahPong, Mean
Class:						CS 2413 Data Structures
Assignment #:				Project# 2 Airport Runway Control Simulation
Due date:					March. 25, 2024
Instructor:					Chao Zhao
Program Description:		Create two runways for Airport Simulation

****************************************************/

#include <iostream>
#include <queue>
#include <time.h>
#include <stdlib.h>
#include "Runway.h"

int main() {

	//declared needed vars 
	int simulation_length, landing_time, takingOff_time;
	float landing_arrival_rate, takingOff_arrival_rate;
	int next_process_airplane;
	char answer;

	std::queue<int> landing_queue, takeOff_queue;

	int counter;
	

	
	// loop for users interface
	do {
		//Prompts for inputs
		std::cout << "Enter the simulation length:\t\t\t\t";
		std::cin >> simulation_length;
		std::cout << "Enter landing time for an airplane:\t\t\t";
		std::cin >> landing_time;
		std::cout << "Enter taking off time for an airplane:\t\t\t";
		std::cin >> takingOff_time;
		std::cout << "Enter landing arrival rate:\t\t\t\t";
		std::cin >> landing_arrival_rate;
		std::cout << "Enter taking off arrival rate:\t\t\t\t";
		std::cin >> takingOff_arrival_rate;
		std::cout << "\n\n";
		//

		//start the algorithm
		Runway simTest(landing_time, takingOff_time, landing_arrival_rate, takingOff_arrival_rate);
		srand(time(NULL)); //Set seed for random generation

		//loop of airplanes
		for (int current_airplane = 1; current_airplane < simulation_length; current_airplane++) {
			//If airplane is coming for landing then push it into landing queue
			if (simTest.is_airplane_coming_for_landing()) {
				landing_queue.push(current_airplane);
			}
			//If airplane is going to take off then push it into take off queue
			if (simTest.is_airplane_coming_for_takeOff()) {
				takeOff_queue.push(current_airplane);
			}

			//Airplane coming to landing is more important than airplane going to take off
			// 
			//if runway not busy and landing queue is not empty then an airplane can come to land
			if (!simTest.is_landing_runway_busy() && !landing_queue.empty()) {
				next_process_airplane = landing_queue.front();
				landing_queue.pop();
				simTest.sum_landing_time(current_airplane - next_process_airplane);
				simTest.start_landing();
			}
			//if runway not busy and landing queue is empty then an airplane can take off
			if (!simTest.is_takeOff_runway_busy() && !takeOff_queue.empty()) {
				next_process_airplane = takeOff_queue.front();
				takeOff_queue.pop();
				simTest.sum_takeOff_time(current_airplane - next_process_airplane);
				simTest.start_takeOff();
			}

			//Waiting time cool down
			simTest.one_time_unit();
		}

		std::cout << "Number of airplanes were landed:\t\t\t" << simTest.airplane_landed() << "\n";
		std::cout << "Average waiting time for Landing was:\t\t\t" << simTest.average_waiting_time_for_landing() << "\n";
		std::cout << "Number of airplanes were took off:\t\t\t" << simTest.airplane_takeOff() << "\n";
		std::cout << "Average waiting time for taking off was:\t\t" << simTest.average_waiting_time_for_takeOff() << "\n";
		counter = 0;
		while (!landing_queue.empty()) {
			counter++;
			landing_queue.pop();
		}
		std::cout << "Number of airplanes were denied for Landing:\t\t" << counter << "\n";
		counter = 0;
		while (!takeOff_queue.empty()) {
			counter++;
			takeOff_queue.pop();
		}
		std::cout << "Number of airplanes were denied for taking off:\t\t" << counter << "\n\n";
		std::cout << "Would you do it again (y/n):\t";
		std::cin.ignore();
		std::cin >> answer;
		std::cout << "\n\n";


	} while (tolower(answer) != 'n');
	
	std::cout << "Thank for using this program!! Bye.\n";
	//
	//Ended
	return 0;
}

