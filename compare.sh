g++ -std=c++20 -I . -Wall -O2 -o gen_r $1
g++ -std=c++20 -I . -Wall -O2 -o sol1_r $2
g++ -std=c++20 -I . -Wall -O2 -o sol2_r $3
many=$4
ctr=0
while [ $ctr -lt $many ]
do
    ./gen_r $ctr > case.txt
    ./sol1_r < case.txt > submit1.txt
    ./sol2_r < case.txt > submit2.txt
    if ! diff submit1.txt submit2.txt; then
        echo "differ on seed" $ctr
        break
    fi
    echo "seed" $ctr "passed."
    ctr=`expr $ctr + 1`
done
rm gen_r
rm sol1_r
rm sol2_r