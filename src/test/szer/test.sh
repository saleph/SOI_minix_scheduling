#!bin/sh
echo ""
echo "Process group A\n"
time ./a.out A &
echo ""
echo "Process group B\n"
time ./a.out B &
echo ""
echo "Process group C\n"
time ./a.out C &
echo ""
