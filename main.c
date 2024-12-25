#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"



int i=0;
struct people *viewer; //from people.h
void registration(int i, struct people *viewer); //from user.c
void movieDispay(); //from display.c
void movieRate(int i,struct people *viewer); //from rateMovie.c
void formula(struct people *viewer); //from recommendation.c

int main(int argc, char **argv) {
    
  viewer = (struct people *)malloc(20 * sizeof(struct people)); //malloc to allocate memory of size 20 times struct people(array of length 20) from heap
if (viewer==NULL) {
   fprintf(stderr, "Memory allocation failed\n");       
}

FILE *fptr;
      fptr = fopen ("user_data.txt", "a+");  //fptr pointer to read user_data.txt file
      if (fptr == NULL) {
         printf("ERROR 404\n");
      }
      char name2[20]; // variable to read names from each line of user_data.txt
      int count2;     // variable to read name counts from each line of user_data.txt
      i=0;
      //while loop that reads each name and its count from every line of user_data.txt and to store those name and their count into viewer (of type struct people)
      while (fscanf(fptr, "%19s %d\n", name2, &count2) != EOF) { // Limit the string length to avoid buffer overflow
        viewer[i].name = malloc(20);//allocate size 20(characters) to each user name in viewer array
        if (viewer[i].name == NULL) {
          fprintf(stderr, "Memory allocation failed\n");
          exit(EXIT_FAILURE); // or handle the error appropriately
        }
        strcpy(viewer[i].name, name2); //copies value of name2(from scanning each line) into viewer[i].name
        viewer[i].count=count2;
        i++; //increments index for next iteration of while loop
      }
    fclose(fptr);

    FILE *fptrMovie;
      fptrMovie = fopen ("user_ratings.txt", "r+"); //fptrMovie pointer to read user_ratings.txt
      if (fptrMovie == NULL) {
         printf("ERROR 404\n");
      }
      int skipFirstLine=0;
      int film=0;
      float film1;  //film values to read rating of each movie 
      float film2;
      float film3;
      float film4;
      float film5;
      float film6;
      float film7;
      float film8;
      float film9;
      float film10;

      // Read the first line to determine its length
      int firstLineLength = 0;
      char ch;
      while ((ch = fgetc(fptrMovie)) != '\n' && ch != EOF) {
      firstLineLength++;
      }

      // Move to the beginning of the second line
      fseek(fptrMovie, firstLineLength + 1, SEEK_SET);
      while (fscanf(fptrMovie, "%f %f %f %f %f %f %f %f %f %f\n", &film1, &film2, &film3, &film4, &film5, &film6, &film7, &film8, &film9, &film10) != EOF) { 
        //each film value(ratings) read from each line(corresponding to a user) stored in viewer[film].movieX 
        viewer[film].movie1=film1;
        viewer[film].movie2=film2;
        viewer[film].movie3=film3;
        viewer[film].movie4=film4;
        viewer[film].movie5=film5;
        viewer[film].movie6=film6;
        viewer[film].movie7=film7;
        viewer[film].movie8=film8;
        viewer[film].movie9=film9;
        viewer[film].movie10=film10;
        film++; 
       
      }
      
      fclose(fptrMovie);
    
    int choice; 
    for (int v=0;v<10;v++) {//for loop so if wrong choice, the loop repeats itself(v will stay 0)
	printf("**** Movie Recommendation System ****\n");//if right choice, loop terminates by setting v to 200
    printf("1. Register User\n");
    printf("2. Display Movies\n");
    printf("3. Rate a Movie\n");
    printf("4. Get Movie Recommendations\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);  // Removed \n from the format string
    
    if (choice==1) {
        registration(i, viewer);
        printf("\n");
        v=0;
    }
    else if(choice==2) {
        movieDispay();
        printf("\n");
        v=0;
    }
    else if(choice==3) {
        movieRate(i, viewer);
        printf("\n");
        v=0;
    }
    else if(choice==4){
      formula(viewer);
      printf("\n");
      v=0;
    }
    else if(choice==0) {
        v=200;
        for(int p=0;p<i+1;p++) {//free each name(string value) from struc people viewer
            free(viewer[p].name); 
        }
        free(viewer);
        exit(0);
    }
    else{
      printf("Please enter an integer between 0 and 5\n");
      printf("\n");
      v=0;
    }
    }
    


	return 0;

	
}                

