#!/bin/bash
echo "size = $1"
ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
echo "times =  $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker_Mac $ARG
if [ -n "$2" ]; then
    echo "detail"
    ./push_swap $ARG
fi
# ./push_swap $(ruby -e "puts (1..500).to_a.shuffle.join(' ')") | wc -l
# ARG=$(ruby -e "puts (1..499).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
# ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker_linux $ARG