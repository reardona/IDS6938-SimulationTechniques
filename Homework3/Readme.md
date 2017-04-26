**USING 1 DAY PASS***
**DUE 4_25**
# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)



![Weirdartthing.png](https://www.dropbox.com/s/wkox40u0l7gkmbs/weird%20art%20thing.png?dl=0&raw=1)

# Introduction
3D Agent vectors were created to simulate simple human behaviors like individual and group movement to analyze crowd dynamics. Each agent was coded to exhibit certain goals and behaviors that are activated through user selection in the GUI. The agents that were chosen mimic typical human movement and speed during normal walking activity. The purpose of this project is to explore how various interactions occur as agents perform seek, flee, arrival, departure, wander, obstacle avoidance, separation, cohesion, alignment, flocking, and leader following behaviors in a controlled environment as well as facilitate the comprehension of agent-based modeling. The creation of these behaviors and their results are discussed below.
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
I created a maze based off the capital city of the Night Elves in the fictional world of World of Warcraft. 

![D1.png](https://www.dropbox.com/s/wbfqp26hkp44q0x/D1.jpg?dl=0&raw=1)
![D2.png](https://www.dropbox.com/s/czvgfl6fqw6wk60/D2.jpg?dl=0&raw=1)
2 different agents were simulated: The tall and fast Night Elves, and the short and slow Dwarfs. Their movements were analyzed as they navigated through the maze of Darnassus in order to find the Temple of the Moon, aka the center of all night elf spiritual life.

![tom.png](https://www.dropbox.com/s/95cleusdbumcaiv/tom.jpeg?dl=0&raw=1)
![editor.png](https://www.dropbox.com/s/r5arfzpeir74z0p/editor.png?dl=0&raw=1)
![3da.png](https://www.dropbox.com/s/os3lyfkbc8tbpak/3da.png?dl=0&raw=1)

According to the PDM, the Dwarfs have more cluster areas and exhibit less path flow spikes compared to the night elves. This is likely due to the decreased movement speed towards their target compared to the faster night elves.
![PDM.png](https://www.dropbox.com/s/avf4fxv0qo5rl7t/PDM.png?dl=0&raw=1)
![ET.png](https://www.dropbox.com/s/3ew19lybslt5b5s/ET.png?dl=0&raw=1)

b.	Model and analyze a building:

This simulation models the everyday activity occurring inside a favorite city of mine that I’ve also lost thousands of virtual hours to; Stormwind City. 

![SW1.png](https://www.dropbox.com/s/16ew8wexjol0zn1/SW1.jpg?dl=0&raw=1)
![SW5.png](https://www.dropbox.com/s/k3tq4io8q1kfmk4/SW5.jpg?dl=0&raw=1)
![SW2.png](https://www.dropbox.com/s/4jmvqaidavs6069/SW2.jpg?dl=0&raw=1)

Stormwind City exists inside the realm of World of Warcraft and serves as the capital city of the Alliance. While it was destroyed by the Horde during the First War, its citizens rebuilt the city with renewed enthusiasm causing Stormwind to becoming the most populated city in the world as well as the cultural and trade center of the Alliance. 
![wow1.png](https://www.dropbox.com/s/nlsm0mau4mx6kjd/wow1.jpg?dl=0&raw=1)
![wow2.png](https://www.dropbox.com/s/gfy0ddd2lsisqg5/wow2.jpg?dl=0&raw=1)
![wow3.png](https://www.dropbox.com/s/lf6ghsl7634zd1w/wow3.jpg?dl=0&raw=1)

Various businesses and services operate inside this city such as training centers for warriors, rogues, and hunters, flight trainers, guild vendors, portals, a library, and even a hairdresser (http://www.wowhead.com/stormwind-city).

![SW6.png](https://www.dropbox.com/s/i3txyq3it8le2cw/SW6.jpg?dl=0&raw=1)
![SW3.png](https://www.dropbox.com/s/j556pkjk3d4m262/SW3.jpg?dl=0&raw=1)
![SW4.png](https://www.dropbox.com/s/9ngf103dvpylla1/SW4.jpg?dl=0&raw=1)

I chose to model the city based off my own personal experience to include areas of high interest to see how the traffic changes according to major changes in the game, in order to explore their effects on queue times and traffic density. 

 4 major queue areas were simulated; Alchemy Training, The Bank, The Innkeeper, and The Auction House. I varied their probabilities based on my own observations in the game, with a lower probability of a player going to the Alchemy Trainer and Innkeeper, and a higher probability of a player going to the Bank and the Auction House. Additionally, 4 NPCs or self service operations were simulated; the Stable Master, the Mailbox, the Cooking Trainer, and the Weapons Master. Both the Stable Master and the Mailbox have a higher probability of being a target than the Cooking Trainer and Weapons Master. 2 different agents were also created to serve as my general population operating inside Stormwind City. While all Alliance races have access to this city, I chose to model two of my favorite races, Night Elfs and Dwarfs. Since Night Elfs have a significantly taller stature than their Dwarf companions, their base walking speed is faster and they will reach their targets faster than the Dwarfs, who are shorter and much stouter.

![Tyrandepng](https://www.dropbox.com/s/pf3azxi0wuc4d27/Tyrande.png?dl=0&raw=1)
![Dwarf.png](https://www.dropbox.com/s/v1wse8543dy6qw0/Dwarf.gif?dl=0&raw=1)

2 simulations were run. The first was modeled based of observations from the middle of an expansion with normal activity. The second simulation was modified to account for changes in behavior due to a new expansion. For example, there will be an increased need to use the services at the Auction House, Bank, the Mailbox, and the Weapons Master due to the level cap increase and change in item values. 

![Sim1.png](https://www.dropbox.com/s/j2xtx40p16rxjke/Sim1.png?dl=0&raw=1)
![Sim2.png](https://www.dropbox.com/s/xgntl96vyjjgplb/Sim2.png?dl=0&raw=1)
![2d.png](https://www.dropbox.com/s/bctctf8s4g713ls/2d.png?dl=0&raw=1)
![3D.png](https://www.dropbox.com/s/e1ese520utzziz7/3D.png?dl=0&raw=1)

It is hypothesized that traffic surrounding these high value areas will increase with the new expansion. After running both simulations for an hour, data was generated on traffic flow outside of all services and a Pedestrian Density Map was also created. The traffic flow graph for the new expansion show an increase in traffic flow for the Bank, Auction House, Mailbox and Weapons Master compared to the graph for normal activity.
![NormalD.png](https://www.dropbox.com/s/7ds8dgi9fr4bstb/NormalD.png?dl=0&raw=1)
![IncreasedD.png](https://www.dropbox.com/s/gfs3zdf8qnnxivy/IncreasedD.png?dl=0&raw=1)
The pedestrian density map also shows a slight increase around the pathways leading towards the Weapons Master, Auction House, and Bank. Therefore the results were successful in supporting my hypothesis. 
![PDFC.png](https://www.dropbox.com/s/mc2m2rof4cjlg1i/PDFC.png?dl=0&raw=1)
![PDFCE.png](https://www.dropbox.com/s/mvboasz9s3tqu20/PDFCE.png?dl=0&raw=1)

Acknowledgments: 
Thank you ferrets for helping me get through the semester. You guys are the real mvps.
![pup1.png](https://www.dropbox.com/s/8vf4d6wa6bb0u9h/pup1.jpg?dl=0&raw=1)
![pup2.png](https://www.dropbox.com/s/94wxljgxsz0ap3e/pup2.jpg?dl=0&raw=1)
