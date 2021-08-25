#!/bin/bash
#Gets needed output colors
NONE='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
PINK='\033[0;35m'

#Start message, creates filepath to restaurants, creates new cpp line for file
echo -e "${GREEN}Start setup${NONE}"

#checks if user has .bash_aliases or .bash_profile created
cd ~ 
if test -f ".bash_aliases";
then
   profile="$(pwd)/.bash_aliases"
elif test -f ".bash_profile";
then
   profile="$(pwd)/.bash_profile"
else
   profile='none'
fi
cd - &> error #gets rid of stupid path message


#Creates Picker program and removes tmp file
g++ -Wall -std=c++17 -o cFileMaker $(pwd)/cFileMaker.cpp

#if person has bash file asks if they want to add alias (Optional)
if [[ "$profile" == "none" ]];
then
   #No profile found
   echo -e "${ORANGE}If you wish to use globally set up a bash profile/alias file and create alias for program${NONE}"
else
   #Getting input
   echo -e "${ORANGE}Optional: Add alias to ${GREEN}$profile${ORANGE}?\n(hit enter to skip)${PINK}"
   sleep 1
   read -p "Alias Name: " name
   #Tests for command
   if [[ "$name" == "" ]];
   then
      echo -e "${RED}Not adding alias${NONE}"
   else
      #Adds alias to correct file
      echo "alias $name='$(pwd)/cFileMaker'" >> $profile
      echo -e "${GREEN}Alias ${ORANGE}'$name'${GREEN} added to ${ORANGE}$profile ${GREEN}file${NONE}"
      #Tells user how to source file
      echo -e "${ORANGE}You must type command: '${GREEN}source $profile${ORANGE}' to execute globally${NONE}"
   fi
fi
sleep 1
echo -e "${GREEN}End setup${NONE}" #Done
