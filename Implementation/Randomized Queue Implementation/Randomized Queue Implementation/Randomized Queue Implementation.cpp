#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

class EmptyException{
public:
	EmptyException(){
		cout << "Queue empty\n";
	}
};
class RandomQueue{
private:
	vector<int>q;
	int last = 0;
	public:
		RandomQueue(){
			
		}

		bool isEmpty(){
			return last==0;
		}
		int size(){
			return last;
		}
		void enqueue(int item){
			if (last == 0){
				q.push_back(item);
				last++;
				return;
			}
			if (last == q.size())q.resize(q.size() * 2);

			q[last]=item; 
			last++;
		}
		void dequeue(){
			if (isEmpty())throw new EmptyException();
			else {
				int x = rand() % size();
				q.erase(q.begin() + x);
				last--;
			}
		}
		int sample(){
			if (isEmpty())throw new EmptyException();
			else{
				int x = rand() % size();
				return q[x];
			}
		}

	};
int main()
{
	RandomQueue x;
	x.enqueue(3);
	x.enqueue(2);
	x.enqueue(7);
	x.enqueue(50);
	x.enqueue(100);
	cout << x.sample() << "\n";
	x.dequeue();
	return 0;
}
