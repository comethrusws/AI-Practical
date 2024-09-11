% Facts: Symptoms experienced by each person

symptom(sheldon, fever).
symptom(sheldon, cold).
symptom(sheldon, headache).
symptom(howard, cough).
symptom(howard, fatigue).
symptom(leonard, sore_throat).
symptom(leonard, fever).
symptom(leonard, cough).
symptom(penny, nausea).
symptom(penny, headache).
symptom(raj, sore_throat).
symptom(raj, fever).
symptom(bernadette, cough).
symptom(bernadette, cold).
symptom(amy, fatigue).
symptom(amy, headache).

%rules haru

% Rule for having the flu
has_flu(X) :-
    symptom(X, fever),
    symptom(X, cough),
    symptom(X, fatigue).

% Rule for having a cold
has_cold(X) :-
    symptom(X, cold),
    symptom(X, cough).

% Rule for having a sore throat
has_sore_throat(X) :-
    symptom(X, sore_throat),
    symptom(X, cough).

% Rule for having a migraine
has_migraine(X) :-
    symptom(X, headache),
    symptom(X, nausea).

% Rule for being unwell in general
is_unwell(X) :-
    symptom(X, _).

