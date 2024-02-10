#include <stdio.h>
#include<stdlib.h> 

// create matrices of m x n dimension 
int** create(int m,int n)
  {  int** matrix = (int**)malloc(sizeof(int*) * m);
  int i,j;
    for ( i = 0; i < m; i++) 
	   {
        matrix[i] = (int*)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++) 
		{
           matrix[i][j] = 0;
        }
    }
    return matrix;
   }//end 

//divides any matrix into segments
void segment(int **A, int **B, int h, int r, int c) 
 { int i,j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < h; j++)
		 {
            A[i][j] = B[r + i][c + j];
        }
    }
}//segment
 
 //add two matrices
  int** add(int ** A,int ** B, int m,int coeff) 
  { int** result=create(m,m);     int i,j;    
   for(i=0;i<m;i++)     
    for(j=0;j<m;j++)      
    {   result[i][j]=A[i][j]+coeff*B[i][j];     
	  } 
	return result;
  } //add
 
 
 
 void Strassen(int** A,int** B,int** result,int n)
 {  
   if(n==1)
     result[0][0]=A[0][0]*B[0][0];
   else
   {
   	 int half=n/2;//half dimension
   	 
   	 // generating sub matrices
		int** a = create(half, half);
		int** b = create(half, half);
		int** c = create(half, half);
		int** d = create(half, half);
		int** e = create(half, half);
		int** f = create(half, half);
		int** g = create(half, half);
		int** h = create(half, half);
		
		// dividing the first matrix
		segment(a, A, half, 0, 0);
		segment(b, A, half, 0, half);
		segment(c, A, half, half, 0);
		segment(d, A, half, half, half);
		
		// dividing the second matrix
		segment(e, B, half, 0, 0);
		segment(f, B, half, 0, half);
		segment(g, B, half, half, 0);
		segment(h, B, half, half, half);
		
		// generating the 7 multiplicative terms
		int** p1 = create(half, half);
		int** p2 = create(half, half);
		int** p3 = create(half, half);
		int** p4 = create(half, half);
		int** p5 = create(half, half);
		int** p6 = create(half, half);
		int** p7 = create(half, half);
		   	
   
        //performing the multiplication
	    Strassen(a, add(f, h, half, -1), p1, half);
        Strassen(add(a, b, half,1), h, p2, half);
        Strassen(add(c, d, half,1), e, p3, half);
        Strassen(d, add(g, e, half, -1), p4, half);
        Strassen(add(a, d, half,1), add(e, h, half,1), p5, half);
        Strassen(add(b, d, half, -1), add(g, h, half,1), p6, half);
        Strassen(add(a, c, half, -1), add(e, f, half,1), p7, half);

        int **result_00 = create(half, half);
        int **result_01 = create(half, half);
        int **result_10 = create(half, half);
        int **result_11 = create(half, half);
        
        //computing the final terms
        result_00=add(add(add(p6,p5,half,1),p4,half,1),p2,half,-1);
        result_01=add(p1,p2,half,1);
        result_10=add(p3,p4,half,1);
        result_11=add(add(add(p1,p3,half,-1),p5,half,1),p7,half,-1);

     //framing result matrix
     int i,j;
        for ( i = 0; i < half; i++) {
            for ( j = 0; j < half; j++) {
                result[i][j] = result_00[i][j];
                result[i][j + half] = result_01[i][j];
                result[half + i][j] = result_10[i][j];
                result[half + i][j + half] = result_11[i][j];
            }
        }

 }
 	
 }//strassen


 void display(int **A,int m,int n)
	{ int i,j;  
	    for(i=0;i<m;i++) 
		  { for(j=0;j<n;j++)    
		    printf("%d\t",A[i][j]);   
			  printf("\n");  
	    } 
	}//display

int main()
{
  int r1,c1,r2,c2;
  printf("Enter dimensions of first matrix-\n");
  scanf("%d",&r1);
  scanf("%d",&c1);	
  printf("Enter dimensions of second matrix-\n");
  scanf("%d",&r2);
  scanf("%d",&c2);
  int i,j;
  if(c1!=r2)
   {
   printf("Matrix dimensions not compatible for multiplication\n");
   return 0;
   }
  int max = (r1 > c1) ? (r1 > c2 ? r1 : c2) : (c1 > c2 ? c1 : c2);
  
  int p=1;
   while(p<max)
   {p=p*2;
   }
      
  int** M1=create(p,p);
  int**M2=create(p,p);
  
  printf("Enter elements for first matrix\n");
  for(i=0;i<r1;i++)
   for(j=0;j<c1;j++)
    scanf("%d",&M1[i][j]);
  
  printf("\nEnter elements for second matrix\n");
  for(i=0;i<r2;i++)
   for(j=0;j<c2;j++)
    scanf("%d",&M2[i][j]);
    
  printf("ORIGINAL MATRIX 1:\n"); 
  display(M1,r1,c1);
  printf("\nORIGINAL MATRIX 2:\n"); 
  display(M2,r2,c2);
    
  printf("\nPADDED MATRIX 1:\n"); 
  display(M1,p,p);
  printf("\nPADDED MATRIX 2:\n"); 
  display(M2,p,p);
    
  
  int**result=create(p,p);
  Strassen(M1,M2,result,p);
  printf("RESULT:\n"); 
  display(result,r1,c2);
  	
}//end of main


