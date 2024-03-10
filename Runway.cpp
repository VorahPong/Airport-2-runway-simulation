/****************************************************

Your name:					VorahPong, Mean
Class:						CS 2413 Data Structures
Assignment #:				Project# 2 Airport Runway Control Simulation
Due date:					March. 25, 2024
Instructor:					Chao Zhao
Program Description:		Create two runways for Airport Simulation

****************************************************/

#include "Runway.h"
#include <cstdlib>

//default constructor
Runway::Runway(int landTime, int takeOffTime, float landRate, float takeOffRate) {
	this->landing_time = landTime;
	this->takeOff_time = takeOffTime;
	this->landing_arrival_rate = landRate;
	this->takeOff_arrival_rate = takeOffRate;

	total_time_landing = 0;
	total_time_takeOff = 0;
	landing_time_left = 0;
	takeOff_time_left = 0;
	takeOff_counter = 0;
	landing_counter = 0;
}

//generate the spawn of airplane coming to landing
bool Runway::is_airplane_coming_for_landing() {
	return (float)rand() / RAND_MAX < landing_arrival_rate;
}

//generate the spawn of airplane going to take off
bool Runway::is_airplane_coming_for_takeOff() {
	return (float)rand() / RAND_MAX < takeOff_arrival_rate;
}

//check if landing runway busy
bool Runway::is_landing_runway_busy() {
	if (landing_time_left > 0) {
		return true;
	}
	return false;
}

//check if take off runway busy
bool Runway::is_takeOff_runway_busy() {
	if (takeOff_time_left > 0) {
		return true;
	}
	return false;
}

//Increase the counter of landing and add time;
void Runway::sum_landing_time(int value) {
	landing_counter++;
	total_time_landing += value;
}

//Increase the counter of take off and add time;
void Runway::sum_takeOff_time(int value) {
	takeOff_counter++;
	total_time_takeOff += value;
}

//if runway is not busy then start landing
void Runway::start_landing() {
	if (!is_landing_runway_busy()) {
		landing_time_left = landing_time;
	}
}

//if runway is not busy then start take off
void Runway::start_takeOff() {
	if (!is_takeOff_runway_busy()) {
		takeOff_time_left = takeOff_time;
	}
}

//Time cooldown for landing and take off
void Runway::one_time_unit() {
	if (is_landing()) {
		landing_time_left--;
	}
	if (is_takeOff()) {
		takeOff_time_left--;
	}
}

//Check if landing time is still on waiting
bool Runway::is_landing() {
	return landing_time_left > 0;
}

//Check if take off time is still on waiting
bool Runway::is_takeOff() {
	return takeOff_time_left > 0;
}

//Return the number of airplane that landed
int Runway::airplane_landed() {
	return landing_counter;
}

//Return the number of airplane that took off
int Runway::airplane_takeOff() {
	return takeOff_counter;
}

//Return the average waiting time for landing
float Runway::average_waiting_time_for_landing() {
	if (landing_counter > 0) {
		return total_time_landing / landing_counter;
	}
}

//Return the average waiting time for take off
float Runway::average_waiting_time_for_takeOff() {
	if (takeOff_counter > 0) {
		return total_time_takeOff / takeOff_counter;
	}
}
