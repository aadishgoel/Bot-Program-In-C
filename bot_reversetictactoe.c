//opposite rows
#include<stdio.h>
int cord[10];

int isempty(int x[3][3])
{ int i,j;
  for(i=0;i<3;i++)
  	for(j=0;j<3;j++)
		if(x[i][j]!=0)
		 	return 0;
   return 1;			
}
int corner(int x[3][3]){
	if(x[0][0]==0){ 
		printf("0 0");
		return 1;
	} 
	else if(x[0][2]==0){
		printf("0 2");
		return 1;
	}
	else if(x[2][0]==0){
		printf("2 0");
		return 1;
	}
	else if(x[2][2]==0){
		printf("2 2");
		return 1;
	}
	return 0;
}
int check(int zero,int count,int x,int y){
	if(zero==1&&count==2){
		printf("%d %d",x,y);
		return 1;
	}
	return 0;
}
int match(int a[3][3],int id){ 
	int i,j,k,z1,z2,z3=0,z4=0,c1,c2,c3=0,c4=0,x1,y1,x2,y2,x3,x4,y4;
	for(i=0,k=2;i<3;i++,k--){
		z1=z2=c1=c2=0;
		for(j=0;j<3;j++){ 
			if(a[i][j]==0){ 
				z1++;
				x1=i;
				y1=j;
			}
			else if(a[i][j]==id)
				c1++;	
			if(a[j][i]==0){
				z2++;
				x2=j;
				y2=i;
			}	
			else if(a[j][i]==id)
				c2++;
		}	
		if(check(z1,c1,x1,y1))
			return 1;
		if(check(z2,c2,x2,y2))
			return 1;
		if(a[i][i]==0){
			z3++;
			x3=i;	
		}
		else if(a[i][i]==id) 
			c3++;	
		if(a[i][k]==0){
			z4++;
			x4=i; 
			y4=k;
		}
		else if(a[i][k]==id)
			c4++;	
	}
	if(check(z3,c3,x3,x3))
		return 1;
	if(check(z4,c4,x4,y4))
		return 1;
	return 0;	
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
int remain(int a[3][3]){
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(a[i][j]==0){
				printf("%d %d",i,j);
				return 1;
			}
	return 0;		
}
int main()
{
	int a[3][3],i,j,id,temp;
	
	for(i=0;i<3;i++)
	scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]); 
    scanf("%d",&id);
  
   if(id==1){
   
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
						remain(a);	
		    	}
		    	else{
				    if(a[1][0]==0)
						printf("1 0");
					else
						remain(a);		
				}
			}
			else if(a[2][2]==1){
	    		if(a[1][2]==0||a[1][0]==0){
					if(a[1][2]==0)	
	    				printf("1 2");
	    			else 
						remain(a);	
	    		}
	    		else{
	    			if(a[2][1]==0)
						printf("2 1");
					else
						remain(a);			
				}
			}
	//	display(a);
		}
	}
	else if(id==2){
	//		printf("Under Construction\n");
		if(match(a,2));
		else if(match(a,1));
		else if(a[1][1]==0)
			printf("1 1");
		else if(count(a,2)==1&&a[1][1]==2){
			if(a[2][1]==0)
				printf("2 1");
			else
				printf("0 1"); 	 
		}	
	    else if(corner(a));
		else 
			remain(a);
	}
}
