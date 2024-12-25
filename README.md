# **Movie Recommendation System**

## **Description**
This project implements a simple movie recommendation system using the C programming language. The system allows users to register, rate movies, and receive recommendations based on collaborative filtering. It demonstrates fundamental concepts of C, including file handling, arrays, and modular programming.

---

## **Features**
### **1. Register User**
- Allows new users to register with a username.
- Validates username uniqueness (case-insensitive).
- Stores user data in `user_data.txt`.
- **Outputs**:
  - **Success**: User is successfully registered.
  - **Error**: User already exists. Please choose a different name.

### **2. Display Movies**
- Displays a list of all available movies stored in `movie_database.txt`.
- Formats movies in an indexed list with details such as title, genre, and average rating.

### **3. Rate a Movie**
- Allows users to rate movies.
- **Validates**:
  - **User existence in `user_data.txt`.**
  - **Valid movie index (from the displayed list).**
  - **Rating value (between 1 and 5).**
- Stores ratings in an m x n matrix and saves them in `user_ratings.txt`.
- **Outputs**:
  - **Success**: Rating recorded successfully.
  - **Error**: User not found. Please register first.

### **4. Get Movie Recommendations**
- Recommends movies to users based on collaborative filtering.
- Excludes movies already rated by the user.
- Uses the average rating of other users to predict preferences.
- **Outputs**:
  - List of recommended movies with predicted ratings.
  - **Error**: User not found. Please register first.

### **5. Exit**
- Gracefully terminates the application.
- Releases all allocated resources.

---

## **Technical Details**
### **Programming Language**
C

### **Files Used**
- `user_data.txt`: Stores user registration details.
- `movie_database.txt`: Contains a list of available movies.
- `user_ratings.txt`: Stores the movie ratings in an m x n matrix format.

### **Recommendation Algorithm**
- Implements collaborative filtering by averaging the ratings of other users for unseen movies.
- **Formula**:  
  \[
  R(u, i) = \frac{\sum R(v, i)}{N}
  \]
  Where:
  - \( R(u, i) \): Predicted rating for user \( u \) and movie \( i \).
  - \( R(v, i) \): Rating given by another user \( v \) to movie \( i \).
  - \( N \): Total number of users who rated movie \( i \).

---

## **Structure Overview**
### **`people.h`**
- Defines a `struct people` that contains:
  - `int count`: Tracks the number of users.
  - `char name[20]`: Stores the user’s name.
  - 10 `float` values for movie ratings.

### **`main.c`**
- Manages the program's main menu and integrates the functionalities of other modules.
- **Memory Allocation**:
  - Allocates memory for up to 20 users using `malloc`.
  - Reads user data (`user_data.txt`) and movie ratings (`user_ratings.txt`) to initialize the program state.
- **Key Functions**:
  - `registration(int i, struct people *viewer)` for user registration.
  - `movieDisplay()` for displaying movies.
  - `movieRate(int i, struct people *viewer)` for rating movies.
  - `formula(struct people *viewer)` for generating recommendations.

### **`user.c`**
- Handles user registration:
  - Reads and writes to `user_data.txt`.
  - Ensures unique usernames using `strcasecmp`.
  - Appends new users to `user_data.txt` and initializes their movie ratings to `0` in `user_ratings.txt`.

### **`display.c`**
- Displays all movies from `movie_database.txt` in a formatted, indexed manner.

### **`rateMovie.c`**
- Handles movie rating:
  - Validates user and movie index inputs.
  - Updates the `user_ratings.txt` file with new ratings.

### **`recommendation.c`**
- Generates movie recommendations:
  - Uses collaborative filtering to predict average ratings for unrated movies.
  - Skips movies already rated by the user.
  - Computes average ratings for unseen movies by iterating through all users.

---

## **Key Learnings**
- File operations for reading, writing, and validating user and movie data.
- Modular programming with structured functions for registration, rating, and recommendations.
- Collaborative filtering for personalized recommendations.
- Validation of user inputs and graceful error handling.
- Dynamic memory management using `malloc` and `free`.

---

