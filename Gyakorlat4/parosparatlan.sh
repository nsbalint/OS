#!/bin/bash

if [ $(($1 % 2)) -eq 0 ]
then
	echo "A szam paros"
else
	echo "A szam paratlan"
fi

