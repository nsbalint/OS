#!/bin/bash 

echo "Hello World"
echo "Hello"
echo "World"

k=15

echo $k


read -t 5 -p "Add meg az x erteket: " x

echo "Az x erteke: " 
echo  $x

read -s -p "Add meg a jelszavadat: " password
echo "A jelszavad:" $password
