#include <iostream>

using namespace std;

template <class T, int r, int c>
class Matrix
{
	public:
		T **x;
		Matrix()
		{
			x=new T*[r];
			for (int i=0;i<r;i++)
				x[i]=new T[c];
		}
		
		~Matrix()
		{
			for (int i=0;i<r;i++)
				delete x[i];
			delete [] x;
		}
		
		void afis()
		{
			for (int i=0;i<r;i++)
			{
				for (int j=0;j<c;j++)
					cout<<x[i][j]<<" ";
				cout<<endl;
			}
		}
		
		void init(T val)
		{
			for (int i=0;i<r;i++)
				for (int j=0;j<c;j++)
				{
					x[i][j]=val;
					val--;
				}
		}
		
		Matrix operator +(Matrix &m)
		{
			Matrix<T,r,c> temp;
			
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
				{
					temp.x[i][j]=x[i][j]+m.x[i][j];
				}
			cout<<"Overload +"<<endl;
			temp.afis();
			return temp;
		}
};

int main()
{
	Matrix<int,3,3> x;
	Matrix<int,3,3> y;
	x.init(9);
	y.init(20);
	x.afis();
	y.afis();
	x+y;
}
