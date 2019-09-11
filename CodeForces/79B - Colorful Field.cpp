#include<stdio.h>
struct point{
	int x, y;
};
int main(){
	int n, m, k, t;
	while (scanf("%d%d%d%d", &n, &m, &k, &t) == 4){
		struct point B[1000];
		for (int i = 0; i < k; i++)
			scanf("%d%d", &B[i].y, &B[i].x);
		for (int i = 0; i < t; i++){
			struct point Q;
			int pos;
			bool block = false;
			scanf("%d%d", &Q.y, &Q.x);
			pos = (Q.y - 1)*m + Q.x;
			for (int j = 0; j < k; j++){
				if (Q.y > B[j].y || (Q.y == B[j].y&&Q.x > B[j].x)){
					pos--;
				}
				if (Q.x == B[j].x&&Q.y == B[j].y){
					block = true;
					break;
				}
			}
			if (block){
				puts("Waste");
			}
			else{
				switch (pos % 3){
				case 0:	puts("Grapes");	break;
				case 1:	puts("Carrots");	break;
				case 2:	puts("Kiwis");	break;
				}
			}
		}
	}
	return 0;
}
