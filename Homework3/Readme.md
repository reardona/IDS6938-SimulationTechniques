**USING 1 DAY PASS***
**DUE 4_25(**
# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

# Homework 3
![Flee.png](&raw=1)

# Introduction
3D Agent vectors were created to simulate simple human behaviors like individual and group movement to analyze crowd dynamics. Each agent was coded to exhibit certain goals and behaviors that are activated through user selection in the GUI. The agents that were chosen mimic typical human movement and speed during normal walking activity. The purpose of this project is to explore various interactions that occur as agents perform seek, flee, arrival, departure, wander, obstacle avoidance, separation, cohesion, alignment, flocking, and leader following behaviors in a controlled environment to aid in the comprehension of agent-based modeling. The creation of these behaviors and their results are discussed below.
___
# Part 1: Behaviors

a.	Derivative Vectors: 4 derivative vectors were set according to predefined input and state vectors.
```sh
deriv[2] = input[0] / Mass; (The force in local body coordinates divided by the mass)
deriv[3] = input[1] / Inertia; (The torque in local body coordinates divided by the inertia)
deriv[0] = state[2]; (The velocity of the agent in local body coordinates)
deriv[1] = state[3]; (The angular velocity of the agent in world coordinates)
```
___
Appropriate Values: Through trial and error I was able to find what I would call ‘stable’ values. I am not sure if they are correct or not, but these values do elicit the desired behaviors. Most of the values were straightforward, except for Kp1, which has to be negative for the agents to behave appropriately.
```sh
Kv0 = 1.0;
Kp1 = -1.0; 
Kv1 = 1.0;
KArrival = 0.01;
KDeparture = 5000.0;
KNoise = 0.0;
KWander = 0.0;
KAvoid = 0.0;
TAvoid = 20.0;
RNeighborhood = 1000.0;
KSeparate = 10.0;
KAlign = 5.0;
KCohesion = 10;
```

b.	6 Individual Behaviors: In this simulation, a user-controlled sphere served as the goal for agents to move towards or away from. The code was written based on the math provided in Webcourses.

Seek & Flee: The distance between the current agent’s position and the target position was calculated and used to determine the new angle (in Cartesian coordinates) and velocity needed to reach the target. The addition of Pi returned the opposite direction, thereby applying the ‘Flee’ behavior. 

Seek: 
```sh
vec2 tmp; //declare
tmp = goal - GPos; // desired velocity
tmp.Normalize(); //clean computation
thetad = atan2(tmp[1], tmp[0]); //new angle
vd = SIMAgent::MaxVelocity; //agent speed
return vec2(cos(thetad)* vd, sin(thetad) * vd); //conversion
```
![Seek.png](https://www.dropbox.com/s/4idpa1403s8q3jp/Seek.png?dl=0&raw=1)

Flee:
```sh
vec2 tmp; //declare
tmp = goal - GPos; // desired velocity
tmp.Normalize(); //clean computation
thetad = atan2(tmp[1], tmp[0]) + M_PI; //return the opposite
vd = SIMAgent::MaxVelocity; //agent speed
return vec2(cos(thetad)* vd, sin(thetad) * vd); //conversion
```
![Flee.png](https://www.dropbox.com/s/5pmmon9vqzsqm8t/Flee.png?dl=0&raw=1)

Arrival & Departure: Similar to the Seek & Flee calculation, the distance between the current Agents position and the target position is needed to determine the desired velocity (Vd). A new angle and speed was returned to direct the Agents movements. Unlike Seek & Flee however, several interesting characteristics emerge as the agent approaches or leaves the target. As the agent gets closer to the target (Arrives) it slows down, and as the agent moves away (Departs) it speeds up. These characteristics are more align with what we would observe in a natural setting.

Arrival:
```sh
vec2 Vd;
Vd = goal - GPos; //desired velocity
thetad = atan2(Vd[1], Vd[0]); //derive the new angle the agent should be targeting
vd = Vd.Length()*KArrival; //Agent speed
return -vec2(cos(thetad)* vd, sin(thetad) * vd); //return the Cartesian coordinates
```
![Arrival.png](https://www.dropbox.com/s/1ulh2zdf2qt798l/Arrival.png?dl=0&raw=1)

Departure:
```sh
vec2 Vd;
Vd = goal - GPos; //desired velocity
Vd.Normalize();
thetad = atan2(Vd[1], Vd[0]); //derive the new angle the agent should be targeting
thetad += M_PI;// +M_PI; //return the opposite (??)
vd = (1.0f / Vd.Length())*KDeparture; //Agent speed
return vec2(cos(thetad)* vd, sin(thetad) * vd); //return the Cartesian coordinates
```
![Departure.png](https://www.dropbox.com/s/yi0mrhcerz6818j/Departure.png?dl=0&raw=1)

Wander: An agent who exhibits wandering behavior lacks a designated target and instead moves around in ‘random’ directions. While it is not possible to return a truly ‘random’ direction, I was able to return erratic movements using the rand function to generate a random point from a circle surrounding the agent.  So as not to make the movements overly erratic, a random point from a larger circle was also generated to provide a dampening effect. The midpoint of these two points provided the new direction for the agent to move. 

Wander:
```sh
vec2 Outer;
vec2 Inner;
vd = SIMAgent::MaxVelocity;

float bigTheta = float(rand() % 360  - 180 ) / 180.0 * M_PI;
float smallTheta = float(rand() % 360 - 180) / 180.0 * M_PI;
Outer = vec2(cos(bigTheta)* vd, sin(bigTheta) * vd);
Inner = vec2(cos(smallTheta)* vd*.5, sin(smallTheta) * vd*.5);
vec2 Dest = .5*(Outer + Inner);
thetad = atan2(Dest[1], Dest[0]);
return Dest;
```
![Wander.png](https://www.dropbox.com/s/3oc8bqpqfg3b3t2/Wander.png?dl=0&raw=1)

c.	5 Group Behaviors: Separation, alignment, and cohesion are primary group behaviors that model the “flocking” motion seen in birds. The new desired velocity emerging from these group behavior calculations provide the foundation for two additional behaviors; flocking and leader following. 

Separation: Separation takes into consideration the position of all the agents’ flockmates within its neighborhood and steers away from the sum of their direction. I had assistance from a computer scientist writing the loop for the agents in the neighborhood as well as help correcting my sumPositions that I wrote based on the equations you provided on Webcourses (Thank you-!!).

```sh
{
vec2 sumPositions = vec2(0, 0);
for (auto agent : SIMAgent::agents)
{
	if (agent == this)
		continue;
		if ((agent->GPos - this->GPos).SqrLength() < RNeighborhood*RNeighborhood)
//loops through every agent in the neighborhood
{
	sumPositions -= (agent->GPos - this->GPos).Normalize();
	//Generate a vector based off the distance between all agents and your current    position, then normalize it.
		}
	}
thetad = atan2(sumPositions[1], sumPositions[0]); //direction
vd = SIMAgent::MaxVelocity;
return vd*sumPositions.Normalize(); //new vector
```

Alignment: Just like the Separation function, Alignment also considers all agents in the appropriate neighborhood to adjust their position. Agents in alignment steer towards the average heading of local flockmates by matching their velocity. 
```sh
{
	vec2 sumPositions = vec2(0, 0);
	for (auto agent : SIMAgent::agents)
	{
		if (agent == this)
			continue;
		if ((agent->GPos - this->GPos).SqrLength() < RNeighborhood*RNeighborhood) //loops through every agent in the neighborhood
		{
			sumPositions += (agent->v0).Normalize(); //Generate a vector based off the distance between all agents and your current position, then normalize it.
		}
	}
	thetad = atan2(sumPositions[1], sumPositions[0]); //direction
	vd = SIMAgent::MaxVelocity;
	return vd*sumPositions.Normalize(); //new vector
```

Cohesion: Agents in cohesion move toward a target based on the average position of all flockmates in its neighborhood. Cohesion is calculated by taking the sum of all positions over the number of positions.

Flocking & Leader Following: By using the previous behaviors described above, large group behaviors can be defined. I tried to convert the equations you provided in Webcourses for these behaviors but a major error exists in my code resulting in the disappearance of all agents upon selection of either Flocking or Leader Following! I am not sure how to fix it, and there is not enough time for me to try and figure out what is wrong, so I will have to upload faulty code.

# Part 2: Simulating a simple pedestrian flow
a.	Create a maze:
b.	Model and analyze a building:

