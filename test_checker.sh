#!/bin/bash
## Setup
FILE="checker"

## Constant Variable
GREEN="\033[1;32m"
GRAY="\033[1;37m"
CYAN="\033[1;36m"
BLUE="\033[1;34m"
YELLOW="\033[1;33m"
MAGENTA="\033[1;35m"
LRED="\033[1;91m"
RED="\033[1;31m"
BOLD="\033[1m"
RESET="\033[0m"

print_compare()
{
    INPUT=$1
    ARG=$2
    EXPECT=$3
    OUTPUT=$(echo -en $INPUT | ./$FILE $ARG 2>&1)
    if [[ $OUTPUT == $EXPECT ]]; then
        echo -en $GREEN"PASS"
    else
        echo -en $RED"FAIL"
    fi
    echo -en $RESET
    echo -en "\t$OUTPUT/$EXPECT"
    echo
}

## Execute Test
echo -e $BLUE"Test Input"$RESET
printf "$BOLD%-22s%-10s%s$RESET\n" "Name" "Status" "Result/Expect"
#1
printf "1. %-20s" "Invalid \$ARG"
INPUT=""
ARG="abc"
print_compare "$INPUT" "$ARG" "Error"
#2
printf "2. %-20s" "Mixin invalid \$ARG"
INPUT=""
ARG="1 2 a"
print_compare "$INPUT" "$ARG" "Error"
#3
printf "3. %-20s" "MAX_INT++"
INPUT=""
ARG="9999999999"
print_compare "$INPUT" "$ARG" "Error"
#4
printf "4. %-20s" "Mixin MAX_INT++"
INPUT=""
ARG="1 2 3 9999999999"
print_compare "$INPUT" "$ARG" "Error"
#5
printf "5. %-20s" "Empty \$ARG"
INPUT=""
ARG=""
print_compare "$INPUT" "$ARG" ""
#6
printf "6. %-20s" "All input"
INPUT="sa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\npa\npb\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "KO"
#7
printf "7. %-20s" "Invalid input"
INPUT="abcd\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "Error"
#8
printf "8. %-20s" "Newline input"
INPUT="\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "Error"
#9
printf "10. %-20s" "Sorted input"
INPUT="ra\nsa\n"
ARG="3 2 1"
print_compare "$INPUT" "$ARG" "OK"