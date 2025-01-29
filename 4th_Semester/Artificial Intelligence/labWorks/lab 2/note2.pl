% Greater than
gt(X, Y) :- 
    X > Y, 
    write('X is greater than Y').
gt(X, Y) :- 
    X =< Y, 
    write('Y is greater than or equal to X, This is if-else statement').

% Greater than or equal to
gte(X, Y) :- 
    X > Y, 
    write('X is greater than Y').
gte(X, Y) :- 
    X =:= Y, 
    write('X and Y are the same').
gte(X, Y) :- 
    X < Y, 
    write('X is smaller than Y, This is if-elif-else').

% Less than
lt(X, Y) :- 
    X < Y, 
    write('X is less than Y').
lt(X, Y) :- 
    X >= Y, 
    write('Y is less than or equal to X, This is if-else statement').

% Less than or equal to
lte(X, Y) :- 
    X < Y, 
    write('X is less than Y').
lte(X, Y) :- 
    X =:= Y, 
    write('X and Y are the same').
lte(X, Y) :- 
    X > Y, 
    write('X is greater than Y, This is if-elif-else').

% Values are equal
eq(X, Y) :- 
    X =:= Y, 
    write('X and Y are equal').
eq(X, Y) :- 
    X =\= Y, 
    write('X and Y are not equal, This is if-else statement').

% Values are not equal
neq(X, Y) :- 
    X =\= Y, 
    write('X and Y are not equal').
neq(X, Y) :- 
    X =:= Y, 
    write('X and Y are equal, This is if-else statement').
