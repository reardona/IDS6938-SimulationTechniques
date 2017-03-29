# Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #2. 

# Discrete-Event Simulation-Ashley Reardon (*I will be taking 2 extra days to finish this assignment*)

<<

# Part 1: Empirical Tests of Randomness
* A/B. Five different random number engines were varied using a uniform distribution for values between [0-100]. A Chi-Square test was used to test for uniformity. N was varied 3 times (60, 100, 500).

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
* C. Five different random number engines were varied using a uniform distribution for values between [0-100]. A Chi-Square test was used to test for Goodness of fit. N was varied 3 times (60, 100, 500).

Normal Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)|

Chi-Squared Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Exponential Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Poisson Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Gamma Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

---

Chi-Square Analysis for Goodness of fit:

Normal Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Chi-Squared Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Exponential Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Poisson Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

Gamma Distribution:
N=60
![ .png]( &raw=1)

N=100
![ .png]( &raw=1)

N=500
![ .png]( &raw=1)

---

* Random numbers were generated to produce a unit-square & circle for 5 different RNGs with a varied n.

*Insert Table here*

---

* Random numbers were generated to produce a unit-square & circle for 5 different distributions with a varied n.

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


