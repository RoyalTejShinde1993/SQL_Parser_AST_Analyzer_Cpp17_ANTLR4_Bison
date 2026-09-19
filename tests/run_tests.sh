#!/usr/bin/env bash

set -u

ANALYZER="./build/sql_analyzer"

passed=0
failed=0

run_test() {
    local name="$1"
    local sql="$2"

    echo "----------------------------------------"
    echo "TEST: $name"
    echo "SQL:  $sql"

    if output=$($ANALYZER "$sql" 2>&1); then
        if echo "$output" | grep -q "Semantic analysis: valid"; then
            echo "PASS"
            ((passed++))
        else
            echo "FAIL"
            echo "$output"
            ((failed++))
        fi
    else
        echo "FAIL"
        echo "$output"
        ((failed++))
    fi
}

run_negative_test() {
    local name="$1"
    local sql="$2"
    local expected="$3"

    echo "----------------------------------------"
    echo "TEST: $name"
    echo "SQL:  $sql"

    output=$($ANALYZER "$sql" 2>&1)

    if echo "$output" | grep -q "Semantic analysis: invalid" &&
       echo "$output" | grep -q "$expected"; then
        echo "PASS"
        ((passed++))
    else
        echo "FAIL"
        echo "$output"
        ((failed++))
    fi
}

# ============================================================
# Positive tests
# ============================================================

run_test "Basic SELECT" \
    "SELECT name FROM users;"

run_test "DISTINCT" \
    "SELECT DISTINCT name FROM users;"

run_test "Alias" \
    "SELECT name AS username FROM users;"

run_test "Qualified column" \
    "SELECT users.name FROM users;"

run_test "Wildcard" \
    "SELECT * FROM users;"

run_test "Table wildcard" \
    "SELECT users.* FROM users;"

run_test "WHERE comparison" \
    "SELECT name FROM users WHERE id = 1;"

run_test "AND" \
    "SELECT name FROM users WHERE id = 1 AND name = 'Alice';"

run_test "OR" \
    "SELECT name FROM users WHERE id = 1 OR name = 'Alice';"

run_test "Arithmetic" \
    "SELECT name FROM users WHERE id + 1 > 2;"

run_test "IS NULL" \
    "SELECT name FROM users WHERE email IS NULL;"

run_test "IS NOT NULL" \
    "SELECT name FROM users WHERE email IS NOT NULL;"

run_test "IN" \
    "SELECT name FROM users WHERE id IN (1, 2, 3);"

run_test "NOT IN" \
    "SELECT name FROM users WHERE id NOT IN (1, 2, 3);"

run_test "String IN" \
    "SELECT name FROM users WHERE name IN ('Alice', 'Bob');"

run_test "JOIN" \
    "SELECT users.name FROM users JOIN orders ON users.id = orders.user_id;"

run_test "GROUP BY" \
    "SELECT name, COUNT(id) FROM users GROUP BY name;"

run_test "HAVING" \
    "SELECT name, COUNT(id) FROM users GROUP BY name HAVING COUNT(id) > 1;"

run_test "HAVING grouped column" \
    "SELECT name, COUNT(id) FROM users GROUP BY name HAVING name = 'Alice';"

run_test "HAVING aggregate expression" \
    "SELECT name, COUNT(id) FROM users GROUP BY name HAVING COUNT(id) + 1 > 2;"

run_test "MIN" \
    "SELECT MIN(id) FROM users;"

run_test "MAX" \
    "SELECT MAX(id) FROM users;"

run_test "MIN MAX GROUP BY" \
    "SELECT name, MIN(id), MAX(id) FROM users GROUP BY name;"

run_test "SUM" \
    "SELECT SUM(amount) FROM orders;"

run_test "AVG" \
    "SELECT AVG(amount) FROM orders;"

run_test "SUM AVG GROUP BY" \
    "SELECT user_id, SUM(amount), AVG(amount) FROM orders GROUP BY user_id;"

run_test "Multiple GROUP BY columns" \
    "SELECT name, email, COUNT(id) FROM users GROUP BY name, email;"

run_test "Qualified GROUP BY" \
    "SELECT users.name, COUNT(users.id) FROM users GROUP BY users.name;"

run_test "Expression GROUP BY" \
    "SELECT id + 1, COUNT(id) FROM users GROUP BY id;"

run_test "Aggregate expression GROUP BY" \
    "SELECT SUM(amount) + 10 FROM orders GROUP BY user_id;"

run_test "Multiple columns in expression GROUP BY" \
    "SELECT name + email, COUNT(id) FROM users GROUP BY name, email;"

run_test "ORDER BY" \
    "SELECT name FROM users ORDER BY name ASC;"

run_test "Multiple ORDER BY" \
    "SELECT name FROM users ORDER BY name ASC, id DESC;"

run_test "Aggregate expression GROUP BY" \
    "SELECT SUM(amount) + 10 FROM orders GROUP BY user_id;"

# ============================================================
# Negative semantic tests
# ============================================================

run_negative_test "Unknown column" \
    "SELECT unknown FROM users;" \
    "Unknown column: unknown"

run_negative_test "Unknown table" \
    "SELECT name FROM products;" \
    "Unknown table: products"

run_negative_test "Invalid qualified column" \
    "SELECT users.name FROM orders;" \
    "Unknown table or alias: users"

run_negative_test "Unknown WHERE column" \
    "SELECT name FROM users WHERE unknown = 1;" \
    "Unknown column: unknown"

run_negative_test "Unknown IN column" \
    "SELECT name FROM users WHERE unknown IN (1, 2, 3);" \
    "Unknown column: unknown"

run_negative_test "Unknown JOIN column" \
    "SELECT users.name FROM users JOIN orders ON users.unknown = orders.user_id;" \
    "Unknown column: users.unknown"

run_negative_test "Ungrouped SELECT column" \
    "SELECT name, email, COUNT(id) FROM users GROUP BY name;" \
    "Column 'email' must appear in GROUP BY or be used in an aggregate function."

run_negative_test "Ungrouped column with expression" \
    "SELECT id + 1, email, COUNT(id) FROM users GROUP BY id;" \
    "Column 'email' must appear in GROUP BY or be used in an aggregate function."

run_negative_test "HAVING ungrouped column" \
    "SELECT name, COUNT(id) FROM users GROUP BY name HAVING email = 'x';" \
    "HAVING expression contains a column that must appear in GROUP BY or be used in an aggregate function."

run_negative_test "Aggregate in GROUP BY" \
    "SELECT COUNT(id) FROM users GROUP BY COUNT(id);" \
    "GROUP BY expression cannot contain an aggregate function."

# ============================================================
# Summary
# ============================================================

echo
echo "========================================"
echo "Regression Test Summary"
echo "========================================"
echo "Passed: $passed"
echo "Failed: $failed"
echo "Total:  $((passed + failed))"
echo "========================================"

if [ "$failed" -eq 0 ]; then
    exit 0
else
    exit 1
fi