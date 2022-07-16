#!/bin/bash
echo "size = $1"
ARG=$(ruby -e "puts (0..$1).to_a.shuffle.join(' ')")
echo "times =  $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker_linux $ARG