int fat(int x){
	if(x == 0){
		output(10,0);
		return 1;
	}else{
		output(x,0);
		return (x*fat(x-1));
	}
}


void main(void){
    int x;
	x = input();
	output(fat(x),0);
}
