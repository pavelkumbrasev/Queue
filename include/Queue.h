#pragma once
template<class T>
class TQueue{
private:
	int lastElem,firstElem,MaxSize,size;
	T* mas;
	
public:
	bool isFull(){return size==MaxSize;}
	bool isEmpty(){return size==0;}
	TQueue(int _MaxSize=100){
		if (_MaxSize<0) throw _MaxSize;
	    MaxSize=_MaxSize;
	    mas=new T[MaxSize];
	    size=0;
	    lastElem=-1;
	    firstElem=0;
	}
	~TQueue(){delete [] mas;}
	TQueue(const TQueue& que){
        MaxSize=que.MaxSize;
	    mas=new T[MaxSize];
	    size=que.size;
	    firstElem=que.firstElem;
	    lastElem=que.lastElem;
		for(int i=firstElem;i<lastElem+1;i++)
			mas[i]=que.mas[i];
	}
	void push(T a){
		if (isFull()) throw a;
		if ((lastElem+1)==MaxSize) lastElem=-1;
		mas[++lastElem]=a;
		size++;
		lastElem++;
	}
	T pop(){
		if (isEmpty()) throw -1;
		T a;
		if(firstElem+1==MaxSize){ a=mas[firstElem]; firstElem=0;}
		else {a=mas[firstElem]; firstElem++;}
		size--;
		return a;
	}
	void clear(){ 
		size=0;
	    lastElem=-1;
	    firstElem=0;
	}
};