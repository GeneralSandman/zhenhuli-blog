
cd $1

echo "[Leetcode $1]"

cat "_question.md"

echo "\n\n[Cpp]"
g++ -std=c++11 -o test.out test.cpp && ./test.out
rm test.out

echo "\n\n[Go]"
go run test.go

echo "\n\n[Scala]"
scala -deprecation test.scala
