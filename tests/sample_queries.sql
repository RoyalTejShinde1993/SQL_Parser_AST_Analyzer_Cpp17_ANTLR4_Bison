-- Basic SELECT
SELECT name FROM users;

-- DISTINCT
SELECT DISTINCT name FROM users;

-- Alias
SELECT name AS username FROM users;

-- Qualified column
SELECT users.name FROM users;

-- Wildcard
SELECT * FROM users;

-- Table wildcard
SELECT users.* FROM users;

-- WHERE comparison
SELECT name FROM users WHERE id = 1;

-- AND / OR
SELECT name FROM users WHERE id = 1 AND name = 'Alice';
SELECT name FROM users WHERE id = 1 OR name = 'Alice';

-- Arithmetic
SELECT name FROM users WHERE id + 1 > 2;

-- NULL checks
SELECT name FROM users WHERE email IS NULL;
SELECT name FROM users WHERE email IS NOT NULL;

-- IN
SELECT name FROM users WHERE id IN (1, 2, 3);

-- NOT IN
SELECT name FROM users WHERE id NOT IN (1, 2, 3);

-- String IN
SELECT name FROM users WHERE name IN ('Alice', 'Bob');

-- JOIN
SELECT users.name FROM users JOIN orders ON users.id = orders.user_id;

-- GROUP BY
SELECT name, COUNT(id) FROM users GROUP BY name;

-- HAVING
SELECT name, COUNT(id) FROM users GROUP BY name HAVING COUNT(id) > 1;

-- ORDER BY
SELECT name FROM users ORDER BY name ASC;

-- Multiple ORDER BY
SELECT name FROM users ORDER BY name ASC, id DESC;
