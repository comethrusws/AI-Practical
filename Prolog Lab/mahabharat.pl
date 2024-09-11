/* Facts */
male(shantanu).
male(bheeshma).
male(chitrangada).
male(vichitravirya).
male(pandu).
male(yudhishtra).
male(bheema).
male(arjuna).
male(nakula).
male(sahadeva).
male(dhritarashtra).
male(duryodhana).
male(dushasana).

female(ganga).
female(satyavati).
female(ambika).
female(ambalika).
female(gandhari).
female(kunti).
female(madri).
female(duhsala).

parent_of(shantanu,bheeshma).
parent_of(shantanu,chitrangada).
parent_of(shantanu,vichitravirya).
parent_of(ganga,bheeshma).
parent_of(satyavati,chitrangada).
parent_of(satyavati,vichitravirya).
parent_of(vichitravirya,dhritarashtra).
parent_of(vichitravirya,pandu).
parent_of(ambika,dhritarashtra).
parent_of(ambalika,pandu).
parent_of(dhritarashtra,duryodhana).
parent_of(dhritarashtra,dushasana).
parent_of(dhritarashtra,duhsala).
parent_of(gandhari,duryodhana).
parent_of(gandhari,dushasana).
parent_of(gandhari,duhsala).
parent_of(pandu,yudhishtra).
parent_of(pandu,bheema).
parent_of(pandu,arjuna).
parent_of(pandu,nakula).
parent_of(pandu,sahadeva).
parent_of(kunti,yudhishtra).
parent_of(kunti,bheema).
parent_of(kunti,arjuna).
parent_of(madri,nakula).
parent_of(madri,sahadeva).


/* RULES */
father_of(X,Y):-male(X),parent_of(X,Y).

mother_of(X,Y):-female(X),parent_of(X,Y).

grandfather_of(X,Y):- male(X),parent_of(X,Z),parent_of(Z,Y).

sister_of(X,Y):- %(X,Y or Y,X)%
                female(X),
                father_of(F,Y),father_of(F,X),X\=Y.

sister_of(X,Y):- female(X),
                mother_of(M,Y), mother_of(M,X),X\=Y.

aunt_of(X,Y):- female(X),
    parent_of(Z,Y), sister_of(Z,X),!.
 
brother_of(X,Y):- %(X,Y or Y,X)%
    male(X),
    father_of(F, Y), father_of(F,X),X \= Y.
 
brother_of(X,Y):- male(X),
    mother_of(M, Y), mother_of(M,X),X \= Y.
 
uncle_of(X,Y):-
    parent_of(Z,Y), brother_of(Z,X).

ancestor_of(X,Y):- parent_of(X,Y).
ancestor_of(X,Y):- parent_of(X,Z),
    ancestor_of(Z,Y).
