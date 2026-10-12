CREATE TABLE Category(
    category_id INT PRIMARY KEY,
    category_name VARCHAR(50) NOT NULL UNIQUE);

CREATE TABLE Student(
    student_id INT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE,
    phone VARCHAR(15),
    join_date DATE DEFAULT(CURRENT_DATE));

CREATE TABLE Book(
    book_id INT PRIMARY KEY,
    title VARCHAR(150) NOT NULL,
    author VARCHAR(100) NOT NULL,
    price DECIMAL(8, 2) CHECK(price > 0),
    category_id INT NOT NULL,
    FOREIGN KEY(category_id) REFERENCES Category(category_id));

CREATE TABLE Borrow(
    borrow_id INT PRIMARY KEY,
    student_id INT NOT NULL,
    book_id INT NOT NULL,
    issue_date DATE NOT NULL,
    return_date DATE,
    FOREIGN KEY(student_id) REFERENCES Student(student_id),
    FOREIGN KEY(book_id) REFERENCES Book(book_id),
    CHECK(return_date IS NULL OR return_date >= issue_date));