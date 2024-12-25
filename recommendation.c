#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"

void formula(struct people *viewer){
  FILE *fptr4;
      fptr4 = fopen ("user_ratings.txt", "a+");//fptr4 pointer to read first element from user_ratings.txt, which is the number of users(nbUser2)
      if (fptr4 == NULL) {
         printf("ERROR 404\n");
      }
   int nbUser2;
   fscanf(fptr4, "%d\n", &nbUser2);
   //printf("%d\n", nbUser2);
   fclose(fptr4);
    char name4[20];
    
    
    
      printf("Enter your username: ");
      scanf("%19s", name4); // Limit the string length to avoid buffer overflow
      getchar(); // Consume the newline character in the input buffer
      int verify2= 0;//variable used inside loop(if verify2=1, then existing name entered)
      int index;
      for(int j=0; j<nbUser2; j++) {
         int nameValidation2 = strcasecmp(viewer[j].name, name4);
        if (nameValidation2==0) {
          verify2 =1;
         index=j;//index stored to know which user it is
        }
      }
      if(verify2==1) {//if verify2=1, then existing name entered 
        int movieNb=0;//indexing of the movie that have not been watched by the corresponding user
        printf("\n");
        printf("**** Movie Recommendation System ****\n");
        if((viewer[index].movie1)==0) { //if the first movie of the chosen user(user name typed that was matched with one of the names in viewer array) has rating of 0
          
            
            float movie1A=0; //variable to determine the average rating of the movie(with only the people who have watched the movie) that the corresponding user hasn't watched
            int N1=0;//the number of people who have watched the movie(not rated 0)
            for (int x=0;x<nbUser2;x++){//loop trough every user 
                if((viewer[x].movie1)!=0){ //if the user has not rated the corresponding movie with 0, then we increment the value of movie1A(rating of the movie) with the previous user who has watched the movie
                    movie1A=movie1A+(viewer[x].movie1);
                    N1++;//increment the number of user who have watched the movie
                }
            }
            if(N1==0){//if no one watched the movie, then do nothing
                //printf("%d. The Shawshank Redemption (Drama) 0\n", movieNb);
            }
            else{
                movieNb++;//increment the index of the movie(indexing of the movie that have not been watched by the corresponding user)
                movie1A=(movie1A/N1);//calculate the average rating(sum of the ratings(that are not 0) divided by the number of people who have watched the movie(have not rated a 0))
                printf("%d. The Shawshank Redemption (Drama) - Predicted Rating: %.1f\n", movieNb, movie1A);
                
            }
        }

        if((viewer[index].movie2)==0) {
          
            
            float movie2A=0;
            int N2=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie2)!=0){
                    movie2A=movie2A+(viewer[x].movie2);
                    N2++;
                }
            }
            if(N2==0){
                //printf("%d. The Godfather (Crime) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie2A=(movie2A/N2);
                printf("%d. The Godfather (Crime) - Predicted Rating: %.1f\n", movieNb, movie2A);
                
            }
        }

        if((viewer[index].movie3)==0) {
          
            
            float movie3A=0;
            int N3=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie3)!=0){
                    movie3A=movie3A+(viewer[x].movie3);
                    N3++;
                }
            }
            if(N3==0){
                //printf("%d. The Dark Knight (Action) 0\n", movieNb);
            }
            else{
              movieNb++;
                movie3A=(movie3A/N3);
                printf("%d. The Dark Knight (Action) - Predicted Rating: %.1f\n", movieNb, movie3A);
                
            }
        }

        if((viewer[index].movie4)==0) {
          
            
            float movie4A=0;
            int N4=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie4)!=0){
                    movie4A=movie4A+(viewer[x].movie4);
                    N4++;
                }
            }
            if(N4==0){
                //printf("%d. Pulp_Fiction (Crime) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie4A=(movie4A/N4);
                printf("%d. Pulp_Fiction (Crime) - Predicted Rating: %.1f\n", movieNb, movie4A);
                
            }
        }

        if((viewer[index].movie5)==0) {
          
            
            float movie5A=0;
            int N5=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie5)!=0){
                    movie5A=movie5A+(viewer[x].movie5);
                    N5++;
                }
            }
            if(N5==0){
                //printf("%d. The Lord of the Rings: The Return of the King (Adventure) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie5A=(movie5A/N5);
                printf("%d. The Lord of the Rings: The Return of the King (Adventure) - Predicted Rating: %.1f\n", movieNb, movie5A);
                
            }
        }

        if((viewer[index].movie6)==0) {
          
            
            float movie6A=0;
            int N6=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie6)!=0){
                    movie6A=movie6A+(viewer[x].movie6);
                    N6++;
                }
            }
            if(N6==0){
                //printf("%d. Forest Gump (Drama) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie6A=(movie6A/N6);
                printf("%d. Forest Gump (Drama) - Predicted Rating: %.1f\n", movieNb, movie6A);
                

            }
        }

        if((viewer[index].movie7)==0) {
          
            
            float movie7A=0;
            int N7=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie7)!=0){
                    movie7A=movie7A+(viewer[x].movie7);
                    N7++;
                }
            }
            if(N7==0){
                //printf("%d. The Matrix (Action) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie7A=(movie7A/N7);
                printf("%d. The Matrix (Action) - Predicted Rating: %.1f\n", movieNb, movie7A);
                
            }
        }

        if((viewer[index].movie8)==0) {
            
            
            float movie8A=0;
            int N8=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie8)!=0){
                    movie8A=movie8A+(viewer[x].movie8);
                    N8++;
                }
            }
            if(N8==0){
                //printf("%d. The Silence of the Lambs (Crime) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie8A=(movie8A/N8);
                printf("%d. The Silence of the Lambs (Crime) - Predicted Rating: %.1f\n", movieNb, movie8A);
                
            }
        }

        if((viewer[index].movie9)==0) {
          
            
            float movie9A=0;
            int N9=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie9)!=0){
                    movie9A=movie9A+(viewer[x].movie9);
                    N9++;
                }
            }
            if(N9==0){
                //printf("%d. Schindler's List (Biography) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie9A=(movie9A/N9);
                printf("%d. Schindler's List (Biography) - Predicted Rating: %.1f\n", movieNb, movie9A);
                
            }
        }

        if((viewer[index].movie10)==0) {
          
            
            float movie10A=0;
            int N10=0;
            for (int x=0;x<nbUser2;x++){
                if((viewer[x].movie10)!=0){
                    movie10A=movie10A+(viewer[x].movie10);
                    N10++;
                }
            }
            if(N10==0){
                //printf("%d. Inception (Action) 0\n", movieNb);
            }
            else{
                movieNb++;
                movie10A=(movie10A/N10);
                printf("%d. Inception (Action) - Predicted Rating: %.1f\n", movieNb, movie10A);
                
            }
        }




        
        
      } 
      else {
        printf("User not found. Please register first.\n");
        
        
      } 
}
