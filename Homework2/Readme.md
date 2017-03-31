# Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #2. 
# Discrete-Event Simulation-Ashley Reardon (*I will be taking 3!! extra days to finish this assignment*) Now due 3/31/11:59pm =^^-^-^=



# Part 1: Empirical Tests of Randomness
A/B. Five different random number engines were varied using a uniform distribution for values between [0-100]. A Chi-Square test was used to test for uniformity. N was varied 3 times (60, 100, 500).

Mersenne Twister:
N=60
![MT_UD60.png](https://www.dropbox.com/s/radf8c2djvk3yhd/MT_UD60.png?dl=0&raw=1)

N=100
![MT100.png](https://www.dropbox.com/s/3l5vxdnmmphwsbj/MT100.png?dl=0&raw=1)

N=250
![ .png](https://www.dropbox.com/s/rutmk77j79qe2nu/MT500.png?dl=0&raw=1)

Knuth:
N=60
![ .png]( https://www.dropbox.com/s/mlgwzb3mt6gjop3/KH60.png?dl=0&raw=1)

N=100
![ .png](https://www.dropbox.com/s/yrznrcpvxbpeenl/KH00.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/360penyqz2ixdu0/KH500.png?dl=0&raw=1)|

Minimal Standard:
N=60
![ .png]( https://www.dropbox.com/s/n90v8wtmlj3gxwq/MSTD_60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/zy2olsuo7jgpn9q/MSTD_100.png?dl=0&raw=1) 

N=500
![ .png]( https://www.dropbox.com/s/qn5nrsa1k3jb0vw/MSTD_500.png?dl=0&raw=1)

RANLUX:(IP)
N=60
![ .png]( https://www.dropbox.com/s/n4swj038p4qhplt/RL_60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/fdblvu5dee22ybq/RLC_100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/r4k5nnlirydsd6e/RL_500.png?dl=0&raw=1)|

Sobol:(IP)
N=60
![ .png]( https://www.dropbox.com/s/sotupintdfa6typ/SO_60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/62pf6954rms3ehp/SO_100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/gwohxjxwjnat6qi/SO_500.png?dl=0&raw=1)|

---

Chi-Square Analysis for Uniformity

Mersenne Twister:
N=60
![ .png]( https://www.dropbox.com/s/lqjm2yj97hkjgdk/MTC60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/6vbzvoz4p1x0kkw/MT_Chi_UD100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/b9j1wtq342a8dgy/MT_UD_CHI_500.png?dl=0&raw=1)|

Knuth:
N=60
![ .png]( https://www.dropbox.com/s/oda190g4ejntydd/KC60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/paa45dur6tymk9j/KC100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/0jbs92ywbhvjsum/KC500.png?dl=0&raw=1)

Minimal Standard:
N=60
![ .png]( https://www.dropbox.com/s/nrxagwfc877rvuq/MSTD_CHI_60tbl.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/1dugcu2v5nfbneo/MSTD_CHI_100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/dzwu7jopavye9qt/MSTD_500_CHI.png?dl=0&raw=1)

RANLUX:
N=60
![ .png]( https://www.dropbox.com/s/j1043h4ob4cldop/RLCh_60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/t4p6vecrj9m31c9/RLCh_100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/enkdez1cuvr66pv/RLCh_500.png?dl=0&raw=1)

Sobol:
N=60
![ .png]( https://www.dropbox.com/s/st74te4i3suenl0/SO_C_60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/akgwuzsm4ai578i/SO_C_100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/jse84rfcjogdi07/SO_C_500.png?dl=0&raw=1)

---
C. Five different distributions were varied using the Mersenne Twister RNG. A Chi-Square test was used (ATTEMPTED!) to test for Goodness of fit. N was varied 3 times (60, 100, 500).

Similar to the Uniform distribution, a Chi-Square analysis was also conducted for these different distributions. However, since I was no longer testing for uniformity, it became challenging trying to figure out how to generate valid expected values for the goodness of fit test. Several methods were used.

I started by utilizing functions in R for each distributions to generate expected values.
* Chisquare: 
* https://stat.ethz.ch/R-manual/R-devel/library/stats/html/Chisquare.html 
* Where: Exp <- 60*pchisq(2*c(1:9,999), df=3, ncp = 0, lower.tail = TRUE)
* Exponential: 
* https://stat.ethz.ch/R-manual/R-devel/library/stats/html/Exponential.html
* Where: Exp <-60*pexp(3*c(1:9, 9999), rate=.1, lower.tail= TRUE)
* Poisson: 
* https://stat.ethz.ch/R-manual/R-devel/library/stats/html/Poisson.html
* Where: Exp <- 60*ppois(2*c(1:9,9999), lambda=9, lower.tail = TRUE)
* Gamma: 
* https://stat.ethz.ch/R-manual/R-devel/library/stats/html/GammaDist.html
* Where: Exp <-60*pgamma(2*c(1:9,9999), shape=2,scale=5, lower.tail=TRUE)
* Normal:
* https://stat.ethz.ch/R-manual/R-devel/library/stats/html/Normal.html
* Where: Exp <-60*pnorm(3*c(1:9,9999), mean=10, sd=4, lower.tail=TRUE)

I then binned out these values in order to organize the frequencies of the raw data. I plotted the expected values into a bar graph in order to compare to what you would typically find based on these distributions. All of them except for Gamma and Poisson fit my expectations. 

Due to lack of consistency, I sought out other methods of extracting valid expected numbers. I turned to Excel's built in distribution function for Gamma and Poisson and utilized Wiki to determine the parameters. This only describes the probability that the bin takes on a value less than the mean and therefore does not give me the expected values needed for the Chi-Square analysis.

Gamma: =GAMMA.DIST(C4,2,2,)
Poisson: =POISSON.DIST(C4,9,TRUE)

The construct validity in expected values caused each Chi-square test to fail therefore further understanding and manipulation of both programs is needed for future analysis. 

On a less defined scale, the frequencies of the raw values can be compared to the frequencies of the expected values to gain insight on functionality of the different distributions. For most distributions the raw frequencies had a similar curve to what was expected. As n increased, the strength of the relationship slightly increased.

Normal Distribution:
N=60
![ .png]( https://www.dropbox.com/s/ailg2wal0bovg82/NML60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/0dohq5h5peh49ju/NML100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/q7tak1cqiptdg9h/NML500.png?dl=0&raw=1)|

Chi-Squared Distribution:
N=60
![ .png]( https://www.dropbox.com/s/b5f9p70imx8xsj4/CSQ60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/45gwhf8roglm8qm/CSQ100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/du42oapyvhzo5a9/CSQ500.png?dl=0&raw=1)

Exponential Distribution:
N=60
![ .png]( https://www.dropbox.com/s/io7kgeqhp7kzyvi/EXP60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/p8v8hgx22kkeblz/EXP100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/5jon9zc1h6bfngg/EXP500.png?dl=0&raw=1)

Poisson Distribution:
N=60
![ .png]( https://www.dropbox.com/s/7aqa50akdgo7zhh/POIS60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/vmb78urr9cxtqxc/POIS100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/5fg8320o9lurk8l/POIS500.png?dl=0&raw=1)

Gamma Distribution:
N=60
![ .png]( https://www.dropbox.com/s/p3yn7u6v5jeiwtb/GAA60.png?dl=0&raw=1)

N=100
![ .png]( https://www.dropbox.com/s/md4d2w8jgk5s1gu/GAA100.png?dl=0&raw=1)

N=500
![ .png]( https://www.dropbox.com/s/seur6etogn5iaj1/GAA500.png?dl=0&raw=1)


---

* Random numbers were generated to produce a unit-square & circle for 5 different RNGs with a varied n. 

![ .png]( https://www.dropbox.com/s/by1t1x2bl22qd3h/de_2.png?dl=0&raw=1)

---

* Random numbers were generated to produce a unit-square & circle for 5 different distributions with a varied n.

![ .png]( https://www.dropbox.com/s/5yhe6vzmseircsk/de_1.png?dl=0&raw=1)
---

# Part 2

* A. A null state game transition matrix was created for the classic game Snakes and Ladders.

|Beginning|End|
| ---- | ---|
|![ .png]( https://www.dropbox.com/s/70020ngc3dvzxv7/nullstart.png?dl=0&raw=1)| ![ .png]( https://www.dropbox.com/s/8fdgls06q4e2pr1/nullend.png?dl=0&raw=1)|

* B. An analysis of the null game was conducted using a Markov Chain simulation to determine the modal number of moves required to finish the game.

![ .png]( https://www.dropbox.com/s/11icr08p8vy5qha/NullM.png?dl=0&raw=1)

A probability loop was implemented to determine how likely the number of rolls would take the user to the last square. After 30 rolls the probability is the highest at 0.151241%. (repeat x30) for modal.

An analysis of the null game was conducted using a Discrete Time Markov Chain simulation to determine the modal number of moves required to finish the game.

* C. A null state game transition matrix was created for the classic game Snakes and Ladders.

|Beginning|End|
| ---- | ---|
|![ .png]( https://www.dropbox.com/s/dbybvtot64gfbwe/SL_begin.png?dl=0&raw=1)| ![ .png]( https://www.dropbox.com/s/vfu6vb53bwpza3a/SL_end.png?dl=0&raw=1)|

An analysis of the Snakes & Ladders game was conducted using a Markov Chain simulation to determine the modal number of moves required to finish the game.

An analysis of the Snakes & Ladders game was conducted using a Discrete Time Markov Chain simulation to determine the modal number of moves required to finish the game.

