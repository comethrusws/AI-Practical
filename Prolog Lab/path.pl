% Facts defining the edges of the graph
edge(a, b).
edge(a, c).
edge(b, d).
edge(c, d).
edge(d, e).

% Base case: there is a path from a node to itself
path(Start, Start, [Start]).

% Recursive case: there is a path from Start to End if there is an edge
% from Start to some Intermediate node, and a path from Intermediate to End
path(Start, End, [Start | Path]) :-
    edge(Start, Intermediate),
    path(Intermediate, End, Path).

% Avoid cycles by keeping track of visited nodes
path_no_cycles(Start, End, Path) :-
    path_no_cycles(Start, End, [Start], Path).

% Base case: the path is found
path_no_cycles(End, End, Visited, Visited).

% Recursive case: find the next node and continue
path_no_cycles(Start, End, Visited, Path) :-
    edge(Start, Intermediate),
    Intermediate \= End,
    \+ member(Intermediate, Visited),  % Ensure no cycles
    path_no_cycles(Intermediate, End, [Intermediate | Visited], Path).

