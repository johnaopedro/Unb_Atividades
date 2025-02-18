#include <cstdio>
#include <vector>
void entrada(int& N,int& T,std::vector<std::pair<int,int>>& processo){
scanf("%d", &N);
scanf("%d", &T);
int pid,t;
for(int i = 0;i < N;i++){
	scanf("%d %d", &pid, &t);
	t *= 1000;
	processo.emplace_back(pid,t);}}
void round_robin(int N,int T,std::vector<std::pair<int,int>>& processo){
int j = 0,turnaround = 0;
while(N){
	int& remaining_time = processo[j].second;
	remaining_time -= T;turnaround += T;
	if(remaining_time <= 0){
		turnaround += remaining_time;
		printf("%d (%d)\n", processo[j].first, turnaround);
		processo.erase(processo.begin() + j);
		if(j == --N){
			j = 0;}
	}else if (++j == N){
		j = 0;}}}
int main(void){
int N,T;
std::vector<std::pair<int, int>> processo;
entrada(N,T,processo);
round_robin(N,T,processo);
return 0;}