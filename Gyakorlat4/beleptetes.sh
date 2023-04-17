#!/bin/bash

read -p "Add meg a felhasznalonevedet: " user
if [ $user = "asd" ]
then
	read -s -p "Add meg a jelszavad: " password
	if [ $password = "palacsinta" ]
	then echo "Sikeres belépés, Hello" $user
	else echo "Rossz jelszó"
	fi
else 
echo "Rossz felhasznalonev!"
fi
