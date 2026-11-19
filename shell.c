void syscall(int ax, int bx, int cx, int dx);

int main(){

char line[80];
char filename[6];
int i;
int sectorsRead; 
char buffer[13312];  
 

while(1){
	    

/*STEP 4*/
	syscall(0,"SHELL>",0,0);
	syscall(1,line,0,0); 
	/*STEP  5*/
	if( line[0] =='t' && line[1]== 'y' && line[2]== 'p' && line[3]=='e' && line[4]== ' '){
		for(i=0; i<6; i++){
                        filename[i]= line[5+ i];
                }
		syscall(3, filename,buffer,&sectorsRead);
		if (sectorsRead !=0){
			syscall(0,buffer,0,0);
		}else{
			syscall(0,"File Not Found /r/n",0,0);
		}
	}
	else if(line[0] =='e' && line[1]=='x' &&line[2]=='e' && line[3]=='c' && line[4] == ' '){
		for(i=0; i<6; i++){
                	filename[i]= line[5+ i];
                }
		/*syscall(0,filename,0,0);*/
		syscall(4,filename,0,0);

	}else{
		syscall(0,"Command Not Found",0,0);
	}
}}





