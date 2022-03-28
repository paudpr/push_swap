# push_swap

Test:

ARG=`seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '`; ./push_swap $ARG ./checker_Mac $ARG