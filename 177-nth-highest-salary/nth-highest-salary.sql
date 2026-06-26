CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
    -- SELECT (
    --       SELECT DISTINCT salary
    --       FROM Employee
    --       ORDER BY salary DESC
    --       LIMIT 1 OFFSET N

        -- )

        
            select distinct salary from employee
            order by salary desc
            limit n,1
    );
END