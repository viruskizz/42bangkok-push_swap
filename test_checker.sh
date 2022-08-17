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
    if [[ $EXPECT == "Error" ]]; then
        ERR=error.log
        OUTPUT=$(echo -en $INPUT | ./$FILE $ARG 2>$ERR && cat $ERR)
        if [ -z $(cat $ERR) ]; then
            echo -en $RED"STDERR"
        elif [[ $(cat $ERR) == $EXPECT ]]; then
            echo -en $GREEN"PASS"
        else
            echo -en $RED"FAIL"
        fi
        if [ -f $ERR ]; then
            /bin/rm $ERR
        fi
    else
        OUTPUT=$(echo -en $INPUT | ./$FILE $ARG 2>&1)
        if [[ $OUTPUT == $EXPECT ]]; then
            echo -en $GREEN"PASS"
        else
            echo -en $RED"FAIL"
        fi
    fi
    echo -en $RESET
    echo -en "\t$OUTPUT/$EXPECT"
    echo
}

## Execute Test
echo -e $BLUE"Test Input"$RESET
printf "$BOLD%-27s%-10s%s$RESET\n" "Name" "Status" "Result/Expect"
#1
printf "1. %-25s" "Invalid \$ARG"
INPUT=""
ARG="abc"
print_compare "$INPUT" "$ARG" "Error"
#2
printf "2. %-25s" "Mixin invalid \$ARG"
INPUT=""
ARG="1 2 a"
print_compare "$INPUT" "$ARG" "Error"
#2
printf "2. %-25s" "Dupplicated \$ARG"
INPUT=""
ARG="1 2 1"
print_compare "$INPUT" "$ARG" "Error"
#4
printf "4. %-25s" "MAX_INT++"
INPUT=""
ARG="9999999999"
print_compare "$INPUT" "$ARG" "Error"
#5
printf "5. %-25s" "Mixin MAX_INT++"
INPUT=""
ARG="1 2 3 9999999999"
print_compare "$INPUT" "$ARG" "Error"
#6
printf "6. %-25s" "No \$ARG"
INPUT=""
ARG=
print_compare "$INPUT" "$ARG" ""
#7
printf "7. %-25s" "Empty \$ARG"
INPUT=""
ARG=""
print_compare "$INPUT" "$ARG" ""
#8
printf "8. %-25s" "All input"
INPUT="sa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\npa\npb\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "KO"
#9
printf "9. %-25s" "No opteration input"
INPUT="abcd\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "Error"
#10
printf "10.%-25s" "Space input"
INPUT="\s\s\s\s\ssa\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "Error"
#11
printf "11.%-25s" "Tab input"
INPUT="sa\t\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "Error"
#12
printf "12.%-25s" "Newline input"
INPUT="\n"
ARG="1 2 3"
print_compare "$INPUT" "$ARG" "Error"
#13
printf "13.%-25s" "KO Test"
INPUT="sa\npb\nrrr\n"
ARG="0 9 1 8 2 7 3 6 4 5"
print_compare "$INPUT" "$ARG" "KO"
#14
printf "14.%-25s" "Sorted input"
INPUT="ra\nsa\n"
ARG="3 2 1"
print_compare "$INPUT" "$ARG" "OK"
#15
printf "15.%-25s" "OK Test"
INPUT="pb\nra\npb\nra\nsa\nra\npa\npa\n"
ARG="0 9 1 8 2"
print_compare "$INPUT" "$ARG" "OK"