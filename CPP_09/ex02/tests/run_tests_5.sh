#!/bin/bash

WTF-/? RN-1 
#RN-2
# Define test cases: "name | input | expected_output"
test_cases=(
  "Sorted Ascending 5 | 1 2 3 4 5 | 1 2 3 4 5"
  "Sorted Descending 5 | 5 4 3 2 1 | 1 2 3 4 5"
  "All Equal 5 | 6 6 6 6 6 | 6 6 6 6 6"
  "One Min 5 | 1 8 8 8 8 | 1 8 8 8 8"
  "One Max 5 | 8 1 1 1 1 | 1 1 1 1 8"
  "Random Duplicates 5 | 3 1 4 1 5 | 1 1 3 4 5"
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
  else
    echo "❌ $name — FAILED"
    echo "   Input:    $input"
    echo "   Expected: $expected"
    echo "   Got:      $actual_clean"
  fi
done