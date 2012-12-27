#include<stdio.h>
#include<math.h>
int X,N, i,j,k; 
int vac[9];
int six_48=6*49;
int C[7][7]={
	{1,0,0,0,0,0,0},
	{1,1,0,0,0,0,0},
	{1,2,1,0,0,0,0},
	{1,3,3,1,0,0,0},
	{1,4,6,4,1,0,0},
	{1,5,10,10,5,1,0},
	{1,6,15,20,15,6,1},
};
int ways;
char comp[54];
int main()
{
	scanf("%d", &X);
	scanf("%d", &N);
	ways=0;
	for( i=0; i<N ; i++ )
	{
		scanf("%s", comp);
		vac[0]= abs(comp[0]+comp[1]+comp[2]+comp[3]+comp[52]+comp[53]-six_48);
		vac[1]= abs(comp[4]+comp[5]+comp[6]+comp[7]+comp[50]+comp[51]-six_48);
		vac[2]= abs(comp[8]+comp[9]+comp[10]+comp[11]+comp[48]+comp[49]-six_48);
		vac[3]= abs(comp[12]+comp[13]+comp[14]+comp[15]+comp[46]+comp[47]-six_48);
		vac[4]= abs(comp[16]+comp[17]+comp[18]+comp[19]+comp[44]+comp[45]-six_48);
		vac[5]= abs(comp[20]+comp[21]+comp[22]+comp[23]+comp[42]+comp[43]-six_48);
		vac[6]= abs(comp[24]+comp[25]+comp[26]+comp[27]+comp[40]+comp[41]-six_48);
		vac[7]= abs(comp[28]+comp[29]+comp[30]+comp[31]+comp[38]+comp[39]-six_48);
		vac[8]= abs(comp[32]+comp[33]+comp[34]+comp[35]+comp[36]+comp[37]-six_48);
		ways+=(C[vac[0]][X]+C[vac[1]][X]+C[vac[2]][X]+C[vac[3]][X]+C[vac[4]][X]+C[vac[5]][X]+C[vac[6]][X]+C[vac[7]][X]+C[vac[8]][X]);
	}
	printf("%d\n", ways);
	
}
