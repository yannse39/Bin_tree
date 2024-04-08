#!/bin/bash
65;7400;1c
BIN_DIR="./check"

# Définie nos fichiers de test
TEST_FILE=(
  "tests.c"
  "tests_2.c"
  "tests_3.c"
  "tests_4.c"
  "tests_5.c"
)

# Définie nos fichiers de sortie attendue
EXPECTED_OUTPUT_FILE=(
  "tests.out"
  "tests_2.out"
  "tests_3.out"
  "tests_4.out"
  "tests_5.out"
)

# Voici notre fonction pour compiler notre fichier C
function compile_test() {
  local file="$1"
  local output_file="$2"

  gcc -o "$output_file" "$file" -L"$BIN_DIR" -lmybintree -Wall -Werror
}

# Voici notre fonction pour lancer notre test
function run_test() {
  local test_file="$1"
  local expected_output_file="$2"

  local output_file="tmp.out"

  ./"$test_file" > "$output_file"

  diff "$output_file" "$expected_output_file" > /dev/null

  if [ $? -eq 0 ]; then
    echo "Test $test_file réussi"
  else
    echo "Test $test_file échoué"
    echo "Sortie attendue:"
    cat "$expected_output_file"
    echo "Sortie obtenue:"
    cat "$output_file"
  fi

  rm "$output_file"
}

# Compiler les fichiers de test
for file in "${TEST_FILE[@]}"; do
  compile_test "$file" "${file%.*}"
done

# Lancer les tests
for i in "${!TEST_FILE[@]}"; do
  run_test "${BIN_DIR}/${TEST_FILE[$i]}" "${EXPECTED_OUTPUT_FILE[$i]}"
done
