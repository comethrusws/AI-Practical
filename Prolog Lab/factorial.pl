% factorial of a number

% base case:  0 ko factorial is 1
factorial(0, 1).

% recursive case: factorial of N is N * factorial(N-1)
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, Result1),
    Result is N * Result1.

