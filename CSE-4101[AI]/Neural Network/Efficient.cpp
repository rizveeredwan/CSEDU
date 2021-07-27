#include <bits/stdc++.h>
using namespace std;
#define MAX 2

int input_num;
int num_per_input;
int num_hidden_layer;
double alpha=1.0;
double acceptance=0.002;


struct Hidden_Layer_Info{
	int num_nodes; //number of nodes per layer
	double weigth_nodes[MAX*10+1][MAX*10+1];
	int matrix_elem; //how many weights 
	double value[MAX*10+1];
	double z[MAX*10+1]; //other layers output  
	double y[MAX*10+1]; //final layers output 
	double delta[MAX*10+1]; //per nodes delta 
	int biased_input[MAX*10+1];
};

Hidden_Layer_Info hidden_layer_info[MAX*10+1]; //hidden layer informations how many node per layer 

struct Input_des{
	int output; //output 
	int inputs[10]; //how many inputs in per input sequence 
};

Input_des input_set[MAX*10+1];


void take_input(){
	printf("start to give input\n");
	for(int i=1;i<=input_num;i++){
		printf("input number:\n");
		for(int j=1;j<=num_per_input;j++) {
			scanf("%d",&input_set[i].inputs[j]);
		}
		printf("output\n");
		scanf("%d",&input_set[i].output); 
	}
	/*
	int biased_input;
	printf("Give biased input\n");
	scanf("%d",&biased_input);
	for(int i=1;i<=input_num;i++){
		input_set[i].inputs[0] = biased_input;
	} */
}

void layer_input(){
	printf("Please give number of hidden layer:\n");
	scanf("%d",&num_hidden_layer);
	for(int i=1;i<=num_hidden_layer;i++){
		printf("In hidden layer %d\n",i);
		printf("please give number of nodes in this layer:\n");
		scanf("%d",&hidden_layer_info[i].num_nodes);
		printf("how many weights in this layer except biasing node\n");
		scanf("%d",&hidden_layer_info[i].matrix_elem); 
		for(int j=1;j<=hidden_layer_info[i].num_nodes;j++) {
			printf("Taking the information about the nodes per layer:\n");
			for(int k=0;k<=hidden_layer_info[i].matrix_elem;k++) {
				if(k==0) {
					printf("weight for the biasing input.\n");
				}
				else {
					printf("Weight for the normal inputs\n"); 
				}
				scanf("%lf",&hidden_layer_info[i].weigth_nodes[j][k]);
			}
			printf("Give biased input for this node\n");
			scanf("%d",&hidden_layer_info[i].biased_input[j]);
		}
	}
	
	printf("Final layer output calculation.\n");
	hidden_layer_info[num_hidden_layer+1].num_nodes=1;
	printf("how many weights in this layer\n");
	scanf("%d",&hidden_layer_info[num_hidden_layer+1].matrix_elem); 
	for(int i=0;i<=hidden_layer_info[num_hidden_layer+1].matrix_elem;i++) {
		if(i==0) {
			printf("weight for the biasing input.\n");
		}
		else {
			printf("weight for the normal input.\n");
		}
		scanf("%lf",&hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][i]); 
	}
	printf("Give biased input for this node\n");
	scanf("%d",&hidden_layer_info[num_hidden_layer+1].biased_input[1]);
	
}

double f(double x){
	double value = exp(-x);
	value = 1 + value;
	value = 1 / value;
	return value;
}

