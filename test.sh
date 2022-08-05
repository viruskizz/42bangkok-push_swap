#!/bin/bash
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
print_header()
{
    START=$1
    END=$2
    echo -e $BLUE"Random: $START - $END"$RESET
    echo -e $BOLD"Size\tSorted\tTimes\tPoint\tStatus"$RESET
}

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

    ## PRINT OUTPUT
    printf  "%4s\t" $SIZE
    echo -en "$OUTPUT\t"
    echo -en "$TIMES\t"
    echo -en "$POINT/5\t"
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

iTime=0
push_swap_test()
{
    START=$1
    END=$2
    SIZE=$(($END-$START+1))
    ARG=$(ruby -e "puts ($START..$END).to_a.shuffle.join(' ')")
    TIMES=$(./push_swap $ARG | wc -l)
    if [[ "$OSTYPE" == "darwin"* ]]; then
        OUTPUT=$(./push_swap $ARG | ./checker_Mac $ARG)
    else
        OUTPUT=$(./push_swap $ARG | ./checker_linux $ARG)
    fi
    iTime=TIMES
    print_result $SIZE $TIMES $OUTPUT
}

test_size()
{
    START=1
    END=$1
    N=$2
    iTime=0
    TOTAL=0
    print_header $START $END
    for (( i=1; i<=$N; i++ ))
    do
        push_swap_test $START $END
        TOTAL=$(($TOTAL+iTime))
    done
    echo -e "\033[4mSummary"$RESET
    printf "• Size: %d\n" $END
    printf "• Run: %d\n" $N
    printf "• Average: %d\n" $(( $TOTAL/$N ))
    echo
}

print_failure()
{
    ARG=$1
    NAME=$2
    OUTPUT=$(./push_swap abc 2>&1)
    # OUTPUT=$(echo "abc" 2>&1)
    echo -en $NAME"\t\t"
    if [ -z "$OUTPUT" ]; then
        echo -en $RED"Stderr"
    elif [[ $OUTPUT == "Error" ]]; then
        echo -en $GREEN"PASS"
    else
        echo -en $RED"FAIL"
    fi
    echo -e $RESET
}
test_fail()
{
    echo -e $BLUE"Failure Test expect Error"$RESET
    echo -e $BOLD"Argument\tStatus"$RESET
    print_failure "abc" "abc"
    print_failure "1 2 a" "1 2 a"
    print_failure "9999999999" "MAX*1"
    print_failure "1 2 3 9999999999" "MAX*4"
    echo
    echo -e $BLUE"Empty Test expect nothing"$RESET
    echo -e $BOLD"Argument\tStatus"$RESET
    echo -en "Empty\t\t"
    if [ -z $(./push_swap) ]; then echo -e $GREEN"PASS"$RESET; else echo -e $RED"FAIL"$RESET; fi
    echo -en "Sorted\t\t"
    if [ -z $(./push_swap 1 2 3) ]; then echo -e $GREEN"PASS"$RESET; else echo -e $RED"FAIL"$RESET; fi
    echo
}

## Execute Test
test_fail
test_size 3 5
test_size 5 10
test_size 100 20
test_size 500 20