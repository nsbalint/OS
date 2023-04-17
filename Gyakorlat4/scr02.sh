#!/bin/bash

a=3

if test $a -lt 5
then 
	echo "a kisebb mint 5"
else
	echo "a nem kisebb mint 5"
fi

echo "Kerem adjon meg egy szamot: "
echo $1
if [ $1 -gt 100 ]
then
	echo " A szamod nagyobb mint 100"
else
	echo " A szamod kisebb mint 100"
fi

if ls /tmp
then
	echo "siker"
else
	echo "nem siker"
fi


