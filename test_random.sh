#!/bin/bash
## Setup
FILE="push_swap"

## Constant Variable
GREEN="\033[1;32m"
GRAY="\033[1;37m"
CYAN="\033[1;36m"
BLUE="\033[1;34m"
YELLOW="\033[1;33m"
MAGENTA="\033[1;35m"
LRED="\033[1;91m"
RED="\033[1;31m"
BOLD="\033[1;37m"
RESET="\033[0m"

## Function
print_times()
{
    SIZE=$1
    TIMES=$2
    OUTPUT=$3
    POINT=0
    if [ $SIZE -le 3 ];
    then
        if [ $TIMES -le 2 ];then
            POINT=5
        fi
    elif [ $SIZE -le 5 ];
    then
        if [ $TIMES -le 8 ];then
            POINT=5
        elif [ $TIMES -le 12 ];then
            POINT=3
        fi
    elif [ $SIZE -le 100 ];then
        if [ $TIMES -le 700 ];then
            POINT=5
        elif [ $TIMES -le 900 ];then
            POINT=4
        elif [ $TIMES -le 1100 ];then
            POINT=3
        elif [ $TIMES -le 1300 ];then
            POINT=2
        elif [ $TIMES -le 1500 ];then
            POINT=1
        fi
    elif [ $SIZE -le 500 ];then
        if [ $TIMES -le 5500 ];then
            POINT=5
        elif [ $TIMES -le 7000 ];then
            POINT=4
        elif [ $TIMES -le 8500 ];then
            POINT=3
        elif [ $TIMES -le 10000 ];then
            POINT=2
        elif [ $TIMES -le 11500 ];then
            POINT=1
        fi
    fi

    ## PRINT OUTPUT
    printf $GRAY"Size:$RESET %s\n" $SIZE
    printf $GRAY"Sorted:$RESET %s\n" $OUTPUT
    printf $GRAY"Times:$RESET %d\n" $TIMES
    printf $GRAY"Point:$RESET %d/5\n" $POINT
    if [ $POINT -eq 0 -o "$OUTPUT" == "KO" ];then
        printf $BOLD"Status:$RESET$RED FAIL"
    elif [ $POINT -eq 1 ];then
        printf $BOLD"Status:$RESET$MAGENTA PASS"
    elif [ $POINT -eq 2 ];then
        printf $BOLD"Status:$RESET$YELLOW PASS"
    elif [ $POINT -eq 3 ];then
        printf $BOLD"Status:$RESET$GRAY PASS"
    elif [ $POINT -eq 4 ];then
        printf $BOLD"Status:$RESET$CYAN PASS"
    elif [ $POINT -eq 5 ];then
        printf $BOLD"Status:$RESET$GREEN PASS"
    fi
    echo -e $RESET
    if [[ "$OUTPUT" == "KO" ]];then
        printf $BOLD"ARG:$RESET $ARG\n"
    fi
}

push_swap_test()
{
    START=$1
    END=$2
    SIZE=$(($END-$START+1))
    ARG=$(ruby -e "puts ($START..$END).to_a.shuffle.join(' ')")
    TIMES=$(./$FILE $ARG | wc -l)
    if [[ "$OSTYPE" == "darwin"* ]]; then
        OUTPUT=$(./$FILE $ARG | ./checker_Mac $ARG)
    else
        OUTPUT=$(./$FILE $ARG | ./checker_linux $ARG)
    fi
    # echo -en "$SIZE\t"
    print_times $SIZE $TIMES $OUTPUT $ARG
}


## Main script
if [ -z $1 ];then
    START=1
    END=$(( ( RANDOM % 500 )  + 1 ))
elif [ -z $2 ];then
    START=1
    END=$1
else
    START=$1
    END=$2
fi
push_swap_test $START $END

## NOTE
# ./push_swap $(ruby -e "puts (1..500).to_a.shuffle.join(' ')") | wc -l
# ARG=$(ruby -e "puts (1..499).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
# ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker_Mac $ARG