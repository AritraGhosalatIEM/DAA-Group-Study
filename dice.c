//NAME:Kinshuk Ganguly SEC:C ROLL:198
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int main() {
    srand(time(NULL));
    int sum;  // rolls
    double upper_percent = 17.5;  // Upper bound as a percentage
    double lower_percent = 16.0;  // Lower bound as a percentage
    int occur[6];
    
    printf("Enter the number of rolls: ");
    scanf("%d", &sum);
    if(sum<=0)
    {   printf("Invalid input. Please enter a positive number of rolls. ");}
    else{
	
    int i;
    int lower_bound = (int)((double)sum * (lower_percent / 100));
    int upper_bound = (int)((double)sum * (upper_percent / 100));
   
    for (i = 0; i < 6; i++) {
        occur[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    }
    int min=0;
    int max=0;
    int current_sum = 0;
    for (i = 0; i < 6; i++)
	{
        current_sum += occur[i];
         if(occur[i]<occur[min])
         min=i;
         if(occur[i]>occur[max])
         max=i;
    }
          
    // Adjust the numbers to make the sum exactly 
	//equal to the number of rolls but never cross the range    
    if (current_sum > sum) {
        
        occur[max] -=current_sum-sum;
        
    }
    else
     occur[min] += sum - current_sum;
    
    // Print the generated numbers and the final sum
   printf("After %d rolls:\n",sum);
    for (i = 0; i < 6; i++) {
    	float prob=(float)occur[i]/sum*100;
    	
        printf("Face %d: %d times (%.2f%)\n", i+1,occur[i],prob);
    }
    }//else
    return 0;
}
