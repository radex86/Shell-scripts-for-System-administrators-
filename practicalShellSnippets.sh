#!bin/bash 
#This script is the work of m@alkali
#Caution: Do not RE-USE the code, learn from it 
#&adapt your own  style
#intended for learning only @nchu....
#====================================

# help Method to guide the user
help(){
	local FLAG=$1
	echo "ERROR:<$FLAG>"
	exit 15
}

# Input Method to read From the user
Inputf() {
	local ELEMS=()
	COUNT=0
	while [ "$ANS" != "N" ]
	do 
		read -p "Input a Number:  " ELEM
		ELEMS[$COUNT]=$ELEM
		COUNT=$((COUNT+1))
		read -p "Do you want to continue(Y/N): " ANS
	done
	echo ${ELEMS[@]} # returning the list of Elements
}

# Variable Init ... 
# Argument
# assume we have input arguments N (1 option and n-1 FILES)

#checking if there is no input
# $* return String stream 
# we wrap it in "" to convert it to String
if [ -z "$*" ]
then
	help "No Argument are passed"
fi 

# retrive all files in variables
COUNT=0
LST1=() #list of all arguments
for ELE in $@ 
do	
  LST1[$COUNT]=$ELE
  COUNT=$((COUNT+1))

done 

echo "list of elements are: ${LST1[@]}"

OPTION=${LST1[0]}
LST2=() # list of all files (N-1 files)
for((i=1;i<${#LST1[@]};i=i+1)) 
do 
	LST2[$i]=${LST1[$i]} # element passing between lists
done

echo "The list of Files are: ${LST2[@]}"

echo $OPTION
case $OPTION in 
	"-a" | "--append" ) ;;
	"-c" | "--compress") ;;
	"-r" | "--reveal" )
		NU=$(Inputf) #return from the function(inputf) 
		echo "The elements retrived are:  ${NU[@]}"
			;;
	*) help "No proper option is Provided";;
esac

echo "pass!"
exit 0


