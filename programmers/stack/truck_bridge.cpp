#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
 	int answer = 1;
	int cnt = 0;
	int out_cnt = 0;

	int tmp_weight = 0;
	
	vector<pair<int, int>>on_bridge;
	
	int weights_on_bridge = 0;
	int done = 0;
	int next_truck = 0;

	while (done < truck_weights.size())
	{
		
		if (truck_weights.size() > next_truck)
		{
			if (weights_on_bridge + truck_weights.at(next_truck) <= weight) {

				on_bridge.push_back(make_pair(truck_weights.at(next_truck), 1));
				weights_on_bridge += truck_weights.at(next_truck);
				
				next_truck++;
			}
		}
		
		for (int i = 0; i < on_bridge.size(); i++) {
			on_bridge.at(i).second++;	
		}
		answer++;
		
		if (on_bridge.at(0).second == bridge_length+1) {
			weights_on_bridge -= on_bridge.at(0).first;
			on_bridge.erase(on_bridge.begin());
			done++;
		}


		
	}
		return answer;
}