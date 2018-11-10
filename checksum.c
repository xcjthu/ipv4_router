#include "checksum.h"

int check_sum(unsigned short *iphd,int len,unsigned short checksum){
   unsigned short ans_sum = 0;
   for(int i = 0; i < len; ++ i){
       if (i != 5)
           ans_sum += iphd[i];
   }
   if (~ans_sum == checksum){
       return 0;
   }
   else
       return -1;
}

unsigned short count_check_sum(unsigned short *iphd){
	/*这里需要将ttl减1*/
    unsigned short ans = 0;
    iphd[3] -= 1;
    unsigned int len = 0x0f & iphd[0];
    len = len << 2;
    for (int i = 0; i < len; ++ i){
    	if (i != 5)
    		ans += iphd[i];
    }
    ans = ~ans;
    iphd[5] = ans;
    return ans;
}
