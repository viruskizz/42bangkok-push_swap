#!/bin/bash
echo "size = $1"
ARG=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
echo "times =  $(./push_swap $ARG | wc -l)"
if [[ "$OSTYPE" == "darwin"* ]]; then
    ./push_swap $ARG | ./checker_Mac $ARG
else
    ./push_swap $ARG | ./checker_linux $ARG
fi
if [ -n "$2" ]; then
    echo "detail"
    ./push_swap $ARG
fi
# ./push_swap $(ruby -e "puts (1..500).to_a.shuffle.join(' ')") | wc -l
# ARG=$(ruby -e "puts (1..499).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
# ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker_Mac $ARG