/*Facts*/
parent(bob,fred).
parent(bob,sally).
parent(fred,arthur).
parent(sally,matilda).

/*Rules*/
sibling(Sibling1,Sibling2) :- parent(X,Sibling1), parent(X,Sibling2), Sibling1\==Sibling2.
cousin(Person1,Person2) :- parent(Parent1, Person1), parent(Parent2, Person2), sibling(Parent1, Parent2).

/*
| ?- sibling(X,Y).

X = fred
Y = sally ? ;

X = sally
Y = fred ? ;

no
| ?- cousin(X,Y).

X = arthur
Y = matilda ? ;

X = matilda
Y = arthur ? ;
*/