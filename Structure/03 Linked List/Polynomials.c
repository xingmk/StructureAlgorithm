#include<stdio.h>
#include<stdlib.h>

typedef struct ploy {
	int expn; //指数部分
	float coef; // 系数部分
	struct ploy* next;
} Ploy;

Ploy *add_ploy(Ploy *La, Ploy *Lb) { 
	Ploy *Lc,
		*pc,
		*pa,
		*pb,
		*ptr; 
	float x;
	Lc = pc = La; 
	pa = La->next; 
	pb = Lb->next;
	while (pa != NULL && pb != NULL) { 
		if (pa->expn < pb->expn) { 
			pc->next = pa; 
			pc = pa; 
			pa = pa->next;
		} if (pa->expn > pb->expn) {
			pc->next = pb; 
			pc = pb; 
			pb = pb->next;
		} else { 
			x = pa->coef + pb->coef;
			if (abs(x)<=1.0e-6) { 
				ptr = pa; 
				pa = pa->next; 
				free(ptr);
				ptr = pb; 
				pb = pb->next; 
				free(ptr);
			} else { 
				pc->next = pa; 
				pa->coef = x;
				pc = pa; 
				pa = pa->next;
				ptr = pb; 
				pb = pb->next; 
				free(pb);
			}
		}
	} 
	if (pa == NULL) pc->next = pb;
	else pc->next = pa ;
	return (Lc) ;
}
int main() {
	return 0;
}
