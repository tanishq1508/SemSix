sumlist:-
	write('Enter a list to sum'),
	read(L),
	sum(L, R),
	write('Sum of list is: '),
	write(R),!.
sum([H|[]], H).
sum([H|T], R):-
	sum(T, R1),
	R is R1+H.
