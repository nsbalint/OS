#!/bin/bash

atlag()
{
	echo $1 "es" $2 "szamok atlaga:" && atlag=$(( ($1+$2)/$# )) && echo  $atlag
	return $atlag

}

visszater()
{  atlag 3 1
if [ $atlag -lt  5 ]
then
        echo "5-nel kisebb atlag"
else
        echo "5-nel nagyobb atlag xd"
fi
}

visszater
