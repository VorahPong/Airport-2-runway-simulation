/****************************************************

Your name:					VorahPong, Mean
Class:						CS 2413 Data Structures
Assignment #:				Project# 2 Airport Runway Control Simulation
Due date:					March. 25, 2024
Instructor:					Chao Zhao
Program Description:		Create two runways for Airport Simulation

****************************************************/

#pragma once

//declare class
class Runway {

public:
	//declare functions and constructor
	Runway(int, int, float, float);

	bool is_airplane_coming_for_landing();		//random generate the spawn of airplane coming to landing
	bool is_airplane_coming_for_takeOff();		//random generate the spawn of airplane going to take off
	bool is_landing();							//Check if landing time is still on waiting
	bool is_takeOff();							//Check if take off time is still on waiting
	void one_time_unit();						//Time cooldown for landing and take off
	bool is_landing_runway_busy();				//check if the landing runway is busy
	bool is_takeOff_runway_busy();				//check if the landing runway is busy
	void start_landing();						//start landing
	void start_takeOff();						//start taking off
	void sum_landing_time(int);					//Increase the counter of landing
	void sum_takeOff_time(int);					//Increase the counter of take off
	int airplane_landed();						//Return the number of airplane that landed
	int airplane_takeOff();						//Return the number of airplane that took off
	float average_waiting_time_for_landing();	//Return the average waiting time for landing
	float average_waiting_time_for_takeOff();	//Return the average waiting time for take off



private:
	//declare needed vars;
	float landing_arrival_rate; //rate of coming landing
	float takeOff_arrival_rate; //rate of coming takeOff
	int total_time_landing;		//store total time for landing
	int total_time_takeOff;		//store total time for take off
	int landing_time;			//store time used for landing
	int takeOff_time;			//store time used for taking off
	int landing_time_left;		//store time left for landing
	int takeOff_time_left;		//store time left for take off
	int takeOff_counter;		//store the number of took off
	int landing_counter;		//store the number of landed

};