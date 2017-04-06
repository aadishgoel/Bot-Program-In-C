# Bot-Program-In-C-For-TIC-TAC-TOE

Here it is a c language code for Undefeatable Bot for Tic Tac Toe game. The bot can play game acting as first player or either as second player according to your choice. It plays One by One move according to the current situation on the board. Bot is Designed in a way to win every battle. Even if the opponent plays the most optimal move It will not let you lose. Bot was originally created for a bot contest.

Here is the link to that :- https://www.hackerearth.com/practice/algorithms/string-algorithm/manachars-algorithm/practice-problems/multiplayer/tic-tac-toe/

#include<stdio.h>
int cord[10];

int isempty(int x[3][3])
{ int flag=1,i,j;
  for(i=0;i<3;i++)
  	for(j=0;j<3;j++)
		if(x[i][j]!=0){ 
			flag=0; 
			return flag;
		} 
   return flag;			
}

int count(int x[3][3],int id){
	int count=0,i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(x[i][j]==id){
			    cord[count*2]=i;
			    cord[(count*2)+1]=j;
				++count;
			}
	return count;			
} 
void display(int x[3][3])
{   int i;
	for(i=0;i<3;i++)
	printf("%d %d %d\n",x[i][0],x[i][1],x[i][2]);
}
int main()
{
	int a[3][3],i,j,id;
	
	for(i=0;i<3;i++)
	scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]); 
    scanf("%d",&id);
   
	if(isempty(a)) 
		printf("2 0\n");
     	
	else if(count(a,2)==1){ 
	    i=cord[0];
	    j=cord[1];
		if(i+j>2) 
			printf("0 0");
		else if(i+j<2||(i==0&&j==2))
			printf("2 2");	
		else if(i==1&&j==1)
			printf("0 2"); 	
	}
	
	else if(count(a,2)==2){
	    i=cord[0];
	    j=cord[1];
			
		if(a[2][2]==1){
			if(a[2][1]==0) 
				printf("2 1");
		else{
			if(i==0&&j==2)
				printf("0 0");
			else if(i==0&&j==0)
				printf("0 2");
			else if(i!=j) 
				printf("1 1");			
			}	
		}
			
		else if(a[0][0]==1){
			if(a[1][0]==0)
				printf("1 0");
			else{	 
				if(cord[2]==cord[3])
					printf("0 2");
				else
					printf("1 1");	
				}
		}
	
		else if(a[0][2]==1){
			     if(a[2][2]==2) printf("0 0");
			else if(a[0][0]==2) printf("2 2");
			else if(a[1][0]==2) printf("1 2");
			else if(a[1][2]==2) printf("1 0");
			else if(a[0][1]==2) printf("2 1");
			else if(a[2][1]==2) printf("0 1");
		}
	} 
	
	else if(count(a,2)==3){
		if(a[0][0]==1&&a[2][2]!=1){
			if(a[1][1]==1){
				if(a[0][2]==2)
				printf("2 2");
				else
				printf("0 2");
			}
			else{
				if(a[1][1]==0)
					printf("1 1");
				else if(a[0][1]==0)
					printf("0 1");
				else
					printf("1 0");	
			}
		}
		else if(a[2][2]==1){
			if(a[1][1]==1){
				if(a[0][0]==0)
					printf("0 0");
				else
					printf("0 2");	
			}
			else if(a[0][0]==2){
				if(a[1][1]==0)
					printf("1 1");
				else if(a[2][1]==0)
					printf("2 1");
				else
					printf("1 2");		
			}
			else if(a[0][0]==1){
				if(a[1][1]==0)
					printf("1 1");
				else
					printf("1 0");	
			}
		}
		else{ 
			if(a[0][1]==2){
				if(a[2][2]==0)
					printf("2 2");
				else
					printf("0 0");	
			}
			else if(a[1][2]==2){
				if(a[0][0]==0)
					printf("0 0");
				else
					printf("2 2");	
			}	
			else if(a[2][1]==2){
				if(a[0][0]==0)
					printf("0 0");
				else
					printf("2 2");	
			}
			else if(a[1][0]==2){
				if(a[2][2]==0)
					printf("2 2");
				else
					printf("0 0");	
			}
		}
	}
    else if(count(a,2)==4){
    	if(a[2][2]==2){
    		if(a[0][1]==0||a[2][1]==0){
	    		if(a[0][1]==0)
	    			printf("0 1");
	    		else
					printf("2 1");	
	    	}
	    	else{
			    if(a[1][0]==0)
					printf("1 0");
				else
					printf("1 2");		
			}
		}
		else if(a[2][2]==1){
    		if(a[1][2]==0||a[1][0]==0){
				if(a[1][2]==0)	
    				printf("1 2");
    			else
					printf("1 0");	
    		}
    		else{
    			if(a[2][1]==0)
					printf("2 1");
				else
					printf("0 1");			
			}
		}
	}
//	display(a);
	
}
