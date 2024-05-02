// C program to illustrate
// power function

#include <stdio.h>
#include<string.h>
int main()
{
   float passengerX=0.0;
   float passengerY =0.0;
   float pointX[3];
   float pointY[3];
   float distance[3];
   int i=0;

   printf("Enter Passenger Cordinates (x,y in meters): ");
   scanf("%f %f",&passengerX,&passengerY);
   printf("Enter Point 1   Cordinates (x,y in meters): ");
   scanf("%f %f",&pointX[0],&pointY[0]);
   printf("Enter Point 2   Cordinates (x,y in meters): ");
   scanf("%f %f",&pointX[1],&pointY[1]);
    printf("Enter Point 3  Cordinates (x,y in meters): ");
   scanf("%f %f",&pointX[2],&pointY[2]);

   for(i=0;i<3;i++)
   {
     distance[i]= sqrt(pow((pointX[i]-passengerX),2) + pow((pointY[i]-passengerY),2) );
     printf("%d Station  : ",i+1);
     if (distance[i]<100)
     {
         printf("Distance is Low\n");
     }
     else if(distance[i]<1000)
     {
         printf("Distance is Moderate\n");
     }
     else
     {
        printf("Distance is High\n");

     }
   }
   printf("Minimum distance station : ");
   if(distance[0]< distance[1])
   { if(distance[0]<distance[2])
      printf("Station 1");
      else
      printf("Station 2");

   }
   else
   {
       if(distance[1]<distance[2])
      printf("Station 2");
      else
      printf("Station 3");
   }
}
