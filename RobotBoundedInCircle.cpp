/*
Robot Bounded In Circle

Solution
On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

"G": go straight 1 unit;
"L": turn 90 degrees to the left;
"R": turn 90 degress to the right.
The robot performs the instructions given in order, and repeats them forever.

Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

Example 1:

Input: "GGLLGG"
Output: true
Explanation: 
The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
Example 2:

Input: "GG"
Output: false
Explanation: 
The robot moves north indefinitely.
Example 3:

Input: "GL"
Output: true
Explanation: 
The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

Note:

1 <= instructions.length <= 100
instructions[i] is in {'G', 'L', 'R'}
   Hide Hint #1  
Calculate the final vector of how the robot travels after executing all instructions once - it consists of a change in position plus a change in direction.
   Hide Hint #2  
The robot stays in the circle iff (looking at the final vector) it changes direction (ie. doesn't stay pointing north), or it moves 0.


*/


class Solution {
public:
    bool isRobotBounded(string instructions) {
        
        vector<int> direction(2, 0); // for Left and Right direction;
        vector<int> position(2, 0); // will point to the current position, and will start with (0, 0)
        
        int i, j, k;
        
        // Keep the Robo in North facing ....(0, 1)
        direction[0] = 0;
        direction[1] = 1;
        
        int n = instructions.length();
        if (n == 0) return true;
        
        
        // perform instructions 4 times to confirm that there is no cycle
        
        for (i = 0; i < 4; i++)
        {
            // Now act as per instruction
            for (j = 0; j < n; j++)
            {
                switch(instructions[j])
                {
                    case 'G':
                        // Move ahead; add direction to the current position
                        position[0] += direction[0];
                        position[1] += direction[1];
                        break;
                    case 'L':
                        // Turn left; change the direction
                        direction = {-direction[1], direction[0]};
                        break;
                    case 'R':
                        // Turn right; change the direction
                        direction = {direction[1], -direction[0]};
                        break;
                    default:
                        printf("\n Unknown instrcution detected ... \n");
                }
            }
        }
        
        // if position is 0, 0 then there is cycle otherwise ... no cycle
        if (position[0] == 0 && position[1] == 0) return true;
        
        return false;
        
    }
};

