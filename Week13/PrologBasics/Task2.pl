/*Facts*/
cyclist(anne).
cyclist(carl).
cyclist(bob).
swimmer(david).
swimmer(anne).
swimmer(ellen).
runner(ellen).
runner(fred).
runner(bob).

/*Rules*/
team(Swimmer,Cyclist,Runner) :- swimmer(Swimmer), cyclist(Cyclist), runner(Runner), Swimmer\==Cyclist, Cyclist\==Runner, Runner\==Swimmer.

/*

| ?- team(S,C,R).

C = anne
R = ellen
S = david ? ;

C = anne
R = fred
S = david ? ;

C = anne
R = bob
S = david ? ;

C = carl
R = ellen
S = david ? ;

C = carl
R = fred
S = david ? ;

C = carl
R = bob
S = david ? ;

C = bob
R = ellen
S = david ? ;

C = bob
R = fred
S = david ? ;

C = carl
R = ellen
S = anne ? ;

C = carl
R = fred
S = anne ? ;

C = carl
R = bob
S = anne ? ;

C = bob
R = ellen
S = anne ? ;

C = bob
R = fred
S = anne ? ;

C = anne
R = fred
S = ellen ? ;

C = anne
R = bob
S = ellen ? ;

C = carl
R = fred
S = ellen ? ;

C = carl
R = bob
S = ellen ? ;

C = bob
R = fred
S = ellen ? ;

*/