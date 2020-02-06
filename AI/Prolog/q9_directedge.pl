edge(p,q).
edge(q,r).
edge(r,s).
edge(s,t).
go(X,Y):-
	path(X,Y),
	write('There is a path'),!;
	write('There is no path'),!.
	path(X,Y):-
		edge(X,Y).
	path(X,Y):-
		edge(X,Z),
		path(Z,Y).
