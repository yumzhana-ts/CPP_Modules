#!/bin/bash

# Define test cases: input => expected output
declare -a tests=(
  "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
  "7 7 * 7 -" "42"
  "1 2 * 2 / 2 * 2 4 - +" "0"
  "(1 + 1)" "Error"

  # Extra operands left on stack
  "5 5 +" "10"
  "5 5 + 3" "Error"

  # Too few operands
  "+" "Error"
  "1 +" "Error"
  "*" "Error"
  "4 /" "Error"

  # Division and subtraction order test
  "8 2 /" "4"
  "8 2 -" "6"
  "2 9 -" "-7"

  # Negative number results
  "2 3 -" "-1"
  "3 2 -" "1"

  # Deep stack operations
  "9 7 1 1 + - / 3 * 2 1 1 + + -" "-1"

  # Very invalid input
  "1 2 + garbage" "Error"
  "" "Error"
  " " "Error"

  # Division by zero
  "9 0 /" "Error"

  # Complex but valid
  "3 5 8 * 7 + *" "141"
)

# Run through the tests
echo "Running RPN tests..."
for ((i=0; i<${#tests[@]}; i+=2)); do
  input=${tests[i]}
  expected=${tests[i+1]}
  output=$(./RPN "$input" 2>&1)

  if [ "$output" == "$expected" ]; then
    echo "✅ Test $((i/2+1)) passed: ./RPN \"$input\" → $output"
  else
    echo "❌ Test $((i/2+1)) failed: ./RPN \"$input\" → $output (expected: $expected)"
  fi
done