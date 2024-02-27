#include<stdio.h>

int main(void){
	
    int day=35;
    int month=32;
	int year=1;
	int newday;
	int newmonth;
	int newyear;
    	
	
	while(day!=0 || month!=0 || year!=0){
	
    	printf("Enter a date (0 0 0 to quit):");
    	scanf("%d %d %d",&day,&month,&year);	
    
	if(day==0 && month==0 && year==0){
		printf("Thanks for using this calendar!");
	}	
    else if(day<30 && (month==1 || month==3 || month==4 || month==5 || month==6 || month==7 || month==8 || month==9) && day>9 && year>=0){
		newday=day+1;
	    printf("The next day of %d.0%d.%d is %d.0%d.%d\n",day,month,year,newday,month,year);
    }
    else if(day<30 && (month==10 || month==11 || month==12) && day>9 && year>=0){
		newday=day+1;
	    printf("The next day of %d.%d.%d is %d.%d.%d\n",day,month,year,newday,month,year);
    }
    else if(day<9 && (month==10 || month==11 || month==12) && day>0 && year>=0){
		newday=day+1;
	    printf("The next day of 0%d.%d.%d is 0%d.%d.%d\n",day,month,year,newday,month,year);
    }
    else if(day<9 && (month==1 || month==3 || month==4 || month==5 || month==6 || month==7 || month==8 || month==9) && day>0 && year>=0){
		newday=day+1;
	    printf("The next day of 0%d.0%d.%d is 0%d.0%d.%d\n",day,month,year,newday,month,year);
    }
    else if(day==9 && (month==1 || month==3 || month==4 || month==5 || month==6 || month==7 || month==8 || month==9) && year>=0){
	    printf("The next day of 09.0%d.%d is 10.0%d.%d\n",month,year,month,year);
    }
    else if(day==9 && (month==10 || month==11 || month==12) && year>=0){
	    printf("The next day of 09.%d.%d is 10.%d.%d\n",month,year,month,year);
    }
	else if(day==31 && month==12 && year>=0){
		newyear=year+1;
		printf("The next day of 31.12.%d is 01.01.%d\n",year,newyear);
	}
   	else if(day==31 && (month==1 || month==3 || month==5 || month==7 || month==8) && year>=0){
		newmonth=month+1;
		printf("The next day of 31.0%d.%d is 01.0%d.%d\n",month,year,newmonth,year);	
	}
	else if(day==31 && month==10 && year>=0){
		printf("The next day of 31.10.%d is 01.11.%d\n",year,year);	
	}
	else if(day==28 && month==2 && year%4!=0 && year>=0){
		printf("The next day of 28.02.%d is 01.03.%d\n",year,year);	
	}
	else if(day==28 && month==2 && year%4==0 && year>=0){		
		printf("The next day of 28.02.%d is 29.02.%d\n",year,year);	
	}
	else if(day<28 && month==2 && day>9 && year>=0){
		newday=day+1;
		printf("The next day of %d.02.%d is %d.02.%d\n",day,year,newday,year);	
	}
	else if(day<=8 && month==2 && day>0 && year>=0){
		newday=day+1;
		printf("The next day of 0%d.02.%d is 0%d.02.%d\n",day,year,newday,year);	
	}
	else if(day==9 && month==2 && year>=0){
		printf("The next day of 09.02.%d is 10.02.%d\n",year,year);	
	}
	else if(day==29 && month==2 && year%4==0 && year>=0){
		printf("The next day of 29.02.%d is 01.03.%d\n",year,year);
	}
	else if(day==30 && month==11 && year>=0){
		printf("The next day of 30.11.%d is 01.12.%d\n",year,year);		
	}
	else if(day==30 && (month==4 || month==6) && year>=0){
		newmonth=month+1;
		printf("The next day of 30.0%d.%d is 01.0%d.%d\n",month,year,newmonth,year);		
	}
	else if(day==30 && month==9 && year>=0){
		printf("The next day of 30.09.%d is 01.10.%d\n",year,year);		
	}
	else if(day==30 && (month==10 || month==12) && year>=0){
		printf("The next day of 30.%d.%d is 31.%d.%d\n",month,year,month,year);		
	}
	else if(day==30 &&  (month==1 || month==3 || month==5 || month==7 || month==8) && year>=0){
		printf("The next day of 30.0%d.%d is 31.0%d.%d\n",month,year,month,year);		
	}
	else
	{
		printf("This is not a valid date!\n");
	}
} }