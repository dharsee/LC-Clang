/*
This is a C program to calculate Angle between hour hand and minute hand in the analogues clock
This is based on the mathematical proof given in the below wiki pedia
https://en.wikipedia.org/wiki/Clock_angle_problem

A method to solve such problems is to consider the rate of change of the angle in degrees per minute. 
The hour hand of a normal 12-hour analogue clock turns 360° in 12 hours (720 minutes) or 0.5° per minute. 
The minute hand rotates through 360° in 60 minutes or 6° per minute.[1]

Equation for the angle of the hour hand
hour_angle = 0.5 * (hour * 60 + minutes) = 720 minutes in 1 hour , means 0.5 degrees in 1 minute

Equation for the angle of the minute hand
minute_angle = 6 * minutes; Since each minute will repesent 6 degree in the clock of 360 degrees

finding diff = abs(hour_angle - minute_angle)

There are two possible angle in the circle (x, y) where x+y = 360 degree

ans = min(36-diff, diff); //take the min of diff and rest in the circle
*/

#include <stdio.h>

int main()
{
	int hour, minute;
	
	// Expect hour and minute input to this program
	// For now, we are using constants
	
	hour = 2;
	minute = 20;
	
	// Find hour hand angle from 12'0 clock
	double hour_angle = 0.5 * (hour * 60 + minute);
	
	//Find minute angle
	double minute_angle = 6 * minute;
	
	// Find the difference the angle
	double diff = abs(hour_angle - minute_angle);
	
	//Get the minimum of diff and rest
	
	printf("\n Angle diff between min(360-diff, diff);
	return 0;
}
