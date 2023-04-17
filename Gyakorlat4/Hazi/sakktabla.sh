#!/bin/bash

for (( i = 1; i <= 8; i++ ))
do
    for (( j = 1; j <= 8; j++ ))
    do
        if (( (i+j)%2==0 ))
        then
            printf "\033[0;47m  \033[m"
        else
            printf "\033[0;40m  \033[m"
        fi
    done
    echo ""
done

