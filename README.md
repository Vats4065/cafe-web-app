# Café Management System

## Overview

The Café Management System is a simple C-based console application that allows users to manage their orders, sign up, and log in to their accounts. Admin users can manage the menu and view orders.

## Features

- User Signup and Login
- User Dashboard with options to:
  - View Café Menu
  - Place Orders
  - View Current Orders
  - Delete Orders
- Admin Dashboard with options to:
  - Manage Menu
  - View All Orders
  - View Registered Users

## File Structure

./cafe-app
./data
menu.txt
orders.txt
users.txt
./src
admin_dashboard.c
login.c
signyp.c
main.c
user_dashboard.c

## Compilation and Execution

To compile and run the application, follow these steps:

1. Navigate to the `src` directory.
2. Compile the code using GCC:
   $ gcc -o cafe_management main.c signup.c login.c user_dashboard.c admin_dashboard.c
   $ ./cafe_management^C
