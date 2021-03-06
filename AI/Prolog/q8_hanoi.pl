hanoi:-
	write('Enter number of rings: '),
	read(N),
	run_hanoi(1, 2, 3, N).
run_hanoi(S, _, D, 1):-
	move(S, D),!.
run_hanoi(S, A, D, N):-
	T is N-1,
	run_hanoi(S, D, A, T),
	move(S, D),
	run_hanoi(A, S, D, T).
move(S, D):-
	write('Move disk '),
	write('from '),
	write(S),
	write(' to '),
	write(D),nl.
