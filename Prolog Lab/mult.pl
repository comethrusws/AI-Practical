% Base case: When the multiplier is 0, the result is 0
multiplication_table(_, 0, 0).

% Recursive case: Generate the multiplication table for N up to M
multiplication_table(N, M, Result) :-
    M > 0,
    M1 is M - 1,
    multiplication_table(N, M1, _),
    Result is N * M,
    write(N), 
    write(' x '), 
    write(M), 
    write(' = '), 
    write(Result), 
    nl.