void artificial_neural_network() {
	int count;
	printf("please give number of iteration:\n");
	scanf("%d",&count);
	for(int i=1;;i++){
		int guni=0;
		for(int j=1;j<=input_num;j++) {
			for(int k=1;k<=num_hidden_layer;k++) {
				if(k==1) {
					double z_in=0.0;
					for(int l=1;l<=hidden_layer_info[k].num_nodes;l++) {
						z_in = hidden_layer_info[k].biased_input[l]*hidden_layer_info[k].weigth_nodes[l][0];
						for(int m=1;m<=num_per_input;m++) {
							z_in=z_in+input_set[j].inputs[m]*hidden_layer_info[k].weigth_nodes[l][m]; 
						}
						
						hidden_layer_info[k].value[l] = z_in; //value 
						hidden_layer_info[k].z[l] = f(z_in); //value 
						//cout<<"l : = " << l<<" and z = "<<hidden_layer_info[k].z[l]<<endl;
					}
				}
				else {
					//other layer works 		
				}
			}
			//final layer
			double y_in=hidden_layer_info[num_hidden_layer+1].biased_input[1]*hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][0];
			y_in = y_in + hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][1] * hidden_layer_info[num_hidden_layer].z[1];
			y_in = y_in + hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][2]*input_set[j].inputs[2];
			
			hidden_layer_info[num_hidden_layer+1].y[1] = f(y_in);
			//cout<<"yin " << hidden_layer_info[num_hidden_layer+1].y[1]<<endl;
			cout<<"iteration num "<<i<<endl;
			double diff = fabs(hidden_layer_info[num_hidden_layer+1].y[1]-input_set[j].output);
			cout<<diff<<endl; 
			if(diff<=acceptance) {
				guni++;
			}
			
			//part of back propagation 
			hidden_layer_info[num_hidden_layer+1].delta[1] = (input_set[j].output-hidden_layer_info[num_hidden_layer+1].y[1]);
			hidden_layer_info[num_hidden_layer+1].delta[1] *= hidden_layer_info[num_hidden_layer+1].y[1]*(1-hidden_layer_info[num_hidden_layer+1].y[1]);
			
			//cout<<"delta1 for final layer" << hidden_layer_info[num_hidden_layer+1].delta[1] << endl;
			
			//cout<<"delta for hidden layers" << endl; 
			for(int p=num_hidden_layer;p>=1;p--){
				for(int q=1;q<=hidden_layer_info[p].num_nodes;q++){
					double del_in=0.0;
					del_in = hidden_layer_info[p+1].delta[1]*hidden_layer_info[p+1].weigth_nodes[1][q];
					hidden_layer_info[p].delta[q] = del_in * hidden_layer_info[p].z[q] * (1 - hidden_layer_info[p].z[q]); 
					//cout<<hidden_layer_info[p].delta[q]<<endl;
				}
			}
			//update of the weights 
			//cout<<"update of the weights" << endl; 
			for(int p=0;p<=hidden_layer_info[num_hidden_layer+1].matrix_elem;p++){
				
				if(p == 0) {
					hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p]= hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p] + hidden_layer_info[num_hidden_layer+1].delta[1] * hidden_layer_info[num_hidden_layer+1].biased_input[1];
				}
				else if(p == 2) {
					hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p]= hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p] + alpha * hidden_layer_info[num_hidden_layer+1].delta[1] * input_set[j].inputs[p];
				}
				else {
					hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p]= hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p] + alpha * hidden_layer_info[num_hidden_layer+1].delta[1] * hidden_layer_info[num_hidden_layer].z[p];
				}
				//cout<<hidden_layer_info[num_hidden_layer+1].weigth_nodes[1][p]<<endl; 
			}
			
			//hidden layer update 
			//cout<<"update of the hidden layer" << endl; 
			for(int p=num_hidden_layer; p>=1;p--){
				for(int q=1;q<=hidden_layer_info[p].num_nodes;q++){
					//cout<<"for q " << q << endl;
					for(int r=0;r<=hidden_layer_info[p].matrix_elem;r++){
						if(r==0){
							hidden_layer_info[p].weigth_nodes[q][r] = hidden_layer_info[p].weigth_nodes[q][r] + hidden_layer_info[p].delta[q]*hidden_layer_info[p].biased_input[1];
						}
						else {
							hidden_layer_info[p].weigth_nodes[q][r] = hidden_layer_info[p].weigth_nodes[q][r] + alpha * hidden_layer_info[p].delta[q]*input_set[j].inputs[r];
						}
						//cout<<hidden_layer_info[p].weigth_nodes[q][r]<<endl;
					}
				}
			}
		}
		if(guni == 2) {
			cout<<"iteration count " << i << endl; 
			printf("Finalayer weights:\n");
			for(int l=1;l<=hidden_layer_info[num_hidden_layer+1].num_nodes;l++){
				for(int m=0;m<=hidden_layer_info[num_hidden_layer+1].matrix_elem;m++){
					cout<<hidden_layer_info[num_hidden_layer+1].weigth_nodes[l][m]<<endl;
				}
			}
			printf("Hidden layer weights:\n");
			cout<<hidden_layer_info[1].weigth_nodes[1][0]<<" "<<hidden_layer_info[1].weigth_nodes[1][1]<<" "<<hidden_layer_info[1].weigth_nodes[1][2]<<endl;
			/*for(int l=1;l<=hidden_layer_info[num_hidden_layer+1].num_nodes;l++){
				for(int m=0;m<=hidden_layer_info[num_hidden_layer+1].matrix_elem;m++){
					cout<<hidden_layer_info[num_hidden_layer+1].weigth_nodes[l][m]<<endl;
				}
			}*/
			break;
		}
		if(i>=1000000){
			cout<<"till now " <<guni << endl; 
			break;
		}
		
	}
}






int main(void) {
	freopen("in2.txt","r",stdin);
	printf("Give input number and num_per_input accordingly:\n"); 
	scanf("%d %d",&input_num,&num_per_input); //how many input 
											 //number per input 
	take_input();
	layer_input();
	artificial_neural_network(); 
											 
}
