#!/bin/sh
python rand100.py 1 10000 > random100
python rand500.py 1 10000 > random500

tput setaf 5; echo "\nrandom 100 +"
i="0"
while [ $i -lt 10 ]
do
    python rand100.py 1 10000 > random100
    arg="`cat random100`"
    tput setaf 6;
    ./push_swap $arg | wc -l
i=$[i+1]
done

sleep 1
tput setaf 5; echo "\n\nrandom500 +"
i="0"
while [ $i -lt 10 ]
do
    python rand500.py 1 10000 > random500
    arg="`cat random500`"
    tput setaf 6;
    ./push_swap $arg | wc -l
i=$[i+1]
done
tput setaf 5; echo "\n"

tput setaf 5; echo "\nrandom 100 -"
i="0"
while [ $i -lt 10 ]
do
    python rand100.py -10000 0 > random100
    arg="`cat random100`"
    tput setaf 6;
    ./push_swap $arg | wc -l
i=$[i+1]
done

sleep 1
tput setaf 5; echo "\n\nrandom500 -"
i="0"
while [ $i -lt 10 ]
do
    python rand500.py -10000 0 > random500
    arg="`cat random500`"
    tput setaf 6;
    ./push_swap $arg | wc -l
i=$[i+1]
done
tput setaf 5; echo "\n"