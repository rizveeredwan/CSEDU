#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int tot_layer;
int hiddent_layer;
int input_set;
int num_input_per_input_set; 
int alpha;
double tolerance;

struct Layer{
	int num_nodes;
	int weight_num_per_node; 
	double weight_vector[MAX+1][MAX+1];
	double output[MAX+1];
	double delta[MAX+1];
};
Layer layer[MAX+1];

int x[MAX+1][MAX+1]; //initial input
int t[MAX+1]; //final output;

void input(){
	freopen("in.txt","r",stdin);
	cout<<"Give number of hidden layer (including output layer) " << endl;
	cin>>hiddent_layer;
	
	cout<<"input layer "<< endl;
	cout<<"Give number of input sets " << endl;
	cin>>input_set;
	cout<<"Give number of input per input set " << endl;
	cin>>num_input_per_input_set;
	for(int i=1;i<=input_set;i++){
		cout<<"input for set " <<i<<endl;
		for(int j=1;j<=num_input_per_input_set;j++){
			cin>>x[i][j];
		}
		cout<<"output for set "<<i<<endl;
		cin>>t[i];
	}
	return;
}

void input_hidden_layer(){
	for(int i=1;i<=hiddent_layer;i++){
		cout<<"information for hidden layer " << i<<endl;
		
		cout<<"number of nodes " << endl;
		cin>>layer[i].num_nodes;
		cout<<"weight number per node " << endl;
		cin>>layer[i].weight_num_per_node;
		
		for(int j=1;j<=layer[i].num_nodes;j++){
			cout<<"node "<<j<<endl;
			for(int k=0;k<layer[i].weight_num_per_node;k++){
				if(k==0) cout<<"biasing weight " << endl;
				cin>>layer[i].weight_vector[j][k];
			}
		}
	}
}

double sigmoid(double x){
	double value =  exp(-x);
	value = 1 + value;
	value = 1/value;
	return value;
}

void artificial_neural_net(){
	cout<<"learning rate / alpha "<<endl;
	cin>>alpha;
	cout<<"tolerance "<<endl;
	cin>>tolerance;
	int cnt=0;
	int it=0;
	while(true){
		it++;
		cout<<cnt<<" "<<it<<endl;
		if(cnt==input_set) break;
		cnt=0;
		for(int i=1;i<=input_set;i++){
			//first hidden layer
			for(int j=1;j<=layer[1].num_nodes;j++){
				layer[1].output[j]=0;
				for(int k=0;k<layer[1].weight_num_per_node;k++){
					if(k==0) layer[1].output[j] = layer[1].weight_vector[j][k];
					else {
						layer[1].output[j] += layer[1].weight_vector[j][k]*x[i][k];
					}
				}
				//cout<<layer[1].output[j]<<endl;
				layer[1].output[j] = sigmoid(layer[1].output[j]);
				//cout<<"z " <<j<< " " <<layer[1].output[j]<<endl;
			}
			
			//other layers
			for(int j=2;j<=hiddent_layer;j++){
				for(int k=1;k<=layer[j].num_nodes;k++){
					for(int l=0;l<layer[j].weight_num_per_node;l++){
						if(l==0) {
							layer[j].output[k] = layer[j].weight_vector[k][l];
						}
						else {
							layer[j].output[k] += layer[j].weight_vector[k][l]*layer[j-1].output[l];
						}
					}
					layer[j].output[k] = sigmoid(layer[j].output[k]);
					//cout<<"ou "<<layer[j].output[k]<<endl;
				}
			}
			//back propagation
			//last leyar
			for(int j=hiddent_layer;j>=1;j--){
				if(j==hiddent_layer){
					layer[j].delta[1] = (t[i] - layer[j].output[1]) * layer[j].output[1] * (1 - layer[j].output[1]);
					double diff = t[i] - layer[j].output[1];
					//cout<<fabs(diff)<<endl;
					if(fabs(diff)<=tolerance) cnt++;
					/*//cout<<"del " << layer[j].delta[1]<<endl;
					layer[j].weight_vector[1][0] = layer[j].weight_vector[1][0] + alpha * 1 * layer[j].delta[1]; 
					for(int k=1;k<=layer[j-1].num_nodes;k++){
						layer[j].weight_vector[1][k] = layer[j].weight_vector[1][k] +  alpha * layer[j].delta[1] * layer[j-1].output[k];
						//cout<<" huss " <<layer[j].weight_vector[1][k]<<endl;
					}*/ 
				}
				else {
					for(int k=1;k<=layer[j].num_nodes;k++){
						layer[j].delta[k] = 0;
						for(int l=1;l<=layer[j+1].num_nodes;l++){
							layer[j].delta[k] = layer[j].delta[k] + layer[j+1].delta[l] * layer[j+1].weight_vector[l][k];
						}
						layer[j].delta[k] = layer[j].delta[k] * layer[j].output[k] * (1 -  layer[j].output[k]);
						//cout<<"error j " << j << " "<< layer[j].delta[k]<<endl;
					}
				}
			}
			
			for(int j=hiddent_layer;j>=2;j--){
				for(int k=1;k<=layer[j].num_nodes;k++){
					//cout<<"error  j = " <<j<<" k = " << layer[j].delta[k]<<endl; 
					for(int l=0;l<layer[j].weight_num_per_node;l++){
						if(l==0) {
							layer[j].weight_vector[k][l] = layer[j].weight_vector[k][l] + alpha * 1 * layer[j].delta[k];
						}
						else {
							layer[j].weight_vector[k][l] = layer[j].weight_vector[k][l] + alpha * layer[j].delta[k] * layer[j-1].output[l];
						}
						//cout<<" j = " <<j<<" k = " << k <<"  l = "<< l<<" "<<layer[j].weight_vector[k][l]<<endl;
					}
				}
			}
			//first hidden layer
			for(int j=1;j<=layer[1].num_nodes;j++){
				for(int k=0;k<layer[1].weight_num_per_node;k++){
					if(k==0) {
						layer[1].weight_vector[j][k] = layer[1].weight_vector[j][k]  + alpha * 1 * layer[1].delta[j];
					}
					else {
						layer[1].weight_vector[j][k] = layer[1].weight_vector[j][k] + alpha * layer[1].delta[j] * x[i][k];
					}
					//cout<<"j = " << j <<" "<<k<<" "<<layer[1].weight_vector[j][k]<<endl;
				}
			}
			
		}
		//break;
		
	}
	
	cout<<"weights " << endl;
	for(int i=1;i<=hiddent_layer;i++){
		cout<<"Layer"<<i<<endl;
		for(int j=1;j<=layer[i].num_nodes;j++){
			cout<<"num nodes "<<j<<endl;
			for(int k=0;k<layer[i].weight_num_per_node;k++){
				cout<<layer[i].weight_vector[j][k]<<endl;
			}
		}
	}
	
}

int main(void){
	
	input();
	input_hidden_layer();
	artificial_neural_net();
	
	return 0;
}
