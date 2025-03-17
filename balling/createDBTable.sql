CREATE DATABASE IF NOT EXISTS balling_db;
GRANT ALL PRIVILEGES ON balling_db.* TO 'bangme'@'%';

USE balling_db;

CREATE TABLE IF NOT EXISTS score_records (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    play_date DATE NOT NULL,
    score INT NOT NULL
);

CREATE TABLE IF NOT EXISTS user_monthly_stats (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    year INT NOT NULL,
    month INT NOT NULL,
    play_count INT NOT NULL DEFAULT 0,
    UNIQUE KEY unique_user_month (username, year, month)
);