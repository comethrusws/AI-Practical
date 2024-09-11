% Prolog program to find mutual friends 

% Friend relationships haru
friend(sheldon, leonard).
friend(leonard, raj).
friend(raj, penny).
friend(penny, amy).
friend(amy, sheldon).

% symmetric friendship rule haru
friends(X, Y) :- friend(X, Y).
friends(X, Y) :- friend(Y, X).

% mutual friends
mutualfriends(X, Y) :-
    friends(X, CommonFriend),
    friends(Y, CommonFriend),
    X \= Y.

