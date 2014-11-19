#include<iostream>
#include<stack>
using namespace std;

class MinStack{
	public:
	stack<int> s;
	stack<int> min;
	void push(int x){
		s.push(x);

		if(min.empty() || x <= min.top())
			min.push(x);
	}

	void pop(){
		int top = s.top();
		s.pop();

		if(top == min.top())
			min.pop();
	}

	int top(){
		return s.top();
	}
	
	int getMin() {
		
		return min.top();
	}
};

int main()
{
	MinStack st;
	st.push(3);
	cout<<st.top()<<endl;
	st.push(1);
	st.push(5);

	cout<<st.getMin()<<endl;
	return 0;
}
