WITH point_table
     AS (SELECT host_team,
                guest_team,
                CASE
                  WHEN host_goals > guest_goals THEN 3
                  WHEN host_goals < guest_goals THEN 0
                  ELSE 1
                END AS host_points,
                CASE
                  WHEN host_goals < guest_goals THEN 3
                  WHEN host_goals > guest_goals THEN 0
                  ELSE 1
                END AS guest_points
         FROM   matches),
     combined_result
     AS (SELECT host_team        AS team_id,
                Sum(host_points) AS total_points
         FROM   point_table
         GROUP  BY host_team
         UNION ALL
         SELECT guest_team        AS team_id,
                Sum(guest_points) AS total_points
         FROM   point_table
         GROUP  BY guest_team)
SELECT a.team_id,
       a.team_name,
       SUM(IFNULL(b.total_points, 0)) AS num_points
FROM   teams a
       LEFT JOIN combined_result b
              ON a.team_id = b.team_id
GROUP  BY a.team_id
ORDER  BY num_points DESC,
          a.team_id ASC; 