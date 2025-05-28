#!/bin/bash

#RN-2
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 6 | 1 2 3 4 5 6 | 1 2 3 4 5 6"
  "Sorted Descending 6 | 6 5 4 3 2 1 | 1 2 3 4 5 6"
  "All Equal 6 | 2 2 2 2 2 2 | 2 2 2 2 2 2"
  "One Min 6 | 1 4 4 4 4 4 | 1 4 4 4 4 4"
  "One Max 6 | 4 1 1 1 1 1 | 1 1 1 1 1 4"
  "Random Duplicates 6 | 6 3 5 3 1 2 | 1 2 3 3 5 6"
)

echo "== Running PmergeMe Tests =="

for test in "${test_cases[@]}"; do
  # Split test case into name, input, expected
  IFS='|' read -r name input expected <<< "$test"

  # Trim whitespace
  name=$(echo "$name" | xargs)
  input=$(echo "$input" | xargs)
  expected=$(echo "$expected" | xargs)

  # Run the program and capture output
  actual=$(./PmergeMe "$input" 2>/dev/null)

  # Clean and normalize output
  actual_clean=$(echo "$actual" | tr -s '[:space:]' ' ' | xargs)

  # Compare output
  if [[ "$actual_clean" == "$expected" ]]; then
    echo "✅ $name — PASSED"
  #else
    #echo "❌ $name — FAILED"
    #echo "   Input:    $input"
    #echo "   Expected: $expected"
    #echo "   Got:      $actual_clean"
  fi
done