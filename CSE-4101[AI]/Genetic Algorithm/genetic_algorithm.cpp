#include <bits/stdc++.h>
using namespace std;
#define MAX 20

struct chromosome{
	int arr[15];
};

struct Temp_Sum{
	int sum;
	int pos;
};

Temp_Sum temp_sum[MAX+1];

bool cmp(Temp_Sum a, Temp_Sum b){
	if(a.sum<b.sum) return true;
	else return false;
}

int size;
int num_population;
int gene;

chromosome population[MAX+1];
int price[MAX+1],weight[MAX+1];
int max_weight;

void input(void);
void print(void);
void mutation(void);
void cross_over(void);
void selection(void);
int total_fitness_count(void);



void cross_over(int one,int two){
	int pos=rand()%gene+1;
	int cnt=rand()%2;
	cnt=1;
	if(cnt==1) {
		//front same
		//after pos changes 
		int A1[MAX+1],A2[MAX+1];
		for(int i=1;i<=pos;i++){
			A1[i]=population[one].arr[i];
		}
		for(int i=pos+1;i<=gene;i++){
			A1[i]=population[two].arr[i];
		}
		for(int i=1;i<=pos;i++){
			A2[i]=population[two].arr[i];
		}
		for(int i=pos+1;i<=gene;i++){
			A2[i]=population[one].arr[i];
		}
		for(int i=1;i<=gene;i++){
			population[one].arr[i]=A1[i];
			population[two].arr[i]=A2[i];
		}
	}
	else{
		//back same front changes
		int A1[MAX+1],A2[MAX+1];
		for(int i=1;i<=pos;i++){
			A1[i]=population[two].arr[i];
		}
		for(int i=pos+1;i<=gene;i++){
			A1[i]=population[one].arr[i];
		}
		for(int i=1;i<=pos;i++){
			A2[i]=population[one].arr[i];
		}
		for(int i=pos+1;i<=gene;i++){
			A2[i]=population[two].arr[i];
		}
		for(int i=1;i<=gene;i++){
			population[one].arr[i]=A1[i];
			population[two].arr[i]=A2[i];
		}
	}
}

void mutation(int number){
	int v=rand()%73;
	int u=rand()%71;
	if(u==v){
		int pos=rand()%gene+1;
		int f1=total_fitness_count();
		population[number].arr[pos] ^= 1;
		int fitness = total_fitness_count();
		if(f1>fitness){
			population[number].arr[pos] ^= 1;
		}
	}
}

//32mu7d

void selection(void){
	for(int i=1;i<=num_population/2;i++){
		cross_over(i,num_population-i+1);
	}
	return;
}

int total_fitness_count(void){
	int global_price=0;
	for(int i=1;i<=num_population;i++){
		int pr=0;
		int wt=0;
		for(int j=1;j<=gene;j++){
			pr += (population[i].arr[j]*price[j]);
			wt += (population[i].arr[j]*weight[j]);
		}
		if(wt>max_weight) {
			wt=max_weight-wt;
			global_price += wt;
		}
		else {
			global_price += pr;
		}
		
	}
	return global_price;
}

void print(void){
	int global_price=0;
	int global_weight=0;
	for(int i=1;i<=num_population;i++){
		int pr=0;
		int wt=0;
		for(int j=1;j<=gene;j++){
			cout<<population[i].arr[j];
			pr += population[i].arr[j]*price[j];
			wt +=  population[i].arr[j]*weight[j];
		}
		cout<<" price = " << pr<<" weight " << wt<<endl;
		if(wt>max_weight){
			wt=max_weight-wt;
			global_price += wt;
		}
		else{
			global_price += pr;
		}
			
	}
	cout<<"fitness " << global_price<<endl;
}

void genetic_algorithm(void){
	int cnt=0;
	int max_fit=0;
	while(true){
		int fitness = total_fitness_count();
		cout<<"fitness here " << fitness<<endl;
		max_fit=max(max_fit,fitness);
		print();
		//char ch=getchar();
		cnt++;
		if(fitness>=590) break;
		selection();
		mutation(rand()%num_population+1);
		if(cnt>=200000) {
			for(int i=1;i<=num_population;i++){
				for(int j=1;j<=gene;j++){
					population[i].arr[j]=rand()%2;
			}
			continue;
			}
		}
		assert(cnt<=INT_MAX);
		if(cnt>=1000000) {
			cout<<max_fit<<" "<<endl;
			//break;
		}
	}
	cout<<cnt<<endl;
}

void input(void){
	printf("Please give number of population: ");
	cin>>num_population;
	printf("Please give number of items: ");
	cin>>gene;
	printf("Give price of the items:\n");
	for(int i=1;i<=gene;i++){
		cin>>price[i];
	}
	printf("Give weight of the items:\n");
	for(int i=1;i<=gene;i++){
		cin>>weight[i];
	}
	printf("Give knapsack weight\n");
	cin>>max_weight;
	
	srand(time(NULL));
	for(int i=1;i<=num_population;i++){
		for(int j=1;j<=gene;j++){
			population[i].arr[j]=rand()%2;
	}
	}
	print();
	selection();
	genetic_algorithm();
}


int main(void){
	//freopen("in.txt","r",stdin);
	input();
	return 0;
}
