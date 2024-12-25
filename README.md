## Movie Recommendation System
# Description
This project implements a simple movie recommendation system using the C programming language. The system allows users to register, rate movies, and receive recommendations based on collaborative filtering. It demonstrates fundamental concepts of C, including file handling, arrays, and modular programming.

* Features
1. Register User
> * Allows new users to register with a username.
> * Validates username uniqueness (case-insensitive).
> * Stores user data in user_data.txt.
> * Outputs:
>   * **Success**: User is successfully registered.
>   * **Error**: User already exists. Please choose a different name.
2. Display Movies
> * Displays a list of all available movies stored in movie_database.txt.
> * Formats movies in an indexed list with details such as title, genre, and average rating.
3. Rate a Movie
> * Allows users to rate movies.
> * Validates:
> * Validates:
>   * **User existence in `user_data.txt`.**
>   * **Valid movie index (from the displayed list).**
>   * **Rating value (between 1 and 5).**
> * Stores ratings in an m x n matrix and saves them in user_ratings.txt.
> * Outputs:
>   * **Success**: Rating recorded successfully.
>   * **Error**: User not found. Please register first.
4. Get Movie Recommendations
> * Recommends movies to users based on collaborative filtering.
> * Excludes movies already rated by the user.
> * Uses the average rating of other users to predict preferences.
> * Outputs:
>   * **List of recommended movies with predicted ratings.**
>   * **Error: User not found. Please register first.**
5. Exit
> * Gracefully terminates the application.
> * Releases all allocated resources.

# Technical Details
* Programming Language: C
* Files Used:
> * user_data.txt: Stores user registration details.
> * movie_database.txt: Contains a list of available movies.
> * user_ratings.txt: Stores the movie ratings in an m x n matrix format.
* Recommendation Algorithm:
> * Implements collaborative filtering by averaging the ratings of other users for unseen movies.
> * Formula:
𝑅
(
𝑢
,
𝑖
)
=
∑
𝑅
(
𝑣
,
𝑖
)
𝑁
R(u,i)= 
N
∑R(v,i)
​
 
 * Where:
> * R(𝑢,𝑖): Predicted rating for user 
𝑢 and movie 𝑖

> * R(𝑣,𝑖): Rating given by another user 
𝑣 to movie 𝑖
> * 𝑁: Total number of users who rated movie 𝑖

* Key Learnings
> * File operations for reading, writing, and validating user and movie data.
> * Modular programming with structured functions for registration, rating, and recommendations.
> * Collaborative filtering for personalized recommendations.
> * Validation of user inputs and graceful error handling.
