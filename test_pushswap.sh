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
BOLD="\033[1m"
RESET="\033[0m"

## Function
print_result()
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

    printf "%4s\t%s\t%s\t%s/5\t" $SIZE $OUTPUT $TIMES $POINT
    if [ $POINT -eq 0 -o "$OUTPUT" == "KO" ];then
        echo -en $RED"FAIL"
    elif [ $POINT -eq 1 ];then
        echo -en $MAGENTA"PASS"
    elif [ $POINT -eq 2 ];then
        echo -en $YELLOW"PASS"
    elif [ $POINT -eq 3 ];then
        echo -en $GRAY"PASS"
    elif [ $POINT -eq 4 ];then
        echo -en $CYAN"PASS"
    elif [ $POINT -eq 5 ];then
        echo -en $GREEN"PASS"
    fi
    echo -e $RESET
}

test_size()
{
    START=$1
    END=$2
    N=$3
    iTime=0
    TOTAL=0
    echo -e $BLUE"Random: $START - $END"$RESET
    echo -e $BOLD"Size\tSorted\tTimes\tPoint\tStatus"$RESET
    for (( i=1; i<=$N; i++ ))
    do
        SIZE=$(($END-$START+1))
        ARG=$(ruby -e "puts ($START..$END).to_a.shuffle.join(' ')")
        TIMES=$(./$FILE $ARG | wc -l)
        if [[ "$OSTYPE" == "darwin"* ]]; then
            OUTPUT=$(./$FILE $ARG | ./checker_Mac $ARG)
        else
            OUTPUT=$(./$FILE $ARG | ./checker_linux $ARG)
        fi
        TOTAL=$(($TOTAL+TIMES))
        print_result $SIZE $TIMES $OUTPUT
    done
    printf "\033[4mSummary\n"$RESET
    printf "• Size: %d\n" $END
    printf "• Run: %d\n" $N
    printf "• Average: %d\n" $(( $TOTAL/$N ))
    echo
}

print_compare()
{
    ARG=$1
    EXPECT=$2
    if [[ $EXPECT == "Error" ]]; then
        ERR=error.log
        OUTPUT=$(./$FILE $ARG 2>$ERR && cat $ERR)
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
        OUTPUT=$(./$FILE $ARG 2>&1)
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
#
# Validation Test
printf $BLUE"Validation Test\n"$RESET
printf "$BOLD%-27s%-10s%s$RESET\n" "Name" "Status" "Result/Expect"
#1
printf "1. %-25s" "Invalid \$ARG"
ARG="abc"
print_compare "$ARG" "Error"
#2
printf "2. %-25s" "Mixin invalid \$ARG"
ARG="1 2 a"
print_compare "$ARG" "Error"
#3
printf "3. %-25s" "Dupplicated \$ARG"
ARG="1 2 3 1"
print_compare "$ARG" "Error"
#4
printf "4. %-25s" "MAX_INT++"
ARG="9999999999"
print_compare "$ARG" "Error"
#5
printf "5. %-25s" "Mixin MAX_INT++"
ARG="1 2 3 9999999999"
print_compare "$ARG" "Error"
#6
printf "6. %-25s" "No \$ARG"
ARG=
print_compare "$ARG" ""
#7
printf "7. %-25s" "Empty \$ARG"
ARG=""
print_compare "$ARG" ""
#8
printf "8. %-25s" "Single \$ARG"
ARG="1"
print_compare "$ARG" ""
#9
printf "9. %-25s" "Sorted \$ARG"
ARG="1 2 3"
print_compare "$ARG" ""
#10
printf "10.%-25s" "Sorted \$ARG"
ARG="1 2 3 4 5 6 7 8 9"
print_compare "$ARG" ""
echo

## Random Size Test
#
# Number: [1 - 3] * 5 
START=1
END=3
ROUND=5
test_size $START $END $ROUND
# Number: [1 - 5] * 10 
START=1
END=5
ROUND=10
test_size $START $END $ROUND
# Number: [1 - 100] * 20
START=1
END=100
ROUND=20
test_size $START $END $ROUND
# Number: [1 - 500] * 20
START=1
END=500
ROUND=20
test_size $START $END $ROUND