#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

KOE
This is the framework for homework #1. Please first read the [homework writeup](HomeWork%231.pdf).

The assignment is due: Monday, February 27 at 11:59PM (EST)

____
# Part 1: Numerical Analysis of Integration Functions
____

Three numerical integration solutions were run: Euler, Midpoint, RK4 and exact, in order to generate numerical and exact values for the ODE: 

- dy/dx = y -1/2* e^x/2 * sin(5x) + 5e^x/2 * cos(5x)

(A). The exact symbolic solution for this ODE is:
- e^(x/2) sin(5 x)
- pow(M_E, (x / 2.0)) *sin(5.0 * x)

(B). From this solution you can derive the df and exact functions:

| DF Function | Exact Function |
| -----------|----------------|
| ![DF Function.png](https://www.dropbox.com/s/kfy65g5m98vybyv/DF%20Function.png?dl=0&raw=1) | ![Exact Function.png](https://www.dropbox.com/s/8y6djnxgam5usl4/Exact%20Function.png?dl=0&raw=1) |

(C.) RK1, RK2, and RK4 were integrated to generate numerical and exact values. h= 0.1, for x= < 0.0, 10.0>.

| X | RK1 | RK2 | RK4 | Exact |
|---|-----|-----|-----|-------|
| 0  | 0| 0  |0  |0   |
| 0.1  |0.5 | 0.5090369272|0.50401476|0.5040062116|
|  0.2 |0.986088280|0.9418917554|0.9299833736|0.9299692608|
|  0.3 |1.336761843|1.178280127|1.158938591|1.158923832|
| 0.4|1.453584287|1.136380907|1.110627992|	1.110618385|
| 0.5|1.28927035|0.798159298|0.768452619|	0.768453444|
| 0.6|0.86543033|0.220768035|0.190477469|	0.190492086|
| 0.7|0.274273714|-0.470402004|-0.49781389|	-0.497785095|
| 0.8|-0.337857308|-1.107144704|	-1.129056656|-1.129016654|
| 0.9|-0.802753055|-1.517667616|	-1.533117725|-1.533072395|
| 1.0|-0.971671551|-1.570878628|	-1.581041974|-1.580998849|
| 1.1|-0.755948824|-1.214747006|	-1.222913458|-1.222879899|
| 1.2| -0.156247699|-0.498141061|	-0.509147006|-0.509128232|
| 1.3|0.728356108|0.431273571|0.412068581|	0.41207112|
| 1.4|1.715934898|1.355046339|1.323019094|	1.323008542|
| 1.5|2.580464313|2.033306318|1.985762151|	1.985745966|
| 1.6|3.106136933|2.264888984|2.20186874|	2.201857271|
| 1.7|3.144749623|1.943723238|1.868173695|	1.868177859|
| 1.8|2.661568066|1.0964239|1.013619327|	1.013647908|
| 1.9|1.756533063|-0.110661518|-0.194376199|	-0.194318978|
| 2.0|0.652703481|-1.399996434|-1.478886739|	-1.4788027|
|2.1|-0.348502481|-2.443310353|-2.513966496|	-2.513863572|
|2.2|-0.937118868|-2.941602204|-3.004245902|	-3.004136603|
|2.3|-0.873976159|-2.70594543|-2.764948334|	-2.764846851|
|2.4|-0.059946601|-1.71816828|-1.781566264|	-1.781484825|
|2.5|1.423979884|-0.153514693|-0.231540836|	-0.231486167|
|2.6|3.319281279|1.644605198|1.54168834|	1.541717508|
|2.7|5.238969258|3.236248676|3.100524943|	3.100538568|
|2.8|6.755270333|4.189210793|4.01709566|	4.017110916|
|2.9|7.507190201|4.192252154|3.985526889|	3.985564681|
3.0|7.302089591|3.148785464|2.914307734|	2.914387906|
3.1|6.184236647|1.224605964|0.972629052|	0.972765385|
3.2|4.449044884|-1.167577779|-1.426190757|	-1.425994463|
3.3|2.593589867|-3.449436793|-3.706500293|	-3.706251919|
3.4|1.209577795|-5.009923054|-5.262921367|	-5.262639293|
3.5|0.840552721|-5.360649903|-5.614631006|	-5.614340022|
3.6|1.836719894|-4.275713547|-4.543483006|	-4.543208093|
3.7|4.244893938|-1.877962749|-2.178355567|	-2.178114923|
3.8|7.765893459|1.356347703|1.001862248|	1.002063203|
3.9|11.797567|4.68431418|4.255978576|	4.256150562|
4.0|15.56128357|7.261608412|6.745634215|	6.745803673|
4.1|18.28779237|8.351461123|7.743070647|7.743275262|
4.2|19.42038688|7.527669226|6.8319912|	6.832272103|
4.3|18.78438686|4.818214028|4.048561713|	4.048954056|
4.4|16.67534928|	0.745902688|	-0.080407378|	-0.079883186|
4.5|13.83454839|	-3.755363171|	-4.622839038|	-4.62218308|
4.6|11.30627052|	-7.53999892|	-8.441122943|	-8.440356708|
4.7|10.20162853|	-9.526142511|	-10.46629701|	-10.4654587|
4.8|11.42050818|	-8.98343453|	-9.983215155|	-9.982350011|
4.9|15.3995765|	-5.75964435|	-6.853708459|	-6.852856091|
5.0|21.95465336|	-0.38078175|	-1.613192731|	-1.612374396|
5.1|30.26839856|	6.014645055|	4.597706732|	4.598497604|
5.2|39.04184528|	11.90757696|	10.26608596|	10.26688721|
5.3|46.78766159|	15.75373022|	13.86098924|	13.86186593|
5.4|52.20384861|	16.38289019|	14.22958423|	14.23061724|
5.5|54.53922906|	13.34297777|	10.93668465|	10.93795441|
5.6|53.8548974|	7.093621803|	4.453381201|	4.454949997|
5.7|51.10278291|	-1.016917323|	-3.870136268|	-3.868238693|
5.8|47.98174569|	-9.00825224|	-12.06319514|	-12.06097868|
5.9|46.58531604|	-14.71564969|	-17.98179125|	-17.97930254|
6.0|48.91085718|	-16.33276767|	-19.84783646|	-19.84514567|
6.1|56.34331178|	-12.91820728|	-16.74997531|	-16.74715483|
6.2|69.24521405|	-4.730353493|	-8.971708122|	-8.968807967|
6.3|86.770879|	6.71462731|	1.956659048|	1.959633321|
6.4|106.976805|	18.90583913|	13.52479088|	13.52789171|
6.5|127.2308958|	28.88713582|	22.79198022|	22.79531867|
6.6|144.845701|	33.9802905|	27.1065171|	27.11024922|
6.7|157.7947748|	32.51209943	|24.82557044|	24.82987139|
6.8|165.3348427|	24.35679009|	15.84845493|	15.85348654|
6.9|168.3623304|	11.13329012|	1.804998656|	1.810878113|
7.0| 169.3838706|	-4.030216515|	-14.18624083|	-14.17946262|
7.1|172.0681429|	-17.14871549|	-28.17228344|	-28.16462716|
7.2|180.4518537|	-24.32396089|	-36.30581142|	-36.29735499|
7.3|197.9702842|	-22.76449392|	-35.85664997|	-35.84749611|
7.4|226.5464061|	-11.62486987|	-26.03915079|	-26.02938275|
7.5|265.9819834|	7.573163658|	-8.420983343|	-8.410618979|
7.6|313.8412016|	31.09105003|	13.23698217|	13.24802651|
7.7|365.909382|	53.7164146|	33.72789984|	33.73982544|
7.8|417.1685434|	69.96783884|	47.60073669|	47.61385252|
7.9|463.0911121|	75.49676734|	50.551947|	50.56663391|
8.0|500.9495217|	68.3428104|	40.66514418|	40.68180013|
8.1|530.8035916|	49.70067888|	19.16044889|	19.17942782|
8.2|555.8758684|	23.94803368|	-9.592897427|	-9.571337455|
8.3|582.1538542|	-2.150655369|	-38.88141649|	-38.85714093|
8.4|617.2422193|	-20.94381739|	-61.14646828|	-61.11945935|
8.5|668.6856376|	-25.78002003|	-69.86074193|	-69.83105503|
8.6|742.143842|	-12.83269433|	-61.33393679|	-61.30162694|
8.7|839.8791755|	17.61878775|	-35.97067969|	-35.93571326|
8.8|959.984196|	60.84206991|	1.404009713|	1.441837177|
8.9|1096.629577|	108.4273937|	42.33439851|	42.37551737|
9.0|1241.37688|	150.1023432|	76.55081616|	76.59589429|
9.1|1385.328763|	176.2233273|	94.44915487|	94.49905918|
9.2|1521.647688|	180.3673069|	89.65808285|	89.71379662|
9.3|1647.829303|	161.3606021|	61.03567726|	61.09819136|
9.4|1767.116099|	124.1582495|	13.51631062|	13.58651544|
9.5|1888.596144|	79.22459545|	-42.53333378|	-42.45472598|
9.6|2025.825999|	40.4187988|	-93.43846738|	-93.35094466|
9.7|2194.184043|	21.77807556|	-125.4239703|	-125.3271744|
9.8|2407.512568|	33.91946812|	-128.1856199|	-128.0792336|
9.9|2674.851039|	80.95594681|	-97.93441991|	-97.81800842|
10.0|2998.124017|	158.7831645|	-39.0670402|	-38.93988091|

The results for all 4 solutions are graphed for comparison:
![Numerical Integration Comparison.png](https://www.dropbox.com/s/ra2auidqzmaj3dk/Numerical%20Integration%20Comparison.png?dl=0&raw=1)

(D). The error percentages for all 4 solutions are graphed for comparison:
![Error Percentages Comparison.png](https://www.dropbox.com/s/b9uqc530ehtg6b2/Error%20Percentages%20Comparison.png?dl=0&raw=1)

(E). The original step size, h= 0.1, was varied 3 times, h= 0.5, h= 1.0, and h= 2.0. The following tables and charts detail the results of RK4 integration and the error rate for these varied step sizes.

RK4 Integration with Varied Step Size

H=0.5:

![h_0.5.png](https://www.dropbox.com/s/1vtexn9wnpxtojd/h_0.5.png?dl=0&raw=1)
![h_0.5_chart.png](https://www.dropbox.com/s/1u0tju43vknokdq/h_0.5_chart.png?dl=0&raw=1)

H= 1.0:

![h_1.0.png](https://www.dropbox.com/s/mffqyqibdqso28w/h_1.0.png?dl=0&raw=1)
![h_1.0_chart.png](https://www.dropbox.com/s/sf27cz4csx5559l/h_1.0_chart.png?dl=0&raw=1)

H= 2.0:

![h_2.0.png](https://www.dropbox.com/s/2bs2a5arjo10zvr/h_2.0.png?dl=0&raw=1)
![h_2.0_chart.png](https://www.dropbox.com/s/cefq7qkm9aje8qg/h_2.0_chart.png?dl=0&raw=1)

(F).

1. Describe how varying the integration method changes the accuracy. 

    The basic numerical integration starts with RK1, which uses an approximation to generate a tangent line from a starting point to its next step. This proves to be inaccurate when the slope is inconsistent, because the tangent line will not detect those changes. Higher order integrations calculate more increments, increasing the accuracy.
2. What happens as you increase the x value to the accuracy?

    As you increase the x-value, accuracy decreases because each stepsize builds off an approximation already containing error, so it will only add more error at that stepsize and grow with subsequent stepsizes.
3. How does varying the step size effect the accuracy? 

    When you increase the stepsize, you are also increasing the amount of information you are missing between the stepsizes. For example, if the slope is changing rapidly between 0 and 1, but you are only checking between o and 2, you will miss the change entirely, and as a result the accuracy will decrease. When a high accuracy is needed, smaller stepsizes must be made to detect changes at the slope. Its downfall is how computationally expensive it can be, so compromises must be made.
4. Which method is the most accurate and why (in particular explain what is taken to account in the solution)?

    Higher order integration methods that improve upon Eulers, by including multiple increments within stepsizes to detect obscure changes, are the most accurate. For example, RK4 includes increments based on the slope at the starting point, midpoint, and end of the interval, increasing its ability to handle changes, which subsequently increases the accuracy without a high dependency on stepsize (which is relative to the necessity of accuracy, ex. Angry Birds vs. Falcon 9 landing). 

____
# Part 2: Programming a Jello Cube
____

A. Forward Euler, Midpoint, RK4(given)

Euler


![aasd.png](https://www.dropbox.com/s/8ya9huewfx23bg9/aasd.png?dl=0&raw=1)


Midpoint


![Midpoint 1.0.png](https://www.dropbox.com/s/rgsgtvfz4vggk3s/Midpoint%201.0.png?dl=0&raw=1) ![Midpoint 1.1.png](https://www.dropbox.com/s/biuveadi4dw3up3/Midpoint%201.1.png?dl=0&raw=1)

B. Particle forces other than gravity.
![Compute Forces.png](https://www.dropbox.com/s/pryv5945mofxbe8/Compute%20Forces.png?dl=0&raw=1)

C. Collision and penetration detection.

|CylinderCollision|FloorCollision|SphereCollision|
|------------------|-----------------|--------------|
| ![CylinderCheck.png](https://www.dropbox.com/s/lvhqhoudg2arcc6/CylinderCheck.png?dl=0&raw=1)|![GroundCheck.png](https://www.dropbox.com/s/hoczbtie6u489c5/GroundCheck.png?dl=0&raw=1) |![SphereCheck.png](https://www.dropbox.com/s/aan0vohlx7rgg3l/SphereCheck.png?dl=0&raw=1) |

|CylinderIntersection|FloorIntersection|SphereIntersection|
|--------------------|-----------------|------------------|
|![Cylinderintersec.png](https://www.dropbox.com/s/v9atq2ol60qbl38/Cylinderintersec.png?dl=0&raw=1)I was having a major issue with my cube exploding so I asked for debugging help from a computer scientist (it was the night the project was due!) he suggested I take out what I had for the 'time' variable and helped me write the distance between the particle and cylinder axis equation. Also, he suggested I define my epsilon at the top since I kept using 0.5. He shared this link with me: http://www.cprogramming.com/tutorial/cpreprocessor.html Also, I received help prior to this from Alex Tuesday night. |![Floorintersec.png](https://www.dropbox.com/s/6la4k4dyof2310w/Floorintersec.png?dl=0&raw=1) |![Sphereintersec.png](https://www.dropbox.com/s/d6sllwwd17o87mq/Sphereintersec.png?dl=0&raw=1) A computer scientist brought me to the worlds.cpp and showed me what variables I needed for a Sphere. From that I was able to use the cylinder file in the worlds text to insert a sphere object.  |

D. Collision and Penetration response.

|ResolveContacts|ResolveCollisions|
|---------------|-----------------|
|![Resolve Contacts.png](https://www.dropbox.com/s/b22voa82af7ybg9/Resolve%20Contacts.png?dl=0&raw=1) | ![Resolve Collisions.png](https://www.dropbox.com/s/sd4vfglseukgjlr/Resolve%20Collisions.png?dl=0&raw=1)|

E. Extra Springs

ShearSprings

![Shear Springs.png](https://www.dropbox.com/s/dygrol2i3t0qrc2/Shear%20Springs.png?dl=0&raw=1) 

![Ss.png](https://www.dropbox.com/s/4yqp7zozjzm8buq/Ss.png?dl=0&raw=1)

BendSprings

![bend springs.png](https://www.dropbox.com/s/evqxigrfjmcrawy/bend%20springs.png?dl=0&raw=1)

____
# Part 3: Written Questions
____

1. What is the effect of the Ks and Kd parameters on the jello?

    Ks is a spring constant that determines how stiff or how elastic the Jello cube will be. When you increase the Ks in the Jell-Os springs (structural, attachment, bend, and shear), it will be able to handle the forces acting on it while maintaining its original shape. With low spring constants, the Jello cube will denature once it collides with other objects. 
Kd on the other hand, manages absorbed energy and tends to decrease the velocity of the mass of connecting points. A dampening constant opposes the motion, so a smaller Kd helps manage the velocity between two points. 
2. What are the benefits and the drawbacks of the collision system used here? What are some different ways in which it could be improved?

    The main benefit of the Jello cube collision system is its low computational power, allowing for a faster run time. Unfortunately, a fast computation decreases the accuracy of the collision detection because only an approximation of a particle is calculated to detect its existence inside a broad boundary. In some instances, my Jello cube did not detect a specific particle colliding into the cylinder. In order to improve upon this, all instances of a particle collision must be taken into account. For example, in a cylinder collision, each particle would be detected for collision at both faces and its surface. 

3. What are some example systems you could model with Mass-spring simulations? Explain how you would you construct the model.
    
    A Mass-spring simulation can be applied to most systems that allow for bending but are able to resist movement, like cloth, grass, and hair. When constructing a model to simulate hair, you would first want to model a sample of a hair strand as a particle. Since hair behaves collectively you can group several particles together. Each hair particle will be connected by several structural and bend springs. The bend springs will provide control over the hairs shape as the character moves around the scene. Extra springs will be applied to account for rapid movement change (so curly hair doesnt unravel during high speeds). Hooks law is used to apply a spring and dampening force to the particles. Additional forces like friction and static can also be applied. Finally, collision detection and response must be implemented for collision with other objects like the ears, head, shoulder, and other particles by taking a sample from a uniformed grid system to detect if a particle is colliding with another particle. If a collision is detected a penalty force will be applied. 

4. Does the jello behave realistically? What integration method did you choose to make the Jello stable?

    My Jello cube does not behave realistically because my penalty force is too high, causing it to bounce slightly. In real life the force would not be strong enough to lift the Jello cube. There is also moderate denaturing that occurs during collision response, which was not expected. I chose to use an RK4 method of integration to account for more accuracy and stability. 

5. How would you model and simulate water (in terms of a continuous simulation)?

    Fluid flow can be modeled and simulated by computing a series of differential equations accounting for particle movement, interaction, and energy flow over time. It is important to discretize the type of particles because surface particles will behave differently than those below them. Several relationships involved in fluid flow include, velocity, density, surface tension, distance between particles, momentum, pressure, energy, and particle interaction. At each time step, the different forces and interactions are computed and applied to the fluid particles.


____
# Part 4: Final Report
____

![environment.png](https://www.dropbox.com/s/d7470iotyvwjrqy/environment.png?dl=0&raw=1)

____
# Extra Features
____

1. Supported a collision with a sphere in an interesting scene:
![environment.png](https://www.dropbox.com/s/d7470iotyvwjrqy/environment.png?dl=0&raw=1)

![asdsadsdsd.png](https://www.dropbox.com/s/w8tqwyupyiska2n/asdsadsdsd.png?dl=0&raw=1)

2. Made a Gif

https://imgflip.com/gif/1klv2m?herp=1488416380375
Does this count as a video?

=^-^=

 =^-^=