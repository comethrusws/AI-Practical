% Facts: Define family members and their relationships

% Males
male(john).
male(mike).
male(bob).
male(james).
male(david).

% Females
female(linda).
female(susan).
female(alice).
female(karen).
female(mary).

% Parent-child relationships
parent(john, mike).  % John is a parent of Mike
parent(john, susan). % John is a parent of Susan
parent(linda, mike). % Linda is a parent of Mike
parent(linda, susan).% Linda is a parent of Susan
parent(mike, alice). % Mike is a parent of Alice
parent(mike, james). % Mike is a parent of James
parent(susan, david).% Susan is a parent of David
parent(susan, mary). % Susan is a parent of Mary
parent(bob, karen).  % Bob is a parent of Karen

% Rules: Define relationships based on the facts

% A is a father of B if A is male and A is a parent of B
father(A, B) :-
    male(A),
    parent(A, B).

% A is a mother of B if A is female and A is a parent of B
mother(A, B) :-
    female(A),
    parent(A, B).

% A is a child of B if B is a parent of A
child(A, B) :-
    parent(B, A).

% A is a sibling of B if they share at least one parent and A is not B
sibling(A, B) :-
    parent(P, A),
    parent(P, B),
    A \= B.

% A is a brother of B if A is a sibling of B and A is male
brother(A, B) :-
    sibling(A, B),
    male(A).

% A is a sister of B if A is a sibling of B and A is female
sister(A, B) :-
    sibling(A, B),
    female(A).

% A is a grandparent of B if A is a parent of P and P is a parent of B
grandparent(A, B) :-
    parent(A, P),
    parent(P, B).

% A is a grandfather of B if A is a grandparent of B and A is male
grandfather(A, B) :-
    grandparent(A, B),
    male(A).

% A is a grandmother of B if A is a grandparent of B and A is female
grandmother(A, B) :-
    grandparent(A, B),
    female(A).

% A is a grandchild of B if B is a grandparent of A
grandchild(A, B) :-
    grandparent(B, A).

% A is an uncle of B if A is a brother of a parent of B
uncle(A, B) :-
    parent(P, B),
    brother(A, P).

% A is an aunt of B if A is a sister of a parent of B
aunt(A, B) :-
    parent(P, B),
    sister(A, P).

% A is a cousin of B if their parents are siblings
cousin(A, B) :-
    parent(P1, A),
    parent(P2, B),
    sibling(P1, P2).

