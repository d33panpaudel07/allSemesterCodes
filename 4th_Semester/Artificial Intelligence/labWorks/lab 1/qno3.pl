cat(tom).
loves(kunal, pasta).
color(hair, black).
loves(nawaz, play_games).
lazy(pratyusha).
dances(lili).
searching_for_food(tom).
loves_to_play(jack, cricket).
loves_to_play(bili, cricket).
free(ryan).

happy(lili) :- dances(lili).
hungry(tom) :- searching_for_food(tom).
friends(jack, bili) :- loves_to_play(jack, cricket), loves_to_play(bili, cricket).
goes_to_play(ryan) :- school_closed, free(ryan).