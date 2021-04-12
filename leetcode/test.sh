
cd $1

echo "[Leetcode $1]"

# cat "_question.md"

if [ -f "cpp_solution.cpp" ]; then
    echo "\n\n[Cpp]"
    g++ -std=c++11 -o cpp_solution.out cpp_solution.cpp && ./cpp_solution.out
    rm cpp_solution.out
fi

if [ -f "go_solution.go" ]; then
    echo "\n\n[Go]"
    go run go_solution.go
fi


if [ -f "scala_solution.scala" ]; then
    echo "\n\n[Scala]"
    scala -deprecation scala_solution.scala
fi

